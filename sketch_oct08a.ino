z#include <Tlc5940.h>
#include <tlc_fades.h>

void setup()
{
   pinMode(7, INPUT);
  digitalWrite(7, HIGH);  
  pinMode(6, INPUT);     
  digitalWrite(6, HIGH);  

  

  
}

void loop(){
{unsigned long time = millis();
  if(digitalRead(7) == LOW){
    Tlc.init();
  tlc_addFade(1, 0, 4095, time+1000, time+4000);
    tlc_addFade(1, 4095, 0, time+5000, time+7000);
   tlc_addFade(2, 0, 4095, time+4000, time+7000);
    tlc_addFade(2, 4095, 0, time+8000, time+10000);
   tlc_addFade(3, 0, 4095, time+7000, time+10000);
    tlc_addFade(3, 4095, 0, time+11000, time+13000);
   tlc_addFade(4, 0, 4095, time+10000, time+13000);
    tlc_addFade(4, 4095, 0, time+14000, time+16000);
   tlc_addFade(5, 0, 4095, time+13000, time+16000);
    tlc_addFade(5, 4095, 0, time+17000, time+19000);}
    if(digitalRead(6) == LOW){
        tlc_addFade(5, 0, 4095, time+1000, time+4000);
    tlc_addFade(5, 4095, 0, time+5000, time+7000);
   tlc_addFade(4, 0, 4095, time+4000, time+7000);
    tlc_addFade(4, 4095, 0, time+8000, time+10000);
   tlc_addFade(3, 0, 4095, time+7000, time+10000);
    tlc_addFade(3, 4095, 0, time+11000, time+13000);
   tlc_addFade(2, 0, 4095, time+10000, time+13000);
    tlc_addFade(2, 4095, 0, time+14000, time+16000);
   tlc_addFade(1, 0, 4095, time+13000, time+16000);
    tlc_addFade(1, 4095, 0, time+17000, time+19000);}
  tlc_updateFades();
  
}}
