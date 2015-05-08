#include "cc1111.h"
#include "global.h"

#define UART0_TX_ISR_VECTOR 0x38
#define UART1_TX_ISR_VECTOR 0x73
#define UART0_RX_ISR_VECTOR 0x13
#define UART1_RX_ISR_VECTOR 0x1B

#define SIZE_OF_UART_RX_BUFFER 256
#define SIZE_OF_UART_TX_BUFFER 256

unsigned char __xdata uartRxBuffer[SIZE_OF_UART_RX_BUFFER];
unsigned char __xdata uartTxBuffer[SIZE_OF_UART_TX_BUFFER];
unsigned short __xdata uartRxIndex, uartTxIndex;
unsigned short __xdata uartRxInterruptIndex, uartTxInterruptIndex;

uint32 __xdata baud_rates[5] = { 2400, 9600, 57600, 115200, 230400 };

uint32 __xdata baud_e_rate_26[5] = { 6, 8, 11, 12, 13 };
uint32 __xdata baud_m_rate_26[5] = { 131, 131, 34, 34, 34 };

uint32 __xdata baud_e_rate_24[5] = { 6, 8, 11, 12, 13 };
uint32 __xdata baud_m_rate_24[5] = { 163, 163, 59, 59, 59 };

uint32 __xdata baud_e_rate_32[5] = { 6, 8, 10, 11, 12 };
uint32 __xdata baud_m_rate_32[5] = { 59, 59, 216, 216, 216 };


void uartMapPort(unsigned char uartPortAlt, unsigned char uartNum) {
    if(uartPortAlt == 1) {
        if (uartNum == 0) {
            PERCFG &= ~0x01;
            P0SEL |= 0x3C;
            P1SEL &= ~0x3C;
        } else {
            PERCFG &= ~0x02;
            P0SEL |= 0x3C;
            P1SEL &= ~0xF0;
        }
    } else {
        if (uartNum == 0) {
            PERCFG |= 0x01;
            P1SEL |= 0x3C;
            P0SEL &= ~0x3C;
        } else {
            PERCFG |= 0x02;
            P1SEL |= 0xF0;
            P0SEL &= ~0x3C;
        }
    }
}

void uartInitBitrate(uint32 uartBaudM, uint32 uartBaudE) {
    CLKCON &= 0x80;
    while(CLKCON & 0x40);
    SLEEP |= 0x04;
    U0BAUD = uartBaudM;
    U0GCR = (U0GCR&~0x1F) | uartBaudE;
}

void setBaudForClockRate(uint8 clockrate, uint32 baudrate) {
    uint8_t i = 0;
    uint8_t j = 0;
    for(;j < 5; j++) {
        if(baud_rates[j] == baudrate){
            i = j;
        }
    }
    switch(clockrate){
    case 24 :
        uartInitBitrate(baud_m_rate_24[i], baud_e_rate_24[i]);
    case 26 :
        uartInitBitrate(baud_m_rate_26[i], baud_e_rate_26[i]);
    case 32 :
        uartInitBitrate(baud_m_rate_32[i], baud_e_rate_32[i]);
    }
}

typedef struct {
    uint8_t uartNum : 1; // UART peripheral number (0 or 1)
    // Initialize UART protocol for desired UART (0 or 1)
    uint8_t START : 1; // Start bit level (low/high)
    // Start bit level = low => Idle level = high (U0UCR.START = 0)
    // Start bit level = high => Idle level = low (U0UCR.START = 1)
    uint8_t STOP : 1; // Stop bit level (low/high)
    // Stop bit level = high (U0UCR.STOP = 1)
    // Stop bit level = low (U0UCR.STOP = 0)
    uint8_t SPB : 1; // Stop bits (0 => 1, 1 => 2)
    // Number of stop bits = 1 (U0UCR.SPB = 0)
    // Number of stop bits = 2 (U0UCR.SPB = 1)
    uint8_t PARITY : 1; // Parity control (enable/disable)
    // Parity = disabled (U0UCR.PARITY = 0)
    // Parity = enabled (U0UCR.PARITY = 1)
    uint8_t BIT9 : 1; // 9 bit enable (8bit / 9bit)
    // 9-bit data disable = 8 bits transfer (U0UCR.BIT9 = 0)
    // 9-bit data enable = 9 bits transfer (U0UCR.BIT9 = 1)
    uint8_t D9 : 1; // 9th bit level or Parity type
    // Level of bit 9 = 0 (U0UCR.D9 = 0), used when U0UCR.BIT9 = 1
    // Level of bit 9 = 1 (U0UCR.D9 = 1), used when U0UCR.BIT9 = 1
    // Parity = Even (U0UCR.D9 = 0), used when U0UCR.PARITY = 1
    // Parity = Odd (U0UCR.D9 = 1), used when U0UCR.PARITY = 1
    uint8_t FLOW : 1; // HW Flow Control (enable/disable)
    // Flow control = disabled (U0UCR.FLOW = 0)
    // Flow control = enabled (U0UCR.FLOW = 1)
    uint8_t ORDER : 1; // Data bit order(LSB/MSB first)
    // Bit order = MSB first (U0GCR.ORDER = 1)
    // Bit order = LSB first (U0GCR.ORDER = 0) => For PC/Hyperterminal
} UART_PROT_CONFIG;
UART_PROT_CONFIG __xdata defaultUartProtConfig;

