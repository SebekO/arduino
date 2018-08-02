#include <SPI.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
dodawanie_inne();
}

unsigned char dodawanie_inne()
{
  for( int x = 0, y = 0, z=0; x<9, y<9, z<9; x++, y++, z++ ){

     
    return x+y+z;
    
}
}


void loop() {
  // put your main code here, to run repeatedly:
  unsigned char wyn= dodawanie_inne();
 Serial.print(wyn);
delay(300);
}

