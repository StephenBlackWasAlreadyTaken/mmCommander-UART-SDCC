#include "global.h"
#include "cc1111usb.h"
#include "cc1111rf.h"


/*************************************************************************************************
 * welcome to the cc1111usb library.
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


USB_STATE usb_data;
__xdata u8  usb_ep0_OUTbuf[EP0_MAX_PACKET_SIZE];                  // these get pointed to by the above structure
__xdata u8  usb_ep5_OUTbuf[EP5OUT_MAX_PACKET_SIZE];               // these get pointed to by the above structure
__xdata USB_EP_IO_BUF     ep0iobuf;
__xdata USB_EP_IO_BUF     ep5iobuf;
__xdata u8 appstatus;

//__xdata dmacfg_t usbdma;
__xdata DMA_DESC usbdma;
//__xdata u8 usbdmar[8];

/*************************************************************************************************
 * experimental!  don't know the full ramifications of using this function yet.  it could cause  *
 * the universe to explode!                                                                      *
 ************************************************************************************************/
void txdataold(u8 app, u8 cmd, u16 len, u8* dataptr)      // assumed EP5 for application use
    // gonna try this direct this time, and ignore all the "state tracking" for the endpoint.
    // wish me luck!  this could horribly crash and burn.
{
    u16 loop;
    u8 firsttime=1;
    USBINDEX=5;
    //EA=0; 
    while (len>0)
     {
        // if we do this in the loop, for some reason ep5iobuf.flags never clears between frames.  
        // don't know why since this bit is cleared in the USB ISR.
        loop = TXDATA_MAX_WAIT;
        while (ep5iobuf.flags & EP_INBUF_WRITTEN && loop>0)                   // has last msg been recvd?
        {
            //REALLYFASTBLINK();
            //REALLYFASTBLINK();
            REALLYFASTBLINK();
            //blink(100,50);
            lastCode[1] = 1;
            //loop--;
        }
        //blink(100,50);
            
        if (firsttime==1){                                             // first time through only please
            //blink(100,50);

            firsttime=0;
            USBF5 = 0x40;
            USBF5 = app;
            USBF5 = cmd;
            USBF5 = len & 0xff;
            USBF5 = len >> 8;
            if (len>EP5IN_MAX_PACKET_SIZE-5)
                loop=EP5IN_MAX_PACKET_SIZE-5;
            else
                loop=len;

        } else {
            if (len>EP5IN_MAX_PACKET_SIZE)
                loop=EP5IN_MAX_PACKET_SIZE;
            else
                loop=len;
        }


        len -= loop;


        for (;loop>0;loop--)
        {
            USBF5 = *dataptr++;
        }
        
        USBCSIL |= USBCSIL_INPKT_RDY;
        ep5iobuf.flags |= EP_INBUF_WRITTEN;                         // set the 'written' flag
    }
    //EA=1;
}

void txdata(u8 app, u8 cmd, u16 len, __xdata u8* dataptr)      // assumed EP5 for application use
    // gonna try this direct this time, and ignore all the "state tracking" for the endpoint.
    // wish me luck!  this could horribly crash and burn.
{
    u16 loop;
    u8 firsttime=1;
    USBINDEX=5;
    //EA=0; 
    while (len>0)
     {
        // if we do this in the loop, for some reason ep5iobuf.flags never clears between frames.  
        // don't know why since this bit is cleared in the USB ISR.
        loop = TXDATA_MAX_WAIT;
        while (ep5iobuf.flags & EP_INBUF_WRITTEN && loop>0)                   // has last msg been recvd?
        {
            //REALLYFASTBLINK();
            //REALLYFASTBLINK();
            REALLYFASTBLINK();
            //blink(100,50);
            lastCode[1] = 1;
            loop--;
        }
        //blink(100,50);
            
        if (firsttime==1){                                             // first time through only please
            //blink(100,50);

            firsttime=0;
            USBF5 = 0x40;
            USBF5 = app;
            USBF5 = cmd;
            USBF5 = len & 0xff;
            USBF5 = len >> 8;
            if (len>EP5IN_MAX_PACKET_SIZE-5)
                loop=EP5IN_MAX_PACKET_SIZE-5;
            else
                loop=len;

        } else {
            if (len>EP5IN_MAX_PACKET_SIZE)
                loop=EP5IN_MAX_PACKET_SIZE;
            else
                loop=len;
        }


        len -= loop;

        DMAARM |= 0x80 + DMAARM1;
        usbdma.srcAddrH = ((u16)dataptr)>>8;
        usbdma.srcAddrL = ((u16)dataptr)&0xff;
        usbdma.destAddrH = 0xde;     //USBF5 == 0xde2a
        usbdma.destAddrL = 0x2a;
        usbdma.lenL = loop;
        usbdma.lenH = 0;
        usbdma.srcInc = 1;
        usbdma.destInc = 0;
        DMAARM |= DMAARM1;
        DMAREQ |= DMAARM1;

        while (!(DMAIRQ & DMAARM1));
        DMAIRQ &= ~DMAARM1;             // FIXME: superfuous?
        
        USBCSIL |= USBCSIL_INPKT_RDY;
        ep5iobuf.flags |= EP_INBUF_WRITTEN;                         // set the 'written' flag
    }
    //EA=1;
}


