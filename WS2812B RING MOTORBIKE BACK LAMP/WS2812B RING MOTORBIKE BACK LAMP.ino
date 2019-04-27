#include <Adafruit_NeoPixel.h>
 
#define PIN 8
#define LICZBADIOD 32
int kier=100;
int r=100,g,b;
int pamiec;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LICZBADIOD, PIN, NEO_GRB + NEO_KHZ800);


void setup()
{ 
 pixels.begin(); // Inicjalizacja biblioteki
 pinMode(7, INPUT_PULLUP); // przycisk stopu
 pinMode(2, INPUT_PULLUP); // przycisk kierunkowskazu L
 pinMode(3, INPUT_PULLUP); // przycisk kierunkowskazu P
 _start();

}
void _start(){  
  int czaswlanczania=50;  
  pixels.setBrightness(100);
  pixels.setPixelColor(0, 100, 0,0);
  pixels.setPixelColor(16, 100, 0,0);
  delay(czaswlanczania);
  pixels.show();
  pixels.setPixelColor(15, 100,  0,0);
  pixels.setPixelColor(31, 100,  0,0);
  delay(czaswlanczania);
  pixels.show();
  pixels.setPixelColor(1, 100,  0,0);
  pixels.setPixelColor(17, 100,  0,0);
  delay(czaswlanczania);
  pixels.show();
  pixels.setPixelColor(14, 100,  0,0);
  pixels.setPixelColor(30, 100,  0,0);
  delay(czaswlanczania);
  pixels.show();
  pixels.setPixelColor(2, 100,  0,0);
  pixels.setPixelColor(18, 100,  0,0);
  delay(czaswlanczania);
  pixels.show();
  pixels.setPixelColor(13, 100,  0,0);
  pixels.setPixelColor(29, 100,  0,0);
  delay(czaswlanczania);
  pixels.show();
  pixels.setPixelColor(3, 100,  0,0);
  pixels.setPixelColor(19, 100,  0,0);
  delay(czaswlanczania);
  pixels.show();
  pixels.setPixelColor(12, 100,  0,0);
  pixels.setPixelColor(28, 100,  0,0);
  delay(czaswlanczania);
  pixels.show();
  pixels.setPixelColor(4, 100,  0,0);
  pixels.setPixelColor(20, 100,  0,0);
  delay(czaswlanczania);
  pixels.show();
  pixels.setPixelColor(11, 100,  0,0);
  pixels.setPixelColor(27, 100,  0,0);
  delay(czaswlanczania);
  pixels.show();
  pixels.setPixelColor(5, 100,  0,0);
  pixels.setPixelColor(21, 100,  0,0);
  delay(czaswlanczania);
  pixels.show();
  pixels.setPixelColor(10, 100,  0,0);
  pixels.setPixelColor(26, 100,  0,0);
  delay(czaswlanczania);
  pixels.show();
  pixels.setPixelColor(6, 100,  0,0);
  pixels.setPixelColor(22, 100,  0,0);
  delay(czaswlanczania);
  pixels.show();
  pixels.setPixelColor(9, 100,  0,0);
  pixels.setPixelColor(25, 100,  0,0);
  delay(czaswlanczania);
  pixels.show();
  pixels.setPixelColor(7, 100,  0,0);
  pixels.setPixelColor(23, 100,  0,0);
  delay(czaswlanczania);
  pixels.show();
  pixels.setPixelColor(8, 100,  0,0);
  pixels.setPixelColor(24, 100,  0,0);
  delay(czaswlanczania);
  pixels.show(); 
}
void loop(){
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
  
  if(digitalRead(7)==LOW) //stop
  {
    _stop();
  }
  if(digitalRead(2)==LOW) //lewy kierunek
  {
    l_kierunek();
  }
  
  if(digitalRead(3)==LOW) //prawy kierunek
  {        
    p_kierunek();  
  } 
  pixels.show();

 }
 
void _stop(){
  r=255;
  pixels.setBrightness(255);
  pixels.show();

}