void uartSetUartNum(uint8 num) {
    defaultUartProtConfig.uartNum = num;
}
void uartSetStart(uint8 start) {
    defaultUartProtConfig.START = start;
}
void uartSetStop(uint8 stop) {
    defaultUartProtConfig.STOP = stop;
}
void uartSetSbp(uint8 sbp) {
    defaultUartProtConfig.SPB = sbp;
}
void uartSetParity(uint8 parity) {
    defaultUartProtConfig.PARITY = parity;
}
void uartSetBit9(uint8 bit9) {
    defaultUartProtConfig.BIT9 = bit9;
}
void uartSetD9(uint8 d9) {
    defaultUartProtConfig.D9 = d9;
}
void uartSetFlow(uint8 flow) {
    defaultUartProtConfig.FLOW = flow;
}
void uartSetOrder(uint8 order) {
    defaultUartProtConfig.ORDER = order;
}

void uartInitProtocol(UART_PROT_CONFIG* uartProtConfig) {
    if (uartProtConfig->uartNum == 0) {
        U0CSR |= 0x80;
        U0UCR = (U0UCR&~0x01) | uartProtConfig->START;
        U0UCR = (U0UCR&~0x02) | (uartProtConfig->STOP << 1);
        U0UCR = (U0UCR&~0x04) | (uartProtConfig->SPB << 2);
        U0UCR = (U0UCR&~0x08) | (uartProtConfig->PARITY << 3);
        U0UCR = (U0UCR&~0x10) | (uartProtConfig->BIT9 << 4);
        U0UCR = (U0UCR&~0x20) | (uartProtConfig->D9 << 5);
        U0UCR = (U0UCR&~0x40) | (uartProtConfig->FLOW << 6);
        U0GCR = (U0GCR&~0x20) | (uartProtConfig->ORDER << 5);
    } else {
        U1CSR |= 0x80;
        U1UCR = (U1UCR&~0x01) | uartProtConfig->START;
        U1UCR = (U1UCR&~0x02) | (uartProtConfig->STOP << 1);
        U1UCR = (U1UCR&~0x04) | (uartProtConfig->SPB << 2);
        U1UCR = (U1UCR&~0x08) | (uartProtConfig->PARITY << 3);
        U1UCR = (U1UCR&~0x10) | (uartProtConfig->BIT9 << 4);
        U1UCR = (U1UCR&~0x20) | (uartProtConfig->D9 << 5);
        U1UCR = (U1UCR&~0x40) | (uartProtConfig->FLOW << 6);
        U1GCR = (U1GCR&~0x20) | (uartProtConfig->ORDER << 5);
    }
}


//NOTE: The code below is for use with polling, trying to use ISR instead
/*void uart0Send(unsigned short* uartTxBuf, unsigned short uartTxBufLength) {*/
/*unsigned short uartTxIndex;*/
/*UTX0IF = 0;*/
/*for (uartTxIndex = 0; uartTxIndex < uartTxBufLength; uartTxIndex++) {*/
/*U0DBUF = uartTxBuf[uartTxIndex];*/
/*while( !UTX0IF );*/
/*UTX0IF = 0;*/
/*}*/
/*}*/

/*void uart1Send(unsigned short* uartTxBuf, unsigned short uartTxBufLength) {*/
/*unsigned short uartTxIndex;*/
/*UTX1IF = 0;*/
/*for (uartTxIndex = 0; uartTxIndex < uartTxBufLength; uartTxIndex++) {*/
/*U1DBUF = uartTxBuf[uartTxIndex];*/
/*while( !UTX1IF );*/
/*UTX1IF = 0;*/
/*}*/
/*}*/

/*void uart0Receive(unsigned short* uartRxBuf, unsigned short uartRxBufLength) {*/
/*unsigned short uartRxIndex;*/
/*U0CSR |= 0x40; URX0IF = 0;*/
/*for (uartRxIndex = 0; uartRxIndex < uartRxBufLength; uartRxIndex++) {*/
/*while( !URX0IF );*/
/*uartRxBuf[uartRxIndex] = U0DBUF;*/
/*URX0IF = 0;*/
/*}*/
/*}*/

/*void uart1Receive(unsigned short* uartRxBuf, unsigned short uartRxBufLength) {*/
/*unsigned short uartRxIndex;*/
/*U1CSR |= 0x40; URX1IF = 0;*/
/*for (uartRxIndex = 0; uartRxIndex < uartRxBufLength; uartRxIndex++) {*/
/*while( !URX1IF );*/
/*uartRxBuf[uartRxIndex] = U1DBUF;*/
/*URX1IF = 0;*/
/*}*/
/*}*/

//TODO: Use the equation to calculate baud rate for more flexibility
/*void uartNSetBaudRate(uint32 baud)*/
/*{*/
/*uint32 baudMPlus256;*/
/*uint8 baudE = 0;*/