//! waitForUSBsetup() is a helper function to allow the usb stuff to settle before real app processing happens.
void waitForUSBsetup() 
{
    while (USBADDR==0 && (appstatus<1))
    {
        usbProcessEvents();

    }
    blink(200,200);
}


/*************************************************************************************************
 *  here begins the initialization stuff... this shouldn't change much between firmwares or      *
 *  devices.                                                                                     *
 *************************************************************************************************/

/* initialize the USB subsystems */
void usb_init(void)
{
    USB_RESET();

    // usb dma
    DMA1CFGH = ((u16)(&usbdma))>>8;
    DMA1CFGL = ((u16)(&usbdma))&0xff;
    usbdma.vlen = 0;
    usbdma.wordSize = 0;
    usbdma.lenH = 0;
    usbdma.tMode = 1;
    usbdma.trig = 0;
    usbdma.irqMask = 1;
    usbdma.m8 = 0;
    usbdma.priority = 1;
    // when used, the following must be set before triggering:
    // usbdma.srcaddr
    // usbdma.dstaddr
    // usbdma.len    // we're using fixed length transfers
    // usbdma.srcinc
    // usbdma.dstinc
    //  then trigger using DMAREQ


    //USBPOW |= USBPOW_SUSPEND_EN;          // ok, no.
    USBPOW &= ~USBPOW_SUSPEND_EN;           // i don't *wanna* go to sleep if the usb bus is idle for 3ms.  at least not yet.

    usb_data.config = 0;                    // start out unconfigured
    usb_data.event = 0;
    usb_data.usbstatus  = USB_STATE_IDLE;   // this tracks the status of our USB Controller


    // configure EP0
    USBINDEX = 0;
    USBMAXI  = (EP0_MAX_PACKET_SIZE+7)>>3;      // these registers live in incrememnts of 8 bytes.  
    USBMAXO  = (EP0_MAX_PACKET_SIZE+7)>>3;      // these registers live in incrememnts of 8 bytes.  
    ep0iobuf.epstatus   =  EP_STATE_IDLE;       // this tracks the status of our endpoint 0
    ep0iobuf.flags      =  0;                   // reset flags for the OUT (recv) buffer
    ep0iobuf.INbytesleft=  0;
    ep0iobuf.OUTbuf     =  &usb_ep0_OUTbuf[0];
    ep0iobuf.OUTlen     =  0;
    ep0iobuf.BUFmaxlen  =  EP0_MAX_PACKET_SIZE;


    // configure EP5 (eventually will be our data endpoint)
    USBINDEX = 5;
    USBMAXI  = (EP5IN_MAX_PACKET_SIZE+7)>>3;    // these registers live in incrememnts of 8 bytes.  
    USBMAXO  = (EP5OUT_MAX_PACKET_SIZE+7)>>3;   // these registers live in incrememnts of 8 bytes.  
    USBCSOH |= USBCSOH_AUTOCLEAR;               // when we drain the FIFO, automagically tell host
    USBCSIH |= USBCSIH_AUTOSET;                 // when the buffer is full, automagically tell host
    ep5iobuf.epstatus   =  EP_STATE_IDLE;       // this tracks the status of our endpoint 5
    ep5iobuf.flags      =  0;
    ep5iobuf.INbytesleft=  0;
    ep5iobuf.OUTbuf     =  &usb_ep5_OUTbuf[0];
    ep5iobuf.OUTlen     =  0;
    ep5iobuf.BUFmaxlen  =  EP5OUT_MAX_PACKET_SIZE;


   
    // setup Interrupt Flag MASKs... we want all interrupts at the moment.  change to your liking)
    USBCIE = 0xf7;          // skip Start Of Frame (SOFIF).  it's basically a keep-alive packet to keep the device from entering SUSPEND.  
    USBIIE = 0xff;
    USBOIE = 0xff;

    // setup interrupt behaviors
    PICTL   |= PICTL_P0IENH;                // must have this enabled to resume from suspend
    PICTL   &= ~PICTL_P0ICON;               // enable interrupts on rising edge
    P0IE    = 1;                            // enable the p0 interrupt flag  (IEN1 is bit-accessible)
    IEN2    |= IEN2_USBIE;                  // enable the USB interrupt flag (IEN2 is *not* bit-accessible)

    USB_RESUME_INT_CLEAR();                 // P0IFG= 0; P0IF= 0
    USB_INT_CLEAR();                        // P2IFG= 0; P2IF= 0;


    USB_INT_ENABLE();     // Enables USB Interrupts to call an ISR

}




/*************************************************************************************************
 * main usb startup code                                                                             *
 *************************************************************************************************/
void initUSB(void)
{
    lastCode[0] = 2;
    USB_ENABLE();                       // enable our usb controller
    usb_init();                         // setup the usb controller settings

}

// usb_up() pulls up the USB_PULLUP_ENABLE signal, which makes the device show up to the Host
void usb_up(void)
{
    USB_PULLUP_ENABLE();                // enable pullup resistor indicating that we are a real usb device
}

// usb_down() pulls down the USB_PULLUP_ENABLE signal, which makes the device go away
void usb_down(void)
{
    USB_PULLUP_DISABLE();                // enable pullup resistor indicating that we are a real usb device
}

/*************************************************************************************************
 * main USB handler/enabler code.                                                                *
 *************************************************************************************************/
