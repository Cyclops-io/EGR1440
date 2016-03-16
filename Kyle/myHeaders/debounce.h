#ifndef __DEBOUNCE_H__
#define __DEBOUNCE_H__

#ifndef __MSP_H__
#include "msp.h"
#endif

#ifndef __MYSYSTICK_H__
#include "D:\Common\School\Files\EGR1440\myHeaders\mySystick.h"
#endif

//#define SW1IN (*((volatile uint8_t *)(0x42098004)))
int myDebounce(uint8_t button, int ms)
{
  static int oldState = 0;
  int State = button;
  if(State == 0)
    {
      SysTick_Init(ms);
      int bounce = 0;
      while (bounce == 0 && (/*SYSTICK_STCSR*/(HWREG32(0xE000E010)) & 0x00010000)==0)
	{
	  State = button;
	  if (State != oldState)
	    {
	      bounce = 1;
	    }
	  else
	    {
	      bounce = 0;
	    }
	  oldState = State;
	}
      return bounce ^ 1;
    }
  return 0;
}

#endif

