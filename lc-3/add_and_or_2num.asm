.ORIG x3000

LD R0,X
LD R1,Y

ADD R2,R0,R1

AND R3,R0,R1

NOT R4,R0
NOT R5,R1
AND R4,R4,R5
NOT R4,R4

AND R5,R0,#1
BRP ELSE
ADD R7,R0,#0
BRNZP ENDIF
ELSE ADD R6,R0,#0
ENDIF HALT


X .FILL x0003
Y .FILL x0004

.END