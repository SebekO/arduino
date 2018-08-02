#include <Adafruit_NeoPixel.h>
 
#define PIN 8
#define LICZBADIOD 32
 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LICZBADIOD, PIN, NEO_GRB + NEO_KHZ800);
 
void setup()
{
  pixels.begin(); // Inicjalizacja biblioteki
}
 
void loop()
{
  int a=100;
int r=255,g,b;
  pixels.setBrightness(255);
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
pixels.show(); // Wysylamy dane do lancucha
delay(a); // Opoznienie 500ms przed zaswieceniem kolejnej diody 
pixels.clear();
pixels.show();
delay(a);
  pixels.setBrightness(255);
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
pixels.show(); // Wysylamy dane do lancucha
delay(a); // Opoznienie 500ms przed zaswieceniem kolejnej diody 
pixels.clear();
pixels.show();
delay(a); 
b=255;
r=0;
  pixels.setPixelColor(16, r,g,b);
  pixels.setPixelColor(17, r,g,b);
  pixels.setPixelColor(18, r,g,b);
  pixels.setPixelColor(19, r,g,b);
  pixels.setPixelColor(20, r,g,b);
  pixels.setPixelColor(21, r,g,b);
  pixels.setPixelColor(22, r,g,b);
  pixels.setPixelColor(23, r,g,b);
  pixels.setPixelColor(24, r,g,b);
  pixels.setPixelColor(25, r,g,b);
  pixels.setPixelColor(26, r,g,b);
  pixels.setPixelColor(27, r,g,b);
  pixels.setPixelColor(28, r,g,b);
  pixels.setPixelColor(29, r,g,b);
  pixels.setPixelColor(30, r,g,b);
  pixels.setPixelColor(31, r,g,b);
  pixels.show(); // Wysylamy dane do lancucha
delay(a); // Opoznienie 500ms przed zaswieceniem kolejnej diody 
pixels.clear();
pixels.show();
delay(a); 
  pixels.setPixelColor(16, r,g,b);
  pixels.setPixelColor(17, r,g,b);
  pixels.setPixelColor(18, r,g,b);
  pixels.setPixelColor(19, r,g,b);
  pixels.setPixelColor(20, r,g,b);
  pixels.setPixelColor(21, r,g,b);
  pixels.setPixelColor(22, r,g,b);
  pixels.setPixelColor(23, r,g,b);
  pixels.setPixelColor(24, r,g,b);
  pixels.setPixelColor(25, r,g,b);
  pixels.setPixelColor(26, r,g,b);
  pixels.setPixelColor(27, r,g,b);
  pixels.setPixelColor(28, r,g,b);
  pixels.setPixelColor(29, r,g,b);
  pixels.setPixelColor(30, r,g,b);
  pixels.setPixelColor(31, r,g,b);
  pixels.show(); // Wysylamy dane do lancucha
delay(a); // Opoznienie 500ms przed zaswieceniem kolejnej diody 
pixels.clear();
pixels.show();
delay(a); 
}
