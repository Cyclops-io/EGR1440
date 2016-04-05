//*****************************************************************************
//
// MSP432 main.c template - P1.0 port toggle
//
//****************************************************************************

#include "msp.h"
extern unsigned int testASM(void);
void myDelay(void);

void main(void)
{
    volatile uint32_t i;

    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer

    P2DIR |= BIT2;            // Configure P1.0 as output

    while(1)
    {
    	testASM();
    	myDelay();
    }
}

void myDelay(void){
	volatile uint32_t i;
	for(i=10000; i>0; i--);
}

