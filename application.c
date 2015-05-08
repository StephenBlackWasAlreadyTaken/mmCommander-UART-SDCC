#include "cc1111rf.h"
#include "global.h"
#include <string.h>
#include "cc1111uart.c"
#include "cc1111usb.h"


/*************************************************************************************************
 * Application Code - these first few functions are what should get overwritten for your app     *
 ************************************************************************************************/

unsigned char __xdata incomingUartPayload[SIZE_OF_UART_RX_BUFFER];
uint8 incomingUartPayloadIdentifier= 0;    //transmission[0]
uint8 incomingUartPayloadMessageCount = 0; //transmission[1]
uint8 incomingUartPayloadSize = 0;         //transmission[2]
uint8 incomingTotalExpectedMessages = 0;

unsigned char __xdata outgoingUartPayload[SIZE_OF_UART_TX_BUFFER];
uint8 outgoingUartPayloadIdentifier= 0;    //transmission[0]
uint8 outgoingUartPayloadMessageCount = 0; //transmission[1]
uint8 outgoingUartPayloadSize = 0;         //transmission[2]

__xdata uint8 processbuffer;

void appMainInit(void) {
}

void sendUartAck() {
    uartTxSendByte(0x01);
}

void sendUartNak() {
    uartTxSendByte(0x00);
}

void sendRfTransmission() {
    transmit(uartRxBuffer, incomingUartPayloadSize, 0);
}


/* appMain is the application.  it is called every loop through main, as does the USB handler code.
 * please do not block if you want USB to work.                                                 */
void addToIncomingMessage() {
    uint8 bufIndex = 3;

    if(incomingUartPayloadIdentifier != uartRxBuffer[0]) { 
        // Seems its part of a new message, lets throw out what we were working on
        // and start working on this one!
        incomingUartPayloadIdentifier = uartRxBuffer[0];
        incomingUartPayloadMessageCount = 0;
        incomingUartPayloadSize = uartRxBuffer[2];
        incomingTotalExpectedMessages = (uartRxBuffer[2] / 17);
        if(uartRxBuffer[2] % 17) { incomingTotalExpectedMessages++; }
    }
    if(incomingUartPayloadMessageCount == (uartRxBuffer[1] - 1)){
        // Cool, it seems we are getting the message we were expecting
        incomingUartPayloadMessageCount = uartRxBuffer[1];

        for(;bufIndex < 20;bufIndex++) {
            incomingUartPayload[bufIndex + ((incomingUartPayloadMessageCount - 1) * 17)] = uartRxBuffer[bufIndex];
        }
        uartRxIndex = 0;
        uartRxInterruptIndex = 0;
        sendUartAck();
        if(incomingTotalExpectedMessages == incomingUartPayloadMessageCount) {
            sendRfTransmission();
        }
    } else {
        //We must have missed a message or something got split up :-/
        sendUartNak();
    }
}


void splitAndSendRfRxOverUart() {
    uint8 messageCounter = 0;
    uint8 payloadCounter = 0;
    outgoingUartPayloadIdentifier++;
    outgoingUartPayloadSize = (uint8)rfrxbuf[processbuffer][0];
    outgoingUartPayloadMessageCount = outgoingUartPayloadSize / 17;
    if(outgoingUartPayloadSize % 17) { outgoingUartPayloadMessageCount++; }
    for(;messageCounter < outgoingUartPayloadMessageCount; messageCounter++){
        outgoingUartPayload[0] = outgoingUartPayloadIdentifier;
        outgoingUartPayload[1] = messageCounter;
        outgoingUartPayload[2] = outgoingUartPayloadSize;
        for(;payloadCounter < 17; payloadCounter++) {
            outgoingUartPayload[payloadCounter + 3] = rfrxbuf[processbuffer][messageCounter*17 + payloadCounter];
        }
        uartTx(outgoingUartPayload, 20);
        sleepMillis(500);
    }
}

void appMainLoop(void) {
    if(uartRxAvailable) {
        sleepMillis(500);
        addToIncomingMessage();
    }

    if(rfif) {
        lastCode[0] = 0xd;
        IEN2 &= ~IEN2_RFIE;

        if(rfif & RFIF_IRQ_DONE) {
            processbuffer = !rfRxCurrentBuffer;
            if(rfRxProcessed[processbuffer] == RX_UNPROCESSED) {
                splitAndSendRfRxOverUart();
                /*txdata(0xfe, 0xf0, (u8)rfrxbuf[processbuffer][0], (u8*)&rfrxbuf[processbuffer]);*/
                /* Set receive buffer to processed so it can be used again */
                rfRxProcessed[processbuffer] = RX_PROCESSED;
                /* Clear processed buffer */
                memset(rfrxbuf[processbuffer],0,BUFFER_SIZE);
            }
        }

        rfif = 0;
        IEN2 |= IEN2_RFIE;
    }
}


