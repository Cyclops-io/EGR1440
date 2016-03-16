//*****************************************************************************
//
// MSP432 main.c template - Empty main
//
//****************************************************************************

#define SETUP  11

#include "msp.h"
#include "stdbool.h"
//no commit for path changes
#include "D:\Common\School\Files\EGR1440\myHeaders\mySetup.h"	//Edit path for save location
#include "D:\Common\School\Files\EGR1440\myHeaders\debounce.h"	//Edit path for save location


void main(void)
{
	const int setupState = SETUP;

    //P1 config data to be OR'ed with the current state
    //of each reg
    uint8_t p1dir = 0b00000001;
    uint8_t p1ren = 0b00010010;
    uint8_t p1out = 0b00010010;

    //P2 config data to be OR'ed with the current state
    //of each reg
    uint8_t p2dir = BIT0|BIT1|BIT2;
    uint8_t p2ren = 0b00000000;
	uint8_t p2out = 0b00000000;

    setup(setupState);
    setP2(p2dir,p2ren,p2out);
    setP1(p1dir,p1ren,p1out);
    setP3P4P5P6P7P8P9P20();

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
