void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
}

void loop() {
LOW=HIGH
  if(digitalRead(1)==LOW){
   Serial.print("Przycisk ");
   Serial.print(1);
   Serial.println(" jest wciesniety");
  }
 if(digitalRead(2)==LOW){
   Serial.print("Przycisk ");
   Serial.print(2);
   Serial.println(" jest wciesniety");
  }
   if(digitalRead(3)==LOW){
   Serial.print("Przycisk ");
   Serial.print(3);
   Serial.println(" jest wciesniety");
  }
   if(digitalRead(4)==LOW){
   Serial.print("Przycisk ");
   Serial.print(4);
   Serial.println(" jest wciesniety");
  }
   if(digitalRead(5)==LOW){
   Serial.print("Przycisk ");
   Serial.print(5);
   Serial.println(" jest wciesniety");
  }
   if(digitalRead(6)==LOW){
   Serial.print("Przycisk ");
   Serial.print(6);
   Serial.println(" jest wciesniety");
  }
   if(digitalRead(7)==LOW){
   Serial.print("Przycisk ");
   Serial.print(7);
   Serial.println(" jest wciesniety");
  }
   if(digitalRead(8)==LOW){
   Serial.print("Przycisk ");
   Serial.print(8);
   Serial.println(" jest wciesniety");
  }
   if(digitalRead(9)==LOW){
   Serial.print("Przycisk ");
   Serial.print(9);
   Serial.println(" jest wciesniety");
  }
   if(digitalRead(10)==LOW){
   Serial.print("Przycisk ");
   Serial.print(10);
   Serial.println(" jest wciesniety");
  }
   if(digitalRead(11)==LOW){
   Serial.print("Przycisk ");
   Serial.print(11);
   Serial.println(" jest wciesniety");
  }
  delay(1000);
}
