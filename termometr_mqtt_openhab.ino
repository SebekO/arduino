/*
 * Temperature Reading
 *
 * Reads sensor value and publishes through MQTT.
 * MQTT Arduino PubSubClient http://knolleary.net/arduino-client-for-mqtt/
 *
 */

#include <SPI.h>
#include <PubSubClient.h>
#include <Ethernet.h>
#include <OneWire.h>
#include <DS18B20.h>

// Numer pinu do którego podłaczasz czujnik
#define ONEWIRE_PIN 2

// Adres czujnika
byte address[8] = {0x28, 0xFF, 0xEA, 0xE9, 0x61, 0x16, 0x3, 0x5F};

OneWire onewire(ONEWIRE_PIN);
DS18B20 sensors(&onewire);
float temperature;
unsigned long time;
char* tempC;
char message_buffer[100];
// Network Settings
// MAC address of ethernet shield
// Look for it on a sticket at the bottom of the shield. 
// Old Arduino Ethernet Shields or clones may not have a dedicated MAC address. Set any hex values here.
byte MAC_ADDRESS[] = {  0xFE, 0xED, 0xDE, 0xAD, 0xBE, 0xEF };

// IP address of MQTT server
byte MQTT_SERVER[] = { 192, 168, 1, 103 };

EthernetClient ethClient;
PubSubClient client(MQTT_SERVER, 1883, callback, ethClient);

void setup()
{  
  // Initilize serial link for debugging
  Serial.begin(9600);
  
  if (Ethernet.begin(MAC_ADDRESS) == 0)
  {
    Serial.println("Failed to configure Ethernet using DHCP");
    return;
  }
   sensors.begin();
  sensors.request(address);
}

void loop()
{
  temperature = sensors.readTemperature(address);
    sensors.request(address);
  if (!client.connected())
  {
    //client.connect("admin", "admin", "admin");
    client.connect("sfo-arduino");
    client.publish("sfo/arduino/alive", "I'm alive!");
  }
  
  tempC = dtostrf( temperature, 5, 2, message_buffer); // TMP36 sensor calibration


  // Publish sensor reading every X milliseconds
  if (millis() > (time + 6000)) {
    time = millis();
    client.publish("home/temperature",tempC);
  }
    
  // MQTT client loop processing
  client.loop();
}

// Handles messages arrived on subscribed topic(s)
void callback(char* topic, byte* payload, unsigned int length) {
}