/*max baud rate is 1500000 (F/16); min is 23 (baudM = 1)*/
/*if (baud < 23 || baud > 1500000)*/
/*return;*/

/*495782 is the largest value that will not overflow the following calculation*/
/*while (baud > 495782)*/
/*{*/
/*baudE++;*/
/*baud /= 2;*/
/*}*/

/*calculate baud rate - see datasheet 12.14.3*/
/*this is derived from (baudM + 256) = baud * 2^28 / 24000000*/
/*baudMPlus256 = (baud * 11) + (baud * 8663 / 46875);*/

/*get baudMPlus256 into the range 256-511 (so BAUD_M is in the range 0-255)*/
/*while (baudMPlus256 > 0x1ff)*/
/*{*/
/*baudE++;*/
/*baudMPlus256 /= 2;*/
/*}*/
/*UNGCR = baudE; // UNGCR.BAUD_E (4:0)*/
/*UNBAUD = baudMPlus256; // UNBAUD.BAUD_M (7:0) - only the lowest 8 bits of baudMPlus256 are used, so this is effectively baudMPlus256 - 256*/
/*}*/

void uartStartTxForIsr(unsigned char uartNum) {
    uartTxIndex = 1;
    if (uartNum == 0) {
        UTX0IF = 0;
        IEN2 |= 0x04;
        U0DBUF = uartTxBuffer[0];
    } else {
        UTX1IF = 0;
        IEN2 |= 0x08;
        U1DBUF = uartTxBuffer[0];
    }
    IEN0 |= 0x80;
}

void UART0_TX_ISR( void ) interrupt( UART0_TX_ISR_VECTOR ) {
    UTX0IF = 0;
    if (uartTxIndex > uartTxInterruptIndex) {
        uartTxIndex = 0;
        uartTxInterruptIndex = 0;
        IEN2 &= ~0x08;
        return;
    }
    U0DBUF = uartTxBuffer[uartTxIndex++];
}

void UART1_TX_ISR( void ) interrupt( UART1_TX_ISR_VECTOR ) {
    UTX1IF = 0;
    if (uartTxIndex > uartTxInterruptIndex) {
        uartTxIndex = 0;
        uartTxInterruptIndex = 0;
        IEN2 &= ~0x08;
        return;
    }
    U1DBUF = uartTxBuffer[uartTxIndex++];
}

void uartStartRxForIsr(unsigned char uartNum) {
    uartRxIndex = 0;
    uartRxInterruptIndex = 0;
    if (uartNum == 0) {
        URX0IF = 0;
        U0CSR |= 0x40;
        IEN0 |= 0x04;
    } else {
        URX1IF = 0;
        U1CSR |= 0x40;
        IEN0 |= 0x08;
    }
    IEN0 |= 0x80;
}

void UART0_RX_ISR( void ) interrupt( UART0_RX_ISR_VECTOR ) {
    URX0IF = 0;
    uartRxBuffer[uartRxInterruptIndex++] = U0DBUF;
    if (uartRxIndex >= SIZE_OF_UART_RX_BUFFER) {
        uartRxIndex = 0; IEN0 &= ~0x04;
    }
}
void UART1_RX_ISR( void ) interrupt( UART1_RX_ISR_VECTOR ) {
    URX1IF = 0;
    uartRxBuffer[uartRxIndex++] = U1DBUF;
    if (uartRxIndex >= SIZE_OF_UART_RX_BUFFER) {
        uartRxIndex = 0; IEN0 &= ~0x08;
    }
}

uint8 uartTxAvailable() {
    if(uartTxInterruptIndex) {
        return 1;
    } else {
        return 0;
    }
}

void uartTx(uint8 __xdata buffer[], uint8 size){
    uint8 position = 0;
    uartTxInterruptIndex = size - 1;
    while (position < size) {
        uartTxBuffer[position] = buffer[position];
        position++;
    }
    uartStartTxForIsr(defaultUartProtConfig.uartNum);
}

void uartTxSendByte(uint8 byte) {
    uartTxInterruptIndex = 1;
    uartTxBuffer[0] = byte;
    uartStartTxForIsr(defaultUartProtConfig.uartNum);
}

uint8 uartRxAvailable() {
    if(uartRxInterruptIndex){
        return 1;
    } else {
        return 0;
    }
}

uint8 uartNRxReceiveByte() {
    uint8 byte = uartRxBuffer[uartRxIndex];
    uartRxIndex++;
    if(uartRxIndex > uartRxInterruptIndex){
        uartRxInterruptIndex = 0;
        uartRxIndex = 0;
    }
    return byte;
}

uint8 uartTxPendingBytes() {
    return uartTxInterruptIndex - uartTxIndex;
}

void uartInit(uint8_t baudrate) {
    setBaudForClockRate(26, baudrate); //TODO: Find the actual clockrate!!
    uartInitProtocol(&defaultUartProtConfig);
    uartStartRxForIsr(defaultUartProtConfig.uartNum);
}
