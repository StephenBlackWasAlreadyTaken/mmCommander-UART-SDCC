#ifndef DMA_H
#define DMA_H

#define DMA_AMOUNT 5

typedef struct
{
    DMA_DESC *DMADescriptor;
    u8 bReserved;
    void (*intCallback);
} dmaconfig;

void dma_init();
u8 dma_register(u8 uiChannel, __xdata DMA_DESC *descriptor, void (*callback))
u8 dma_unregister(u8 uiChannel)
void dmaInterruptHandler() __interrupt DMA_VECTOR

#endif
