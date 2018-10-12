const int segment[] = {11,12,5,7,8,10,9};
const int enable[] = {4,6};
const byte nums[] = {0x3F,0x06,0x5B,0x4F,0X66,0X6D,0X7D,0X7,0XFF,0X6F,0X77,0X7C,0X39,0X5E,0X79,0X71};
const int datap[] = {A5,A4,A3,2,A2,3,A1,A0};
byte data  = 0;


void show(byte num)
{
  num = nums[num];
  for(int i = 0 ; i < 7 ; i++)
  {
     digitalWrite(segment[i],num & 1);
     num = num >> 1;
  }
}

void enable_seg(int i)
{
 if ( i % 2 == 0 )
 {
   digitalWrite(enable[0],LOW);
   digitalWrite(enable[1],HIGH);
 }
 else
 {
   digitalWrite(enable[1],LOW);
   digitalWrite(enable[0],HIGH);
 }
}

 
void setup() {
    
  for(int i = 0 ; i < 8 ; i++)
  {
    pinMode(datap[i],INPUT);
  }
  for(int i = 0 ; i < 2 ; i++)
  {
    pinMode(enable[i],OUTPUT);  
  }
  for(int i = 0 ; i < 7 ; i++)
  {
    pinMode(segment[i],OUTPUT);
  }  
}
void readEEPROM()
{
  data = 0x00;
  for(int i = 0 ; i < 8 ; i++)
  {
    data = data << 1;
    data += digitalRead(datap[i]);
    
  }
}
void loop() {
  // put your main code here, to run repeatedly:
 readEEPROM();
 enable_seg(0);
 show(((int) data) % 16);
 delay(10);
 enable_seg(1);
 show(((int) data) / 16);
 delay(10);
 
}
