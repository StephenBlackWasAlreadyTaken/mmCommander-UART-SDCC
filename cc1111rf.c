#include "cc1111rf.h"
#include "global.h"

#include <string.h>

/* Rx buffers */
volatile __xdata u8 rfRxCurrentBuffer;
volatile __xdata u8 rfrxbuf[BUFFER_AMOUNT][BUFFER_SIZE];
volatile __xdata u8 rfRxCounter[BUFFER_AMOUNT];
volatile __xdata u8 rfRxProcessed[BUFFER_AMOUNT];
volatile __xdata u8 bRxDMA;
/* Tx buffers */
volatile __xdata u8 rftxbuf[BUFFER_SIZE];
volatile __xdata u8 rfTxCounter = 0;

u8 rfif;
volatile __xdata u8 rf_status;
volatile __xdata DMA_DESC rfDMA;

volatile __xdata u8 bRepeatMode = 0;

/*************************************************************************************************
 * RF init stuff                                                                                 *
 ************************************************************************************************/
void init_RF(u8 bEuRadio, register_e rRegisterType)
{
    /* Init DMA channel */
    DMA0CFGH = ((u16)(&rfDMA))>>8;
    DMA0CFGL = ((u16)(&rfDMA))&0xff;

    /* clear buffers */
    memset(rfrxbuf,0,(BUFFER_AMOUNT * BUFFER_SIZE));
    memset(rftxbuf,0,BUFFER_SIZE);
	
    IOCFG2      = 0x00;
	IOCFG1      = 0x00;
	IOCFG0      = 0x00;
	SYNC1       = 0x0c;
	SYNC0       = 0x4e;
	PKTLEN      = 0xff;
	if(rRegisterType == RECV)
	{
		PKTCTRL1    = 0x40;
	}
	else
	{
		PKTCTRL1	= 0x00;
	}
	PKTCTRL0    = 0x05;
	ADDR        = 0x00;
	CHANNR      = 0x00;
	FSCTRL1     = 0x08;
	FSCTRL0     = 0x00;
	FREQ2       = 0x24;
	FREQ1       = 0x2d;
	FREQ0       = 0xdd;
	MDMCFG4     = 0xca;
	MDMCFG3     = 0xa3;
	MDMCFG2     = 0x93;
	MDMCFG1     = 0x23;
	MDMCFG0     = 0x11;
	DEVIATN     = 0x36;
	MCSM2       = 0x07;
	if(rRegisterType == RECV)
	{
		MCSM1       = 0x3C;
	}
	else
	{
		MCSM1       = 0x30;
	}
	MCSM0       = 0x18;
	FOCCFG      = 0x16;
	BSCFG       = 0x6c;
	AGCCTRL2    = 0x43;
	AGCCTRL1    = 0x40;
	AGCCTRL0    = 0x91;
	FREND1      = 0x56;
	FREND0      = 0x10;
	FSCAL3      = 0xe9;
	FSCAL2      = 0x2a;
	FSCAL1      = 0x00;
	FSCAL0      = 0x1f;
	if(rRegisterType == RECV)
	{
		TEST2       = 0x81;
		TEST1       = 0x35;
	}
	else
	{
		TEST2       = 0x88;
		TEST1       = 0x31;
	}
	TEST0       = 0x09;
	PA_TABLE0   = 0x50;

	/* If not EU change frequency */
	if(!bEuRadio)
	{
		FSCTRL1 = 0x0c;
		FREQ2 = 0x25;
		FREQ1 = 0x95;
		FREQ0 = 0x55;
		FREND1 = 0xb6;
		FREND0 = 0x10;
		FSCAL3 = 0xea;
		FSCAL2 = 0x2a;
		FSCAL1 = 0x00;
		FSCAL0 = 0x1f;
	}

	/* Setup interrupts */
	RFTXRXIE = 1;                   // FIXME: should this be something that is enabled/disabled by usb?
	RFIM = 0xd1;
	RFIF = 0;
	rfif = 0;
	IEN2 |= IEN2_RFIE;

	/* Put radio into idle state */
	setRFIdle();
}

void setRFRx(void)
{
    RFST = RFST_SRX;
    while(!(MARCSTATE & MARC_STATE_RX));
    rf_status = RF_STATE_IDLE;
}

void setRFTx(void)
{
    RFST = RFST_STX;
    while(!(MARCSTATE & MARC_STATE_TX));
    rf_status = RF_STATE_IDLE;
}

void setRFIdle(void)
{
	RFST = RFST_SIDLE;
	while(!(MARCSTATE & MARC_STATE_IDLE));
	rf_status = RF_STATE_IDLE;
}

int waitRSSI()
{
	u16 u16WaitTime = 0;
	while(u16WaitTime < RSSI_TIMEOUT_US)
	{
		if(PKTSTATUS & (PKTSTATUS_CCA | PKTSTATUS_CS))
		{
			return 1;
		}
		else
		{
			sleepMicros(50);
			u16WaitTime += 50;
		}
	}
	return 0;
}

