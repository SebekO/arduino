#include <Adafruit_NeoPixel.h>
 
#define PIN 6
#define LICZBADIOD 32
int delay_kier=0, czaswlanczania=50;
int r, g, b;
int rStart = 100, gStart = 0, bStart = 0;
int rKier = 40, gKier = 0, bKier = 0;
int mstick;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LICZBADIOD, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin(); // Inicjalizacja biblioteki
 pinMode( 7, INPUT_PULLUP ); // przycisk stopu
 pinMode( 2, INPUT_PULLUP ); // przycisk kierunkowskazu P
 pinMode( 3, INPUT_PULLUP ); // przycisk kierunkowskazu L
 pinMode( 1, INPUT_PULLUP ); // przycisk wyłącznia kierunkowskazu
  _start();
  
   Serial.begin(9600);
  while (!Serial) {
    ;
  }
}

void _start() {  
  pixels.setBrightness( 100 );
  pixels.setPixelColor( 0, rStart, gStart, bStart );
  pixels.setPixelColor( 16, rStart, gStart, bStart );
  delay( czaswlanczania );
  pixels.show();
  pixels.setPixelColor( 15, rStart, gStart, bStart );
  pixels.setPixelColor( 31, rStart, gStart, bStart );
  delay( czaswlanczania );
  pixels.show();
  pixels.setPixelColor( 1, rStart, gStart, bStart );
  pixels.setPixelColor( 17, rStart, gStart, bStart );
  delay( czaswlanczania );
  pixels.show();
  pixels.setPixelColor( 14, rStart, gStart, bStart );
  pixels.setPixelColor( 30, rStart, gStart, bStart );
  delay( czaswlanczania );
  pixels.show();
  pixels.setPixelColor( 2, rStart,  gStart, bStart );
  pixels.setPixelColor( 18, rStart,  gStart, bStart );
  delay( czaswlanczania );
  pixels.show();
  pixels.setPixelColor( 13, rStart, gStart, bStart );
  pixels.setPixelColor( 29, rStart,  gStart, bStart );
  delay( czaswlanczania );
  pixels.show();
  pixels.setPixelColor( 3, rStart, gStart, bStart );
  pixels.setPixelColor( 19, rStart, gStart, bStart );
  delay( czaswlanczania );
  pixels.show();
  pixels.setPixelColor( 12, rStart, gStart, bStart );
  pixels.setPixelColor( 28, rStart, gStart, bStart );
  delay( czaswlanczania );
  pixels.show();
  pixels.setPixelColor( 4, rStart, gStart, bStart );
  pixels.setPixelColor( 20, rStart, gStart, bStart );
  delay( czaswlanczania );
  pixels.show();
  pixels.setPixelColor( 11, rStart, gStart, bStart );
  pixels.setPixelColor( 27, rStart, gStart, bStart );
  delay( czaswlanczania );
  pixels.show();
  pixels.setPixelColor( 5, rStart,  gStart, bStart );
  pixels.setPixelColor( 21, rStart,  gStart, bStart );
  delay( czaswlanczania );
  pixels.show();
  pixels.setPixelColor( 10, rStart, gStart, bStart );
  pixels.setPixelColor( 26, rStart, gStart, bStart );
  delay( czaswlanczania );
  pixels.show();
  pixels.setPixelColor( 6, 100, gStart, bStart );
  pixels.setPixelColor( 22, 100, gStart, bStart );
  delay( czaswlanczania );
  pixels.show();
  pixels.setPixelColor( 9, rStart, gStart, bStart );
  pixels.setPixelColor( 25, rStart, gStart, bStart );
  delay( czaswlanczania );
  pixels.show();
  pixels.setPixelColor(7, rStart, gStart, bStart);
  pixels.setPixelColor(23, rStart, gStart, bStart);
  delay(czaswlanczania);
  pixels.show();
  pixels.setPixelColor( 8, rStart, gStart, bStart );
  pixels.setPixelColor( 24, rStart, gStart, bStart );
  delay( czaswlanczania );
  pixels.show(); 
}

void loop() {
  if( digitalRead(7) == HIGH && digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(1) == LOW) {
    b = analogRead(A0);
    b = map( b, 0, 1023, 0, 255); 
    Serial.println(b);
  }
  if( digitalRead(7) == LOW && digitalRead(2) == HIGH && digitalRead(3) == HIGH ) { _stop();  Serial.println("STOP"); }  //stop  
  else if( digitalRead(3) == LOW ) { while( digitalRead(1) == LOW && digitalRead(2) == HIGH ) { l_kierunek(); Serial.println("LKIER"); } }  //lewy kierunek 
  else if( digitalRead(2) == LOW ) { while( digitalRead(1) == LOW && digitalRead(3) == HIGH ) { p_kierunek(); Serial.println("PKIER"); } } //prawy kierunek
  else {
    mstick = 0; 
    pixels.clear(); 
    r = 100;
    pixels.setBrightness(100);
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
  }
}

void _stop(){
  r = 255; g = 0; b = 0;
  pixels.setBrightness(255);
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
}

