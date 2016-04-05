
#include "msp.h"
extern unsigned int myToggle(int n);
extern void SysTick_Init(void);
void SysTickWait6s(void);
void blinkLed(void);
void myDelay(void);
void testASM(void);

void main(void)
{
	
    WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer
    P2DIR |= BIT2;            // Configure P1.0 as output

    testASM();

}


void blinkLed(void){
    SysTick_Init();

    while(1){
    myToggle(3);
    SysTickWait6s();
    }

}


void myDelay(void){
	volatile uint32_t i;
	for(i=10000; i>0; i--);
}
