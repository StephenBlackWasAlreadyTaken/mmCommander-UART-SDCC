#include "cc1111rf.h"
#include "global.h"
#include "nic.h"

#ifdef VIRTUAL_COM
#include "cc1111_vcom.h"

// FIXME: this belongs elsewhere...
#define STATUS_TAG 0
#define STATUS_LEN 1
#define STATUS_VAL 2

#define TAG_MODE    0x01 /* Value is mode, IDLE,RX,TX */
#define TAG_SEND    0x02 /* Value is what to send */
#define TAG_STATUS  0x03 /* Value is the status value want to know, for example RSSI */
#define TAG_REG     0x04 /* Register values, value as register=value */

#define TLV_MAX_DATA 50    

#define SIZE_OF_UART_RX_BUFFER 50
#define SIZE_OF_UART_TX_BUFFER SIZE_OF_UART_RX_BUFFER
u16__xdata uartRxBuffer[SIZE_OF_UART_RX_BUFFER];
u16 __xdata uartTxBuffer[SIZE_OF_UART_TX_BUFFER];
u16 __xdata uartRxIndex, uartTxIndex;

typedef struct
{
    u8 uiTag;
    u8 uiLength;
    u8 uiData[TLV_MAX_DATA];
} tlv_t;

static __xdata tlv_t tlv_recv,tlv_send;
static __xdata uiDataPtr = 0;
static __xdata u8 uiStatus = STATUS_TAG;
#else
#include "chipcon_usb.h"
#endif

typedef struct {
    // Start bit level = low => Idle level = high (U0UCR.START = 0)
    // Start bit level = high => Idle level = low (U0UCR.START = 1)
    unsigned char START : 0;
    // Stop bit level = high (U0UCR.STOP = 1)
    // Stop bit level = low (U0UCR.STOP = 0)
    unsigned char STOP : 1;
    // Number of stop bits = 1 (U0UCR.SPB = 0)
    // Number of stop bits = 2 (U0UCR.SPB = 1)
    unsigned char SPB : 0;
    // Parity = disabled (U0UCR.PARITY = 0)
    // Parity = enabled (U0UCR.PARITY = 1)
    unsigned char PARITY : 0;
    // 9-bit data disable = 8 bits transfer (U0UCR.BIT9 = 0)
    // 9-bit data enable = 9 bits transfer (U0UCR.BIT9 = 1)
    unsigned char BIT9 : 0;
    // Level of bit 9 = 0 (U0UCR.D9 = 0), used when U0UCR.BIT9 = 1
    // Level of bit 9 = 1 (U0UCR.D9 = 1), used when U0UCR.BIT9 = 1
    // Parity = Even (U0UCR.D9 = 0), used when U0UCR.PARITY = 1
    // Parity = Odd (U0UCR.D9 = 1), used when U0UCR.PARITY = 1
    unsigned char D9 : 0;
    // Flow control = disabled (U0UCR.FLOW = 0)
    // Flow control = enabled (U0UCR.FLOW = 1)
    unsigned char FLOW : 1;
    // Bit order = MSB first (U0GCR.ORDER = 1)
    // Bit order = LSB first (U0GCR.ORDER = 0) => For PC/Hyperterminal
    unsigned char ORDER : 0; // Data bit order(LSB/MSB first)
} UART_PROT_CONFIG;
UART_PROT_CONFIG __xdata uartProtConfig;

