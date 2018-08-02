
// Program odczytuje temperaturę z czujnika

#include <OneWire.h>
#include <DS18B20.h>

// Numer pinu do którego podłaczasz czujnik
#define ONEWIRE_PIN 2

// Adres czujnika
byte address[8] = {0x28, 0xFF, 0xEA, 0xE9, 0x61, 0x16, 0x3, 0x5F};
float temperature;
OneWire onewire(ONEWIRE_PIN);
DS18B20 sensors(&onewire);

void setup() {
  while(!Serial);
  Serial.begin(9600);

  sensors.begin();
  sensors.request(address);
}

void loop() {
  if (sensors.available())
  {
     temperature = sensors.readTemperature(address);

    Serial.print(temperature);
    Serial.println(F(" 'C"));

    sensors.request(address);
  }

  // tu umieść resztę twojego programu
  // Będzie działał bez blokowania
}

