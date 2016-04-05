	.thumb
	.text
	.align 2
	
	.global timerCheck
	
SYSTICK_STCSR	.field	0xE000E010
SYSTICK_STRVR	.field	0xE000E014
SYSTICK_STCVR	.field	0xE000E018

timerCheck	.asmfunc
	;check to see if the 
	;R0 is the return value of a function
	MOV		R1, #0x00010000
	AND		R0, R1
	BX		LR
	.endasmfunc
	.end