void uartInitProtocol(UART_PROT_CONFIG* uartProtConfig) {
    U0CSR |= 0x80;
    U0UCR = (U0UCR&~0x01) | uartProtConfig->START;
    U0UCR = (U0UCR&~0x02) | (uartProtConfig->STOP << 1);
    U0UCR = (U0UCR&~0x04) | (uartProtConfig->SPB << 2);
    U0UCR = (U0UCR&~0x08) | (uartProtConfig->PARITY << 3);
    U0UCR = (U0UCR&~0x10) | (uartProtConfig->BIT9 << 4);
    U0UCR = (U0UCR&~0x20) | (uartProtConfig->D9 << 5);
    U0UCR = (U0UCR&~0x40) | (uartProtConfig->FLOW << 6);
    U0GCR = (U0GCR&~0x20) | (uartProtConfig->ORDER << 5);
}
typedef struct {
    structure for DMA descriptor:
        unsigned char SRCADDRH; // High byte of the source address
    unsigned char SRCADDRL; // Low byte of the source address
    unsigned char DESTADDRH; // High byte of the destination address
    unsigned char DESTADDRL; // Low byte of the destination address
    unsigned char VLEN : 3; // Length configuration
    unsigned char LENH : 5; // High byte of fixed length
    unsigned char LENL : 8; // Low byte of fixed length
    unsigned char WORDSIZE : 1; // Number of bytes per transfer element
    unsigned char TMODE : 2; // DMA trigger mode (e.g. single or repeated)
    unsigned char TRIG : 5; // DMA trigger; UART RX/TX
    unsigned char SRCINC : 2; // Number of source address increments
    unsigned char DESTINC : 2; // Number of destination address increments
    unsigned char IRQMASK : 1; // DMA interrupt mask
    unsigned char M8 : 1; // Number of desired bit transfers in byte mode
    unsigned char PRIORITY : 2; // The DMA memory access priority
} DMA_DESC;

// Allocate DMA descriptor for UART RX/TX:
// Note that, since the DMA controller only offers one address/reference
// register for DMA channels 1 - 4, the DMA controller expects the
// allocated descriptors for DMA channels 2 – 4 to be located in direct
// address succession to the DMA channel 1 descriptor. This is typically
// relevant when the application has already allocated DMA channel 0, and 1,
// for other purposes than UART support.
DMA_DESC __xdata uartDmaRxTxCh[2]; 

void uartStartTxDmaChan(
    DMA_DESC *uartDmaTxDescr,
    unsigned char uartDmaTxChan,
    unsigned char* uartTxBuf,
    u16 uartTxBufSize) {
    unsigned char uartNum = 0;
    // Source = allocated UART TX buffer, destination = UxDBUF
    // Number of DMA byte transfers = UART TX buffer size.
    uartDmaTxDescr->SRCADDRH = (u16)(uartTxBuf+1)>>8;
    uartDmaTxDescr->SRCADDRL = (u16)(uartTxBuf+1);
    uartDmaTxDescr->DESTADDRH = 0xDF;
    uartDmaTxDescr->DESTADDRL = (uartNum == 0) ? 0xC1:0xF9;
    uartDmaTxDescr->LENH = ((uartTxBufSize-1)>>8)&0xFF;
    uartDmaTxDescr->LENL = (uartTxBufSize-1)&0xFF;
    uartDmaTxDescr->VLEN = 0x00; // Use fixed length DMA transfer count
    uartDmaTxDescr->WORDSIZE = 0x00; // Perfrom 1-byte DMA transfers
    uartDmaTxDescr->TMODE = 0x00; // Single byte transfer per DMA trigger
    uartDmaTxDescr->TRIG = 15 + (2*uartNum); // DMA trigger = USARTx TX complete
    uartDmaTxDescr->SRCINC = 0x01; // Increment source pointer by 1 byte
    // address after each transfer.
    uartDmaTxDescr->DESTINC = 0x00; // Do not increment destination pointer:
    // points to USART UxDBUF register.
    uartDmaTxDescr->IRQMASK = 0x01; // Enable DMA interrupt to the CPU
    uartDmaTxDescr->M8 = 0x00; // Use all 8 bits for transfer count
    uartDmaTxDescr->PRIORITY = 0x00; // DMA memory access has low priority
    // Link DMA descriptor with its corresponding DMA configuration register.
    if (uartDmaTxChan < 1) {
        DMA0CFGH = (unsigned char)((u16)uartDmaTxDescr>>8); //NOTE: May need to use unsigned shorts instead of u16
        DMA0CFGL = (unsigned char)((u16)uartDmaTxDescr&0x00FF);
    } else {
        DMA1CFGH = (unsigned char)((u16)uartDmaTxDescr>>8);
        DMA1CFGL = (unsigned char)((u16)uartDmaTxDescr&0x00FF);
    }
    // Arm DMA channel and apply 45 NOP's for loading DMA configuration
    DMAARM = (( < uartDm Chan) & 1 < aTx 0x1F);
    __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm;
    __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm;
    __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm;
    __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm;
    __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm;
    __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm;
    __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm;
    __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm;
    __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm;

    // Enable the DMA interrupt (IEN1.DMAIE = IEN0.EA = 1),
    // and clear potential pending DMA interrupt requests (IRCON.DMAIF = 0).
    IEN0 |= 0x80; IEN1 |= 0x01; IRCON &= ~0x01;
    // Send the very first UART byte to trigger a UART TX session:
    if (uartNum == 0) {
        U0DBUF = uartTxBuf[0];
    } else {
        U1DBUF = uartTxBuf[0];
    }
    // At this point the UART generates a DMA trigger each time it has
    // transmitted a byte, leading to a DMA transfer from the allocated
    // TX source buffer to UxDBUF. Once the DMA controller has completed
    // the defined range of transfers, the CPU vectors its execution to
    // the DMA ISR in Figure 23.
} 

