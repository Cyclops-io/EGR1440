;CCS
;http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0489h/Caccddic.html
	.thumb	; we will use Thumb assembly language   
    .text        ; Assembles into the .text (executable code) section
    .align 2     ; align the section program counter (SPC) on the next boundary
    			 ; 2 aligns the SPC on the next word boundary
	.global myToggle
           
P2DIR  .field 0x40004C05     ; Port 2 Direction; Initialize a bitfield     
P2OUT  .field 0x40004C03     ; Port 2 Output   
MOLLY  .byte 0ABh                 
BIT3	.equ	4            ; Use EQU to define constants. This is similar to the use of #define to define a constant in C.	

myToggle	.asmfunc   ;.asmfunc helps with the debugger 
	LDR		R1,  P2OUT
	LDRB	R0, [R1]
;	EOR		R0, R0, #4
	EOR		R0, R0, #BIT3 ; same as above
	STRB	R0, [R1] 
ret:
	;MOV PC, lr ; return back to the main program
	BX		LR  ; return back to the main program
	.endasmfunc ; help with debugging 
	.end
	