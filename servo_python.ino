int incomingByte = 0;
#include <Servo.h>

Servo myservo;

int pos = 0;
void setup(){
  Serial.begin(9600);
  myservo.attach(9);
}

void loop(){
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    Serial.print("I got: "); // ASCII printable characters
    Serial.println(incomingByte, DEC);
    for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees

      myservo.write(pos);
      delay(15);
    }

    for (pos = 90; pos >= 0; pos -= 1){
      myservo.write(pos);
      delay(15);
    }
    delay(5000);
    for (pos = 0; pos <= 90; pos += 1) {
      myservo.write(pos);
      delay(15);
    }
  }
}
