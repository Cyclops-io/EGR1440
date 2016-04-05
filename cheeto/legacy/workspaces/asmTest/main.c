//*****************************************************************************
//
// MSP432 main.c template - Empty main
//
//****************************************************************************

#include "msp.h"
extern void myToggle(void);
extern void timerInit(void);
extern int timerCheck(void);
void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer
	P2DIR |= BIT2;
	timerInit();
	while (1)
	{
		if (timerCheck() != 0)
			myToggle();
	}
}
