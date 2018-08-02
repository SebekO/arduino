
float mq3_analogPin = A0; // connected to the output pin of MQ3 

void setup(){
  Serial.begin(9600); // open serial at 9600 bps
}

void loop()
{
//  delay(10000);// give ample warmup time for readings to stabilize
  float mq3_value = analogRead(mq3_analogPin);
  mq3_value= mq3_value*(0.04*0.21);
  Serial.print("TWOJ WYNIK: ");
  Serial.println(mq3_value);
  if(mq3_value>4.5)
  {
      Serial.print("Gratulacje dojebales rekord ");
  }
 

  delay(500); //Just here to slow down the output.
}
