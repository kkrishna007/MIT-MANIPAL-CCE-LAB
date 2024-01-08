  AREA  RESET, DATA, READONLY
  EXPORT __Vectors
__Vectors
  DCD 0X1001000
  DCD Reset_Handler
  ALIGN 
  AREA mycode, CODE, READONLY
  ENTRY
  EXPORT Reset_Handler
Reset_Handler
  LDR R0, =0x12345678 
  LDR R1, =0xAABBCCDD
  LDR R2, =0xDEADBEEF
  LDR R3, =0xFEDCBA98
  MOV R4, #0xFFFFFFFF
  MOV R5, #0x10
  MOV R7, #0xF3
  MOV R8, #30
  MOV R9, #35
  MOV R10,#0xFFFFFFD1
STOP
B STOP
  END






