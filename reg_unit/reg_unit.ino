//Clock Input Pin
#define CLOCK_INPUT 0
//Data Memory Inputs
#define DATA_MEMORY_INPUT_ADDRESS_0 20
#define DATA_MEMORY_INPUT_ADDRESS_1 2
#define DATA_MEMORY_INPUT_ADDRESS_2 3
#define DATA_MEMORY_INPUT_ADDRESS_3 4
#define DATA_MEMORY_INPUT_ADDRESS_4 5
#define DATA_MEMORY_INPUT_ADDRESS_5 6
#define DATA_MEMORY_INPUT_ADDRESS_6 7
#define DATA_MEMORY_INPUT_ADDRESS_7 8
#define DATA_MEMORY_INPUT_WRITE_DATA_0 9
#define DATA_MEMORY_INPUT_WRITE_DATA_1 10
#define DATA_MEMORY_INPUT_WRITE_DATA_2 11
#define DATA_MEMORY_INPUT_WRITE_DATA_3 12
#define DATA_MEMORY_INPUT_MEMWRITE 13
#define DATA_MEMORY_INPUT_MEMREAD 14
#define DATA_MEMORY_INPUT_CLR 15
//Outputs
#define DATA_MEMORY_OUTPUT_0 16
#define DATA_MEMORY_OUTPUT_1 17
#define DATA_MEMORY_OUTPUT_2 18
#define DATA_MEMORY_OUTPUT_3 19


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

#define REG_INPUT_WRITE_DATA_0 33
#define REG_INPUT_WRITE_DATA_1 34
#define REG_INPUT_WRITE_DATA_2 35
#define REG_INPUT_WRITE_DATA_3 36


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


//reg data

int regMem[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0};


int dataMemory[256]={0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

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
  //Data memory inputs
  pinMode(DATA_MEMORY_INPUT_ADDRESS_0, INPUT);
  pinMode(DATA_MEMORY_INPUT_ADDRESS_1, INPUT);
  pinMode(DATA_MEMORY_INPUT_ADDRESS_2, INPUT);
  pinMode(DATA_MEMORY_INPUT_ADDRESS_3, INPUT);
  pinMode(DATA_MEMORY_INPUT_ADDRESS_4, INPUT);
  pinMode(DATA_MEMORY_INPUT_ADDRESS_5, INPUT);
  pinMode(DATA_MEMORY_INPUT_ADDRESS_6, INPUT);
  pinMode(DATA_MEMORY_INPUT_ADDRESS_7, INPUT);
  pinMode(DATA_MEMORY_INPUT_WRITE_DATA_0, INPUT);
  pinMode(DATA_MEMORY_INPUT_WRITE_DATA_1, INPUT);
  pinMode(DATA_MEMORY_INPUT_WRITE_DATA_2, INPUT);
  pinMode(DATA_MEMORY_INPUT_WRITE_DATA_3, INPUT);
  pinMode(DATA_MEMORY_INPUT_MEMWRITE, INPUT);
  pinMode(DATA_MEMORY_INPUT_MEMREAD, INPUT);
  pinMode(DATA_MEMORY_INPUT_CLR, INPUT);
  //outputs
  pinMode(DATA_MEMORY_OUTPUT_0, OUTPUT);
  pinMode(DATA_MEMORY_OUTPUT_1, OUTPUT);
  pinMode(DATA_MEMORY_OUTPUT_2, OUTPUT);
  pinMode(DATA_MEMORY_OUTPUT_3, OUTPUT);


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

  pinMode(REG_INPUT_WRITE_DATA_0, INPUT);
  pinMode(REG_INPUT_WRITE_DATA_1, INPUT);
  pinMode(REG_INPUT_WRITE_DATA_2, INPUT);
  pinMode(REG_INPUT_WRITE_DATA_3, INPUT);

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

  Serial.begin(9600);

}

