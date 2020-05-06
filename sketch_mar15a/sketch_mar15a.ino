#include <SoftwareSerial.h>
static const int RXPin = 4, TXPin = 3;
SoftwareSerial ss(RXPin, TXPin);
void setup()  
{
  Serial.begin(115200);
 
  while (!Serial) { }
 
  ss.begin(9600);
}
 
void loop()
{
  if (ss.available())
  {
    Serial.write(ss.read());
  }

}
