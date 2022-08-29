//reg input pins
#define REG_INPUT_READ_A_0 21
#define REG_INPUT_READ_A_1 22
#define REG_INPUT_READ_A_2 23
#define REG_INPUT_READ_A_3 24

#define REG_INPUT_READ_B_0 25
#define REG_INPUT_READ_B_1 26
#define REG_INPUT_READ_B_2 27
#define REG_INPUT_READ_B_3 28

#define REG_INPUT_WRITE_REG_0 29
#define REG_INPUT_WRITE_REG_1 30
#define REG_INPUT_WRITE_REG_2 31
#define REG_INPUT_WRITE_REG_3 32

//analog
#define REG_INPUT_WRITE_DATA_0 0
#define REG_INPUT_WRITE_DATA_1 1
#define REG_INPUT_WRITE_DATA_2 2
#define REG_INPUT_WRITE_DATA_3 3


#define REG_INPUT_WRITE_EN 37
#define REG_INPUT_CLR 38

//reg output pins
#define REG_OUTPUT_READ_A_0 39
#define REG_OUTPUT_READ_A_1 40
#define REG_OUTPUT_READ_A_2 41
#define REG_OUTPUT_READ_A_3 42
 
#define REG_OUTPUT_READ_B_0 43
#define REG_OUTPUT_READ_B_1 44
#define REG_OUTPUT_READ_B_2 45
#define REG_OUTPUT_READ_B_3 46
#define REG_OUTPUT_READ_B_DEBUG_2 8
#define REG_OUTPUT_READ_B_DEBUG_3 9

//Data Memory Inputs
#define DATA_MEMORY_INPUT_ADDRESS_0 20
#define DATA_MEMORY_INPUT_ADDRESS_1 2
#define DATA_MEMORY_INPUT_ADDRESS_2 3
#define DATA_MEMORY_INPUT_ADDRESS_3 4
#define DATA_MEMORY_INPUT_ADDRESS_4 5
#define DATA_MEMORY_INPUT_ADDRESS_5 6
#define DATA_MEMORY_INPUT_ADDRESS_6 7
#define DATA_MEMORY_INPUT_ADDRESS_7 8
//analog
#define DATA_MEMORY_INPUT_WRITE_DATA_0 4
#define DATA_MEMORY_INPUT_WRITE_DATA_1 5
#define DATA_MEMORY_INPUT_WRITE_DATA_2 6
#define DATA_MEMORY_INPUT_WRITE_DATA_3 7

#define DATA_MEMORY_INPUT_MEMWRITE 13
#define DATA_MEMORY_INPUT_MEMREAD 14
#define DATA_MEMORY_INPUT_CLR 15
//Outputs
#define DATA_MEMORY_OUTPUT_0 16
#define DATA_MEMORY_OUTPUT_1 17
#define DATA_MEMORY_OUTPUT_2 18
#define DATA_MEMORY_OUTPUT_3 19



//reg data

int regMem[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0};

//data memory

int dataMemory[256]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


int dataMemoryOutputPins[4]={
  DATA_MEMORY_OUTPUT_0,
  DATA_MEMORY_OUTPUT_1,
  DATA_MEMORY_OUTPUT_2,
  DATA_MEMORY_OUTPUT_3
};

int regAOutputPins[4]={
    REG_OUTPUT_READ_A_0,
    REG_OUTPUT_READ_A_1,
    REG_OUTPUT_READ_A_2,
    REG_OUTPUT_READ_A_3
  };

int regBOutputPins[4]={
  REG_OUTPUT_READ_B_0,
  REG_OUTPUT_READ_B_1,
  REG_OUTPUT_READ_B_2,
  REG_OUTPUT_READ_B_3
};

int prevWriteStatus=false;

int prevMemReadStatus=false;

int writeDelay=250;


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
  //reg input
  pinMode(REG_INPUT_READ_A_0, INPUT);
  pinMode(REG_INPUT_READ_A_1, INPUT);
  pinMode(REG_INPUT_READ_A_2, INPUT);
  pinMode(REG_INPUT_READ_A_3, INPUT);

  pinMode(REG_INPUT_READ_B_0, INPUT);
  pinMode(REG_INPUT_READ_B_1, INPUT);
  pinMode(REG_INPUT_READ_B_2, INPUT);
  pinMode(REG_INPUT_READ_B_3, INPUT);

  pinMode(REG_INPUT_WRITE_REG_0, INPUT);
  pinMode(REG_INPUT_WRITE_REG_1, INPUT);
  pinMode(REG_INPUT_WRITE_REG_2, INPUT);
  pinMode(REG_INPUT_WRITE_REG_3, INPUT);

  pinMode(REG_INPUT_WRITE_EN, INPUT);
  pinMode(REG_INPUT_CLR, INPUT);

  //output
  pinMode(REG_OUTPUT_READ_A_0, OUTPUT);
  pinMode(REG_OUTPUT_READ_A_1, OUTPUT);
  pinMode(REG_OUTPUT_READ_A_2, OUTPUT);
  pinMode(REG_OUTPUT_READ_A_3, OUTPUT);

  pinMode(REG_OUTPUT_READ_B_0, OUTPUT);
  pinMode(REG_OUTPUT_READ_B_1, OUTPUT);
  pinMode(REG_OUTPUT_READ_B_2, OUTPUT);
  pinMode(REG_OUTPUT_READ_B_3, OUTPUT);
  
