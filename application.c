#include "cc1111rf.h"
#include "global.h"

#include <string.h>

#ifdef VIRTUAL_COM
#include "cc1111.h"
#include "cc1111_vcom.h"

#define STATUS_TAG 0
#define STATUS_LEN 1
#define STATUS_VAL 2

#define TAG_MODE    0x01 /* Value is mode, IDLE,RX,TX */
#define TAG_SEND    0x02 /* Value is what to send */
#define TAG_STATUS  0x03 /* Value is the status value want to know, for example RSSI */
#define TAG_REG     0x04 /* Register values, value as register=value */

#define TLV_MAX_DATA 50    

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
#include "cc1111usb.h"
#endif

/*************************************************************************************************
 * welcome to the cc1111usb application.
 * this lib was designed to be the basis for your usb-app on the cc1111 radio.  hack fun!
 *
 * 
 * best way to start is to look over the library and get a little familiar with it.
 * next, put code as follows:
 * * any initialization code that should happen at power up goes in appMainInit()
 * * the main application loop code should go in appMainLoop()
 * * usb interface code should go into appHandleEP5.  this includes a switch statement for any 
 *      verbs you want to create between the client on this firmware.
 *
 * if you should need to change anything about the USB descriptors, do your homework!  particularly
 * keep in mind, if you change the IN or OUT max packetsize, you *must* change it in the 
 * EPx_MAX_PACKET_SIZE define, the desciptor definition (be sure to get the right one!) and should 
 * correspond to the setting of MAXI and MAXO.
 * 
 * */


#ifdef VIRTUAL_COM
void sendTLV()
{
    __xdata u8 sendData[TLV_MAX_DATA+2];
    __xdata u8 i = 0;

    vcom_putstr("sendtlv");

    sendData[0] = tlv_send.uiTag;
    sendData[1] = tlv_send.uiLength;
    for(i = 2; i < TLV_MAX_DATA; i++)
    {
        if(tlv_send.uiData[i-2] == '\0')
        {
            break;
        }
        else
        {
            sendData[i] = tlv_send.uiData[i - 2];
        }
    }

    vcom_putstr(sendData);
}

void processTLV()
{
    vcom_putstr("process");
#pragma disable_warning 110
    if(tlv_recv.uiTag == TAG_MODE)
    {
        if(tlv_recv.uiData[0] == 'I' & tlv_recv.uiData[1] == 'D' & tlv_recv.uiData[2] == 'L' & tlv_recv.uiData[3] == 'E')
        {
            setRFIdle();
        }
        else if(tlv_recv.uiData[0] == 'R' & tlv_recv.uiData[1] == 'X')
        {
            RxOn();
        }
        else if(tlv_recv.uiData[0] == 'T' & tlv_recv.uiData[1] == 'X')
        {
            /* future purposes */
        }       
    }
    else if(tlv_recv.uiTag == TAG_SEND)
    {
        vcom_putstr(tlv_recv.uiData);
        vcom_putchar(tlv_recv.uiLength);
        transmit(tlv_recv.uiData,tlv_recv.uiLength,0); 
    }
    else if(tlv_recv.uiTag == TAG_STATUS)
    {
        if(tlv_recv.uiData[0] == 'R' & tlv_recv.uiData[1] == 'S' & tlv_recv.uiData[2] == 'S' & tlv_recv.uiData[3] == 'I')
        {
            vcom_putstr("RSSI");
            //RxOn();
            tlv_send.uiTag = tlv_recv.uiTag;
            tlv_send.uiLength = 1;
            tlv_send.uiData[0] = RSSI;
            tlv_send.uiData[1] = '\0';
            sendTLV();
            //setRFIdle();
        }
    }
    else if(tlv_recv.uiTag == TAG_REG)
    {

    }
}

