#include <Adafruit_NeoPixel.h>
 
#define PIN 6
#define LICZBADIOD 32
int r = 0, g = 0, b = 255;
int q = 25, w = 60;
 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LICZBADIOD, PIN, NEO_GRB + NEO_KHZ800);
 
void setup()
{
  pixels.begin(); // Inicjalizacja biblioteki

}
void loop()
{
 p();
 p();
 p();
 p();
 p();
 delay( w );
 p1();
 p1();
 p1();
 p1();
 p1();
     
}
void p(){
  pixels.setPixelColor( 0, r, g, b );
  pixels.setPixelColor( 1, r, g, b );
  pixels.setPixelColor( 2, r, g, b );
  pixels.setPixelColor( 3, r, g, b );
  pixels.setPixelColor( 4, r, g, b );
  pixels.setPixelColor( 5, r, g, b );
  pixels.setPixelColor( 6, r, g, b );
  pixels.setPixelColor( 7, r, g, b );
  pixels.setPixelColor( 8, r, g, b );
  pixels.setPixelColor( 9, r, g, b );
  pixels.setPixelColor( 10, r, g, b );
  pixels.setPixelColor( 11, r, g, b );
  pixels.setPixelColor( 12, r, g, b );
  pixels.setPixelColor( 13, r, g, b );
  pixels.setPixelColor( 14, r, g, b );
  pixels.setPixelColor( 15, r, g, b );
  pixels.show();
  delay( q );
  pixels.clear();
  pixels.show();
  delay( q );
}
void p1(){
  pixels.setPixelColor( 16, r, g, b );
  pixels.setPixelColor( 17, r, g, b );
  pixels.setPixelColor( 18, r, g, b );
  pixels.setPixelColor( 19, r, g, b );
  pixels.setPixelColor( 20, r, g, b );
  pixels.setPixelColor( 21, r, g, b );
  pixels.setPixelColor( 22, r, g, b );
  pixels.setPixelColor( 23, r, g, b );
  pixels.setPixelColor( 24, r, g, b );
  pixels.setPixelColor( 25, r, g, b );
  pixels.setPixelColor( 26, r, g, b );
  pixels.setPixelColor( 27, r, g, b );
  pixels.setPixelColor( 28, r, g, b );
  pixels.setPixelColor( 29, r, g, b );
  pixels.setPixelColor( 30, r, g, b );
  pixels.setPixelColor( 31, r, g, b );
  pixels.show();
  delay( q );
  pixels.clear();
  pixels.show();
  delay( q );
}
