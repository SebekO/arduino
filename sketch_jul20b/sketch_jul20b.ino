void setup() {
  // put your setup code here, to run once:
Serial4.begin(57600);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial4.print("pozdro");
  Serial.print("pozdro");

}
