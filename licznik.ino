int odczytanaWartosc = 0; //Zmienna do przechowywania odczytu ADC
int prog = 0; //Próg włączenia światła - ustawiany potencjometrem
 
void setup() {
  pinMode(8, OUTPUT); //Konfiguracja wyjść pod diodę LED
  Serial.begin(9600);
}
 
void loop() {
  odczytanaWartosc = analogRead(A5);//Odczytanie wartości z ADC
  prog = analogRead(A4);//Odczytanie wartości z ADC  
  
  if (odczytanaWartosc < prog) { //Czy jest ciemniej od ustawionego progu?
     digitalWrite(8, HIGH);//Włączenie diody    
  } else {
     digitalWrite(8, LOW);//Wyłączenie diody      
  }
  Serial.println(odczytanaWartosc);
  
  delay(50);
}
