		.thumb
		.data
		.align	4
		
		.global	testASM
		.thumbfunc	testASM
		.text
		.align
A:		.word	0xF631024C, 0X17539ABD
PtA		.field	A, 32
		.align
testASM	.asmfunc
		LDR		R3, PtA	; R3 points to A
		LDR		R4, [R3]
		LDR		R5, [R3, #4]
		LDRD	R6, R7, [R3]
		LDRH	R8, [R3]
		LDRH	R9, [R3, #4]
		
		LDRSB	R8, [R3]
		LDRSB	R9, [R3, #4]
		
		BX	LR
		.endasmfunc
		.end
		