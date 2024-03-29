#include<SoftwareSerial.h>
SoftwareSerial BT(10,11);
String readData;

int Relay1=4;
int Relay2=5;
int Relay3=6;
int Relay4=7;
int Relay5=2;
int Relay6=3;
int Relay7=12;
int Relay8=13;
int val1=0;
int val2=0;
int val3=0;
int val4=0;
int val5=0;
int val6=0;
int val7=0;
int val8=0;


void setup()
{
  BT.begin(9600);
  Serial.begin(9600);
   pinMode(Relay1,OUTPUT);
   pinMode(Relay2,OUTPUT);
   pinMode(Relay3,OUTPUT);
   pinMode(Relay4,OUTPUT);
   pinMode(Relay5,OUTPUT);
   pinMode(Relay6,OUTPUT);
   pinMode(Relay7,OUTPUT);
   pinMode(Relay8,OUTPUT);
   digitalWrite(Relay1,HIGH);
   digitalWrite(Relay2,HIGH);
   digitalWrite(Relay3,HIGH);
   digitalWrite(Relay4,HIGH);
   digitalWrite(Relay5,HIGH);
   digitalWrite(Relay6,HIGH);
   digitalWrite(Relay7,HIGH);
   digitalWrite(Relay8,HIGH);
}
void loop()
{
  while (BT.available())
  {
    delay(10);
    char c=BT.read();
    readData +=c;
  }
  if(readData.length()>0)
  {
    Serial.println(readData);
    
    if (readData=="light")
    {
      val1=digitalRead(Relay1);
      if(val1==0)
      {
       digitalWrite(Relay1,HIGH);
       val1=1;
    }
    else 
    {
      digitalWrite(Relay1,LOW);
      val1=0;
    }
    delay(200);
    }


    if (readData=="ac")
    {
      val3=digitalRead(Relay3);
      if(val3==0)
      {
       digitalWrite(Relay3,HIGH);
       val3=1;
    }
    else 
    {
      digitalWrite(Relay3,LOW);
      val3=0;
    }
    delay(200);
    }


    if (readData=="geyser")
    {
      val5=digitalRead(Relay5);
      if(val5==0)
      {
       digitalWrite(Relay5,HIGH);
       val5=1;
    }
    else 
    {
      digitalWrite(Relay5,LOW);
      val5=0;
    }
    delay(200);
    }



    if (readData=="door")
    {
      val6=digitalRead(Relay6);
      if(val6==0)
      {
       digitalWrite(Relay6,HIGH);
       val6=1;
    }
    else 
    {
      digitalWrite(Relay6,LOW);
      val6=0;
    }
    delay(200); //delay of 200 millisecond
    }

    
    if (readData=="cloths")
    {
      val8=digitalRead(Relay8);
      if(val8==0)
      {
       digitalWrite(Relay8,HIGH);
       val8=1;
    }
    else 
    {
      digitalWrite(Relay8,LOW);
      val8=0;
    }
    delay(200);
    }


    
    if (readData=="fan")
    {
      val2=digitalRead(Relay2);
      if(val2==0)
      {
       digitalWrite(Relay2,HIGH);
       val2=1;
    }
    else 
    {
      digitalWrite(Relay2,LOW);
      val2=0;
    }
    delay(200);
    }


    
    if (readData=="window")
    {
      val7=digitalRead(Relay7);
      if(val7==0)
      {
       digitalWrite(Relay7,HIGH);
       val7=1;
    }
    else 
    {
      digitalWrite(Relay7,LOW);
      val7=0;
    }
    delay(200);
    }


    
    if (readData=="cctv")
    {
      val4=digitalRead(Relay4);
      if(val4==0)
      {
       digitalWrite(Relay4,HIGH);
       val4=1;
    }
    else 
    {
      digitalWrite(Relay4,LOW);
      val4=0;
    }
    delay(200);
    }

    readData="";
    }
      
    }
