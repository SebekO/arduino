#define diodaPIN 3
 
int wypelnienie = 0;
int zmiana = 5;
 
void setup() {
 pinMode(diodaPIN, OUTPUT);//Konfiguracja pinu jako wyjścia 
}
 
void loop() {
 analogWrite(diodaPIN, wypelnienie); //Generujemy sygnał o zadanym wypełnieniu
 
 if (wypelnienie < 255) { //Jeśli wypełnienie mniejsze od 100%
 wypelnienie = wypelnienie + zmiana; //Zwiększamy wypełnienie
 } else {
 wypelnienie = 0; //Jeśli wypełnienie większe od 100%, to wracamy na początek
 }
 
 delay(50); //Małe opóźnienie, aby efekt był widoczny
}
