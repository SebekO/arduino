#include <Wire.h>
#include <Time.h>
#include <DS1307RTC.h>
#include <Adafruit_NeoPixel.h>
#include <LiquidCrystal_I2C.h>
#define BACKLIGHT_PIN 3
LiquidCrystal_I2C  lcd(0x27,2,1,0,4,5,6,7);

const char *monthName[12] = {
  "Jan", "Feb", "Mar", "Apr", "May", "Jun",
  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};
 
#define PIN 6
#define LICZBADIOD 16
 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LICZBADIOD, PIN, NEO_GRB + NEO_KHZ800);
void setup() {
  lcd.begin(16, 2);
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
  Serial.begin(9600);
  while (!Serial) ; // wait for serial
  delay(200);
  pixels.begin();
  pixels.clear();
}

void loop() {
  tmElements_t tm;
int sekundy=tm.Second;
int minuty=tm.Minute;
int godziny=tm.Hour-12;
  if (RTC.read(tm)) {
    Serial.println(tm.Hour);
    Serial.write(':');
    Serial.println(tm.Minute);
    Serial.write(':');
    Serial.println(tm.Second);
    }
  pixels.setBrightness(10);
  sekundy=map(sekundy, 0, 59, 0, 15);
  minuty=map(minuty, 0, 59, 0, 15);
  Serial.println(sekundy);
  Serial.println(minuty);
  Serial.println(godziny);
  
     pixels.setPixelColor(15-sekundy, 255, 0, 0); // Dioda "i" oraz skladowe R=255 G=0 B=0
     pixels.setPixelColor(15-minuty, 0, 0, 255); // Dioda "i" oraz skladowe R=255 G=0 B=0
    switch (godziny){
    case 0:
      pixels.setPixelColor(0, 0, 255, 0);
      if(minuty==15){
        pixels.setPixelColor(0, 0, 255, 255);
        }
    break;
    case 1:
      pixels.setPixelColor(15, 0, 255, 0);
      pixels.setPixelColor(14, 0, 255, 0);
      if(minuty==0){
        pixels.setPixelColor(15, 0, 255, 255);
        }
      if(minuty==1){
        pixels.setPixelColor(14, 0, 255, 255);
        }     
    break;
    case 2:
      pixels.setPixelColor(14, 0, 255, 0);
      pixels.setPixelColor(13, 0, 255, 0);
      if(minuty==1){
        pixels.setPixelColor(14, 0, 255, 255);
        }
      if(minuty==2){
        pixels.setPixelColor(13, 0, 255, 255);
        }   
    break;
    case 3:
      pixels.setPixelColor(12, 0, 255, 0);
       if(minuty==3){
        pixels.setPixelColor(12, 0, 255, 255);
       }
    break;
    case 4:
      pixels.setPixelColor(11, 0, 255, 0);
      pixels.setPixelColor(10, 0, 255, 0);
      if(minuty==4){
        pixels.setPixelColor(11, 0, 255, 255);
        }
      if(minuty==5){
        pixels.setPixelColor(10, 0, 255, 255);
        }   
    break;
    case 5:
      pixels.setPixelColor(10, 0, 255, 0);
      pixels.setPixelColor(9, 0, 255, 0);
      if(minuty==5){
        pixels.setPixelColor(10, 0, 255, 255);
        }
      if(minuty==6){
        pixels.setPixelColor(9, 0, 255, 255);
        }   
    break;
    case 6:
      pixels.setPixelColor(8, 0, 255, 0);
      if(minuty==7){
        pixels.setPixelColor(8, 0, 255, 255);
      }
    break;
    case 7:
      pixels.setPixelColor(7, 0, 255, 0);
      pixels.setPixelColor(6, 0, 255, 0);
      if(minuty==8){
        pixels.setPixelColor(7, 0, 255, 255);
        }
      if(minuty==9){
        pixels.setPixelColor(6, 0, 255, 255);
        }   
    break;
    case 8:
      pixels.setPixelColor(6, 0, 255, 0);
      pixels.setPixelColor(5, 0, 255, 0);  
      if(minuty==9){
        pixels.setPixelColor(6, 0, 255, 255);
        } 
      if(minuty==10){
        pixels.setPixelColor(5, 0, 255, 255);
        }  
    break;
    case 9:
      pixels.setPixelColor(4, 0, 255, 0);
      if(minuty==11){
        pixels.setPixelColor(4, 0, 255, 255);
        }
    break;
    case 10:
      pixels.setPixelColor(3, 0, 255, 0);
      pixels.setPixelColor(2, 0, 255, 0);
      if(minuty==12){
        pixels.setPixelColor(3, 0, 255, 255);
        }
      if(minuty==13){
        pixels.setPixelColor(2, 0, 255, 255);
        }   
    break;
    case 11:
      pixels.setPixelColor(2, 0, 255, 0);
      pixels.setPixelColor(1, 0, 255, 0);
      if(minuty==13){
        pixels.setPixelColor(2, 0, 255, 255);
        }
      if(minuty==14){
        pixels.setPixelColor(1, 0, 255, 255);
        }   
    break;
    }
    if(sekundy==minuty){
      pixels.setPixelColor(15-sekundy, 255, 0, 255);
    }
    pixels.show();
   
    if(tm.Second==0){
      pixels.clear();
        }        
//  delay(1000);
    if (RTC.read(tm)) {
   
    lcd.setCursor (0, 0);
    LCDprint2digits(tm.Hour);
    lcd.print(':');
    LCDprint2digits(tm.Minute);
    lcd.print(':');
    LCDprint2digits(tm.Second);
    lcd.setCursor (0, 1);
    lcd.print(tm.Day);
    lcd.print('/');
    lcd.print(monthName[tm.Month-1]);
    lcd.print('/');
    lcd.print(tmYearToCalendar(tm.Year));
    
    
  } else {
    if (RTC.chipPresent()) {
      lcd.println("DS1307 stoi. Uruchom Zegar");
      } 
       else {
      lcd.println("DS1307 blad oczczytu!");
      lcd.println("sprawdz polaczenie");
    }
    delay(9000);
  }
  delay(1000);
}

//void print2digits(int number) {
//  if (number >= 0 && number < 10) {
//    Serial.write('0');
//  }
//  Serial.print(number);
//}
  
void LCDprint2digits(int number) {
  if (number >= 0 && number < 10) {
    lcd.write('0');
  }
  lcd.print(number);
}
