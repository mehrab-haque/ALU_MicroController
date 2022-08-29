//Clock Input Pin
#define CLOCK_INPUT 50
int programState=0,prevProgramState=0;
bool isClockPressed=false;
int delayMs=500;


int programCounter=-1;
//unsigned int iMData[256]={0xbfc1,0xbfc2,0xbfc2,0xbf92,0xbfa4,0x59a3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};



unsigned int iMData[256]={0xbf93,0x7fae,0x19a8,0x29ab,0xd8ac,0x5a93,0xaaa1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};



//Instruction memory output
#define IM_OUTPUT_0 34
#define IM_OUTPUT_1 35
#define IM_OUTPUT_2 36
#define IM_OUTPUT_3 37
#define IM_OUTPUT_4 38
#define IM_OUTPUT_5 39
#define IM_OUTPUT_6 40
#define IM_OUTPUT_7 41
#define IM_OUTPUT_8 42
#define IM_OUTPUT_9 43
#define IM_OUTPUT_10 44
#define IM_OUTPUT_11 45
#define IM_OUTPUT_12 46
#define IM_OUTPUT_13 47
#define IM_OUTPUT_14 48
#define IM_OUTPUT_15 49
//input
#define IM_INPUT_PREVIEW_0 0
#define IM_INPUT_PREVIEW_1 1
#define IM_INPUT_PREVIEW_2 2
#define IM_INPUT_PREVIEW_3 3
#define IM_INPUT_PREVIEW_4 4
#define IM_INPUT_PREVIEW_5 5
#define IM_INPUT_PREVIEW_6 6
#define IM_INPUT_PREVIEW_7 7



//Main Control Unit Pins
//Input (analog)
#define CONTROL_UNIT_INPUT_OPCODE_0 0
#define CONTROL_UNIT_INPUT_OPCODE_1 1
#define CONTROL_UNIT_INPUT_OPCODE_2 2
#define CONTROL_UNIT_INPUT_OPCODE_3 3
//Output
#define CONTROL_UNIT_OUTPUT_REGDST 5
#define CONTROL_UNIT_OUTPUT_BRANCH 6
#define CONTROL_UNIT_OUTPUT_MEMREAD 7
#define CONTROL_UNIT_OUTPUT_MEMTOREG 8
#define CONTROL_UNIT_OUTPUT_ALUOP_0 9
#define CONTROL_UNIT_OUTPUT_ALUOP_1 10
#define CONTROL_UNIT_OUTPUT_ALUOP_2 11
#define CONTROL_UNIT_OUTPUT_MEMWRITE 12
#define CONTROL_UNIT_OUTPUT_ALUSRC 13
#define CONTROL_UNIT_OUTPUT_REGWRITE 14
#define CONTROL_UNIT_OUTPUT_BEQ 15
#define CONTROL_UNIT_OUTPUT_JUMP 16

#define IMMEDIATE_OUTPUT 53


//jump analog input
#define JUMP_INPUT_EN 12

#define JUMP_INPUT_ADDRESS_0 4
#define JUMP_INPUT_ADDRESS_1 5
#define JUMP_INPUT_ADDRESS_2 6
#define JUMP_INPUT_ADDRESS_3 7
#define JUMP_INPUT_ADDRESS_4 8
#define JUMP_INPUT_ADDRESS_5 9
#define JUMP_INPUT_ADDRESS_6 10
#define JUMP_INPUT_ADDRESS_7 11



//Alu Control unit IO
//Input
#define ALU_CONTROL_UNIT_INPUT_A_0 17
#define ALU_CONTROL_UNIT_INPUT_A_1 18
#define ALU_CONTROL_UNIT_INPUT_A_2 19
#define ALU_CONTROL_UNIT_INPUT_A_3 20
#define ALU_CONTROL_UNIT_INPUT_B_0 21
#define ALU_CONTROL_UNIT_INPUT_B_1 22
#define ALU_CONTROL_UNIT_INPUT_B_2 23
#define ALU_CONTROL_UNIT_INPUT_B_3 24
#define ALU_CONTROL_UNIT_INPUT_ALUOP_0 13
#define ALU_CONTROL_UNIT_INPUT_ALUOP_1 14
#define ALU_CONTROL_UNIT_INPUT_ALUOP_2 15
//Output
#define ALU_CONTROL_UNIT_OUTPUT_0 28
#define ALU_CONTROL_UNIT_OUTPUT_1 29
#define ALU_CONTROL_UNIT_OUTPUT_2 30
#define ALU_CONTROL_UNIT_OUTPUT_3 31
#define ALU_CONTROL_UNIT_OUTPUT_OVERFLOW 32
#define ALU_CONTROL_UNIT_OUTPUT_ZERO 33



