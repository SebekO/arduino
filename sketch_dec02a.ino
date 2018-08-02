void setup() {
  pinMode(A0, OUTPUT);
 Serial.begin(9600);
  while (!Serial) {
}
}

void loop() {
int var=analogRead(1);
delay(1000);
Serial.print("Analog 1: ");
   Serial.println(var);
   analogWrite(0, var);
   Serial.print("Analog 0: ");
   Serial.println(analogRead(0));


}

