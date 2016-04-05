#include "msp.h"
#define P1IFG_1   (HWREG8(0x42000000+32*0x4C1C+4*1))  /* Port 1 Interrupt Flag1 */
#define P1IFG_4   (HWREG8(0x42000000+32*0x4C1C+4*4))  /* Port 1 Interrupt Flag4 */

volatile uint32_t FallingEdges = 0;
void EventCounterInit(void){
  //__asm ("    CPSID  I\n"     //dissable interrups - set the I bit
         //"    BX     LR\n");
  FallingEdges = 0;                // initialize counter
  P1SEL0 &= ~0x12;
  P1SEL1 &= ~0x12;                 // configure P1.4 and P1.1 as GPIO
  P1DIR &= ~0x12;                  // make P1.4 and P1.1 in (built-in Button 1 and Button 2)
  P1REN |= 0x12;                   // enable pull resistors on P1.4 and P1.1
  P1OUT |= 0x12;                   // P1.4 and P1.1 are pull-up
  P1IES |= 0x12;                   // P1.4 and P1.1 are falling edge event
  P1IFG &= ~0x12;                  // clear flag4 and flag1 (reduce possibility of extra interrupt)
  P1IE |= 0x12;                    // arm interrupt on P1.4 and P1.1
  NVIC_IPR8 = (NVIC_IPR8&0x00FFFFFF)|0x40000000; // priority 2
  NVIC_ISER1 = 0x00000008;         // enable interrupt 35 in NVIC

  //__asm  ("    CPSIE  I\n"          //enable interrupts; clear the I bit
    //      "    BX     LR\n");
}

// no critical section/race because only one input
void PORT1_IRQHandler(void){
  FallingEdges = FallingEdges + 1;
  P1IFG_1 = 0;      // clear flag1, acknowledge
  P1OUT ^= 0x01;    // toggle LED1
}

int main(void){
    WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer
  EventCounterInit();              // initialize P1.4 and P1.1 interrupts
  // initialize P1.0 and make it output (P1.0 built-in LED1)
  P1SEL0 &= ~0x01;
  P1SEL1 &= ~0x01;                 // configure built-in LED1 as GPIO
  P1DIR |= 0x01;                   // make built-in LED1 out
  P1OUT &= ~0x01;                  // LED1 = off
  // initialize P2.2-P2.0 and make them outputs (P2.2-P2.0 built-in RGB LEDs)
  P2SEL0 &= ~0x07;
  P2SEL1 &= ~0x07;                 // configure built-in RGB LEDs as GPIO
  P2DS |= 0x07;                    // make built-in RGB LEDs high drive strength
  P2DIR |= 0x07;                   // make built-in RGB LEDs out
  P2OUT &= ~0x07;                  // RGB = off
// end of new code (now with LEDs)
  while(1){
	  //__asm  ("    WFI\n"       //wait for interrupts
	    //      "    BX     LR\n");
  }
}