int imOutPins[16]={
  IM_OUTPUT_0,
  IM_OUTPUT_1,
  IM_OUTPUT_2,
  IM_OUTPUT_3,
  IM_OUTPUT_4,
  IM_OUTPUT_5,
  IM_OUTPUT_6,
  IM_OUTPUT_7,
  IM_OUTPUT_8,
  IM_OUTPUT_9,
  IM_OUTPUT_10,
  IM_OUTPUT_11,
  IM_OUTPUT_12,
  IM_OUTPUT_13,
  IM_OUTPUT_14,
  IM_OUTPUT_15
};


int imInPins[8]={
  IM_INPUT_PREVIEW_0,
  IM_INPUT_PREVIEW_1,
  IM_INPUT_PREVIEW_2,
  IM_INPUT_PREVIEW_3,
  IM_INPUT_PREVIEW_4,
  IM_INPUT_PREVIEW_5,
  IM_INPUT_PREVIEW_6,
  IM_INPUT_PREVIEW_7
};

//Main Control Unit Mapping
int opcodeMap[16][12]={
  {1,0,0,0,1,1,0,0,0,1,0,0},
  {1,0,0,0,0,0,0,0,0,1,0,0},
  {1,0,0,0,1,0,0,0,0,1,0,0},
  {0,1,0,0,1,0,0,0,0,0,0,0},
  {0,1,0,0,1,0,0,0,0,0,1,0},
  {0,0,0,0,0,0,0,1,1,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,1},
  {0,0,0,0,1,0,0,0,1,1,0,0},
  {0,0,1,1,0,0,0,0,1,1,0,0},
  {1,0,0,0,0,1,0,0,0,1,0,0},
  {0,0,0,0,0,1,1,0,1,1,0,0},
  {0,0,0,0,0,0,0,0,1,1,0,0},
  {0,0,0,0,1,1,0,0,1,1,0,0},
  {1,0,0,0,0,0,1,0,0,1,0,0},
  {0,0,0,0,0,1,0,0,0,1,0,0},
  {0,0,0,0,1,0,1,0,0,1,0,0}
};
//Main control output pins map
int opCodeOutputPins[12]={
  CONTROL_UNIT_OUTPUT_REGDST,
  CONTROL_UNIT_OUTPUT_BRANCH,
  CONTROL_UNIT_OUTPUT_MEMREAD,
  CONTROL_UNIT_OUTPUT_MEMTOREG,
  CONTROL_UNIT_OUTPUT_ALUOP_0,
  CONTROL_UNIT_OUTPUT_ALUOP_1,
  CONTROL_UNIT_OUTPUT_ALUOP_2,
  CONTROL_UNIT_OUTPUT_MEMWRITE,
  CONTROL_UNIT_OUTPUT_ALUSRC,
  CONTROL_UNIT_OUTPUT_REGWRITE,
  CONTROL_UNIT_OUTPUT_BEQ,
  CONTROL_UNIT_OUTPUT_JUMP
};

//High-Low Map
int highLowMap[2]={
  LOW,
  HIGH
};
//Analog High Low Map
int analogHighLowMap[2]={
  0,
  1023
};


int calculate4BitSignedBinary(int i0,int i1,int i2,int i3){
  int number;
  number=i0*1+i1*2+i2*4+i3*8;
  
  if(i3==0){
    return number;
  }
  number=16-number;
 
  return -number;
}