void l_kierunek(){
    for(int i = 1; i <= 10; i++ ){
    pixels.clear();
    pixels.setPixelColor(16, 255,g,b);
    pixels.setPixelColor(17, 255,g,b);
    pixels.setPixelColor(18, 255,g,b);
    pixels.setPixelColor(19, 255,g,b);
    pixels.setPixelColor(20, 255,g,b);
    pixels.setPixelColor(21, 255,g,b);
    pixels.setPixelColor(22, 255,g,b);
    pixels.setPixelColor(23, 255,g,b);
    pixels.setPixelColor(24, 255,g,b);
    pixels.setPixelColor(25, 255,g,b);
    pixels.setPixelColor(26, 255,g,b);
    pixels.setPixelColor(27, 255,g,b);
    pixels.setPixelColor(28, 255,g,b);
    pixels.setPixelColor(29, 255,g,b);
    pixels.setPixelColor(30, 255,g,b);
    pixels.setPixelColor(31, 255,g,b);
    int r=192,g=64,b;
    pixels.setBrightness(255);
    pixels.setPixelColor(11, r,g,b);
    pixels.setPixelColor(12, r,g,b);
    pixels.show();
    delay(kier);
    pixels.setPixelColor(10, r,g,b);
    pixels.setPixelColor(13, r,g,b);
    pixels.show();
    delay(kier);
    pixels.setPixelColor(9, r,g,b);
    pixels.setPixelColor(14, r,g,b);
    pixels.show();
    delay(kier);
    pixels.setPixelColor(8, r,g,b);
    pixels.setPixelColor(15, r,g,b);
    pixels.show();
    delay(kier);
    pixels.setPixelColor(7, r,g,b);
    pixels.setPixelColor(0, r,g,b);
    pixels.show();
    delay(kier);
    pixels.setPixelColor(6, r,g,b);
    pixels.setPixelColor(1, r,g,b);
    pixels.show();
    delay(kier);
    pixels.setPixelColor(5, r,g,b);
    pixels.setPixelColor(2, r,g,b);
    pixels.show();
    delay(kier);
    pixels.setPixelColor(4, r,g,b);
    pixels.setPixelColor(3, r,g,b);
    pixels.show();
    delay(kier);
      if(digitalRead(7)==LOW) //stop
  {
      r=255;
  pixels.setBrightness(255);
  pixels.show();
  }
  }
}

void p_kierunek(){
  for(int i = 1; i <= 10; i++ ){
    pixels.clear();
    pixels.setPixelColor(0, 255,g,b);
    pixels.setPixelColor(1, 255,g,b);
    pixels.setPixelColor(2, 255,g,b);
    pixels.setPixelColor(3, 255,g,b);
    pixels.setPixelColor(4, 255,g,b);
    pixels.setPixelColor(5, 255,g,b);
    pixels.setPixelColor(6, 255,g,b);
    pixels.setPixelColor(7, 255,g,b);
    pixels.setPixelColor(8, 255,g,b);
    pixels.setPixelColor(9, 255,g,b);
    pixels.setPixelColor(10, 255,g,b);
    pixels.setPixelColor(11, 255,g,b);
    pixels.setPixelColor(12, 255,g,b);
    pixels.setPixelColor(13, 255,g,b);
    pixels.setPixelColor(14, 255,g,b);
    pixels.setPixelColor(15, 255,g,b);
    int r=192,g=64,b;
    pixels.setBrightness(255);
    pixels.setPixelColor(19, r,g,b);
    pixels.setPixelColor(20, r,g,b);
    pixels.show();
    delay(kier);
    pixels.setPixelColor(18, r,g,b);
    pixels.setPixelColor(21, r,g,b);
    pixels.show();
    delay(kier);
    pixels.setPixelColor(17, r,g,b);
    pixels.setPixelColor(22, r,g,b);
    pixels.show();
    delay(kier);
    pixels.setPixelColor(16, r,g,b);
    pixels.setPixelColor(23, r,g,b);
    pixels.show();
    delay(kier);
    pixels.setPixelColor(31, r,g,b);
    pixels.setPixelColor(24, r,g,b);
    pixels.show();
    delay(kier);
    pixels.setPixelColor(30, r,g,b);
    pixels.setPixelColor(25, r,g,b);
    pixels.show();
    delay(kier);
    pixels.setPixelColor(29, r,g,b);
    pixels.setPixelColor(26, r,g,b);
    pixels.show();
    delay(kier);
    pixels.setPixelColor(28, r,g,b);
    pixels.setPixelColor(27, r,g,b);
    pixels.show();
    delay(kier);
      if(digitalRead(7)==LOW) //stop
  {
      r=255;
  pixels.setBrightness(255);
  pixels.show();
  }
 }
}


 