void uartStartRxDmaChan(
    DMA_DESC *uartDmaRxDescr,
    unsigned char uartDmaRxChan,
    unsigned char* uartRxBuf,
    u16 uartRxBufSize) {
    unsigned char uartNum = 0;
    // Source = UxDBUF, destination = allocated UART RX buffer
    // Number of DMA byte transfers = UART RX buffer size.
    uartDmaRxDescr->DESTADDRH = (u16)uartRxBuf>>8;
    uartDmaRxDescr->DESTADDRL = (u16)uartRxBuf;
    uartDmaRxDescr->SRCADDRH = 0xDF;
    uartDmaRxDescr->SRCADDRL = (uartNum == 0) ? 0xC1:0xF9;
    uartDmaRxDescr->LENH = (uartRxBufSize>>8)&0xFF;
    uartDmaRxDescr->LENL = uartRxBufSize&0xFF;
    uartDmaRxDescr->VLEN = 0x00; // Use fixed length DMA transfer count
    uartDmaRxDescr->WORDSIZE = 0x00; // Perform 1-byte transfers
    uartDmaRxDescr->TMODE = 0x00; // Single byte transfer per DMA trigger
    uartDmaRxDescr->TRIG = 14 + (2*uartNum); // DMA trigger = USARTx RX complete
    uartDmaRxDescr->SRCINC = 0x00; // Do not increment source pointer.
    // points to USART UxDBUF register.
    uartDmaRxDescr->DESTINC = 0x01; // Increment destination pointer by
    // 1 byte address after each transfer.
    uartDmaRxDescr->IRQMASK = 0x01; // Enable DMA interrupt to the CPU
    uartDmaRxDescr->M8 = 0x00; // Use all 8 bits for transfer count
    uartDmaRxDescr->PRIORITY = 0x00; // DMA memory access has low priority
    // Link DMA descriptor with its corresponding DMA configuration register.
    if (uartDmaRxChan < 1) {
        DMA0CFGH = (unsigned char)((u16)uartDmaRxDescr>>8);
        DMA0CFGL = (unsigned char)((u16)uartDmaRxDescr&0x00FF);
    } else {
        DMA1CFGH = (unsigned char)((u16)uartDmaRxDescr>>8);
        DMA1CFGL = (unsigned char)((u16)uartDmaRxDescr&0x00FF);
    }
    // Arm DMA channel and apply 45 NOP's for loading DMA configuration
    DMAARM = (( < uartDm Chan) & 1 < aRx 0x1F);
    __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm;
    __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm;
    __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm;
    __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm;
    __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm;
    __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm;
    __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm;
    __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm;
    __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm; __asm; nop; __endasm;
    // Enable the DMA interrupt (IEN1.DMAIE = IEN0.EA = 1),
    // and clear potential pending DMA interrupt requests (IRCON.DMAIF = 0)
    IEN0 |= 0x80; IEN1 |= 0x01; IRCON &= ~0x01;
    // Enable UARTx RX
    if (uartNum == 0) {
        U0CSR |= 0x40;
    } else {
        U1CSR |= 0x40;
    }
    // At this point the UART generates a DMA trigger each time it has received
    // a byte, leading to a DMA transfer from UxDBUF to the allocated RX target
    // buffer. Once the DMA controller has completed the defined range of
    // transfers, the CPU vectors its execution to the DMA ISR in Figure 24.
} 