/* Functions contains attempt for DMA but not working yet, please leave bDma 0 */
u8 transmit(__xdata u8* buf, u16 len, u8 bDma)
{
    u8 uiRSSITries = 5;

	/* Put radio into idle state */
	setRFIdle();

	/* If len is empty, assume first byte is the length */
	if(len == 0)
	{
		len = buf[0];
        len++;
	}

    /* If DMA transfer, disable rxtx interrupt */
	RFTXRXIE = !bDma; 

	/* Clean tx buffer */
	memset(rftxbuf,0,len);

	/* Copy userdata to tx buffer */
	strcpy(rftxbuf,buf);

	/* Reset byte pointer */
	rfTxCounter = 0;

    /* Configure DMA struct */
    if(bDma)
    {
        rfDMA.srcAddrH = ((u16)buf)>>8;
        rfDMA.srcAddrL = ((u16)buf)&0xff;
        rfDMA.destAddrH = ((u16)&X_RFD)>>8;
        rfDMA.destAddrL = ((u16)&X_RFD)&0xff;
        rfDMA.lenH = len >> 8;
        rfDMA.vlen = 0;
        rfDMA.lenL = len;
        rfDMA.trig = 19;
        rfDMA.tMode = 0;
        rfDMA.wordSize = 0;
        rfDMA.priority = 1;
        rfDMA.m8 = 0;
        rfDMA.irqMask = 0;
        rfDMA.srcInc = 1;
        rfDMA.destInc = 0;
        
        DMA0CFGH = ((u16)(&rfDMA))>>8;
        DMA0CFGL = ((u16)(&rfDMA))&0xff;
    }

	/* Strobe to rx */
	RFST = RFST_SRX;
	while(!(MARCSTATE & MARC_STATE_RX));
	/* wait for good RSSI, TODO change while loop this could hang forever */
	do
    {
        uiRSSITries--;
	} while(!waitRSSI() && uiRSSITries);

    if(uiRSSITries)
    {
        /* Arm DMA channel */
        if(bDma)
        {
            DMAIRQ &= ~DMAARM0;
            DMAARM |= (0x80 | DMAARM0);
            nop(); nop(); nop(); nop();
            nop(); nop(); nop(); nop();
            DMAARM = DMAARM0;
            nop(); nop(); nop(); nop();
            nop(); nop(); nop(); nop();
        }
	    /* Put radio into tx state */
    	RFST = RFST_STX;
    	while(!(MARCSTATE & MARC_STATE_TX));
        return 1;
    }
    return 0;
}

void startRX(u8 bDma)
{
    /* If DMA transfer, disable rxtx interrupt */
    RFTXRXIE = !bDma;
    bRxDMA = bDma;

    /* Clear rx buffer */
    memset(rfrxbuf,0,BUFFER_SIZE);

    /* Set both byte counters to zero */
	rfRxCounter[FIRST_BUFFER] = 0;
	rfRxCounter[SECOND_BUFFER] = 0;

	/*
	 * Process flags, set first flag to false in order to let the ISR write bytes into the buffer,
	 *  The second buffer should flag processed on initialize because it is empty.
	 */
	rfRxProcessed[FIRST_BUFFER] = RX_UNPROCESSED;
	rfRxProcessed[SECOND_BUFFER] = RX_PROCESSED;

	/* Set first buffer as current buffer */
	rfRxCurrentBuffer = 0;

	S1CON &= ~(S1CON_RFIF_0|S1CON_RFIF_1);
	RFIF &= ~RFIF_IRQ_DONE;

    if(bDma)
    {
        rfDMA.srcAddrH = ((u16)&X_RFD)>>8;
        rfDMA.srcAddrL = ((u16)&X_RFD)&0xff;
        rfDMA.destAddrH = ((u16)&rfrxbuf[rfRxCurrentBuffer])>>8;
        rfDMA.destAddrL = ((u16)&rfrxbuf[rfRxCurrentBuffer])&0xff;
        rfDMA.lenH = 0;
        rfDMA.vlen = 0;
        rfDMA.lenL = 12;
        rfDMA.trig = 19;
        rfDMA.tMode = 0;
        rfDMA.wordSize = 0;
        rfDMA.priority = 1;
        rfDMA.m8 = 0;
        rfDMA.irqMask = 0;
        rfDMA.srcInc = 0;
        rfDMA.destInc = 1;
        
        DMA0CFGH = ((u16)(&rfDMA))>>8;
        DMA0CFGL = ((u16)(&rfDMA))&0xff;
        
        DMAIRQ &= ~DMAARM0;
        DMAARM |= (0x80 | DMAARM0);
        nop(); nop(); nop(); nop();
        nop(); nop(); nop(); nop();
        DMAARM = DMAARM0;
        nop(); nop(); nop(); nop();
        nop(); nop(); nop(); nop();
    }

	RFST = RFST_SRX;

	RFIM |= RFIF_IRQ_DONE;
}

