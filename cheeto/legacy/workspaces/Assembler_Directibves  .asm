;ccs
			.thumb // declares the function will be in thumb instrustrunction
			.data // intiates data libray
Molly		.set 011h
			.string "Austin", "Houston", "Dallas" // declares austin, houston, dallas as strings
			.string 41h, 42h, 43h, 44h //declares 41h, 42h, 43h, 44h as string values
;Bethany	.byte 0Ah, 0Bh
			.align 4
			.global M //declairs M as a global veriable
M			.field 32
			.align 2
			.text // initiates text library
PtM			.field M, 32
P41N 		.field 0x0004C21,  32
BIT5		.equ 0x20
			.global main
			.thumbfunc	main
Bethany		.byte 0Ah, 0Bh
main 		.asmfunc
			Mov			R0, #Molly // moves #Molly to register 0
			LDR			R1, Bethany // loads Bethany into register 1
			LDR			R0, P41N // loads P41N into register 0
			LDRB	R1, [R0] // puts the value of register 0 into register 1
			AND			R1, R1, #BIT5
			LDR			R2, PtM
			STR			R1, [R2] // stors register 2 in register 1
			BX			LR
			.endasmfunc
			.end
