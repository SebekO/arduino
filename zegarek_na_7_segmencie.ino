#include <Arduino.h>
#include <TM1637Display.h>
#include <Wire.h>
#include <Time.h>
#include <DS1307RTC.h>

#define CLK 2
#define DIO 3
#define TEST_DELAY   500
TM1637Display display(CLK, DIO);

const uint8_t SEG_DONE[] = {
	SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,           // d
	SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
	SEG_C | SEG_E | SEG_G,                           // n
	SEG_A | SEG_D | SEG_E | SEG_F | SEG_G            // E
	};
const uint8_t SEG_POL[] = {
	SEG_A | SEG_D | SEG_E | SEG_F,           // C
	SEG_B | SEG_C | SEG_E | SEG_F | SEG_G,   // H
	SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // U
        SEG_B | SEG_C | SEG_D,                   // J
	};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) ; // wait for serial
  delay(200);
}

void loop() {
  // put your main code here, to run repeatedly:
  tmElements_t tm;
int sekundy=tm.Second;
int minuty=tm.Minute;
int godziny=tm.Hour;
  if (RTC.read(tm)) {
    Serial.print(tm.Hour);
    Serial.write(':');
    Serial.print(tm.Minute);
    Serial.write(':');
    Serial.println(tm.Second);
    }
//    delay(200);
    
    
    int k, a;
    a = analogRead(A1);
    a=map(a, 0, 1023, 0, 15);
  uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
  display.setBrightness(15);



//if(digitalRead(0)==HIGH){
//  display.setSegments(SEG_DONE);
//}
if(digitalRead(9)==HIGH){
  display.setSegments(SEG_POL);
}
else {
  display.showNumberDec(godziny, true, 2, 0);

  display.showNumberDec(minuty, true, 2, 2);
}


  
} 