int setup_send_ep0(u8* payload, u16 length)
{
    if (ep0iobuf.epstatus != EP_STATE_IDLE)
    {
        /* catestropic error.  *must* fix! */
        blink(1000,1000);
        blink(1000,1000);
        blink(1000,1000);
        return -1;
    }

    ep0iobuf.INbuf = payload;
    ep0iobuf.INbytesleft = length;
    ep0iobuf.epstatus = EP_STATE_TX;

    return 0;
}

/* send from XDATA */
int setup_sendx_ep0(__xdata u8* payload, u16 length)
{
    if (ep0iobuf.epstatus != EP_STATE_IDLE)
    {
        /* catestropic error.  *must* fix! */
        blink(1000,1000);
        blink(1000,1000);
        blink(1000,1000);
        return -1;
    }

    ep0iobuf.INbuf = payload;
    ep0iobuf.INbytesleft = length;
    ep0iobuf.epstatus = EP_STATE_TX;

    return 0;
}

/*  unused????
int setup_send_ep5(u8* payload, u16 length)
{
    if (ep5iobuf.epstatus != EP_STATE_IDLE)
        return -1;

    ep5iobuf.INbuf = payload;
    ep5iobuf.INbytesleft = length;
    ep5iobuf.epstatus = EP_STATE_TX;
    
    return 0;
}
*/

void usb_arm_ep0IN(){
    /***********************
     * should queue up and send one packet this run.... and recalculate bytesleft so we hit the next packet next run.
     */
    u8  tlen;
    u8  csReg = USBCS0_INPKT_RDY;

    USBINDEX = 0;
    
    if (ep0iobuf.INbytesleft > EP0_MAX_PACKET_SIZE)
        tlen = EP0_MAX_PACKET_SIZE;
    else
    {
        tlen = ep0iobuf.INbytesleft;
        csReg |= USBCS0_DATA_END;
    }

    // FIXME:   IMPLEMENT DMA FOR THESE TRANSFERS
    ep0iobuf.INbytesleft -= tlen;
    for (; tlen>0; tlen--) {               // FIXME: Use DMA
        USBF0 = *ep0iobuf.INbuf;
        ep0iobuf.INbuf++;
    }
    USBCS0  |= csReg;
    if (ep0iobuf.INbytesleft == 0)
        ep0iobuf.epstatus = EP_STATE_IDLE;
}


u8 setup_recv_ep0(){
    ep0iobuf.epstatus = EP_STATE_RX;
    return 0;
}

u16 usb_recv_ep0OUT(){
    /*********************************************************************************************
     * handle receipt of one packet and set flags
     * if another packet has yet to be handled by the application (ie. received through this 
     * function but not acted upon or cleared), return -1
     ********************************************************************************************/
    u16 loop;

    u8* payload = &ep0iobuf.OUTbuf[0];
    ep0iobuf.OUTlen = (u16)USBCNT0;

    if (ep0iobuf.flags & EP_OUTBUF_WRITTEN)
    {
        ep0iobuf.epstatus = EP_STATE_STALL;            // FIXME: don't currently handle stall->idle...
        return -1;
    }
    ep0iobuf.flags |= EP_OUTBUF_WRITTEN;            // hey, we've written here, don't write again until this is cleared by a application handler

    if (ep0iobuf.OUTlen>EP0_MAX_PACKET_SIZE)
        ep0iobuf.OUTlen = EP0_MAX_PACKET_SIZE;

    ///////////////////////////////  FIXME: USE DMA //////////////////////////////////////////
    for (loop=ep0iobuf.OUTlen; loop>0; loop--){
        *payload = USBF0;
        payload++;
    }
    //////////////////////////////////////////////////////////////////////////////////////////
    
    if (ep0iobuf.OUTlen < EP0_MAX_PACKET_SIZE)
        appHandleEP0OUTdone();
    return ep0iobuf.OUTlen;
    
}

    /**********************************         NEVER USED..... deprecating.
u16 usb_recv_ep5OUT(){
     * handle receipt of one packet and set flags
     * if another packet has yet to be handled by the application (ie. received through this function but not acted upon or cleared), return -1
    //u16 loop;

    u8* payload = &ep5iobuf.OUTbuf[0];

    USBINDEX = 5;
    ep5iobuf.OUTlen = (USBCNTH<<8) + USBCNTL;

    if (ep5iobuf.flags & EP_OUTBUF_WRITTEN)
    {
        USBCSOL |= USBCSOL_SEND_STALL;
        ep5iobuf.epstatus = EP_STATE_STALL;
        return -1;
    }
    ep5iobuf.flags |= EP_OUTBUF_WRITTEN;            // hey, we've written here, don't write again until this is cleared by a application handler

    if (ep5iobuf.OUTlen>ep5iobuf.BUFmaxlen)
        ep5iobuf.OUTlen = ep5iobuf.BUFmaxlen;

    ///////////////////////////////  FIXME: USE DMA //////////////////////////////////////////
    //for (loop=ep5iobuf.OUTlen; loop>0; loop--){
    //    *payload++ = USBF5;
    //}
    //////////////////////////////////////////////////////////////////////////////////////////

    while ((DMAIRQ & DMAARM1))
        blink(20,20);
    DMAARM |= 0x80 + DMAARM1;
    usbdma.srcAddrH = 0xde;     //USBF5 == 0xde2a
    usbdma.srcAddrL = 0x2a;
    usbdma.destAddrH = ((u16)payload)>>8;
    usbdma.destAddrL = ((u16)payload)&0xff;
    usbdma.lenL = ep5iobuf.OUTlen;
    usbdma.lenH = 0;
    usbdma.srcInc = 0;
    usbdma.destInc = 1;
    DMAARM |= DMAARM1;
    DMAREQ |= DMAARM1;

    while (!(DMAIRQ & DMAARM1));
    DMAIRQ &= ~DMAARM1;             // FIXME: superfuous?
        
    USBCSOL &= 0xfe;
    
    return ep5iobuf.OUTlen;
    
}

     */