//  pinMode(REG_OUTPUT_READ_B_DEBUG_2, OUTPUT);
//  pinMode(REG_OUTPUT_READ_B_DEBUG_3, OUTPUT);


  //Data memory inputs
  pinMode(DATA_MEMORY_INPUT_ADDRESS_0, INPUT);
  pinMode(DATA_MEMORY_INPUT_ADDRESS_1, INPUT);
  pinMode(DATA_MEMORY_INPUT_ADDRESS_2, INPUT);
  pinMode(DATA_MEMORY_INPUT_ADDRESS_3, INPUT);
  pinMode(DATA_MEMORY_INPUT_ADDRESS_4, INPUT);
  pinMode(DATA_MEMORY_INPUT_ADDRESS_5, INPUT);
  pinMode(DATA_MEMORY_INPUT_ADDRESS_6, INPUT);
  pinMode(DATA_MEMORY_INPUT_ADDRESS_7, INPUT);
  
  pinMode(DATA_MEMORY_INPUT_MEMWRITE, INPUT);
  pinMode(DATA_MEMORY_INPUT_MEMREAD, INPUT);
  pinMode(DATA_MEMORY_INPUT_CLR, INPUT);
  //outputs
  pinMode(DATA_MEMORY_OUTPUT_0, OUTPUT);
  pinMode(DATA_MEMORY_OUTPUT_1, OUTPUT);
  pinMode(DATA_MEMORY_OUTPUT_2, OUTPUT);
  pinMode(DATA_MEMORY_OUTPUT_3, OUTPUT);

  Serial.begin(9600);

}


void printRegisters(){
  Serial.println("####Register Data####");
  Serial.println("$t0="+String(regMem[8])+", "+"$t1="+String(regMem[9])+", "+"$t2="+String(regMem[10])+", "+"$t3="+String(regMem[11])+", "+"$t4="+String(regMem[12])+", "+"$sp="+String(regMem[13])+", "+"$zero="+String(regMem[15]));
  Serial.println("####Register Data End####");
}

