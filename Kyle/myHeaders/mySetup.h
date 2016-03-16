#ifndef MYSETUP_H
#define MYSETUP_H

#ifndef MSP_H
#include "msp.h"
#endif

void setup(int opts)
{
	//int x,y;
	switch (opts)
	{
	case 01: // Stop watchdog timer
		WDTCTL = WDTPW | WDTHOLD;
		break;
	case 10:
		//x = 1;
		break;
	case 11:
		WDTCTL = WDTPW | WDTHOLD;
		//y = 1;
		break;
	}
	//if((x ==1)|(y==1)) enum STATE{RS = 0, S = 1};

}

#endif


