	.thumb
	.text
	.align 2
	
	.global timerInit
	
SYSTICK_STCSR	.field	0xE000E010
SYSTICK_STRVR	.field	0xE000E014
SYSTICK_STCVR	.field	0xE000E018

timerInit	.asmfunc
	;SYSTICK_STCSR = 0;
	;SYSTICK_STRVR = 0X000000FF;
	;SYSTICK_STCVR = 0;
	;SYSTICK_STCSR = 0X00000005;
	;each C instruction takes 3 asm instructions
	;1: load pointer for register into R1
	;2: load value to stor in register into R0
	;3: write value in R0 to register pointed to by R1
	;CORRECT INIT SEQUENCE IS:
	;1: program the value in strvr
	;2: clear the stcvr register (by writing any value to it)
	;3: configure the stcsr for operation
	
	;clear the status register
	LDR		R1, SYSTICK_STCSR
	MOV		R0, #0
	STRB	R0, [R1]
	
	;program the value in strvr
	LDR		R1, SYSTICK_STRVR
	MOV		R0, #0xFF
	STRB	R0, [R1]
	
	;clear the stcvr register (by writing any value to it)
	LDR		R1, SYSTICK_STCVR
	MOV		R0, #0
	STRB	R0, [R1]
	
	;configure the stcsr for operation
	LDR		R1, SYSTICK_STCSR
	MOV		R0, #5
	STRB	R0, [R1]
	
	BX		LR
	.endasmfunc
	.end