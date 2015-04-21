#ifndef CC1111RF_H
#define CC1111RF_H

#include "cc1111.h"

#define DMA_CFG_SIZE 8
#define BUFFER_SIZE 65
#define BUFFER_AMOUNT 2

#define RSSI_TIMEOUT_US 1500

#define RF_STATE_RX 1
#define RF_STATE_TX 2
#define RF_STATE_IDLE 3

#define RF_SUCCESS 0

#define RF_DMA_VLEN_1   	1<<5
#define RF_DMA_VLEN_3   	4<<5
#define RF_DMA_LEN     	 	0xfe
#define RF_DMA_WORDSIZE 	0
#define RF_DMA_TMODE    	0
#define RF_DMA_TRIGGER  	19
#define RF_DMA_SRC_INC  	1<<6
#define RF_DMA_DST_INC  	1<<4
#define RF_DMA_IRQMASK_DI	0<<3
#define RF_DMA_IRQMASK_EN  	1<<3
#define RF_DMA_M8       	0<<2
#define RF_DMA_M7			1<<2
#define RF_DMA_PRIO_LOW		0<<1
#define RF_DMA_PRIO_NOR    	1<<1
#define RF_DMA_PRIO_HIGH 	1<<2

#define FIRST_BUFFER 0
#define SECOND_BUFFER 1
#define RX_UNPROCESSED 0
#define RX_PROCESSED 1

/* Type for registers:
	NORMAL: registers are configured by client
	RECV: registers are set for receive
	XMIT: registers are set for transmit
*/
typedef enum{NORMAL,RECV,XMIT} register_e;

/* Rx buffers */
extern volatile __xdata u8 rfRxCurrentBuffer;
extern volatile __xdata u8 rfrxbuf[BUFFER_AMOUNT][BUFFER_SIZE];
extern volatile __xdata u8 rfRxCounter[BUFFER_AMOUNT];
extern volatile __xdata u8 rfRxProcessed[BUFFER_AMOUNT];
/* Tx buffers */
extern volatile __xdata u8 rftxbuf[BUFFER_SIZE];
extern volatile __xdata u8 rfTxCounter;

extern u8 rfif;
extern __xdata u8 lastCode[2];

void rfTxRxIntHandler(void) __interrupt RFTXRX_VECTOR; // interrupt handler should transmit or receive the next byte
void rfIntHandler(void) __interrupt RF_VECTOR; // interrupt handler should trigger on rf events

void setRFIdle(void);
int waitRSSI(void);
void RxOn(void);
void RxIdle(void);
u8 transmit(__xdata u8*, u16 len, u8 bDma);
void stopRX(void);
void startRX(u8 bDma);
void init_RF(u8 bEuRadio, register_e rRegisterType);

#endif
