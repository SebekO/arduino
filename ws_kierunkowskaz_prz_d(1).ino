#include <Adafruit_NeoPixel.h>
 
#define PIN 6
#define LICZBADIOD 16
 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LICZBADIOD, PIN, NEO_GRB + NEO_KHZ800);
 
void setup()
{
 pixels.begin(); // Inicjalizacja biblioteki
 pinMode(2, INPUT_PULLUP);
 pinMode(1, INPUT_PULLUP);
}
 
void loop()
{
  pixels.setBrightness(100);
    pixels.setPixelColor(0, 255, 255, 255);
    pixels.setPixelColor(1, 255, 255, 255);
    pixels.setPixelColor(2, 255, 255, 255);
    pixels.setPixelColor(3, 255, 255, 255);
    pixels.setPixelColor(4, 255, 255, 255);
    pixels.setPixelColor(5, 255, 255, 255);
    pixels.setPixelColor(6, 255, 255, 255);
    pixels.setPixelColor(7, 255, 255, 255);
    pixels.setPixelColor(8, 255, 255, 255);
    pixels.setPixelColor(9, 255, 255, 255);
    pixels.setPixelColor(10, 255, 255, 255);
    pixels.setPixelColor(11, 255, 255, 255);
    pixels.setPixelColor(12, 255, 255, 255);
    pixels.setPixelColor(13, 255, 255, 255);
    pixels.setPixelColor(14, 255, 255, 255);
    pixels.setPixelColor(15, 255, 255, 255);
    pixels.setPixelColor(16, 255, 255, 255);
      pixels.show();
    if(digitalRead(2)==LOW)
    {pixels.setBrightness(500);
    pixels.show();}
     if(digitalRead(1)==LOW){
     pixels.setBrightness(500);
    pixels.setPixelColor(0, 192,64,0);
    pixels.setPixelColor(1, 192,64,0);
    pixels.setPixelColor(2, 192,64,0);
    pixels.setPixelColor(3, 192,64,0);
    pixels.setPixelColor(4, 192,64,0);
    pixels.setPixelColor(5, 192,64,0);
    pixels.setPixelColor(6, 192,64,0);
    pixels.setPixelColor(7, 192,64,0);
    pixels.setPixelColor(8, 192,64,0);
    pixels.setPixelColor(9,192,64,0);
    pixels.setPixelColor(10, 192,64,0);
    pixels.setPixelColor(11, 192,64,0);
    pixels.setPixelColor(12, 192,64,0);
    pixels.setPixelColor(13, 192,64,0);
    pixels.setPixelColor(14, 192,64,0);
    pixels.setPixelColor(15, 192,64,0);
    pixels.setPixelColor(16, 192,64,0);
      pixels.show();
   delay(666);
   pixels.setBrightness(100);
    pixels.setPixelColor(0, 255, 255, 255);
    pixels.setPixelColor(1, 255, 255, 255);
    pixels.setPixelColor(2, 255, 255, 255);
    pixels.setPixelColor(3, 255, 255, 255);
    pixels.setPixelColor(4, 255, 255, 255);
    pixels.setPixelColor(5, 255, 255, 255);
    pixels.setPixelColor(6, 255, 255, 255);
    pixels.setPixelColor(7, 255, 255, 255);
    pixels.setPixelColor(8, 255, 255, 255);
    pixels.setPixelColor(9, 255, 255, 255);
    pixels.setPixelColor(10, 255, 255, 255);
    pixels.setPixelColor(11, 255, 255, 255);
    pixels.setPixelColor(12, 255, 255, 255);
    pixels.setPixelColor(13, 255, 255, 255);
    pixels.setPixelColor(14, 255, 255, 255);
    pixels.setPixelColor(15, 255, 255, 255);
    pixels.setPixelColor(16, 255, 255, 255);
      pixels.show();
    delay(666);
     pixels.setBrightness(500);
    pixels.setPixelColor(0, 192,64,0);
    pixels.setPixelColor(1, 192,64,0);
    pixels.setPixelColor(2, 192,64,0);
    pixels.setPixelColor(3, 192,64,0);
    pixels.setPixelColor(4, 192,64,0);
    pixels.setPixelColor(5, 192,64,0);
    pixels.setPixelColor(6, 192,64,0);
    pixels.setPixelColor(7, 192,64,0);
    pixels.setPixelColor(8, 192,64,0);
    pixels.setPixelColor(9,192,64,0);
    pixels.setPixelColor(10, 192,64,0);
    pixels.setPixelColor(11, 192,64,0);
    pixels.setPixelColor(12, 192,64,0);
    pixels.setPixelColor(13, 192,64,0);
    pixels.setPixelColor(14, 192,64,0);
    pixels.setPixelColor(15, 192,64,0);
    pixels.setPixelColor(16, 192,64,0);
    pixels.show();
       
//       for(int led=1; led<16;led++)
//    pixels.setBrightness(50);
//    pixels.show();
//    pixels.setPixelColor(led, 192,64,0);
//     delay(100);
     
//    delay(100);
//    pixels.setPixelColor(8-i, 255,0,0);
//    pixels.show();
 }

    pixels.show(); // Wysylamy dane do lancucha
    
   
}