/*************************************************************************************************
 * administrative USB handler functions                                                          *
 *************************************************************************************************/
void usbGetConfiguration()
{
    setup_send_ep0(&usb_data.config, 1);
}

void usbSetConfiguration(USB_Setup_Header* pReq)
{
    usb_data.config = pReq->wValue & 0xff;
}


u8* usbGetDescriptorPrimitive(u8 wantedType, u8 index){

    u8 descType;
    u8* descPtr = (u8*)&USBDESCBEGIN;                 // start of data... sorta

    descType = *(descPtr+1);


    while (descType != 0xff ){

        if (descType == wantedType){
            if (index == 0){
                descType = 0xff;                            // WARNING: destructive.  go directly to ret, do not pass go, do not collect $200
            } else {
                index--;
                descPtr = descPtr + (u8)*descPtr;
                descType = *(descPtr+1);
            }
        } else 
        {
            descPtr = descPtr + (u8)*descPtr;
            descType = *(descPtr+1);
        }
    }
    return descPtr;
}

void usbGetDescriptor(USB_Setup_Header* pReq)
{
    u8* buffer;                                  // this will point to the start of the descriptor (in code) when we're done
    u16 length;

    switch ((pReq->wValue)>>8){
        case USB_DESC_DEVICE:
            buffer = usbGetDescriptorPrimitive((pReq->wValue)>>8, 0);
            length = (u8)*(buffer);
            break;
        case USB_DESC_CONFIG:
            buffer = usbGetDescriptorPrimitive((pReq->wValue)>>8, (pReq->wValue)&0xff);
            length = (u16)*(buffer+2);
            if ((pReq->wValue>>8) != *(buffer+1))
                while (1)   //blink(100,100);                               ///////// DEBUGGING!  WILL STOP EXECUTION!
                    blink_binary_baby_lsb((pReq->wValue), 16); 
            break;
        case USB_DESC_STRING:
            buffer = usbGetDescriptorPrimitive((pReq->wValue)>>8, (pReq->wValue)&0xff);
            length = (u8)*(buffer);
            break;
        default:
            buffer = usbGetDescriptorPrimitive((pReq->wValue)>>8, (pReq->wValue)&0xff);
            length = (u8)*(buffer);
            break;
    }
    if (length > pReq->wLength)
        length = pReq->wLength;

    setup_send_ep0(buffer, length);
    if ((pReq->wValue>>8) == USB_DESC_CONFIG){
        REALLYFASTBLINK();
        appstatus |= 1;                                         //  hack to trigger "waitForUSBsetup()"
    }
    
}


