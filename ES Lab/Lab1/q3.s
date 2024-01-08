  AREA RESET, DATA, READONLY
  EXPORT __Vectors
__Vectors
  DCD 0X1001000
  DCD Reset_Handler
  ALIGN 
  AREA mycode, CODE, READONLY
  ENTRY
  EXPORT Reset_Handler
Reset_Handler
  MOV R7, #-0x35
  MOV R8, #30
  MOV R9, #0x35
  MOV R10,#-0x2F
  ADD R9,R7,R8
  ADDS R11,R9,R10
  
STOP
  B STOP
  END