void setup() {
  //Clock Input Setup
  pinMode(CLOCK_INPUT, INPUT);
  
  //Instruction Memory Output
    pinMode(IM_OUTPUT_0, OUTPUT);
    pinMode(IM_OUTPUT_1, OUTPUT);
    pinMode(IM_OUTPUT_2, OUTPUT);
    pinMode(IM_OUTPUT_3, OUTPUT);
    pinMode(IM_OUTPUT_4, OUTPUT);
    pinMode(IM_OUTPUT_5, OUTPUT);
    pinMode(IM_OUTPUT_6, OUTPUT);
    pinMode(IM_OUTPUT_7, OUTPUT);
    pinMode(IM_OUTPUT_8, OUTPUT);
    pinMode(IM_OUTPUT_9, OUTPUT);
    pinMode(IM_OUTPUT_10, OUTPUT);
    pinMode(IM_OUTPUT_11, OUTPUT);
    pinMode(IM_OUTPUT_12, OUTPUT);
    pinMode(IM_OUTPUT_13, OUTPUT);
    pinMode(IM_OUTPUT_14, OUTPUT);
    pinMode(IM_OUTPUT_15, OUTPUT);

    pinMode(IMMEDIATE_OUTPUT, OUTPUT);


 
  //Main Control Unit Outputs
  pinMode(CONTROL_UNIT_OUTPUT_REGDST, OUTPUT);
  pinMode(CONTROL_UNIT_OUTPUT_BRANCH, OUTPUT);
  pinMode(CONTROL_UNIT_OUTPUT_MEMREAD, OUTPUT);
  pinMode(CONTROL_UNIT_OUTPUT_MEMTOREG, OUTPUT);
  pinMode(CONTROL_UNIT_OUTPUT_ALUOP_0, OUTPUT);
  pinMode(CONTROL_UNIT_OUTPUT_ALUOP_1, OUTPUT);
  pinMode(CONTROL_UNIT_OUTPUT_ALUOP_2, OUTPUT);
  pinMode(CONTROL_UNIT_OUTPUT_MEMWRITE, OUTPUT);
  pinMode(CONTROL_UNIT_OUTPUT_ALUSRC, OUTPUT);
  pinMode(CONTROL_UNIT_OUTPUT_REGWRITE, OUTPUT);
  pinMode(CONTROL_UNIT_OUTPUT_BEQ, OUTPUT);
  pinMode(CONTROL_UNIT_OUTPUT_JUMP, OUTPUT);

  //ALU COntrol Unit Inputs
  pinMode(ALU_CONTROL_UNIT_INPUT_A_0, INPUT);
  pinMode(ALU_CONTROL_UNIT_INPUT_A_1, INPUT);
  pinMode(ALU_CONTROL_UNIT_INPUT_A_2, INPUT);
  pinMode(ALU_CONTROL_UNIT_INPUT_A_3, INPUT);
  pinMode(ALU_CONTROL_UNIT_INPUT_B_0, INPUT);
  pinMode(ALU_CONTROL_UNIT_INPUT_B_1, INPUT);
  pinMode(ALU_CONTROL_UNIT_INPUT_B_2, INPUT);
  pinMode(ALU_CONTROL_UNIT_INPUT_B_3, INPUT);
  
  //Outputs
   pinMode(ALU_CONTROL_UNIT_OUTPUT_0, OUTPUT);
   pinMode(ALU_CONTROL_UNIT_OUTPUT_1, OUTPUT);
   pinMode(ALU_CONTROL_UNIT_OUTPUT_2, OUTPUT);
   pinMode(ALU_CONTROL_UNIT_OUTPUT_3, OUTPUT);
   pinMode(ALU_CONTROL_UNIT_OUTPUT_OVERFLOW, OUTPUT);
   pinMode(ALU_CONTROL_UNIT_OUTPUT_ZERO, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  
  int isClockPulse = digitalRead(CLOCK_INPUT);
  if(isClockPulse && !isClockPressed){
    delay(delayMs);
    isClockPressed=true;
    prevProgramState=programState;
    programState++;
    programCounter++;
    
  }
  if(!isClockPulse)
    isClockPressed=false;
  if(prevProgramState!=programState){
    prevProgramState=programState;
    Serial.println(programCounter);

    //IM output
    //IM Input Preview
    int mask=1;
    for(int i=0;i<8;i++){
      analogWrite(imInPins[i], analogHighLowMap[(programCounter&mask)>>i]);
      mask=mask<<1;
    }
  
    //IM Output
    mask=1;
    for(int i=0;i<16;i++){
      digitalWrite(imOutPins[i],highLowMap[(iMData[programCounter]&mask)>>i]);
      mask=mask<<1;
    }

    delay(100);

    //main control unit
    //Read Main Control Unit Input
      int opCode_0=analogRead(CONTROL_UNIT_INPUT_OPCODE_0)>500?1:0;
      int opCode_1=analogRead(CONTROL_UNIT_INPUT_OPCODE_1)>500?1:0;
      int opCode_2=analogRead(CONTROL_UNIT_INPUT_OPCODE_2)>500?1:0;
      int opCode_3=analogRead(CONTROL_UNIT_INPUT_OPCODE_3)>500?1:0;
      int opCode=opCode_0+opCode_1*2+opCode_2*4+opCode_3*8;

      

      
      for(int i=0;i<12;i++){
        if(opCodeOutputPins[i]!=CONTROL_UNIT_OUTPUT_MEMWRITE && opCodeOutputPins[i]!=CONTROL_UNIT_OUTPUT_MEMREAD && opCodeOutputPins[i]!=CONTROL_UNIT_OUTPUT_REGWRITE)digitalWrite(opCodeOutputPins[i],highLowMap[opcodeMap[opCode][i]]);
        else digitalWrite(opCodeOutputPins[i],LOW);
      }
      delay(10);

      int isJump=analogRead(JUMP_INPUT_EN)>500?1:0;
      if(isJump){
        int jmp_address_0=analogRead(JUMP_INPUT_ADDRESS_0)>500?1:0;
        int jmp_address_1=analogRead(JUMP_INPUT_ADDRESS_1)>500?1:0;
        int jmp_address_2=analogRead(JUMP_INPUT_ADDRESS_2)>500?1:0;
        int jmp_address_3=analogRead(JUMP_INPUT_ADDRESS_3)>500?1:0;
        int jmp_address_4=analogRead(JUMP_INPUT_ADDRESS_4)>500?1:0;
        int jmp_address_5=analogRead(JUMP_INPUT_ADDRESS_5)>500?1:0;
        int jmp_address_6=analogRead(JUMP_INPUT_ADDRESS_6)>500?1:0;
        int jmp_address_7=analogRead(JUMP_INPUT_ADDRESS_7)>500?1:0;

        int jump_address=jmp_address_0+jmp_address_1*2+jmp_address_2*4+jmp_address_3*8+jmp_address_4*16+jmp_address_5*32+jmp_address_6*64+jmp_address_7*128;
        Serial.println("jump to : "+String(jump_address));
        programCounter=jump_address;
        programState++;
        
       }
       else{ 
          //alu operatrions
          delay(100);
          //Read ALU Control Unit Input
          int aluInA0=digitalRead(ALU_CONTROL_UNIT_INPUT_A_0);
          int aluInA1=digitalRead(ALU_CONTROL_UNIT_INPUT_A_1);
          int aluInA2=digitalRead(ALU_CONTROL_UNIT_INPUT_A_2);
          int aluInA3=digitalRead(ALU_CONTROL_UNIT_INPUT_A_3);
          int aluInA=calculate4BitSignedBinary(aluInA0,aluInA1,aluInA2,aluInA3);

          int aluInB;

          Serial.println("Opcode : "+String(opCode));

          if(opCode==5 || opCode==7 || opCode==8 || opCode==10 || opCode==11 || opCode==12 || opCode==14 || opCode==15)
            aluInB=calculate4BitSignedBinary(iMData[programCounter]&1,((iMData[programCounter]>>1)&1),((iMData[programCounter]>>2)&1),((iMData[programCounter]>>3)&1));
          else{

            digitalWrite(IM_OUTPUT_8,highLowMap[(iMData[programCounter]>>4)&1]);
            digitalWrite(IM_OUTPUT_9,highLowMap[(iMData[programCounter]>>5)&1]);
            digitalWrite(IM_OUTPUT_10,highLowMap[(iMData[programCounter]>>6)&1]);
            digitalWrite(IM_OUTPUT_11,highLowMap[(iMData[programCounter]>>7)&1]);
//            delay(1000);
            delay(500);
            int aluInB0=digitalRead(ALU_CONTROL_UNIT_INPUT_A_0);
            int aluInB1=digitalRead(ALU_CONTROL_UNIT_INPUT_A_1);
            int aluInB2=digitalRead(ALU_CONTROL_UNIT_INPUT_A_2);
            int aluInB3=digitalRead(ALU_CONTROL_UNIT_INPUT_A_3);
            Serial.println(String(aluInB3)+String(aluInB2)+String(aluInB1)+String(aluInB0));
            aluInB=calculate4BitSignedBinary(aluInB0,aluInB1,aluInB2,aluInB3);
          }
  

          int aluOp_0=analogRead(ALU_CONTROL_UNIT_INPUT_ALUOP_0)>500?1:0;
          int aluOp_1=analogRead(ALU_CONTROL_UNIT_INPUT_ALUOP_1)>500?1:0;
          int aluOp_2=analogRead(ALU_CONTROL_UNIT_INPUT_ALUOP_2)>500?1:0;
          int aluOp=aluOp_0+aluOp_1*2+aluOp_2*4;

          int aluResult;
            switch(aluOp){
              case 0:
                aluResult=aluInA+aluInB;
                break;
              case 1:
                aluResult=aluInA-aluInB;
                break;
              case 2:
                aluResult=aluInA&aluInB;
                
                break;
              case 3:
                aluResult=aluInA|aluInB;
                break;
              case 4:
                aluResult=~(aluInA|aluInB);
                break;
              case 5:
                aluResult=aluInA<<aluInB;
                break;
              case 6:
                aluResult=aluInA>>aluInB;
                break;
              default:
                aluResult=0;
            }
          
          aluResult=calculate4BitSignedBinary(aluResult&1,(aluResult>>1)&1,(aluResult>>2)&1,(aluResult>>3)&1);

          Serial.println("ALU Input A : "+String(aluInA));
          Serial.println("ALU Input B : "+String(aluInB));
          Serial.println("ALU Result : "+String(aluResult));

          digitalWrite(ALU_CONTROL_UNIT_OUTPUT_0,highLowMap[aluResult&1]);
          digitalWrite(ALU_CONTROL_UNIT_OUTPUT_1,highLowMap[(aluResult&2)>>1]);
          digitalWrite(ALU_CONTROL_UNIT_OUTPUT_2,highLowMap[(aluResult&4)>>2]);
          digitalWrite(ALU_CONTROL_UNIT_OUTPUT_3,highLowMap[(aluResult&8)>>3]);
          digitalWrite(ALU_CONTROL_UNIT_OUTPUT_ZERO,highLowMap[aluResult==0]);

         delay(100);
          if(opCode==5 || opCode==7 || opCode==8 || opCode==10 || opCode==11 || opCode==12 || opCode==14 || opCode==15)
            digitalWrite(IMMEDIATE_OUTPUT,HIGH);
         delay(2000);
         if(opCode!=5 && opCode!=8){
          
          digitalWrite(CONTROL_UNIT_OUTPUT_REGWRITE,HIGH);
           delay(1000);
           digitalWrite(CONTROL_UNIT_OUTPUT_REGWRITE,LOW);
           delay(1000);
         }
         
//         digitalWrite(IMMEDIATE_OUTPUT,LOW);

          if(opCode==5){
            digitalWrite(IM_OUTPUT_8,highLowMap[(iMData[programCounter]>>4)&1]);
            digitalWrite(IM_OUTPUT_9,highLowMap[(iMData[programCounter]>>5)&1]);
            digitalWrite(IM_OUTPUT_10,highLowMap[(iMData[programCounter]>>6)&1]);
            digitalWrite(IM_OUTPUT_11,highLowMap[(iMData[programCounter]>>7)&1]);

            
            delay(200);              

            
              digitalWrite(CONTROL_UNIT_OUTPUT_MEMWRITE,HIGH);
              delay(100);
              digitalWrite(CONTROL_UNIT_OUTPUT_MEMWRITE,LOW);
          }
          if(opCode==8){
            delay(500);
            digitalWrite(CONTROL_UNIT_OUTPUT_MEMREAD,HIGH);
            delay(100);
            digitalWrite(CONTROL_UNIT_OUTPUT_MEMREAD,LOW);
          }

           digitalWrite(IMMEDIATE_OUTPUT,LOW);


          
       }

    
    
    
  }
  
}
