	.thumb
	.text
	.align 2
	
	.global myToggle
P2DIR	.field	0x40004C05
P2OUT	.field	0x40004C03
BIT3	.equ	4

myToggle	.asmfunc
	LDR		R1, P2OUT
	LDRB	R0, [R1]
	EOR		R0, R0, #BIT3
	STRB	R0, [R1]
	BX		LR
	.endasmfunc
	.end