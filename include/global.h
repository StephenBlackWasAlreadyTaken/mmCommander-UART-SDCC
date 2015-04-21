#ifndef GLOBAL_H
#define GLOBAL_H

#include "cc1111.h"
#include "cc1111usbdebug.h"

#define SLEEPTIMER  1200
#define RADIO_EU 1
    
#define nop() __asm nop __endasm;

// used for debugging and tracing execution.  see client's ".getDebugCodes()"
extern __xdata u8 lastCode[2];

//////////////  DEBUG   //////////////
//#define VIRTUAL_COM
//#define RADIO_EU 
//#define TRANSMIT_TEST
//#define RECEIVE_TEST
//////////////////////////////////////



/* board-specific defines */
#ifdef IMMEDONGLE
    // CC1110 IMME pink dongle - 26mhz
    #define LED_RED   P2_3
    #define LED_GREEN P2_4
    #define SLEEPTIMER  1100
    
#elif defined DONSDONGLES
    // CC1111 USB Dongle with breakout debugging pins (EMK?) - 24mhz
    #define LED_RED   P1_1
    #define LED_GREEN P1_1
    #define SLEEPTIMER  1200
    #define CC1111EM_BUTTON P1_2

#else
    // CC1111 USB Chronos watch dongle - 24mhz
    #define LED_RED   P1_0
    #define LED_GREEN P1_0
    #define SLEEPTIMER  1200
#endif

#define LED     LED_GREEN


#define REALLYFASTBLINK()        { LED=1; sleepMillis(2); LED=0; sleepMillis(10); }
#define blink( on_cycles, off_cycles)  {LED=1; sleepMillis(on_cycles); LED=0; sleepMillis(off_cycles);}

/* function declarations */
void sleepMillis(int ms);
void sleepMicros(int us);
//void blink(u16 on_cycles, u16 off_cycles);
void blink_binary_baby_lsb(u16 num, char bits);
#endif
