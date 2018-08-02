
int licznik;
int klikacz = 0;


void setup()

{
  Serial.begin(9600);
  pinMode(klikacz, INPUT_PULLUP);

}

void loop()
{
  if(digitalRead(klikacz) == LOW)
  {
    delay(200);
    licznik++;
    Serial.println(licznik);
  }
}
