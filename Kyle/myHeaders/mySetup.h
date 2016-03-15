#ifndef MYSETUP_H
#define MYSETUP_H

#ifndef MSP_H
#include "msp.h"
#endif

void setup()
{
  WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer
  P2DIR |= BIT0|BIT1|BIT2;	//port 2 direction
	    //current contence or with BIT0(P2.0) or BIT1(P2.1) or BIT2(P2.2)
		//BITs can be faunt in msp.h -> msp432p401r.h
  P1DIR |= 0b00000001;	//port 1 direction all original state but P1.0 is output


  P1REN = 0b00010010;		//port 1 reg enable
  P1OUT = 0b00010010;		//port 1 our put ||||input pullup resistor
}

#endif


