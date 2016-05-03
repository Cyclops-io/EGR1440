//*****************************************************************************
//
// MSP432 main.c template - Empty main
//
//****************************************************************************

#include "msp.h"
	//SYSTICK Registers
	#define SYSTICK_STCSR   (HWREG32(0xE000E010)) /* SysTick Control and Status Register */
	#define SYSTICK_STRVR   (HWREG32(0xE000E014)) /* SysTick Reload Value Register */
	#define SYSTICK_STCVR   (HWREG32(0xE000E018)) /* SysTick Current Value Register */
	#define SYSTICK_STCR    (HWREG32(0xE000E01C)) /* SysTick Calibration Value Register */
//fucntion prototypes
void SysTick_Init(double ms);
int debounce(int ms);

//bit-band regions
#define SW2IN (*((volatile uint8_t *)(0x42098010)))
#define SW1IN (*((volatile uint8_t *)(0x42098004)))

//enums
enum states
{
	singleRed,
	rgbRed,
	rgbGreen,
	rgbBlue,
	rgbWhite,
	red,
	green,
};
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;

	P2DIR |= BIT0|BIT1|BIT2;
	P1DIR |= 0b00000001;
	
	P1REN = 0b00010010;
	P1OUT = 0b00010010;

	enum states currentState = singleRed;
	while (1)
	{
		if (debounce(1000))
		{

			P2OUT = 0;
			P1OUT = 0;
			P1OUT = 0b00010010;
			switch(currentState)
			{
				case singleRed:
					P1OUT ^= BIT0;
					currentState = rgbRed;
					break;
				case rgbRed:
					P2OUT ^= BIT0;
					currentState = rgbGreen;
					break;
				case rgbGreen:
					P2OUT ^= BIT1;
					currentState = rgbBlue;
					break;
				case rgbBlue:
					P2OUT ^= BIT2;
					currentState = rgbWhite;
					break;
				case rgbWhite:
					P2OUT ^= BIT2|BIT1|BIT0;
					currentState = singleRed;
					break;
			}
		}
	}
}



int debounce(int ms)
{
		SysTick_Init(ms);
		while (((SYSTICK_STCSR&0x00010000) == 0));
		return 1;
}
