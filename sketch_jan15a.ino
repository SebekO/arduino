void setup() {
Serial.begin(9600);
  while (!Serial) {
    ;
  }
  // put your setup code here, to run once:
pinMode(A0, INPUT);
pinMode(1, INPUT);
}

void loop() {
  int a = analogRead(A0);
  Serial.println(a);
  delay(100);
//  int b = digitalRead(7);
//  Serial.println(b);
  // put your main code here, to run repeatedly:

}
