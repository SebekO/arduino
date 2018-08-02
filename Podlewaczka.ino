// czas pomiedzy pomiarami 5min - 300.000ms
#define ODSTEP 1000
// limit po ilu odczytach liczmy srednia
#define LIMIT_ODCZYTOW 20

int czujka = 7;  
int pompa = 2; 
int stan = 0; 
int D1 = 8;
int D2 = 9;
int D3 = 10;
int D4 = 11;

// informacje o odczytach
int suma_odczytow = 0;
int liczba_odczytow = 0;
unsigned long czas_poprzedni = 0;

void setup() {
	pinMode(czujka, INPUT);
	pinMode(pompa, OUTPUT);

	// hurtowa inicjalizacja pinow 8-11 na wyj�cia
	for (int i = 8; i < 12; i++)
		pinMode(i, OUTPUT);
}

void loop() {
	// czas liczony od momentu wlaczenia urzadzenia 
	unsigned long czas_aktualny = millis(); 

	// sprawdza czy uplynal juz okreslony czas miedzy pomiarami
	if(czas_aktualny - czas_poprzedni > ODSTEP) {
		czas_poprzedni = czas_aktualny; 

		// stan czujnika
		stan = digitalRead(czujka);  
  
		// dodajemy odczyt
		liczba_odczytow += 1;
		
		// sumujemy odczyty
		suma_odczytow += analogRead(A2);
		
		if(liczba_odczytow >= LIMIT_ODCZYTOW){
		    	int srednia = ceil(suma_odczytow / liczba_odczytow);
			
			if (srednia > 900) { 
				digitalWrite (D1, HIGH);
				digitalWrite (D2, LOW);
				digitalWrite (D3, LOW);
				digitalWrite (D4, LOW);
			}
			if (srednia > 500 && srednia < 900) { 
				digitalWrite (D1, HIGH);
				digitalWrite (D2, HIGH);
				digitalWrite (D3, LOW);
				digitalWrite (D4, LOW);
			}
			if (srednia > 300 && srednia < 500) { 
				digitalWrite (D1, LOW);
				digitalWrite (D2, HIGH);
				digitalWrite (D3, HIGH);
				digitalWrite (D4, LOW);
			}		   
			if (srednia < 300) { 
				digitalWrite (D1, LOW);
				digitalWrite (D2, LOW);
				digitalWrite (D3, HIGH);
				digitalWrite (D4, HIGH);
			}
		   
			if (stan == HIGH)  {
				digitalWrite (pompa, HIGH);
				delay(3000); 
				digitalWrite (pompa, LOW);
			}
			// zerowanie licznikow
			liczba_odczytow = suma_odczytow = 0;
		}
	}
 }
 
