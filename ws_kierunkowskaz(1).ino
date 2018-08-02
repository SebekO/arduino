#include <Adafruit_NeoPixel.h>
 
#define PIN 6
#define LICZBADIOD 16
 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LICZBADIOD, PIN, NEO_GRB + NEO_KHZ800);
 
void setup()
{
 int czaswlanczania=50;
 pixels.begin(); // Inicjalizacja biblioteki
 pinMode(1, INPUT_PULLUP);
 pinMode(2, INPUT_PULLUP);
 pinMode(3, INPUT_PULLUP);
 pinMode(4, INPUT_PULLUP);

    pixels.setBrightness(100);
    pixels.setPixelColor(0, 255, 0,0);
    delay(czaswlanczania);
    pixels.show();
    pixels.setPixelColor(15, 255,  0,0);
    delay(czaswlanczania);
    pixels.show();
    pixels.setPixelColor(1, 255,  0,0);
    delay(czaswlanczania);
    pixels.show();
    pixels.setPixelColor(14, 255,  0,0);
    delay(czaswlanczania);
    pixels.show();
    pixels.setPixelColor(2, 255,  0,0);
    delay(czaswlanczania);
    pixels.show();
    pixels.setPixelColor(13, 255,  0,0);
    delay(czaswlanczania);
    pixels.show();
    pixels.setPixelColor(3, 255,  0,0);
    delay(czaswlanczania);
    pixels.show();
    pixels.setPixelColor(12, 255,  0,0);
    delay(czaswlanczania);
    pixels.show();
    pixels.setPixelColor(4, 255,  0,0);
    delay(czaswlanczania);
    pixels.show();
    pixels.setPixelColor(11, 255,  0,0);
    delay(czaswlanczania);
    pixels.show();
    pixels.setPixelColor(5, 255,  0,0);
    delay(czaswlanczania);
    pixels.show();
    pixels.setPixelColor(10, 255,  0,0);
    delay(czaswlanczania);
    pixels.show();
    pixels.setPixelColor(6, 255,  0,0);
    delay(czaswlanczania);
    pixels.show();
    pixels.setPixelColor(9, 255,  0,0);
    delay(czaswlanczania);
    pixels.show();
    pixels.setPixelColor(7, 255,  0,0);
    delay(czaswlanczania);
    pixels.show();
    pixels.setPixelColor(8, 255,  0,0);
    delay(czaswlanczania);
    pixels.show();
    
 
 
}
 
void loop()
{
  int r=150,g,b;
    pixels.setBrightness(100);
    pixels.setPixelColor(0, r,g,b);
    pixels.setPixelColor(1, r,g,b);
    pixels.setPixelColor(2, r,g,b);
    pixels.setPixelColor(3, r,g,b);
    pixels.setPixelColor(4, r,g,b);
    pixels.setPixelColor(5, r,g,b);
    pixels.setPixelColor(6, r,g,b);
    pixels.setPixelColor(7, r,g,b);
    pixels.setPixelColor(8, r,g,b);
    pixels.setPixelColor(9, r,g,b);
    pixels.setPixelColor(10, r,g,b);
    pixels.setPixelColor(11, r,g,b);
    pixels.setPixelColor(12, r,g,b);
    pixels.setPixelColor(13, r,g,b);
    pixels.setPixelColor(14, r,g,b);
    pixels.setPixelColor(15, r,g,b);
    pixels.setPixelColor(16, r,g,b);
     
      if(digitalRead(1)==LOW)
    {
      pixels.setBrightness(255);
      pixels.show();
    }
    if(digitalRead(2)==LOW)
    {
      for(int a;a<LICZBADIOD;a++)
      {
        int r=192,g=64,b;
        pixels.clear();
        pixels.setBrightness(100);
        pixels.setPixelColor(0, r,g,b);
        pixels.setPixelColor(1, r,g,b);
        pixels.setPixelColor(2, r,g,b);
        pixels.setPixelColor(3, r,g,b);
        pixels.setPixelColor(4, r,g,b);
        pixels.setPixelColor(5, r,g,b);
        pixels.setPixelColor(6, r,g,b);
        pixels.setPixelColor(7, r,g,b);
        pixels.setPixelColor(8, r,g,b);
        pixels.setPixelColor(9, r,g,b);
        pixels.setPixelColor(10, r,g,b);
        pixels.setPixelColor(11, r,g,b);
        pixels.setPixelColor(12, r,g,b);
        pixels.setPixelColor(13, r,g,b);
        pixels.setPixelColor(14, r,g,b);
        pixels.setPixelColor(15, r,g,b);
        pixels.setPixelColor(16, r,g,b);
        pixels.setPixelColor(a, 0, 0,0);
        pixels.setPixelColor(a+1, 0, 0,0);
        pixels.show();
        delay(66);      
      }
    }
    if(digitalRead(3)==LOW)
    {
        int r=255,g=255,b=255;
        pixels.setBrightness(255);
        pixels.clear();
        pixels.setPixelColor(0, 60,0,0);
        pixels.setPixelColor(1, 60,0,0);
        pixels.setPixelColor(2, 60,0,0);
        pixels.setPixelColor(3, 60,0,0);
        pixels.setPixelColor(4, 60,0,0);
        pixels.setPixelColor(5, r,g,b);
        pixels.setPixelColor(6, r,g,b);
        pixels.setPixelColor(7, r,g,b);
        pixels.setPixelColor(8, r,g,b);
        pixels.setPixelColor(9, r,g,b);
        pixels.setPixelColor(10, r,g,b);
        pixels.setPixelColor(11, r,g,b);
        pixels.setPixelColor(12, r,g,b);
        pixels.setPixelColor(13, 60,0,0);
        pixels.setPixelColor(14, 60,0,0);
        pixels.setPixelColor(15, 60,0,0);
       
        pixels.show();

    }
    if(digitalRead(4)==LOW)
    {
    }
      
      
pixels.show();

   }
