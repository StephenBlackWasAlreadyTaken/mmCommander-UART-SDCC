#ifndef CC1111USB
#define CC1111USB

#include "cc1111.h"
#include "global.h"

#define     EP0_MAX_PACKET_SIZE     64
#define     EP5OUT_MAX_PACKET_SIZE  64
#define     EP5IN_MAX_PACKET_SIZE   500
//   #define     EP5_MAX_PACKET_SIZE     255
        // note: descriptor needs to be adjusted to match EP5_MAX_PACKET_SIZE

typedef struct {
    u8   usbstatus;
    u16  event;
    u8   config;
} USB_STATE;

typedef struct {
    u8*  INbuf;
    u16  INbytesleft;
    u8*  OUTbuf;
    u16  OUTlen;
    u16  BUFmaxlen;
    volatile u8   flags;
    u8   epstatus;
    //__xdata u8*  reg;
    //void*   OUTDONE_handle;                                     // this is a function pointer which is called when the OUT transfer is done.  i may destroy this.
} USB_EP_IO_BUF;

// extern global variables
extern USB_STATE usb_data;
extern __xdata u8  usb_ep0_OUTbuf[EP0_MAX_PACKET_SIZE];                  // these get pointed to by the above structure
extern __xdata u8  usb_ep5_OUTbuf[EP5OUT_MAX_PACKET_SIZE];               // these get pointed to by the above structure
extern __xdata USB_EP_IO_BUF     ep0iobuf;
extern __xdata USB_EP_IO_BUF     ep5iobuf;
extern __xdata u8 appstatus;

// provided by cc1111usb.c
void usbIntHandler(void) __interrupt P2INT_VECTOR;
void p0IntHandler(void) __interrupt P0INT_VECTOR;
void clock_init(void);
void txdataold(u8 app, u8 cmd, u16 len, u8* dataptr);
void txdata(u8 app, u8 cmd, u16 len, __xdata u8* dataptr);
int setup_send_ep0(u8* payload, u16 length);
int setup_sendx_ep0(__xdata u8* payload, u16 length);
u16 usb_recv_ep0OUT();

u16 usb_recv_epOUT(u8 epnum, USB_EP_IO_BUF* epiobuf);
void initUSB(void);
void usb_up(void);
void usb_down(void);
void waitForUSBsetup();
// export as this *must* be in main loop.
void usbProcessEvents(void);


// provided by user application
void appHandleEP0OUTdone(void);
int appHandleEP0(USB_Setup_Header* pReq);
int appHandleEP5();

void USBDESCBEGIN(void);

#define EP_INBUF_WRITTEN        1
#define EP_OUTBUF_WRITTEN       2


// usb_data bits
#define USBD_CIF_SUSPEND        (u16)0x1
#define USBD_CIF_RESUME         (u16)0x2
#define USBD_CIF_RESET          (u16)0x4
#define USBD_CIF_SOFIF          (u16)0x8
#define USBD_IIF_EP0IF          (u16)0x10
#define USBD_IIF_INEP1IF        (u16)0x20
#define USBD_IIF_INEP2IF        (u16)0x40
#define USBD_IIF_INEP3IF        (u16)0x80
#define USBD_IIF_INEP4IF        (u16)0x100
#define USBD_IIF_INEP5IF        (u16)0x200
#define USBD_OIF_OUTEP1IF       (u16)0x400
#define USBD_OIF_OUTEP2IF       (u16)0x800
#define USBD_OIF_OUTEP3IF       (u16)0x1000
#define USBD_OIF_OUTEP4IF       (u16)0x2000
#define USBD_OIF_OUTEP5IF       (u16)0x4000

#define TXDATA_MAX_WAIT         100

#define     CMD_PEEK        0x80
#define     CMD_POKE        0x81
#define     CMD_PING        0x82
#define     CMD_STATUS      0x83
#define     CMD_POKE_REG    0x84
#define     CMD_RFMODE      0x85

#define     DEBUG_CMD_STRING    0xf0
#define     DEBUG_CMD_HEX       0xf1
#define     DEBUG_CMD_HEX16     0xf2
#define     DEBUG_CMD_HEX32     0xf3
#define     DEBUG_CMD_INT       0xf4

#endif
