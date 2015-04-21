#include "cc1111usb.h"

/*************************************************************************************************
 * debug stuff.  slows executions.                                                               *
 ************************************************************************************************/
/* blinks the EP0 SETUP packet in binary on the LED */
void debugEP0Req(u8 *pReq)
{
    (void) pReq;
    /*
    //u8  loop;

    for (loop = sizeof(USB_Setup_Header);loop>0; loop--)
    {
        blink_binary_baby_lsb(*(pReq), 8);
        pReq++;
    }*/

}


/* sends a debug message up to the python code to be spit out on stderr */
void debug(__code u8* text)
{
    u16 len = 0;
    __code u8* ptr = text;
    while (*ptr++ != 0)
        len ++;
    txdata(0xfe, 0xf0, len, (__xdata u8*)text);
}

/*void debughex(u8 num)*/
/*{*/
    /*txdata(0xfe, DEBUG_CMD_HEX, 1, (__xdata u8*)&num);*/
/*}*/

/*void debughex16(u16 num)*/
/*{*/
    /*txdata(0xfe, DEBUG_CMD_HEX16, 2, (__xdata u8*)&num);*/
/*}*/

/*void debughex32(u32 num)*/
/*{*/
    /*txdata(0xfe, DEBUG_CMD_HEX32, 4, (__xdata u8*)&num);*/
/*}*/
 

