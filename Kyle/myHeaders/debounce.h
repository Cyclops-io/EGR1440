#ifndef __DEBOUNCE_H__
#define __DEBOUNCE_H__

#ifndef __MSP_H__
#include "msp.h"
#endif

#ifndef __MYSYSTICK_H__
#include "D:\School\EGR1440\myHeaders\mySystick.h"
#endif

#define SW1IN (*((volatile uint8_t *)(0x42098004)))
int myDebounce()
{
  static int oldState = 0;
  int State = SW1IN;
  if(State == 0)
    {
      SysTick_Init(50);
      int bounce = 0;
      while (bounce == 0 && (/*SYSTICK_STCSR*/(HWREG32(0xE000E010)) & 0x00010000)==0)
	{
	  State = SW1IN;
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

