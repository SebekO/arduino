#include <SPI.h>
#include <RFID.h>
#include <Adafruit_NeoPixel.h>
 
#define PIN 2
#define LICZBADIOD 32
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LICZBADIOD, PIN, NEO_GRB + NEO_KHZ800);
#define SS_PIN 7
#define RST_PIN 6
RFID rfid(SS_PIN, RST_PIN); 


// Setup variables:
    int serNum0;
    int serNum1;
    int serNum2;
    int serNum3;
    int serNum4;

int caly;
void setup()
{ 
  Serial.begin(9600);
  delay(2000);
  SPI.begin(); 
  rfid.init();
  pixels.begin();
  pinMode(7, OUTPUT); 
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT);
  pixels.setBrightness(50);

}

void loop()
{
    
    if (rfid.isCard()) {
        if (rfid.readCardSerial()) {
            if (rfid.serNum[0] != serNum0
                && rfid.serNum[1] != serNum1
                && rfid.serNum[2] != serNum2
                && rfid.serNum[3] != serNum3
                && rfid.serNum[4] != serNum4
            ) {
                /* With a new cardnumber, show it. */
                Serial.println(" ");
                Serial.println("Wykryto karte");
                serNum0 = rfid.serNum[0];
                serNum1 = rfid.serNum[1];
                serNum2 = rfid.serNum[2];
                serNum3 = rfid.serNum[3];
                serNum4 = rfid.serNum[4];
               
                //Serial.println(" ");
                Serial.println("Numer karty:");
                Serial.print("Dziesietnie: ");
		Serial.print(rfid.serNum[0],DEC);
                Serial.print(", ");
		Serial.print(rfid.serNum[1],DEC);
                Serial.print(", ");
		Serial.print(rfid.serNum[2],DEC);
                Serial.print(", ");
		Serial.print(rfid.serNum[3],DEC);
                Serial.print(", ");
		Serial.print(rfid.serNum[4],DEC);
                Serial.println(" ");
                        
                Serial.print("Szesnastkowo: ");
		Serial.print(rfid.serNum[0],HEX);
                Serial.print(", ");
		Serial.print(rfid.serNum[1],HEX);
                Serial.print(", ");
		Serial.print(rfid.serNum[2],HEX);
                Serial.print(", ");
		Serial.print(rfid.serNum[3],HEX);
                Serial.print(", ");
		Serial.print(rfid.serNum[4],HEX);
                Serial.println(" ");
                caly = serNum0 + serNum1 + serNum2 + serNum3 + serNum4;
                Serial.print("Suma(dziesietna): ");
                Serial.print(caly);          
   
            }
             if (caly== 640){
               digitalWrite(7, HIGH);
               for(int i=0; i<LICZBADIOD; i++){
               pixels.setPixelColor(i, 0, 0, 255); // Dioda "i" oraz skladowe R=255 G=0 B=0
               pixels.show(); // Wysylamy dane do lancucha
               } 
               delay(1200);
               digitalWrite(7, LOW);
             }
             if (caly== 530){
               digitalWrite(4, HIGH);
               for(int i=0; i<LICZBADIOD; i++){
               pixels.setPixelColor(i, 255, 0, 0); // Dioda "i" oraz skladowe R=255 G=0 B=0
               pixels.show(); // Wysylamy dane do lancucha
               } 
               delay(1200);
               digitalWrite(4, LOW);
             }
             if (caly== 396){
               digitalWrite(5, HIGH);
               for(int i=0; i<LICZBADIOD; i++){
               pixels.setPixelColor(i, 0, 255, 0); // Dioda "i" oraz skladowe R=255 G=0 B=0
               pixels.show(); // Wysylamy dane do lancucha
               }
               delay(1200);
               digitalWrite(5, LOW);
             }
             
          }
    }
    rfid.halt();
}
