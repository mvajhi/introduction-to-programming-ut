.ORIG x3000

AND R5,R5,#0
LD R3,A
LD R4,B


JSR MULTI

HALT

MULTI BRZ ENDWHILE
ADD R5,R5,R3
ADD R4,R4,#-1
BRNZP MULTI
ENDWHILE
RET

A .FILL X0005
B .FILL X0003

.END