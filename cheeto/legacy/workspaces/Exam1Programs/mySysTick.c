#include "msp.h"
// Initialize SysTick with busy wait running at bus clock.
void SysTick_Init(void){
  SYSTICK_STCSR = 0;                    // disable SysTick during setup
  SYSTICK_STRVR = 0x00FFFFFF;           // maximum reload value
  SYSTICK_STCVR = 0;                    // any write to current clears it
  SYSTICK_STCSR = 0x00000005;           // enable SysTick with no interrupts
}

// (2^24+1)*(1/(3*10^6)) = 5.5924 ; about 6 seconds

void SysTickWait6s(void){
	SYSTICK_STRVR = 0x00FFFFFF;           // maximum reload value; any write to CVR clears it and COUNTFLAG in CSR
	 while((SYSTICK_STCSR&0x00010000) == 0){}
}

