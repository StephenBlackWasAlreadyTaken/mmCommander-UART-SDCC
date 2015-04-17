#include "chipcon_usb.h"

/*************************************************************************************************
 * debug stuff.  slows executions.                                                               *
 ************************************************************************************************/
/* sends a debug message up to the python code to be spit out on stderr */
void debug(code u8* text)
{
    u16 len = 0;
    code u8* ptr = text;
    while (*ptr++ != 0)
        len ++;
    txdata(0xfe, 0xf0, len, (xdata u8*)text);
}

void debughex(__xdata u8 num)
{
    txdata(0xfe, DEBUG_CMD_HEX, 1, (xdata u8*)&num);
}

void debughex16(__xdata u16 num)
{
    txdata(0xfe, DEBUG_CMD_HEX16, 2, (xdata u8*)&num);
}

void debughex32(__xdata u32 num)
{
    txdata(0xfe, DEBUG_CMD_HEX32, 4, (xdata u8*)&num);
}
 

