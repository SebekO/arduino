    #include <Adafruit_NeoPixel.h>
     
    #define PIN 6
    #define LICZBADIOD 16
    
     
    Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LICZBADIOD, PIN, NEO_GRB + NEO_KHZ800);
     
    void setup()
    {
      pinMode(2, INPUT);
      pixels.begin(); // Inicjalizacja biblioteki
    }
     
    void loop()
    {
            pixels.clear();

      if(digitalRead(2)==HIGH)
      {
      pixels.clear();
      pixels.setBrightness(200);
      pixels.setPixelColor(0, 255, 0, 0);
      pixels.setPixelColor(1, 255, 0, 0);
      pixels.setPixelColor(2, 255, 0, 0);
      pixels.setPixelColor(3, 255, 0, 0);
      pixels.setPixelColor(4, 255, 0, 0);
      pixels.setPixelColor(5, 255, 0, 0);
      pixels.setPixelColor(6, 255, 0, 0);
      pixels.setPixelColor(7, 255, 0, 0);
      pixels.setPixelColor(8, 255, 0, 0);
      pixels.setPixelColor(9, 255, 0, 0);
      pixels.setPixelColor(10, 255, 0, 0);
      pixels.setPixelColor(11, 255, 0, 0);
      pixels.setPixelColor(12, 255, 0, 0);
      pixels.setPixelColor(13, 255, 0, 0);
      pixels.setPixelColor(14, 255, 0, 0);
      pixels.setPixelColor(15, 255, 0, 0);
      pixels.setPixelColor(16, 255, 0, 0);
      pixels.setPixelColor(17, 255, 0, 0);
      pixels.setPixelColor(18, 255, 0, 0);
      pixels.setPixelColor(19, 255, 0, 0);
      pixels.setPixelColor(20, 255, 0, 0);
      pixels.setPixelColor(21, 255, 0, 0);
      pixels.setPixelColor(22, 255, 0, 0);
      pixels.setPixelColor(23, 255, 0, 0);
      pixels.show();
      }

//      if(digitalRead(2)==HIGH)
//      {  
//        int a=83,r=22,g=7,b=0;
//        pixels.clear();
//        pixels.setPixelColor(24, r, g, b);
//        pixels.setPixelColor(39, r, g, b);
//        delay(a);
//        pixels.show();
//        pixels.setPixelColor(25, 32, 9, b);
//        pixels.setPixelColor(38, 32, 9, b);
//        delay(a);
//        pixels.show();
//        pixels.setPixelColor(26, 52, 14, b);
//        pixels.setPixelColor(37, 52, 14, b);
//        delay(a);
//        pixels.show();
//        pixels.setPixelColor(27, 82, 24, b);
//        pixels.setPixelColor(36, 82, 24, b);
//        delay(a);
//        pixels.show();
//        pixels.setPixelColor(28, 112, 34, b);
//        pixels.setPixelColor(35, 112, 34, b);
//        delay(a);
//        pixels.show();
//        pixels.setPixelColor(29, 132, 44, b);
//        pixels.setPixelColor(34, 132, 44, b);
//        delay(a);
//        pixels.show();
//        pixels.setPixelColor(30, 162, 54, b);
//        pixels.setPixelColor(33, 162, 54, b);
//        delay(a);
//        pixels.show();
//        pixels.setPixelColor(31, 192, 64, b);
//        pixels.setPixelColor(32, 192, 64, b);
//        delay(a);
//        pixels.show();
//      }
//      
//      if(digitalRead(3)==HIGH)
//      {
//        pixels.setBrightness(255);
//        pixels.setPixelColor(40, 255, 0, 0);
//        pixels.setPixelColor(41, 255, 0, 0);
//        pixels.setPixelColor(42, 255, 0, 0);
//        pixels.setPixelColor(43, 255, 0, 0);
//        pixels.setPixelColor(44, 255, 0, 0);
//        pixels.setPixelColor(45, 255, 0, 0);
//        pixels.setPixelColor(46, 255, 0, 0);
//        pixels.setPixelColor(47, 255, 0, 0);
//        pixels.setPixelColor(48, 255, 0, 0);
//        pixels.setPixelColor(49, 255, 0, 0);
//        pixels.setPixelColor(50, 255, 0, 0);
//        pixels.setPixelColor(51, 255, 0, 0);
//        pixels.clear();
//      }    
 
      pixels.clear();
    }