//////////////////////////////////////////////////////////////////////////////////////////////////
// handler for activity on endpoint 0.  THIS IS VERY VERY IMPORTANT!                            //
//                                                                                              //
// the handler is broken down into some administrative handlers, then the state engine for the  //
// endpoint 0.  IDLESTATE is the home state
// all configuration, control, and announcement to the OS is done through endpoint 0            //
// basic flow is that 8 bytes (setup packet) are read in from the host which identify what the  //
// transaction is supposed to be.  individual handlers are then called to respond or react to   //
// the purpose of the command.  these 8 bytes are clearly documented in the USB spec            //
// for more information, read USB IN A NUTSHELL, which can be downloaded from the Internet.     //
// google it.                                                                                   //
//////////////////////////////////////////////////////////////////////////////////////////////////
void handleCS0(void)
{
    USB_Setup_Header req;
    u8* pReq = (u8*)(&req);
    u8  csReg;
    u8  loop;
    u16 val;
    USBINDEX = 0;
    //REALLYFASTBLINK();

    //** DEBUG: GETS HERE.... doesn't have to do anything in particular to show up in Linux logs...**/
    csReg = USBCS0;

    // check if the last xaction ended prematurely by a new setup packet
    if (csReg & USBCS0_SETUP_END) 
    {
        ep0iobuf.epstatus = EP_STATE_IDLE;
        USBCS0 |= USBCS0_CLR_SETUP_END;
    }

    // handle a stall packet
    if (csReg & USBCS0_SENT_STALL) 
    {
        USBCS0 = 0x00;
        lastCode[1] = 4;
        ep0iobuf.epstatus = EP_STATE_IDLE;
        blink(200,200);
    }
    
    if (ep0iobuf.epstatus == EP_STATE_STALL)
    {
        blink(500,500);
        ep0iobuf.epstatus = EP_STATE_IDLE;
    }



    ///////// begin handlers based on EP0 state.
    if (ep0iobuf.epstatus == EP_STATE_IDLE)
    {

        if (csReg & USBCS0_OUTPKT_RDY)                          // do we have a SETUP packet ready for us to consume?
        {
            // read in Setup Token Packet
            USBINDEX = 0;
            for (loop=0; loop<8; loop++,pReq++) {               // FIXME: Use DMA
                *pReq = USBF0;
            }

            //REALLYFASTBLINK();
            // handle by target and direction - skeleton shell... only interested in getting noticed and allowed to send shit down the usb interface!
            // Device Requests
            if (req.bmRequestType & USB_BM_REQTYPE_DIRMASK)                       // should be *sending* data, if any
            {   
                switch(req.bmRequestType & USB_BM_REQTYPE_TYPEMASK)
                {
                    case USB_BM_REQTYPE_TYPE_STD:               //  STANDARD type

                        loop = req.bmRequestType & USB_BM_REQTYPE_TGTMASK;
                        if (loop == USB_BM_REQTYPE_TGT_DEV)
                        {
                            switch (req.bRequest){
                                // return wLength bytes of Device/Config/Interface/EP info (wValue information)
                                case USB_GET_DESCRIPTOR:
                                    usbGetDescriptor(&req);
                                    break;
                                case USB_GET_CONFIGURATION: 
                                    usbGetConfiguration(); 
                                    break;
                                // send back 0x0000 for GET_STATUS (not self-powered and not remote-wake-up capable.
                                case USB_GET_STATUS:
                                    val = 0;
                                    setup_send_ep0((u8*)&val, 2);
                                    break;
                                default:
                                    debugEP0Req((u8*)&req);
                            }
                        }
                        // Interface Requests
                        else if (loop == USB_BM_REQTYPE_TGT_INTF)
                        {
                            switch (req.bRequest){
                                case USB_GET_STATUS:        break;
                                case USB_GET_INTERFACE:     break;
                                default:
                                    debugEP0Req((u8*)&req);
                            }
                        }
                        // EndPoint Requests
                        else if (loop == USB_BM_REQTYPE_TGT_EP)
                        {
                            switch (req.bRequest){
                                case USB_GET_STATUS:
                                    setup_send_ep0("\x00\x00", 2);
                                    break;
                                case USB_SYNCH_FRAME:
                                    break;
                                default:
                                    debugEP0Req((u8*)&req);
                            }
                        } else {
                            debugEP0Req((u8*)&req);
                            USBCS0 |= USBCS0_SEND_STALL;
                        }
                        break;
                    case USB_BM_REQTYPE_TYPE_CLASS:             // CLASS type
                        break;
                    case USB_BM_REQTYPE_TYPE_VENDOR:            // VENDOR type
                        appHandleEP0(&req);
                        break;
                    case USB_BM_REQTYPE_TYPE_RESERVED:          // RESERVED
                        USBCS0 |= USBCS0_SEND_STALL;
                        debugEP0Req((u8*)&req);
                }
            } else {                                            // should be *receiving* data, if any
                switch(req.bmRequestType & USB_BM_REQTYPE_TYPEMASK)
                {
                    case USB_BM_REQTYPE_TYPE_STD:               // STANDARD type
                        loop = req.bmRequestType & USB_BM_REQTYPE_TGTMASK;
                        if (loop == USB_BM_REQTYPE_TGT_DEV)
                        {
                            switch (req.bRequest){
                                case USB_SET_ADDRESS:
                                    USBADDR = req.wValue;
                                    break;
                                case USB_SET_CONFIGURATION:
                                    usbSetConfiguration(&req);
                                    break;
                                // return wLength bytes of Device/Config/Interface/EP info (wValue information)
                                case USB_CLEAR_FEATURE:
                                    break;
                                case USB_SET_FEATURE:
                                    break;
                                case USB_SET_DESCRIPTOR:
                                    break;
                                default:
                                    debugEP0Req((u8*)&req);
                            }
                        }
                        // Interface Requests
                        else if (loop == USB_BM_REQTYPE_TGT_INTF)
                        {
                            switch (req.bRequest){
                                case USB_CLEAR_FEATURE:     break;
                                case USB_SET_FEATURE:       break;
                                case USB_SET_INTERFACE:     break;
                                default:
                                    debugEP0Req((u8*)&req);
                            }
                        }
                        // EndPoint Requests
                        else if (loop == USB_BM_REQTYPE_TGT_EP)
                        {
                            switch (req.bRequest){
                                case USB_CLEAR_FEATURE:     break;
                                case USB_SET_FEATURE:       break;
                                default:
                                    debugEP0Req((u8*)&req);
                            }
                        } else {
                            USBCS0 |= USBCS0_SEND_STALL;
                            debugEP0Req((u8*)&req);
                        }
                        break;
                    case USB_BM_REQTYPE_TYPE_CLASS:             // CLASS type
                        break;
                    case USB_BM_REQTYPE_TYPE_VENDOR:            // VENDOR type
                        appHandleEP0(&req);
                        break;
                    case USB_BM_REQTYPE_TYPE_RESERVED:          // RESERVED type
                        debugEP0Req((u8*)&req);
                        USBCS0 |= USBCS0_SEND_STALL;
                }

            }       // else *receive*
            USBCS0 |= USBCS0_CLR_OUTPKT_RDY;                    // clear the bit, we got it.
            if (req.wLength == 0x0)
                USBCS0 |= USBCS0_DATA_END;                      // if the length is 0, signal that we got it and we're good.  (where did i come up with this?!?)

        }       // USBCS0_OUTPKT_RDY
    }       // EP_STATE_IDLE

    
    if (ep0iobuf.epstatus == EP_STATE_TX)
    {
        usb_arm_ep0IN(); 
    }
    if (ep0iobuf.epstatus == EP_STATE_RX)
    {
        usb_recv_ep0OUT();
    }
    
}

