//*****************************************************************************
//
// MSP432 main.c template - P1.0 port toggle
//
//****************************************************************************

#include "msp.h"
extern void MyFactorial(void);
void main(void)
{
    volatile uint32_t i;

    WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer

    // The following code toggles P1.0 port
    P1DIR |= BIT0;                      // Configure P1.0 as output
    MyFactorial();
}