/* appHandleEP5 gets called when a message is received on endpoint 5 from the host.  this is the 
 * main handler routine for the application as endpoint 0 is normally used for system stuff.
 *
 * important things to know:
 *  * your data is in ep5iobuf.OUTbuf, the length is ep5iobuf.OUTlen, and the first two bytes are
 *      going to be \x40\xe0.  just craft your application to ignore those bytes, as i have ni
 *      puta idea what they do.  
 *  * transmit data back to the client-side app through txdatai().  this function immediately 
 *      xmits as soon as any previously transmitted data is out of the buffer (ie. it blocks 
 *      while (ep5iobuf.flags & EP_INBUF_WRITTEN) and then transmits.  this flag is then set, and 
 *      cleared by an interrupt when the data has been received on the host side.                */
int appHandleEP5() {
    u8 app, cmd;
    u16 len;
    __xdata u8 *buf;

    app = ep5iobuf.OUTbuf[4];
    cmd = ep5iobuf.OUTbuf[5];
    buf = &ep5iobuf.OUTbuf[6];
    len = (u16)*buf;
    buf += 2;                                               // point at the address in memory
    // ep5iobuf.OUTbuf should have the following bytes to start:  <app> <cmd> <lenlow> <lenhigh>
    // check the application
    //  then check the cmd
    //   then process the data
    switch (cmd)
    {
    default:
        break;
    }
    ep5iobuf.flags &= ~EP_OUTBUF_WRITTEN;                       // this allows the OUTbuf to be rewritten... it's saved until now.
    return 0;
}

/* in case your application cares when an OUT packet has been completely received.               */
void appHandleEP0OUTdone(void) {}

/* this function is the application handler for endpoint 0.  it is called for all VENDOR type    *
 * messages.  currently it implements a simple ping-like application.                           */
int appHandleEP0(USB_Setup_Header* pReq) {
    if (pReq->bmRequestType & USB_BM_REQTYPE_DIRMASK)       // IN to host
    {
        switch (pReq->bRequest)
        {
        case 0:
            setup_send_ep0(&lastCode[0], 2);
            break;
        case 1:
            setup_sendx_ep0((__xdata u8*)USBADDR, 40);
            break;
        case 2:
            setup_sendx_ep0((__xdata u8*)pReq->wValue, pReq->wLength);
            break;

        }
    } else                                                  // OUT from host
    {
        if (pReq->wIndex&0xf)                               // EP0 receive.    CURRENTLY DOES NOTHING WITH THIS....
        {
            usb_recv_ep0OUT();
            ep0iobuf.flags &= ~EP_OUTBUF_WRITTEN;
        }
    }
    return 0;
}



/*************************************************************************************************
 *  here begins the initialization stuff... this shouldn't change much between firmwares or      *
 *  devices.                                                                                     *
 *************************************************************************************************/

/* initialize the IO subsystems for the appropriate dongles */
static void io_init(void) {
#ifdef IMMEDONGLE
    // IM-ME Dongle.  It's a CC1110, so no USB stuffs.  Still, a bit of stuff to init for talking to it's own Cypress USB chip
    P0SEL |= (BIT5 | BIT3);     // Select SCK and MOSI as SPI
    P0DIR |= BIT4 | BIT6;       // SSEL and LED as output
    P0 &= ~(BIT4 | BIT2);       // Drive SSEL and MISO low

    P1IF = 0;                   // clear P1 interrupt flag
    IEN2 |= IEN2_P1IE;          // enable P1 interrupt
    P1IEN |= BIT1;              // enable interrupt for P1.1

    P1DIR |= BIT0;              // P1.0 as output, attention line to cypress
    P1 &= ~BIT0;                // not ready to receive

#elif defined DONSDONGLES
    // CC1111 USB Dongle
    // turn on LED and BUTTON
    P1DIR |= 3;
    // Turn off LED
    LED = 0;
    // Activate BUTTON - Do we need this?
    //CC1111EM_BUTTON = 1;

#else
    // CC1111 USB (ala Chronos watch dongle), we just need LED
    P0DIR |= 0x0F;
    P0_0 = 0;
    P0_1 = 0;
    P0_2 = 0;
    P0_3 = 0;

    P1DIR |= 3;
    /*P1DIR |= 0x08;
      P1_3 = 0;
      P2DIR |= 0x10;
      P2_4 = 0;*/
    LED = 0;
#endif
}

void clock_init(void) {
    // SET UP CPU SPEED!  USE 26MHz
    // Set the system clock source to HS XOSC and max CPU speed,
    // ref. [clk]=>[clk_xosc.c]
    SLEEP &= ~SLEEP_OSC_PD;
    while( !(SLEEP & SLEEP_XOSC_S) );
    CLKCON = (CLKCON & ~(CLKCON_CLKSPD | CLKCON_OSC)) | CLKSPD_DIV_1;
    while (CLKCON & CLKCON_OSC);
    SLEEP |= SLEEP_OSC_PD;
    while (!IS_XOSC_STABLE());
}

/*************************************************************************************************
 * main startup code                                                                             *
 *************************************************************************************************/
void initBoard(void) {
    clock_init();
    io_init();
    uartInit(9800);
}

void main (void) {
    u8 uiRadioEu = 0;
    initBoard();
    initUSB();

#ifdef RADIO_EU
    uiRadioEu = 1;
#endif
    init_RF(uiRadioEu,NORMAL);
    EA = 1;
    appMainInit();
    while (1) {
        usbProcessEvents();
        appMainLoop();
    }
}