/*************************************************************************************************
 * welcome to the cc1111usb application.
 * this lib was designed to be the basis for your usb-app on the cc1111 radio.  hack fun!
 *
 * 
 * best way to start is to look over the library and get a little familiar with it.
 * next, put code as follows:
 * * any initialization code that should happen at power up goes in appMainInit()
 * * the main application loop code should go in appMainLoop()
 * * usb interface code: register a callback using register_Cb_ep5() as demonstrated in appMainInit()
 *
 * if you should need to change anything about the USB descriptors, do your homework!  particularly
 * keep in mind, if you change the IN or OUT max packetsize, you *must* change it in the 
 * EPx_MAX_PACKET_SIZE define, and should correspond to the setting of MAXI and MAXO.
 * 
 * */




/*************************************************************************************************
 * Application Code - these first few functions are what should get overwritten for your app     *
 ************************************************************************************************/

__xdata u32 loopCnt;
__xdata u8 xmitCnt;

int appHandleEP5(void);

/* appMainInit() is called *before Interrupts are enabled* for various initialization things. */
void appMainInit(void)
{
    //registerCb_ep0Vendor( appHandleEP0Vendor );
    registerCb_ep5( appHandleEP5 );

    loopCnt = 0;
    xmitCnt = 1;

    RxMode();
}

/* appMain is the application.  it is called every loop through main, as does the USB handler code.
 * do not block if you want USB to work.                                                           */
void appMainLoop(void)
{
    //  this is part of the NIC code to handle received RF packets and may be replaced/modified //
    __xdata u8 processbuffer;

    if (rfif)
    {
        lastCode[0] = LC_MAIN_RFIF;
        IEN2 &= ~IEN2_RFIE;

        if(rfif & RFIF_IRQ_DONE)
        {
            processbuffer = !rfRxCurrentBuffer;
            if(rfRxProcessed[processbuffer] == RX_UNPROCESSED)
            {
                if (PKTCTRL0&1)     // variable length packets have a leading "length" byte, let's skip it
                    txdata(APP_NIC, NIC_RECV, (u8)rfrxbuf[processbuffer][0], (u8*)&rfrxbuf[processbuffer][1]);
                else
                    txdata(APP_NIC, NIC_RECV, PKTLEN, (u8*)&rfrxbuf[processbuffer]);

                // Set receive buffer to processed so it can be used again //
                rfRxProcessed[processbuffer] = RX_PROCESSED;
            }
        }

        rfif = 0;
        IEN2 |= IEN2_RFIE;
    }
    //////////////////////////////////////////////////////////////////////////////////////////////
}

/* appHandleEP5 gets called when a message is received on endpoint 5 from the host.  this is the 
 * main handler routine for the application as endpoint 0 is normally used for system stuff.
 *
 * important things to know:
 *  * your data is in ep5.OUTbuf, the length is ep5.OUTlen, and the first two bytes are
 *      going to be \x40\xe0.  just craft your application to ignore those bytes, as i have ni
 *      puta idea what they do.  
 *  * transmit data back to the client-side app through txdatai().  this function immediately 
 *      xmits as soon as any previously transmitted data is out of the buffer (ie. it blocks 
 *      while (ep5.flags & EP_INBUF_WRITTEN) and then transmits.  this flag is then set, and 
 *      cleared by an interrupt when the data has been received on the host side.                */
int appHandleEP5()
{   // not used by VCOM
#ifndef VIRTUAL_COM
    __xdata u8 *ptr = &ep5.OUTbuf[0];

    switch (ep5.OUTcmd)
    {
        /*
           case CMD_RFMODE:
           switch (*ptr++)
           {
           case RF_STATE_RX:

           RxMode();
           break;
           case RF_STATE_IDLE:
           IdleMode();
           break;
           case RF_STATE_TX:
           transmit(ptr, len);
           break;
           }
           txdata(app,cmd,len,ptr);
           break;
           */
    default:
        break;
    }
    ep5.flags &= ~EP_OUTBUF_WRITTEN;                       // this allows the OUTbuf to be rewritten... it's saved until now.
#endif
    return 0;
}

