float mq3_analogPin = A0; // connected to the output pin of MQ3 

void setup(){
  Serial.begin(9600); // open serial at 9600 bps
  delay(1000);
}

void loop()
{
  float mq3_value = analogRead(mq3_analogPin);
//  mq3_value=mq3_value*0,004*0,21;
   Serial.print("TWOJ WYNIK: ");
  Serial.println(mq3_value);

// mq3_value=map(mq3_value, 175, 1023, 0, 100);
// if (mq3_value <= -1)
//{
//  Serial.print("TWOJ WYNIK: ");
//  Serial.println(0.00);
//}
//else
//{
// Serial.print("TWOJ WYNIK: ");
//  Serial.println(mq3_value);
//}
//  
//  if(mq3_value>4.5)
//  {
//      Serial.print("Gratulacje dojebales rekord ");
//  }
 

  delay(1000); //Just here to slow down the output.
}
