	.thumb
	.data
	.align 4
	
	.global testASM
	.thumbfunc testASM
	.align
	.text
testASM .asmfunc
	MOV R1, #0
	SUB R1, R1, #94
	MOV R0, R1
	LSL R1, #1
	ADD R1, R0
	
	;MOV R2, #0
	;MOV R3, #94
	;MVN R3, R3
	;ADD R3, #1
	;ADD R2, R3
	BX	LR
	.endasmfunc
	.end