/*************************************************************************************************
 *  here begins the initialization stuff... this shouldn't change much between firmwares or      *
 *  devices.                                                                                     *
 *************************************************************************************************/

static void appInitRf(void)
{
    IOCFG2    = 0x00;
    IOCFG1    = 0x00;
    IOCFG0    = 0x00;
    SYNC1     = 0xFF;
    SYNC0     = 0x00;
    PKTLEN    = 0xff;
    PKTCTRL1  = 0x00; // PQT threshold  - was 0x00
    PKTCTRL0  = 0x00;
    ADDR      = 0x00;
    CHANNR    = 0x00;
    FSCTRL1   = 0x06;
    FSCTRL0   = 0x00;
    FREQ2     = 0x26;
    FREQ1     = 0x30;
    FREQ0     = 0x00;
    /*FREQ2       = 0x24; // eu = 0x26;*/
    /*FREQ1       = 0x2E; // eu = 0x30;*/
    /*FREQ0       = 0x38; // eu = 0x00;*/
    MDMCFG4   = 0x59;
    MDMCFG3   = 0x66;
    MDMCFG2   = 0x33;
    MDMCFG1   = 0x62;
    MDMCFG0   = 0x1A;
    DEVIATN   = 0x13;
    MCSM2     = 0x07;             // RX_TIMEOUT
    MCSM1     = 0x30;             // CCA_MODE RSSI below threshold unless currently recvg pkt - always end up in RX mode
    MCSM0     = 0x18;             // fsautosync when going from idle to rx/tx/fstxon
    FOCCFG    = 0x17;
    BSCFG     = 0x6c;
    AGCCTRL2  = 0x03;
    AGCCTRL1  = 0x40;
    AGCCTRL0  = 0x91;
    FREND1    = 0x56;
    FREND0    = 0x12;
    FSCAL3    = 0xe9;
    FSCAL2    = 0x2A;
    FSCAL1    = 0x00;
    FSCAL0    = 0x1F;
    TEST2     = 0x88; // low data rates, increased sensitivity - was 0x88
    TEST1     = 0x31; // always 0x31 in tx-mode, for low data rates, increased sensitivity - was 0x31
    TEST0     = 0x09;
    PA_TABLE7 = 0x00;
    PA_TABLE6 = 0x00;
    PA_TABLE5 = 0x00;
    PA_TABLE4 = 0x00;
    PA_TABLE3 = 0x00;
    PA_TABLE2 = 0x52;
    PA_TABLE1 = 0x00;
    PA_TABLE0 = 0x00;
    RFTXRXIE  = 0;
}

static void appInitUart(void) { // Uart Alt1
    // P0SEL.SELP0_2/3/4/5 = 1 => RX = P0_2, TX = P0_3, CT = P0_4, RT = P0_5
    PERCFG &= ~0x01;
    P0SEL |= 0x3C;
    P1SEL &= ~0x3C;

    ///////////////////////////////////////////////////////////////
    // Set Baud Rate to 9600
    // cc1110 M= 131 E= 8
    // cc1111 M= 163 E= 8
    CLKCON &= 0x80;
    while(CLKCON & 0x40);
    // Set SLEEP.OSC_PD to power down the HS RCOSC.
    SLEEP |= 0x04;
    // Initialize bitrate (U0BAUD.BAUD_M, U0GCR.BAUD_E)
    U0BAUD = 163;
    U0GCR = (U0GCR&~0x1F) | 8;

    ///////////////////////////////////////////////////////////////
}

/*************************************************************************************************
 * main startup code                                                                             *
 *************************************************************************************************/
void initBoard(void)
{
    // in global.c
    clock_init();
    io_init();
}


void main (void)
{
    initBoard();
    initUSB();
    init_RF();
    appMainInit();

    /* Enable interrupts */
    EA = 1;
    usb_up();


    // wait until the host identifies the usb device (the host timeouts are awfully fast)
    waitForUSBsetup();

    while (1)
    {  
        usbProcessEvents();
        appMainLoop();
    }

}