void fetchTLV()
{
    __xdata char ucValue;

#pragma disable_warning 110
    switch(uiStatus)
    {
    case STATUS_TAG:
        vcom_putstr("tag");
        uiDataPtr = 0;
        tlv_recv.uiTag = vcom_getchar(); 
        /* if valid TLV continue */
        if(tlv_recv.uiTag == TAG_MODE | tlv_recv.uiTag == TAG_SEND | tlv_recv.uiTag == TAG_STATUS | tlv_recv.uiTag == TAG_REG)
        {
            uiStatus = STATUS_LEN;
        }
        break;
    case STATUS_LEN:
        vcom_putstr("len");
        tlv_recv.uiLength = vcom_getchar();
        uiStatus = STATUS_VAL;
        break;
    case STATUS_VAL:
        vcom_putstr("val");
        ucValue = vcom_getchar();
        if(ucValue == '\n')
        {
            /* Receive done, process */
            processTLV();
            uiStatus = STATUS_TAG;
        }
        else
        {
            tlv_recv.uiData[uiDataPtr] = ucValue;
            tlv_recv.uiData[uiDataPtr+1] = '\0';
            uiDataPtr++;
        }
        break;
    default:
        uiStatus = STATUS_TAG;
        break;
    }
}
#endif

/*************************************************************************************************
 * Application Code - these first few functions are what should get overwritten for your app     *
 ************************************************************************************************/

void appMainInit(void)
{
}

/* appMain is the application.  it is called every loop through main, as does the USB handler code.
 * please do not block if you want USB to work.                                                 */
void appMainLoop(void)
{
    __xdata u8 processbuffer;

#ifdef TRANSMIT_TEST
    /*__xdata u8 u8Packet[13];

      u8Packet[0] = 0x0B;
      u8Packet[1] = 0x48;
      u8Packet[2] = 0x41;
      u8Packet[3] = 0x4C;
      u8Packet[4] = 0x4C;
      u8Packet[5] = 0x4F;
      u8Packet[6] = 0x43;
      u8Packet[7] = 0x43;
      u8Packet[8] = 0x31;
      u8Packet[9] = 0x31;
      u8Packet[10] = 0x31;
      u8Packet[11] = 0x31;
      u8Packet[12] = 0x00;
      transmit(u8Packet,0,1);
      sleepMillis(800);*/

    fetchTLV();
#endif

    if(rfif)
    {
        lastCode[0] = 0xd;
        IEN2 &= ~IEN2_RFIE;

        if(rfif & RFIF_IRQ_DONE)
        {
            processbuffer = !rfRxCurrentBuffer;
            if(rfRxProcessed[processbuffer] == RX_UNPROCESSED)
            {
                txdata(0xfe, 0xf0, (u8)rfrxbuf[processbuffer][0], (u8*)&rfrxbuf[processbuffer]);
                /* Set receive buffer to processed so it can be used again */
                rfRxProcessed[processbuffer] = RX_PROCESSED;
                /* Clear processed buffer */
                memset(rfrxbuf[processbuffer],0,BUFFER_SIZE);
            }
        }

        rfif = 0;
        IEN2 |= IEN2_RFIE;
    }
    //debug("testing");
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
int appHandleEP5()
{
#ifndef VIRTUAL_COM
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
#endif
    return 0;
}

/* in case your application cares when an OUT packet has been completely received.               */
void appHandleEP0OUTdone(void)
{
#ifndef VIRTUAL_COM
    //code here
#endif
}

/* this function is the application handler for endpoint 0.  it is called for all VENDOR type    *
 * messages.  currently it implements a simple ping-like application.                           */
int appHandleEP0(USB_Setup_Header* pReq)
{
#ifdef VIRTUAL_COM
    pReq = 0;
#else
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
#endif
    return 0;
}



/*************************************************************************************************
 *  here begins the initialization stuff... this shouldn't change much between firmwares or      *
 *  devices.                                                                                     *
 *************************************************************************************************/

/* initialize the IO subsystems for the appropriate dongles */
static void io_init(void)
{
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
#ifndef VIRTUAL_COM
    LED = 0;
#endif
#endif
}

void clock_init(void){
    //  SET UP CPU SPEED!  USE 26MHz
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
void initBoard(void)
{
    clock_init();
    io_init();
}

void main (void)
{
    u8 uiRadioEu = 0;

    initBoard();
    initUSB();

#ifdef RADIO_EU
    uiRadioEu = 1;
#endif
#ifdef RECEIVE_TEST
    init_RF(uiRadioEu,RECV);
#else
    /* Transmit has no special things, for now parse as normal */
    init_RF(uiRadioEu,NORMAL);
#endif

    /* Make sure interrupts are enabled */
    EA = 1;

    appMainInit();

#ifdef RECEIVE_TEST
    startRX(1);
#endif

    while (1)
    {  
        usbProcessEvents();
        appMainLoop();
    }

}

