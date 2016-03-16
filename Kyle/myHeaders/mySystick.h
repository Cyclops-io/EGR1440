#ifndef __MYSYSTICK_H__
#define __MYSYSTICK_H__

#ifndef __MSP_H__
#include "msp.h"
#endif

void SysTick_Init(int ms)
{
    int time = (0x00ffffff * (ms /1000.0))/6;
    /*SYSTICK_STCSR*/ (HWREG32(0xE000E010)) = 0;
    /*SYSTICK_STRVR*/ (HWREG32(0xE000E014))= time;
    /*SYSTICK_STCVR*/ (HWREG32(0xE000E018))= 0;
    /*SYSTICK_STCSR*/ (HWREG32(0xE000E010))= 0x00000005;
}

#endif
