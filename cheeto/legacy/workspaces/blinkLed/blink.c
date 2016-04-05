//*****************************************************************************
//
// MSP432 main.c template - P1.0 port toggle
//
//****************************************************************************

#include "msp.h"

void main(void)
{
    volatile uint32_t i;

    WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer

    // The following code toggles P1.0 port
    P1DIR |= BIT0; // Configure P1.0 as output
    P2DIR |= BIT1; // Configure P2.1 as output
    P2DIR |= BIT2; // Configure P2.2 as output
    P2DIR |= BIT0; // Configure P2.0 as output

    int count = 0;
    while(1)
    {
        P1OUT ^= BIT0;// Toggle P1.0
        switch (count % 3)
        {
          case 0:
            P2OUT ^= BIT0;
            break;
          case 1:
            P2OUT ^= BIT1;
            break;
          case 2:
            P2OUT ^= BIT2;
            break;
        }
        count++;
        for(i=10000; i>0; i--);         // Delay
    }
}