void loop() {
  //reg operations
  int isWriteMode=digitalRead(REG_INPUT_WRITE_EN);
  int isClearMode=digitalRead( REG_INPUT_CLR);

  //reg read
  int readBLoc=digitalRead(REG_INPUT_READ_B_0)+digitalRead(REG_INPUT_READ_B_1)*2+digitalRead(REG_INPUT_READ_B_2)*4+digitalRead(REG_INPUT_READ_B_3)*8;
  int readALoc=digitalRead(REG_INPUT_READ_A_0)+digitalRead(REG_INPUT_READ_A_1)*2+digitalRead(REG_INPUT_READ_A_2)*4+digitalRead(REG_INPUT_READ_A_3)*8;
  
  int mask=1;
  
  for(int i=0;i<4;i++){
     digitalWrite(regBOutputPins[i],highLowMap[(regMem[readBLoc]&mask)>>i]);
    digitalWrite(regAOutputPins[i],highLowMap[(regMem[readALoc]&mask)>>i]);
   
    mask=mask<<1;
  }

  if(isWriteMode && prevWriteStatus!=isWriteMode){
    prevWriteStatus=1;
    delay(writeDelay);
    int writeLoc=digitalRead(REG_INPUT_WRITE_REG_0)+digitalRead(REG_INPUT_WRITE_REG_1)*2+digitalRead(REG_INPUT_WRITE_REG_2)*4+digitalRead(REG_INPUT_WRITE_REG_3)*8;
    int writeData_0=analogRead(REG_INPUT_WRITE_DATA_0)>500?1:0;
    int writeData_1=analogRead(REG_INPUT_WRITE_DATA_1)>500?1:0;
    int writeData_2=analogRead(REG_INPUT_WRITE_DATA_2)>500?1:0;
    int writeData_3=analogRead(REG_INPUT_WRITE_DATA_3)>500?1:0;
    int writeData=calculate4BitSignedBinary(writeData_0,writeData_1,writeData_2,writeData_3);
 
    if(writeLoc==15)writeData=0;
    regMem[writeLoc]=writeData;
   

    printRegisters();

     

 

    
    }
    else if(!isWriteMode){
      prevWriteStatus=0;
    }

   
 if(isClearMode){
    for(int i=0;i<16;i++)
      regMem[i]=0;
    regMem[13]=15;
  }


 


  //Serial.println(out);

  // Data Memory Operations
  int isReadMode=digitalRead(DATA_MEMORY_INPUT_MEMREAD);
  isWriteMode=digitalRead(DATA_MEMORY_INPUT_MEMWRITE);
  isClearMode=digitalRead(DATA_MEMORY_INPUT_CLR);

  if(isReadMode && prevMemReadStatus!=isReadMode){
    prevMemReadStatus=1;
        int writeLoc=digitalRead(REG_INPUT_WRITE_REG_0)+digitalRead(REG_INPUT_WRITE_REG_1)*2+digitalRead(REG_INPUT_WRITE_REG_2)*4+digitalRead(REG_INPUT_WRITE_REG_3)*8;


    int writeData_0=analogRead(REG_INPUT_WRITE_DATA_0)>500?1:0;
    int writeData_1=analogRead(REG_INPUT_WRITE_DATA_1)>500?1:0;
    int writeData_2=analogRead(REG_INPUT_WRITE_DATA_2)>500?1:0;
    int writeData_3=analogRead(REG_INPUT_WRITE_DATA_3)>500?1:0;
//    int address_0=digitalRead(DATA_MEMORY_INPUT_ADDRESS_0);
//    int address_1=digitalRead(DATA_MEMORY_INPUT_ADDRESS_1);
//    int address_2=digitalRead(DATA_MEMORY_INPUT_ADDRESS_2);
//    int address_3=digitalRead(DATA_MEMORY_INPUT_ADDRESS_3);
    int address=writeData_0+writeData_1*2+writeData_2*4+writeData_3*8+ writeData_3*16+writeData_3*32+writeData_3*64+writeData_3*128;


    
    int data=dataMemory[address];



    
    
 
    if(writeLoc==15)data=0;
    regMem[writeLoc]=data;
    Serial.print("INSIDE WRITEMODE of LW, add. " );
    Serial.print(writeLoc);
    Serial.print( " data ");
    Serial.println(data);
   // Serial.println(String(data_3)+String(data_2)+String(data_1)+String(data_0));

     printRegisters();
    
    
    //Serial.println(data);
    //Serial.println(address);
    int mask=1;
    for(int i=0;i<4;i++){
      digitalWrite(dataMemoryOutputPins[i],highLowMap[(data&mask)>>i]);
      mask=mask<<1;
    }
  }
 else if(!isReadMode){
      prevMemReadStatus=0;
    }

  
  if(isWriteMode){
    delay(writeDelay);
    // sign extension to 8 bits
    int writeData_0=analogRead(REG_INPUT_WRITE_DATA_0)>500?1:0;
    int writeData_1=analogRead(REG_INPUT_WRITE_DATA_1)>500?1:0;
    int writeData_2=analogRead(REG_INPUT_WRITE_DATA_2)>500?1:0;
    int writeData_3=analogRead(REG_INPUT_WRITE_DATA_3)>500?1:0;
//    int address_0=digitalRead(DATA_MEMORY_INPUT_ADDRESS_0);
//    int address_1=digitalRead(DATA_MEMORY_INPUT_ADDRESS_1);
//    int address_2=digitalRead(DATA_MEMORY_INPUT_ADDRESS_2);
//    int address_3=digitalRead(DATA_MEMORY_INPUT_ADDRESS_3);
    int address=writeData_0+writeData_1*2+writeData_2*4+writeData_3*8+ writeData_3*16+writeData_3*32+writeData_3*64+writeData_3*128;
    
    writeData_0=analogRead(DATA_MEMORY_INPUT_WRITE_DATA_0)>500?1:0;
    writeData_1=analogRead(DATA_MEMORY_INPUT_WRITE_DATA_1)>500?1:0;
    writeData_2=analogRead(DATA_MEMORY_INPUT_WRITE_DATA_2)>500?1:0;
    writeData_3=analogRead(DATA_MEMORY_INPUT_WRITE_DATA_3)>500?1:0;
    int data=calculate4BitSignedBinary(writeData_0,writeData_1,writeData_2,writeData_3);
    dataMemory[address]=data;
        Serial.println("Data memory write address: "+String(address)+", value: "+data);

  }
  else if(isClearMode){
    for(int i=0;i<256;i++)
      dataMemory[i]=0;
  }


  


  

}
