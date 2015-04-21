#include "dma.h"

static __xdata dmaconfig dmaConfig[DMA_AMOUNT]; 

void dma_init()
{
    u8 i = 0;

    DMA0CFGH = ((u16)(dmaConfig[0].DMADescriptor))>>8;
    DMA0CFGL = ((u16)(dmaConfig[0].DMADescriptor))&0xff;
    DMA1CFGH = ((u16)(dmaConfig[1].DMADescriptor))>>8;
    DMA1CFGL = ((u16)(dmaConfig[1].DMADescriptor))&0xff;
    DMA2CFGH = ((u16)(dmaConfig[2].DMADescriptor))>>8;
    DMA2CFGL = ((u16)(dmaConfig[2].DMADescriptor))&0xff;
    DMA3CFGH = ((u16)(dmaConfig[3].DMADescriptor))>>8;
    DMA3CFGL = ((u16)(dmaConfig[3].DMADescriptor))&0xff;
    DMA4CFGH = ((u16)(dmaConfig[4].DMADescriptor))>>8;
    DMA4CFGL = ((u16)(dmaConfig[4].DMADescriptor))&0xff;

    for(i = 0; i < DMA_AMOUNT; i++)
    {
        dmaConfig[i].DMADescriptor = '\0';
        dmaConfig[i].bReserved = 0;
        dmaConfig[i].intCallback = '\0';
    }
}

/* Returns:
    1: Success
    2: Invalid channel
    3: Channel in use
*/

u8 dma_register(u8 uiChannel, __xdata DMA_DESC *descriptor, void (*callback))
{
    if(uiChannel < 5)
    {
        if(!dmaConfig[uiChannel].bReserved)
        {
            dmaConfig[uiChannel].bReserved = 1;
            dmaConfig[uiChannel].DMADescriptor = descriptor;
            if(callback != '\0')
            {
                dmaConfig[uiChannel].intCallback = callback;
            }
            return 1;
        }
        return 3;
    }
    return 2;
}

u8 dma_unregister(u8 uiChannel)
{
    if(uiChannel < 5)
    {
        if(dmaConfig[uiChannel].bReserved)
        {
            dmaConfig[uiChannel].DMADescriptor = '\0';
            dmaConfig[uiChannel].intCallback = '\0';
            dmaConfig[uiChannel].bReserved = 0;
            return 1;
        }
    }
    return 0;
}

void dmaInterruptHandler() __interrupt DMA_VECTOR
{   
    /* TODO, find correct callback */
}
