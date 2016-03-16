//*****************************************************************************
//
// MSP432 main.c template - Empty main
//
//****************************************************************************

#include "msp.h"
#include "stdbool.h"
//no commit for path changes
#include "D:\Common\School\Files\EGR1440\myHeaders\mySetup.h"	//Edit path for save location
#include "D:\Common\School\Files\EGR1440\myHeaders\debounce.h"	//Edit path for save location


void main(void)
{
	int setupState = 01;
    setup(setupState);

    P2DIR |= BIT0|BIT1|BIT2;	//port 2 direction
  	    //current contence or with BIT0(P2.0) or BIT1(P2.1) or BIT2(P2.2)
  		//BITs can be found in msp.h -> msp432p401r.h
    P1DIR |= 0b00000001;	//port 1 direction all original state but P1.0 is output
    P1REN = 0b00010010;		//port 1 reg enable
    P1OUT = 0b00010010;		//port 1 our put ||||input pullup resistor
    enum STATE{RS = 0, S = 1};
    int previousState = 0;
    enum STATE state= RS;
    while(true)
      {
    	int currentState = myDebounce();
    	int latched = 0;
    	if (currentState > previousState)
    	{
    		latched = 1;
    		state ^= 1;
    	}
    	if (latched == 1)
    	{
    		switch (state)
    		{
    		case RS:
    			P2OUT = 0;
    			P1OUT = 0;
    			P1OUT = 0b00010010;
    			break;
    		case S:
    			P2OUT ^= BIT1;
    			break;
    		}
    	}
    	previousState = currentState;
      }
}