void stopRX(void)
{
    RFIM &= ~RFIF_IRQ_DONE;
    setRFIdle();

    DMAARM |= 0x81;                 // ABORT anything on DMA 0

    DMAIRQ &= ~1;

    S1CON &= ~(S1CON_RFIF_0|S1CON_RFIF_1);
    RFIF &= ~RFIF_IRQ_DONE;
}

void RxOn(void)
{
    if (rf_status != RF_STATE_RX)
    {
        rf_status = RF_STATE_RX;
        startRX(bRxDMA);
    }
}

void RxIdle(void)
{
    if (rf_status == RF_STATE_RX)
    {
    	stopRX();
        rf_status = RF_STATE_IDLE;
    }
}

/* Repeater mode...
    Say whut? Mode that receives a packet and then sends it into the air again :)
    Idea: Setup two DMA channels, we can use channel 0 we normally use and combine that with channel 3, because if correct 1 and 2 are used by USB
    Channel 0 will hold the RX, with one extra configuration than normally it should generate an interrupt when DMA is done.
    Channel 3 will hold the TX data, the TX data will be set to the buffer the RX puts his data in, the channel is activated by the DMA done interrupt of the receiver.
   */
void RepeaterStart()
{
    bRepeatMode = 1;
}

void RepeaterStop()
{
    bRepeatMode = 0;
}

/* End Repeater mode... */

//void dmaIntHandler(void) __interrupt DMA_VECTOR // Interrupt handler for DMA */

void rfTxRxIntHandler(void) __interrupt RFTXRX_VECTOR  // interrupt handler should transmit or receive the next byte
{
    lastCode[1] = 17;

    if(MARCSTATE == MARC_STATE_RX)
    {
    	rfrxbuf[rfRxCurrentBuffer][rfRxCounter[rfRxCurrentBuffer]++] = RFD;
    	if(rfRxCounter[rfRxCurrentBuffer] >= BUFFER_SIZE)
        {
        	rfRxCounter[rfRxCurrentBuffer] = 0;
        }
    }
    else if(MARCSTATE == MARC_STATE_TX)
    {
    	if(rftxbuf[rfTxCounter] != 0)
    	{
			RFD = rftxbuf[rfTxCounter++];
    	}
    }
    RFTXRXIF = 0;
}


void rfIntHandler(void) __interrupt RF_VECTOR  // interrupt handler should trigger on rf events
{
    lastCode[1] = 16;
    S1CON &= ~(S1CON_RFIF_0 | S1CON_RFIF_1);
    rfif |= RFIF;

    if (RFIF & RFIF_IRQ_SFD)
    {
        // mark the last time we received a packet.  this will be used for MAC layer decisions in 
        // some protocols like FHSS 
        RFIF &= ~RFIF_IRQ_SFD;
    }
    else if(RFIF & RFIF_IRQ_RXOVF)
    {
    	/* RX overflow, only way to get out of this is to restart receiver */
    	stopRX();
    	startRX(bRxDMA);
        RFIF &= ~RFIF_IRQ_RXOVF;
    }
    else if(RFIF & RFIF_IRQ_TXUNF)
    {
    	/* Put radio into idle state */
		setRFIdle();
        RFIF &= ~RFIF_IRQ_TXUNF;
    }
    else if(RFIF & RFIF_IRQ_DONE)
    {
    	if(rf_status == RF_STATE_TX)
    	{
    		DMAARM |= 0x81;
    	}
    	else
    	{
			if(rfRxProcessed[!rfRxCurrentBuffer] == RX_PROCESSED)
			{
				/* Switch current buffer */
				rfRxCurrentBuffer ^= 1;
				rfRxCounter[rfRxCurrentBuffer] = 0;
				/* Set both buffers to unprocessed */
				rfRxProcessed[FIRST_BUFFER] = RX_UNPROCESSED;
				rfRxProcessed[SECOND_BUFFER] = RX_UNPROCESSED;
                if(bRxDMA)
                {
                    /* Switch DMA buffer */
                    rfDMA.destAddrH = ((u16)&rfrxbuf[rfRxCurrentBuffer])>>8;
                    rfDMA.destAddrL = ((u16)&rfrxbuf[rfRxCurrentBuffer])&0xff;
                    /* Arm DMA for next receive */
                    DMAARM = DMAARM0;
                    nop(); nop(); nop(); nop();
                    nop(); nop(); nop(); nop();
                }
			}
			else
			{
				/* Main app didn't process previous packet yet, drop this one */
				memset(rfrxbuf[rfRxCurrentBuffer],0,BUFFER_SIZE);
				rfRxCounter[rfRxCurrentBuffer] = 0;
			}
    	}
        RFIF &= ~RFIF_IRQ_DONE;
    }
}