void loop() {
  // Data Memory Operations
  int isReadMode=digitalRead(DATA_MEMORY_INPUT_MEMREAD);
  int isWriteMode=digitalRead(DATA_MEMORY_INPUT_MEMWRITE);
  int isClearMode=digitalRead(DATA_MEMORY_INPUT_CLR);

  if(isReadMode){
    int address=digitalRead(DATA_MEMORY_INPUT_ADDRESS_0)+digitalRead(DATA_MEMORY_INPUT_ADDRESS_1)*2+digitalRead(DATA_MEMORY_INPUT_ADDRESS_2)*4+digitalRead(DATA_MEMORY_INPUT_ADDRESS_3)*8+digitalRead(DATA_MEMORY_INPUT_ADDRESS_4)*16+digitalRead(DATA_MEMORY_INPUT_ADDRESS_5)*32+digitalRead(DATA_MEMORY_INPUT_ADDRESS_6)*64+digitalRead(DATA_MEMORY_INPUT_ADDRESS_7)*128;
    int data=dataMemory[address];
    Serial.println(data);
    Serial.println(address);
    int mask=1;
    for(int i=0;i<4;i++){
      digitalWrite(dataMemoryOutputPins[i],highLowMap[(data&mask)>>i]);
      mask=mask<<1;
    }
  }
  else if(isWriteMode){
    delay(writeDelay);
    int address=digitalRead(DATA_MEMORY_INPUT_ADDRESS_0)+digitalRead(DATA_MEMORY_INPUT_ADDRESS_1)*2+digitalRead(DATA_MEMORY_INPUT_ADDRESS_2)*4+digitalRead(DATA_MEMORY_INPUT_ADDRESS_3)*8+digitalRead(DATA_MEMORY_INPUT_ADDRESS_4)*16+digitalRead(DATA_MEMORY_INPUT_ADDRESS_5)*32+digitalRead(DATA_MEMORY_INPUT_ADDRESS_6)*64+digitalRead(DATA_MEMORY_INPUT_ADDRESS_7)*128;
    int data=calculate4BitSignedBinary(digitalRead(DATA_MEMORY_INPUT_WRITE_DATA_0),digitalRead(DATA_MEMORY_INPUT_WRITE_DATA_1),digitalRead(DATA_MEMORY_INPUT_WRITE_DATA_2),digitalRead(DATA_MEMORY_INPUT_WRITE_DATA_3));
    dataMemory[address]=data;
  }
  else if(isClearMode){
    for(int i=0;i<256;i++)
      dataMemory[i]=0;
  }


  //reg operations
  isWriteMode=digitalRead(REG_INPUT_WRITE_EN);
  isClearMode=digitalRead( REG_INPUT_CLR);

  //reg read
  int readALoc=digitalRead(REG_INPUT_READ_A_0)+digitalRead(REG_INPUT_READ_A_1)*2+digitalRead(REG_INPUT_READ_A_2)*4+digitalRead(REG_INPUT_READ_A_3)*8;
  int readBLoc=digitalRead(REG_INPUT_READ_B_0)+digitalRead(REG_INPUT_READ_B_1)*2+digitalRead(REG_INPUT_READ_B_2)*4+digitalRead(REG_INPUT_READ_B_3)*8;
  int mask=1;
  
  for(int i=0;i<4;i++){
    digitalWrite(regAOutputPins[i],highLowMap[(regMem[readALoc]&mask)>>i]);
    digitalWrite(regBOutputPins[i],highLowMap[(regMem[readBLoc]&mask)>>i]);
    mask=mask<<1;
  }

  if(isWriteMode){
    delay(writeDelay);
    int writeLoc=digitalRead(REG_INPUT_WRITE_REG_0)+digitalRead(REG_INPUT_WRITE_REG_1)*2+digitalRead(REG_INPUT_WRITE_REG_2)*4+digitalRead(REG_INPUT_WRITE_REG_3)*8;
    int writeData=calculate4BitSignedBinary(digitalRead(REG_INPUT_WRITE_DATA_0),digitalRead(REG_INPUT_WRITE_DATA_1),digitalRead(REG_INPUT_WRITE_DATA_2),digitalRead(REG_INPUT_WRITE_DATA_3));
    regMem[writeLoc]=writeData;
  }
  else if(isClearMode){
    for(int i=0;i<16;i++)
      regMem[i]=0;
    regMem[13]=15;
  }
  
  
}
