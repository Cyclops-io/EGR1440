//*****************************************************************************
//
// MSP432 main.c template - Empty main
//
//****************************************************************************

#include "msp.h"

//fucntion prototypes
void SysTick_Init(int ms);
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
	rgbWhite
};
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;

	P2DIR |= BIT0|BIT1|BIT2;
	P1DIR |= 0b00000001;
	
	P1REN = 0b00010010;
	P1OUT = 0b00010010;

	int previousButtonState = 0;
	enum states currentState = singleRed;
	while (1)
	{
		int currentButtonState = debounce(50);
		int latched = 0;
		if (currentButtonState > previousButtonState)
			latched = 1;
		if (latched == 1)
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
		previousButtonState = currentButtonState;
	}
}

void SysTick_Init(int ms)
{
	//six seconds = 0x00FFFFFF
	//calculation (ffffff/6) = (x / seconds)
	//x = seconds * ffffff / 6
	int registerValue = (0x00ffffff * (ms / 1000.0)) / 6;
	SYSTICK_STCSR = 0;                    // disable SysTick during setup
	SYSTICK_STRVR = registerValue;           // maximum reload value
	SYSTICK_STCVR = 0;                    // any write to current clears it
	SYSTICK_STCSR = 0x00000005;           // enable SysTick with no interrupts
}

int debounce(int ms)
{
	static int previousButtonState = 0;
	int currentButtonState = SW1IN;
	if (currentButtonState == 0)
	{
		SysTick_Init(ms);
		int bounced = 0;
		while (bounced == 0 && ((SYSTICK_STCSR&0x00010000) == 0))
		{
			currentButtonState = SW1IN;
			if (currentButtonState != previousButtonState)
				bounced = 1;
			else bounced = 0;
			previousButtonState = currentButtonState;
		}
		return bounced ^ 1;
	}
	return 0;
}
