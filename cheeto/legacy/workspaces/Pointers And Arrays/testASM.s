	.thumb
	.data
	.align	4
	
	.global testASM
	.thumbfunc	testASM
	.text
	.align
A:	.word 0xF631024C, 0x17539ABD
PtA	.field A, 32

	.align
testASM .asmfunc
	LDR R3, PtA	;r3 points to A
	LDR R4, [R3]
	LDR R5, [R3, #4]
	BX		LR
	.endasmfunc
	.end