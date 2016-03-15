//*****************************************************************************
//
// MSP432 main.c template - Empty main
//
//****************************************************************************

#include "msp.h"
#include "stdbool.h"
#include "D:\School\EGR1440\myHeaders\mySetup.h"
#include "D:\School\EGR1440\myHeaders\debounce.h"

//#define SW2IN *((volatile uint8_t *)(0x42098010))
//#define SW1IN *((volatile uint8_t *)(0x42098004))

void main(void)
{

    setup();
    int previousState = 0;

    while(true)
      {
    	int currentState = myDebounce();
    	int latched = 0;
    	if (currentState > previousState)
    	{
    		latched = 1;
    	}
    	if (latched == 1)
    	{
    		P2OUT = 0;
    		P1OUT = 0;
    		P1OUT = 0b00010010;
    		P2OUT ^= BIT1;
    	}
    	previousState = currentState;
      }
}
