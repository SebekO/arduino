#include <SPI.h>
#include <RFID.h>
#include <Adafruit_NeoPixel.h>
 
#define PIN 6 // Pin data input LED
#define LICZBADIOD 16 // Number of LED
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LICZBADIOD, PIN, NEO_GRB + NEO_KHZ800);
#define SS_PIN 10
#define RST_PIN 9
RFID rfid(SS_PIN, RST_PIN); 


// Setup variables:
    int serNum0;
    int serNum1;
    int serNum2;
    int serNum3;
    int serNum4;

int all;
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
                Serial.println("Card found");
                serNum0 = rfid.serNum[0];
                serNum1 = rfid.serNum[1];
                serNum2 = rfid.serNum[2];
                serNum3 = rfid.serNum[3];
                serNum4 = rfid.serNum[4];
               
                //Serial.println(" ");
                Serial.println("Cardnumber:");
                Serial.print("Dec: ");
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
                        
                Serial.print("Hex: ");
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
                all = serNum0 + serNum1 + serNum2 + serNum3 + serNum4;
                Serial.print("Cardnumber(Dec:): ");
                Serial.print(all);          
   
            }
             if (all== 640){
               digitalWrite(7, HIGH);
               for(int i=0; i<LICZBADIOD; i++){
               pixels.setPixelColor(i, 0, 0, 255); // LED "i" and color R=255 G=0 B=0
               pixels.show(); // Sent data to LED
               } 
               delay(1200);
               digitalWrite(7, LOW);
             }
             if (all== 530){
               digitalWrite(4, HIGH);
               for(int i=0; i<LICZBADIOD; i++){
               pixels.setPixelColor(i, 255, 0, 0); // Dioda "i" and color R=255 G=0 B=0
               pixels.show(); // Sent data to LED
               } 
               delay(1200);
               digitalWrite(4, LOW);
             }
             if (all== 396){
               digitalWrite(5, HIGH);
               for(int i=0; i<LICZBADIOD; i++){
               pixels.setPixelColor(i, 0, 255, 0); // Dioda "i" and color R=255 G=0 B=0
               pixels.show(); // Sent data to LED
               }
               delay(1200);
               digitalWrite(5, LOW);
             }
             
          }
    }
    rfid.halt();
}



