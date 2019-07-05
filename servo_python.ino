    
char incomingByte;
int count;
#include <Servo.h>

Servo myservo;

int pos = 0;
void setup()
{
  Serial.begin(9600);
  myservo.attach(9);
}

void loop()
{
  if (Serial.available() > 0) 
  {
    incomingByte = Serial.read();
    Serial.print("I got: "); // ASCII printable characters
    Serial.println(incomingByte, DEC);
    //count=0;
    if(incomingByte=='v') //recognised
    {
      count=count+5;
    }
    if(count%10==0 && count<=20)
    {
      for (pos = 0; pos <= 90; pos += 1) 
      { // goes from 0 degrees to 90 degrees
  
        myservo.write(pos);
        delay(15);
      }
  delay(700);
     for (pos = 90; pos >= 0; pos -= 1)
      {
        myservo.write(pos);
        delay(15);
      }
    if(count==20)
    {
      exit(0);
    }
      
    }
    
    
    else if(incomingByte=='x')  //not recognised
    {
      /*pos=0;
      myservo.write(pos);
      delay(15);*/
      exit(0);
    }
    //delay(5000);
    /*for (pos = 0; pos <= 90; pos += 1) 
    {
      myservo.write(pos);
      delay(15);
    }*/
   
  }
}
