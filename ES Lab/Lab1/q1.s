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
  
  MOV R0, # 14
  MOV R1, # 0x10 
  MOV R3, # -15
  LDR R4, Numb1
  
STOP
  
  B STOP

Numb1 DCD 0x10001001

  END
   
  
