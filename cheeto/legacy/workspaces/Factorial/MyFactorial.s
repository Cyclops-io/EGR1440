;Cortex-M4 implements the ARMv7-M Thumb instruction set 
		.thumb
		
		.global	MyFactorial
		.thumbfunc	MyFactorial
MyFactorial:	.asmfunc

		MOV r6,#10 ; load 10 into r6
		MOV r7,#1 ; if n = 0, at least n! = 1
loop 	CMP r6, #0
		;if register r6 is greater than zero, 
		;perform the multiply, the subtraction,
		;and the branch; otherwise, do not 
		;execute any of these instructions.”
		ITTT GT ; start of our IF-THEN block
		;if the subtraction ended up with a result of zero, 
		;then the zero (Z) flag in the Application Program Status Register (APSR)
		;will be set, and the condition greater-than does not exist. 
		; IT<x><y><z><cond>; x, y, and z are optional (T (for "then") or E (for "else").
		; <cond> NE or EQ or GT, etc. that are reflected in the APSR flags

		;Each matching subsequent instruction must have conditions 
		;that match up with the IT instruction.
		MULGT r7, r6, r7 ; multiply conditionally
		SUBGT r6, r6, #1 ;conditional subtract 
		BGT loop ; end of IF-THEN block
		
stop	B stop ; branches to itself 

		BX		LR
		.endasmfunc
		.end