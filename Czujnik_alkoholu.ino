#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define BACKLIGHT_PIN 3
LiquidCrystal_I2C	lcd(0x27,2,1,0,4,5,6,7);

int test =0;
int poziomsuma = 0;
int kalib, poziomalk, wskaznik;

byte plamka[8] =
{
  B10111,
  B11011,
  B11101,
  B11110,
  B11110,
  B11101,
  B11011,
  B10111
};

void setup() {
  Serial.begin(9600);
  lcd.begin (16,2); 
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);

  lcd.createChar(1,plamka);
  lcd.home ();
  lcd.print("Nagrzewanie");
  lcd.setCursor(0, 1);
  for (int i = 1; i < 17; i++) {
    lcd.setCursor(12, 0);
    lcd.print(i);
    lcd.setCursor(i-1, 1);
    lcd.write(1);
    delay (200); //Ustaw na co najmniej 1000 milisekund
  }
  lcd.clear();
  lcd.home ();
  lcd.print("Kalibracja");
  for (int i = 1; i < 11; i++) {
    int prob = analogRead(A0);
    Serial.println(prob);
    test=test+prob;
    lcd.setCursor(i-1, 1);
    lcd.write(1);
    delay (500);
  }
  kalib = test/10;
  Serial.print("Kalib:");
  Serial.println(kalib);
}

void loop() {
  lcd.clear();
  lcd.home ();
  lcd.print("CHUCH w CZUJNIK");
  for (int h = 1; h < 6; h++) {
    int poziom = analogRead(A0);
    Serial.println(poziom);
    poziomsuma=poziomsuma+poziom;
    delay (400); 
  }

  poziomalk = poziomsuma/5 ;
  Serial.print("TWOJ WYNIK:     ");
  Serial.println(poziomalk);
  wskaznik = poziomalk-kalib;
  Serial.print("kalib:");
  Serial.println(kalib);
  Serial.print("Wskaznik:");
  Serial.println(wskaznik);
  lcd.home ();
  lcd.print("TWOJ WYNIK:     ");
  for (int i = 0; i <= wskaznik; i++) {
    lcd.setCursor(i, 1);
    lcd.write(1);
  }
  delay(5000);  
  poziomalk=0;
  poziomsuma=0;
  wskaznik =0;
}

