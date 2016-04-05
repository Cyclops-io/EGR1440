#include <stdint.h>
#include "msp.h"

void ledInit(void)
{
	P1SEL0 &= ~0x01;
	P1SEL1 &= ~0x01;
	P1DIR |= 0x01;
}

void ledOn(void)
{
	P1OUT |= 0x01;
}

void ledOff(void)
{
	P1OUT &= ~0x01;
}

void ledOutput(uint8_t data)
{
	P1OUT = (P1OUT&0xFE) | data;
}
#define LEDOUT (*((volatile uint8_t *)(0x42098040)))
void ledOn2(void)
{
	LEDOUT = 0x01;
}
void ledOff2(void)
{
	LEDOUT = 0x00;
}
void ledOutput2(uint8_t data)
{
	LEDOUT = data;
}
void port1Init(void)
{
	P2SEL0 = 0x00;
	P1SEL1 = 0x00;
	P1DIR = 0x00;
	P1REN = 0x12;
	P1OUT = 0x12;
}
void port2Init(void)
{
	P2SEL0 = 0x00;
	P2SEL1 = 0x00;
	P2DS = 0x07;
	P2DIR = 0x07;
	P2OUT = 0x00;
}

#define SW2IN (*((volatile uint8_t *)(0x42098010)))
#define SW1IN (*((volatile uint8_t *)(0x42098004)))
#define BLUEOUT  (*((volatile uint8_t *)(0x42098068)))
#define GREENOUT (*((volatile uint8_t *)(0x42098064)))
#define REDOUT   (*((volatile uint8_t *)(0x42098060)))

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;
	port1Init();
	port2Init();
	ledInit();
	BLUEOUT = 0;
	GREENOUT = 1;
	REDOUT = 1;
	
	while (1)
	{
		if ((SW1IN==0 || SW2IN==0))
			ledOn2();
		else
			ledOff2();
		if (SW1IN==0)
			BLUEOUT = 1;
		else
			BLUEOUT = 0;
		if (SW2IN==0)
			REDOUT = 1;
		else
			REDOUT = 0;
	}
}
