char incomingByte;


void setup(){
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  
}

void loop(){
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    Serial.print("I got: "); // ASCII printable characters
    Serial.println(incomingByte, DEC);
    

    if(incomingByte=='v')
    {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1000);
    }
    else if(incomingByte=='x')
    {
      digitalWrite(LED_BUILTIN,LOW);
      delay(1000);
    }
  }
}