void p_kierunek() {
  pixels.setPixelColor( 16, rKier, g, b );
  pixels.setPixelColor( 17, rKier, g, b );
  pixels.setPixelColor( 18, rKier, g, b ); 
  pixels.setPixelColor( 19, rKier, g, b );
  pixels.setPixelColor( 20, rKier, g, b );
  pixels.setPixelColor( 21, rKier, g, b );
  pixels.setPixelColor( 22, rKier, g, b );
  pixels.setPixelColor( 23, rKier, g, b );
  pixels.setPixelColor( 24, rKier, g, b );
  pixels.setPixelColor( 25, rKier, g, b );
  pixels.setPixelColor( 26, rKier, g, b );
  pixels.setPixelColor( 27, rKier, g, b );
  pixels.setPixelColor( 28, rKier, g, b );
  pixels.setPixelColor( 29, rKier, g, b );
  pixels.setPixelColor( 30, rKier, g, b );
  pixels.setPixelColor( 31, rKier, g, b );
  pixels.show();
  rKier=40; g = 0; b = 0;
  int r=192,g=64,b;
  pixels.setBrightness(255);
  if( 00 == (mstick % 80) ) { pixels.setPixelColor( 11, r, g, b ); pixels.setPixelColor( 12, r, g, b ); pixels.show(); }
  if( 10 == (mstick % 80) ) { pixels.setPixelColor( 10, r, g, b ); pixels.setPixelColor( 13, r, g, b ); pixels.show(); }
  if( 20 == (mstick % 80) ) { pixels.setPixelColor( 9, r, g, b ); pixels.setPixelColor( 14, r, g, b ); pixels.show(); }
  if( 30 == (mstick % 80) ) { pixels.setPixelColor( 8, r, g, b ); pixels.setPixelColor( 15, r, g, b ); pixels.show(); }
  if( 40 == (mstick % 80) ) { pixels.setPixelColor( 7, r, g, b ); pixels.setPixelColor( 0, r, g, b ); pixels.show(); }
  if( 50 == (mstick % 80) ) { pixels.setPixelColor( 6, r, g, b ); pixels.setPixelColor( 1, r, g, b ); pixels.show(); }
  if( 60 == (mstick % 80) ) { pixels.setPixelColor( 5, r, g, b ); pixels.setPixelColor( 2, r, g, b ); pixels.show(); }
  if( 70 == (mstick % 80) ) { pixels.setPixelColor( 4, r, g, b ); pixels.setPixelColor( 3, r, g, b ); pixels.show(); pixels.clear(); }
  mDelay(1);
  if( digitalRead(7) == LOW ) rKier = 255;
  if( digitalRead(3) == LOW ) mstick = 0;
}

void l_kierunek() {
  pixels.setPixelColor(0, rKier,g,b);
  pixels.setPixelColor(1, rKier,g,b);
  pixels.setPixelColor(2, rKier,g,b);
  pixels.setPixelColor(3, rKier,g,b);
  pixels.setPixelColor(4, rKier,g,b);
  pixels.setPixelColor(5, rKier,g,b);
  pixels.setPixelColor(6, rKier,g,b);
  pixels.setPixelColor(7, rKier,g,b);
  pixels.setPixelColor(8, rKier,g,b);
  pixels.setPixelColor(9, rKier,g,b);
  pixels.setPixelColor(10, rKier,g,b);
  pixels.setPixelColor(11, rKier,g,b);
  pixels.setPixelColor(12, rKier,g,b);
  pixels.setPixelColor(13, rKier,g,b);
  pixels.setPixelColor(14, rKier,g,b);
  pixels.setPixelColor(15, rKier,g,b);
  pixels.show();
  rKier=40; g = 0; b = 0;
  int r=192,g=64,b;
  pixels.setBrightness(255);
  if( 00 == (mstick % 80) ) { pixels.setPixelColor( 19, r, g, b ); pixels.setPixelColor( 20, r, g, b ); pixels.show(); }
  if( 10 == (mstick % 80) ) { pixels.setPixelColor( 18, r, g, b ); pixels.setPixelColor( 21, r, g, b ); pixels.show(); }
  if( 20 == (mstick % 80) ) { pixels.setPixelColor( 17, r, g, b ); pixels.setPixelColor( 22, r, g, b ); pixels.show(); }
  if( 30 == (mstick % 80) ) { pixels.setPixelColor( 16, r, g, b ); pixels.setPixelColor( 23, r, g, b ); pixels.show(); }
  if( 40 == (mstick % 80) ) { pixels.setPixelColor( 31, r, g, b ); pixels.setPixelColor( 24, r, g, b ); pixels.show(); }
  if( 50 == (mstick % 80) ) { pixels.setPixelColor( 30, r, g, b ); pixels.setPixelColor( 25, r, g, b ); pixels.show(); }
  if( 60 == (mstick % 80) ) { pixels.setPixelColor( 29, r, g, b ); pixels.setPixelColor( 26, r, g, b ); pixels.show(); }
  if( 70 == (mstick % 80) ) { pixels.setPixelColor( 28, r, g, b ); pixels.setPixelColor( 27, r, g, b ); pixels.show(); pixels.clear(); }
  mDelay(1);
  if( digitalRead(7) == LOW ) rKier = 255;
  if( digitalRead(2) == LOW ) mstick = 0;
}

void mDelay( int ms) {
  
  while( ms-- ) {
    delay(1);
    
    mstick++;
    if( mstick > 79 ) mstick=0;
    Serial.println(mstick);
  }
}
