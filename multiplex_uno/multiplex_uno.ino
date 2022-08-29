#define INS_CODE_0 0
#define INS_CODE_1 1
#define INS_CODE_2 2
#define INS_CODE_3 3
#define INS_CODE_4 4
#define INS_CODE_5 5
#define INS_CODE_6 6
#define INS_CODE_7 7

#define IMMEDIATE 8

#define WRITE_LOC_0 9
#define WRITE_LOC_1 10
#define WRITE_LOC_2 11
#define WRITE_LOC_3 12


void setup() {
  pinMode(INS_CODE_0,INPUT);
  pinMode(INS_CODE_1,INPUT);
  pinMode(INS_CODE_2,INPUT);
  pinMode(INS_CODE_3,INPUT);
  pinMode(INS_CODE_4,INPUT);
  pinMode(INS_CODE_5,INPUT);
  pinMode(INS_CODE_6,INPUT);
  pinMode(INS_CODE_7,INPUT);

  pinMode(IMMEDIATE,INPUT);

  pinMode(WRITE_LOC_0,OUTPUT);
  pinMode(WRITE_LOC_1,OUTPUT);
  pinMode(WRITE_LOC_2,OUTPUT);
  pinMode(WRITE_LOC_3,OUTPUT);

}

void loop() {
  int isImmediate=digitalRead(IMMEDIATE);

  int ins_0=digitalRead(INS_CODE_0);
  int ins_1=digitalRead(INS_CODE_1);
  int ins_2=digitalRead(INS_CODE_2);
  int ins_3=digitalRead(INS_CODE_3);
  int ins_4=digitalRead(INS_CODE_4);
  int ins_5=digitalRead(INS_CODE_5);
  int ins_6=digitalRead(INS_CODE_6);
  int ins_7=digitalRead(INS_CODE_7);

  if(isImmediate){
    digitalWrite(WRITE_LOC_0,ins_4);
    digitalWrite(WRITE_LOC_1,ins_5);
    digitalWrite(WRITE_LOC_2,ins_6);
    digitalWrite(WRITE_LOC_3,ins_7);
  }else{
    digitalWrite(WRITE_LOC_0,ins_0);
    digitalWrite(WRITE_LOC_1,ins_1);
    digitalWrite(WRITE_LOC_2,ins_2);
    digitalWrite(WRITE_LOC_3,ins_3);
  }
 
}
