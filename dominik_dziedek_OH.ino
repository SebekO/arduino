 #include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>
#include <OneWire.h>
#include <DS18B20.h>

//KUCHNIA
//SUFIT
const int S021B = 2;
const int S021 = 5;
String S021_1("S021_1");
String S021_0("S021_0");
//BLAT
const int S022B = 3;
const int S022 = 6;
String S022_1("S022_1");
String S022_0("S022_0");
const int AFTER_CHANGE_DELAY = 500;
//CZUJNIK CZADU
float MQ9 = A2;
char* MQ9VV;
char MQ9_buffer[100];
//TEMPERATURA
#define ONEWIRE_PIN 7
// Adresy czujników
byte address[8]= {
  0x28, 0xFF, 0xEA, 0xE9, 0x61, 0x16, 0x3, 0x5F};
OneWire onewire(ONEWIRE_PIN);
DS18B20 sensors(&onewire);
float TEMP;
char* TEMPP;
char TEMP_buffer[100];
//KUCHNIA
//SUFIT
int S021BS;
int S021S = LOW;
//BLAT
int S022BS;
int S022S = LOW;

//numer IP komputera na ktĂłrym jest uruchomiony serwer mqtt
byte mqtt_server[] = { 192, 168, 1, 103 };
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

IPAddress ip(192, 168, 1, 5);


void setup() {
  Serial.begin(9600);
  initializeMqtt();
  initializeOut();
  initializeNetwork();
}
void loop() {
  checkS021SS();
  checkS022SS();
  checkMQ9();
  checkTEMP();
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
  executeRemoteCommand(strPayload);
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
  boolean publishState = mqtt_client.publish("domoticz/In", ssid);
  Serial.print(" published: ");
  Serial.println(publishState);
}

void initializeMqtt()
{
  if (mqtt_client.connect("arduinoClient", "admin", "admin")) {
    mqtt_client.subscribe("domoticz/In");
    Serial.println("MQTT connect OK");
  } else {
    Serial.println("MQTT connect failed");
  }
}

void checkMqtt()
{
  mqtt_client.loop();
}

void executeRemoteCommand(String command) {
  Serial.println(command);
  //KUCHNIA
  //SUFIT
    if (command == S021_1) {
    S021SS(HIGH);
  }
  if (command == S021_0) {
    S021SS(LOW);
  }
  //BLAT
  if (command == S022_1) {
    S022SS(HIGH);
  }
  if (command == S022_0) {
    S022SS(LOW);
  }
}
//CZUJNIK CZADU
void checkMQ9(){
  int MQ9V=analogRead(MQ9);
  MQ9V=map(MQ9V, 0, 1023, 0, 100);
  if(MQ9V>=30){
  MQ9VV=dtostrf(MQ9V, 3, 3, MQ9_buffer);
  sendMqttState(MQ9VV);
  }
}
//CZUJNIK TEMPERATURY
void checkTEMP(){
  sensors.begin();
  sensors.request(address);
  TEMP = sensors.readTemperature(address);
  sensors.request();
  TEMPP= dtostrf( TEMP, 5, 2, TEMP_buffer);
}
void initializeOut() {
  //KUCHNIA
  //SUFIT
  pinMode(S021, OUTPUT);
  pinMode(S021B, INPUT_PULLUP);
  //BLAT
  pinMode(S022, OUTPUT);
  pinMode(S022B, INPUT_PULLUP);
  S021SS(LOW);
  S022SS(LOW);
}
//KUCHNIA
//SUFIT
void checkS021SS(){
 S021BS = digitalRead(S021B);
  if (S021BS == LOW) {
    toogleS021();
    delay(AFTER_CHANGE_DELAY);
  }
}
void S021SS(int state) {
  digitalWrite(S021, state);
  S021S = state;
  if (state == LOW) {
    sendMqttState(S021_0);
  } else {
    sendMqttState(S021_1);
  }
}
void toogleS021() {
  if (S021S == LOW) {
    S021SS(HIGH);
  } else {
    S021SS(LOW);
  }
}
//BLAT
void checkS022SS(){
  S022BS = digitalRead(S022B);
  if (S022BS == LOW) {
    toogleS022();
    delay(AFTER_CHANGE_DELAY);
  }
}
void S022SS(int state) {
  digitalWrite(S022, state);
  S022S = state;
  if (state == LOW) {
    sendMqttState(S022_0);
  } else {
    sendMqttState(S022_1);
  }
}
void toogleS022() {
  if (S022S == LOW) {
    S022SS(HIGH);
  } else {
    S022SS(LOW);
  }
}
