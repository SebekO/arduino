#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>


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








//numer IP komputera na ktĂłrym jest uruchomiony serwer mqtt
byte mqtt_server[] = { 192, 168, 1, 103 };
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

IPAddress ip(192, 168, 1, 5);


void setup() {
  Serial.begin(9600);
  initializeMqtt();
  initializeNetwork();
  sensors.begin();
  sensors.request(address);
}
void loop() {
setStolState();
  checkMqtt();
}
void initializeNetwork() {
  Ethernet.begin(mac, ip);
}
void callback(char* topic, byte* payload, unsigned int length) {
  payload[length] = '\0';
  String strPayload = String((char*)payload);
  Serial.print("IN: ");
  Serial.println(strPayload);
}

EthernetClient client;
PubSubClient mqtt_client(mqtt_server, 1883, callback, client);

void sendMqttState(String state) {
  Serial.print("STATE: ");
  Serial.print(state);
  /*
    konieczna weryfikacja czy mamy aktywne poĹ‚Ä…czenie
    jeĹ›li nie, trzeba je odnowiÄ‡
  */
  boolean connected = mqtt_client.connected();
  if (!connected) {
    initializeMqtt();
  }
  char ssid[state.length() + 1];
  state.toCharArray(ssid, state.length() + 1);
  boolean publishState = mqtt_client.publish("/GF_LivingIn", ssid);
  Serial.print(" published: ");
  Serial.println(publishState);
}

void initializeMqtt()
{
  if (mqtt_client.connect("arduinoClient", "admin", "admin")) {
    mqtt_client.subscribe("/GF_Living");
    Serial.println("MQTT connect OK");
  } else {
    Serial.println("MQTT connect failed");
  }
}

void checkMqtt()
{
  mqtt_client.loop();
}



void setStolState() {

//    sendMqttState();

}




