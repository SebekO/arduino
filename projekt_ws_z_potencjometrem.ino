#include <Adafruit_NeoPixel.h>
 
#define PIN 6
#define LICZBADIOD 16

 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LICZBADIOD, PIN, NEO_GRB + NEO_KHZ800);
 
void setup()
{
  pixels.begin(); // Inicjalizacja biblioteki
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
}
 
void loop()
{
//     int ilosc = analogRead(0);
//     int jasnosc = analogRead(1);
//     ilosc = map(ilosc, 0, 1023, 0, 20);
//     jasnosc = map(jasnosc, 0, 1023, 0, 255);
//     pixels.setPixelColor(ilosc, 255, 0, 0);
//     pixels.setBrightness(jasnosc);
//     pixels.show();
pixels.setBrightness(100);
    pixels.setPixelColor(0, 255, 0,0);
    pixels.setPixelColor(1, 255,  0,0);
    pixels.setPixelColor(2, 255,  0,0);
    pixels.setPixelColor(3, 255,  0,0);
    pixels.setPixelColor(4, 255,  0,0);
    pixels.setPixelColor(5, 255,  0,0);
    pixels.setPixelColor(6, 255,  0,0);
    pixels.setPixelColor(7, 255,  0,0);
    pixels.setPixelColor(8, 255,  0,0);
    pixels.setPixelColor(9, 255,  0,0);
    pixels.setPixelColor(10, 255,  0,0);
    pixels.setPixelColor(11, 255,  0,0);
    pixels.setPixelColor(12, 255,  0,0);
    pixels.setPixelColor(13, 255,  0,0);
    pixels.setPixelColor(14, 255,  0,0);
    pixels.setPixelColor(15, 255,  0,0);
    pixels.setPixelColor(16, 255,  0,0);
     if(digitalRead(1)==LOW){
    pixels.setPixelColor(0, 192,64,0);
    pixels.setPixelColor(1, 192,64,0);
    pixels.setPixelColor(2, 192,64,0);
    pixels.setPixelColor(3, 192,64,0);
    pixels.setPixelColor(4, 192,64,0);
    pixels.setPixelColor(5, 192,64,0);
    pixels.setPixelColor(6, 192,64,0);
    pixels.setPixelColor(7, 192,64,0);
    pixels.show();
    delay(666);
    pixels.setPixelColor(0, 255, 0,0);
    pixels.setPixelColor(1, 255,  0,0);
    pixels.setPixelColor(2, 255,  0,0);
    pixels.setPixelColor(3, 255,  0,0);
    pixels.setPixelColor(4, 255,  0,0);
    pixels.setPixelColor(5, 255,  0,0);
    pixels.setPixelColor(6, 255,  0,0);
    pixels.setPixelColor(7, 255,  0,0);
    pixels.show();
    delay(666);
        }
        if(digitalRead(2)==LOW){
    pixels.setPixelColor(0, 192,64,0);
    pixels.setPixelColor(1, 192,64,0);
    pixels.setPixelColor(2, 192,64,0);
    pixels.setPixelColor(3, 192,64,0);
    pixels.setPixelColor(4, 192,64,0);
    pixels.setPixelColor(5, 192,64,0);
    pixels.setPixelColor(6, 192,64,0);
    pixels.setPixelColor(7, 192,64,0);
    pixels.show();
    delay(666);
    pixels.setPixelColor(0, 0, 0,0);
    pixels.setPixelColor(1, 0,  0,0);
    pixels.setPixelColor(2, 0,  0,0);
    pixels.setPixelColor(3, 0,  0,0);
    pixels.setPixelColor(4, 0,  0,0);
    pixels.setPixelColor(5, 0,  0,0);
    pixels.setPixelColor(6, 0,  0,0);
    pixels.setPixelColor(7, 0,  0,0);
    pixels.show();
    delay(666);
        }
        if(digitalRead(3)==LOW){
          for(int i=0;i<16;i++){
    pixels.setPixelColor(i, 192,64,0);
    pixels.setPixelColor(i+1, 192,64,0);
    pixels.setPixelColor(i+2, 192,64,0);
   

    pixels.show();
    delay(100);
    pixels.setPixelColor(i, 0, 0,0);
    pixels.show();
    delay(100);
        }}
        if(digitalRead(4)==LOW)
    {pixels.setBrightness(255);
    pixels.show();}
      pixels.show();

      
       
   
   
}