void handleOUTEP5(void)
{
    // client is sending commands... or looking for information...  status... whatever...
    u16 loop, len;
    u8 cmd, app;
    __xdata u8* ptr; 
    __xdata u8* dptr;
    USBINDEX = 5;
    if (ep5iobuf.flags & EP_OUTBUF_WRITTEN)                     // have we processed the last OUTbuf?  don't want to clobber it.
    {
        ep5iobuf.epstatus = EP_STATE_STALL;
        USBCSOL |= USBCSOL_SEND_STALL;
        //blink(300,200);
        lastCode[1] = 5;
        return;
    }
    ep5iobuf.flags |= EP_OUTBUF_WRITTEN;                        // track that we've read into the OUTbuf

    // setup DMA
    ptr = &ep5iobuf.OUTbuf[0];
    while ((DMAIRQ & DMAARM1))
        blink(20,20);
    DMAARM |= 0x80 + DMAARM1;
    usbdma.srcAddrH = 0xde;     //USBF5 == 0xde2a
    usbdma.srcAddrL = 0x2a;
    usbdma.destAddrH = ((u16)ptr)>>8;
    usbdma.destAddrL = ((u16)ptr)&0xff;
    usbdma.srcInc = 0;
    usbdma.destInc = 1;
    usbdma.lenL = USBCNTL;
    usbdma.lenH = USBCNTH;

    len = (usbdma.lenH<<8)+usbdma.lenL;
    if (len > EP5OUT_MAX_PACKET_SIZE)                           // FIXME: if they wanna send too much data, do we accept what we can?  or bomb?
    {                                                           //  currently choosing to bomb.
        ep5iobuf.epstatus = EP_STATE_STALL;
        USBCSOL |= USBCSOL_SEND_STALL;
        USBCSOL &= ~USBCSOL_OUTPKT_RDY;
        blink(300,200);
        return;
    }
    //REALLYFASTBLINK();
    //blink(300,200);
    //blink_binary_baby_lsb(len, 8);
    //for (loop=len;loop>0;loop--)
    //{
    //    *ptr++ = USBF5;
    //}

    //  DMA Trigger
    DMAARM |= DMAARM1;
    DMAREQ |= DMAARM1;

    while (!(DMAIRQ & DMAARM1));
    DMAIRQ &= ~DMAARM1;             // FIXME: superfuous?

    ep5iobuf.OUTlen = len;

    if (ep5iobuf.OUTlen >= 8)
    {
        app = ep5iobuf.OUTbuf[4];
        cmd = ep5iobuf.OUTbuf[5];
        ptr = &ep5iobuf.OUTbuf[6];
        len =  (u16)*ptr++;
        len += (u16)*ptr++ << 8;
        //ptr += 2;                                               // point at the address in memory
        
        if (app == 0xff)                                        // system application
        {
			#pragma disable_warning 110
            switch (cmd)
            {
                case CMD_PEEK:
                    len =  *ptr++;
                    len += *ptr++ << 8;
                    loop =  (u16)*ptr++;                                    // just using loop for our immediate purpose.  sorry.
                    loop += (u16)*ptr++ << 8;                               // hack, but it works
                    dptr = (__xdata u8*) loop;
                    txdata(app, cmd, len, dptr);
                    //REALLYFASTBLINK();

                    break;
                case CMD_POKE:
                    loop =  *ptr++;
                    loop += *ptr++ << 8;                                    // just using loop for our immediate purpose.  sorry.
                    dptr = (__xdata u8*) loop;                                // hack, but it works
                    // FIXME: do we want to DMA here?
                    for (loop=2;loop<len;loop++)
                    {
                        *dptr++ = *ptr++;
                    }
                    txdata(app, cmd, 1, (__xdata u8*)"0");

                    break;
                case CMD_POKE_REG:
                    loop =  *ptr++;
                    loop += *ptr++ << 8;                                    // just using loop for our immediate purpose.  sorry.
                    dptr = (__xdata u8*) loop;                                // hack, but it works
                    for (loop=2;loop<len;loop++)
                    {
                        *dptr = *ptr++;
                    }
                    txdata(app, cmd, 1, (__xdata u8*)"");

                    break;
                case CMD_PING:
                    txdata(app,cmd,len,ptr);
                    //REALLYFASTBLINK();
                    break;
                case CMD_STATUS:
                    txdata(app, cmd, 13, (__xdata u8*)"UNIMPLEMENTED");
                    // unimplemented
                    break;
                case CMD_RFMODE:
					#pragma disable_warning 110
                    switch (*ptr++)
                    {
                        case RF_STATE_RX:
                            RxOn(); 
                            break;
                        case RF_STATE_IDLE:
                            setRFIdle();  
                            break;
                        case RF_STATE_TX:
                            transmit(ptr, len, 0);  
                            break;
                    }
                default:
                    txdata(app,cmd,len,ptr);
            }
            ep5iobuf.flags &= ~EP_OUTBUF_WRITTEN; 
        }
        else
            appHandleEP5();                                         // must clear this flag:   ep5iobuf.flags &= ~EP_OUTBUF_WRITTEN; 
    } else {
        lastCode[1] = 7;                                            // got crap...
    }
    USBCSOL &= ~USBCSOL_OUTPKT_RDY;
}

