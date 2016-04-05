#include "msp.h"
extern void testASM(void);

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer
	testASM();
}
