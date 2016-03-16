#ifndef MYSETUP_H
#define MYSETUP_H

#ifndef MSP_H
#include "msp.h"
#endif

//enum STATE{RS = 0, S = 1};
#if SETUP == 10 || SETUP == 11
#include "D:\Common\School\Files\EGR1440\myHeaders\SRS.h"
#endif

#if SW1 == 1
#undef SW1
#undef SW2
#define SW1 (*((volatile uint8_t *)(0x42098004)))
#define SW2 (*((volatile uint8_t *)(0x42098010)))
#elif SW1 == 2
#undef SW1
#undef SW2
#define SW1 (*((volatile uint8_t *)(0x42098010)))
#define SW2 (*((volatile uint8_t *)(0x42098004)))
#endif

#if Ucolor == 1
#define RED		BIT0
#define GREEN	BIT1
#define	BLUE	BIT2
#endif

void setup(const int opts)
{
	switch (opts)
	{
	case 01: // Stop watchdog timer
		WDTCTL = WDTPW | WDTHOLD;
		break;
	case 10:
		break;
	case 11:
		WDTCTL = WDTPW | WDTHOLD;
		break;
	default:
		break;
	}
}

void setP1(uint8_t dir, uint8_t ren, uint8_t out)
{
    P1DIR |= dir;
    P1REN |= ren;
    P1OUT |= out;
}
void setP2(uint8_t dir, uint8_t ren, uint8_t out)
{
    P2DIR |= dir;
    P2REN |= ren;
    P2OUT |= out;
}
setP3P4P5P6P7P8P9P20()
{
	P3DIR |= 0b00000000;
	P3REN |= 0b00000000;
	P3OUT |= 0b00000000;

	P4DIR |= 0b00000000;
	P4REN |= 0b00000000;
	P4OUT |= 0b00000000;

	P5DIR |= 0b00000000;
	P5REN |= 0b00000000;
	P5OUT |= 0b00000000;

	P6DIR |= 0b00000000;
	P6REN |= 0b00000000;
	P6OUT |= 0b00000000;

	P7DIR |= 0b00000000;
	P7REN |= 0b00000000;
	P7OUT |= 0b00000000;

	P8DIR |= 0b00000000;
	P8REN |= 0b00000000;
	P8OUT |= 0b00000000;

	P9DIR |= 0b00000000;
	P9REN |= 0b00000000;
	P9OUT |= 0b00000000;

	P10DIR |= 0b00000000;
	P10REN |= 0b00000000;
	P10OUT |= 0b00000000;
}
#endif