#define handleINEP5()  ep5iobuf.flags &= ~EP_INBUF_WRITTEN 

//void handleINEP5(void)
//{
//    // change state so the firmware knows that the packet has been picked up and can be overwritten.
//    ep5iobuf.flags &= ~EP_INBUF_WRITTEN;
//}

void usbProcessEvents(void)
{
    //REALLYFASTBLINK();
    if (usb_data.event & (USBD_IIF_EP0IF))
    {
        // read the packet and interpret/handle
        handleCS0();
        usb_data.event &= 0xfe7;

    } 
    
    // handle Suspend signals
    if (usb_data.event & USBD_CIF_SUSPEND) {
        usb_data.usbstatus = USB_STATE_SUSPEND;
        usb_data.event    &= ~USBD_CIF_SUSPEND;
        PM1();                                               // sir, if you'll not be needing me i'll close down for a while.  sure go ahead.
    }

    if (usb_data.event & (USBD_CIF_RESET | USBD_CIF_RESUME)) {
        lastCode[0] = 10;
        usb_data.usbstatus = USB_STATE_RESUME;
        usb_data.event    &= ~(USBD_CIF_RESUME);
        //}
        //// FIXME:   WHAT ARE WE REALLY TRYING TO DO HERE?  CONSOLIDATE UNLESS ABSOLUTELY NECESSARY TO HAVE TWO RESUME HANDLERS BACK TO BACK....
        //if (usb_data.usbstatus == USB_STATE_RESUME)
        //{
        USBPOW |= USBPOW_RESUME;
        sleepMillis(8);
        USBPOW &= ~USBPOW_RESUME;

        usb_data.usbstatus = USB_STATE_IDLE;
    }


    // usb_data.event accumulates the event flags.  *as they are handled, make sure you clear them!*

    if (usb_data.event & USBD_CIF_RESET || usb_data.usbstatus == USB_STATE_RESET)                // handle RESET
    { //      catching either the CIF_RESET or the USB_STATE_RESET... should normalize.. probably catching the same stuff.
        usb_init();
        lastCode[0] = 11;
        usb_data.event &= ~USBD_CIF_RESET;
    } 

    if (usb_data.event & (USBD_OIF_OUTEP5IF))
    {
        lastCode[0] = 12;
        if (ep5iobuf.epstatus == EP_STATE_STALL)                        // gotta clear this somewhere...
        {
            //blink(200,200);
            lastCode[1] = 8;
            ep5iobuf.epstatus = EP_STATE_IDLE;
            USBINDEX=5;
            USBCSOL &= 0x9f;                                            // clear both command (SEND_STALL) and status (SENT_STALL)
        }
        handleOUTEP5();
        usb_data.event &= ~USBD_OIF_OUTEP5IF;
        
    }

    //if (usb_data.event & (USBD_IIF_INEP5IF))
    //{ 
    //    handleINEP5();
    //    usb_data.event &= ~USBD_IIF_INEP5IF;
    //}

    if (usb_data.event & ~(USBD_IIF_INEP5IF|USBD_OIF_OUTEP5IF|USBD_IIF_EP0IF|USBD_CIF_RESET|
                USBD_CIF_RESUME|USBD_CIF_SUSPEND|USBD_CIF_SOFIF))
    {
        lastCode[1] = 9;
        blink_binary_baby_lsb(usb_data.event, 16);
        usb_data.event &= ~(USBD_IIF_INEP5IF|USBD_OIF_OUTEP5IF|USBD_IIF_EP0IF|USBD_CIF_RESET|
                USBD_CIF_RESUME|USBD_CIF_SUSPEND|USBD_CIF_SOFIF);
    }

    if (usb_data.usbstatus == USB_STATE_BLINK)
    {
        REALLYFASTBLINK();
        usb_data.usbstatus = USB_STATE_IDLE;

    }

}


/*************************************************************************************************
 * Interrupt Service Routines                                                                    *
 ************************************************************************************************/
void usbIntHandler(void) __interrupt P2INT_VECTOR
{

    while (!IS_XOSC_STABLE());
    EA=0;

    //usb_data.usbstatus = USB_STATE_BLINK;
 
    // Set event flags for interpretation by main loop.  Since these registers are cleared upon read, we OR with the existing flags
    usb_data.event |= USBCIF;
    usb_data.event |= (USBIIF << 4);
    usb_data.event |= (USBOIF << 9);
 
    // process events that are fast and not part of the main loop
    //processFastEvents();
    if (usb_data.event & (USBD_IIF_INEP5IF))
    {
        ep5iobuf.flags &= ~EP_INBUF_WRITTEN;
        usb_data.event &= ~USBD_IIF_INEP5IF;
    }
 
    // Clear the P2 interrupt flag
    USB_INT_CLEAR();                                // P2IFG= 0; P2IF= 0;
    EA=1;

}

void p0IntHandler(void) __interrupt P0INT_VECTOR  // P0_7's interrupt is used as the USB RESUME interrupt
{
    while (!IS_XOSC_STABLE());
    EA=0;
    //usb_data.usbstatus = USB_STATE_BLINK;           // tell me we have an interrupt
    if (P0IFG & P0IFG_USB_RESUME)
        usb_data.usbstatus = USB_STATE_RESUME;

    SLEEP &= ~0x3;                                  // clear the PM mode bits
    USB_RESUME_INT_CLEAR();
    
    EA=1;
}

// setup Config Descriptor  (see cc1111.h for defaults and fields to change)
// all numbers are lsb.  modify this for your own use.
void USBDESCBEGIN(void){
__asm
0001$:    ; Device descriptor
               .DB 0002$ - 0001$     ; bLength 
               .DB USB_DESC_DEVICE   ; bDescriptorType
               .DB 0x00, 0x02        ; bcdUSB
               .DB 0x02              ; bDeviceClass i
               .DB 0x00              ; bDeviceSubClass
               .DB 0x00              ; bDeviceProtocol
               .DB EP0_MAX_PACKET_SIZE ;   EP0_PACKET_SIZE
               .DB 0x51, 0x04        ; idVendor Texas Instruments
               .DB 0x15, 0x47        ; idProduct CC1111
               .DB 0x01, 0x00        ; bcdDevice             (change to hardware version)
               .DB 0x01              ; iManufacturer
               .DB 0x02              ; iProduct
               .DB 0x03              ; iSerialNumber
               .DB 0x01              ; bNumConfigurations
0002$:     ; Configuration descriptor
               .DB 0003$ - 0002$     ; bLength
               .DB USB_DESC_CONFIG   ; bDescriptorType
               .DB 0006$ - 0002$     ; 
               .DB 00
               .DB 0x01              ; NumInterfaces
               .DB 0x01              ; bConfigurationValue  - should be nonzero
               .DB 0x00              ; iConfiguration
               .DB 0x80              ; bmAttributes
               .DB 0xfa              ; MaxPower
0003$: ; Interface descriptor
               .DB 0004$ - 0003$           ; bLength
               .DB USB_DESC_INTERFACE      ; bDescriptorType
               .DB 0x00                    ; bInterfaceNumber
               .DB 0x00                    ; bAlternateSetting
               .DB 0x02                    ; bNumEndpoints
               .DB 0xff                    ; bInterfaceClass
               .DB 0xff                    ; bInterfaceSubClass
               .DB 0x01                    ; bInterfaceProcotol
               .DB 0x00                    ; iInterface
0004$:  ; Endpoint descriptor (EP5 IN)
               .DB 0005$ - 0004$           ; bLength
               .DB USB_DESC_ENDPOINT       ; bDescriptorType
               .DB 0x85                    ; bEndpointAddress
               .DB 0x02                    ; bmAttributes - bits 0-1 Xfer Type (0=Ctrl, 1=Isoc, 2=Bulk, 3=Intrpt);      2-3 Isoc-SyncType (0=None, 1=FeedbackEndpoint, 2=Adaptive, 3=Synchronous);       4-5 Isoc-UsageType (0=Data, 1=Feedback, 2=Explicit)
               .DB 0xf4, 0x01              ; wMaxPacketSize
               .DB 0x01                    ; bInterval
0005$:  ; Endpoint descriptor (EP5 OUT)
               .DB 0006$ - 0005$           ; bLength
               .DB USB_DESC_ENDPOINT       ; bDescriptorType
               .DB 0x05                    ; bEndpointAddress
               .DB 0x02                    ; bmAttributes
               .DB 0x40, 0x00              ; wMaxPacketSize
               .DB 0x01                    ; bInterval
0006$:    ; Language ID
               .DB 0007$ - 0006$           ; bLength
               .DB USB_DESC_STRING         ; bDescriptorType
               .DB 0x09                    ; US-EN
               .DB 0x04
0007$:    ; Manufacturer
               .DB 0008$ - 0007$           ; bLength
               .DB USB_DESC_STRING         ; bDescriptorType
               .DB "a", 0
               .DB "t", 0
               .DB "l", 0
               .DB "a", 0
               .DB "s", 0
               .DB " ", 0
               .DB "i", 0
               .DB "n", 0
               .DB "s", 0
               .DB "t", 0
               .DB "r", 0
               .DB "u", 0
               .DB "m", 0
               .DB "e", 0
               .DB "n", 0
               .DB "t", 0
               .DB "s", 0
0008$:    ; Product
               .DB 0009$ - 0008$             ; bLength
               .DB USB_DESC_STRING           ; bDescriptorType
               .DB "C", 0
               .DB "C", 0
               .DB "1", 0
               .DB "1", 0
               .DB "1", 0
               .DB "1", 0
               .DB " ", 0
               .DB "U", 0
               .DB "S", 0
               .DB "B", 0
               .DB " ", 0
               .DB "K", 0
               .DB "i", 0
               .DB "c", 0
               .DB "k", 0
               .DB "a", 0
               .DB "s", 0
               .DB "s", 0
0009$:   ;; Serial number
               .DB 0010$ - 0009$            ;; bLength
               .DB USB_DESC_STRING          ;; bDescriptorType
               .DB "0", 0
               .DB "0", 0
               .DB "1", 0
0010$:
               .DB  0
               .DB  0xff
__endasm;
}



