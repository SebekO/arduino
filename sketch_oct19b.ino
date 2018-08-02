#include <SPI.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define wifi_ssid "<li_id=content-453765>"
#define wifi_password "lolek70510825"

const int HALOGEN_BUTTON_PIN = 28;
const int HALOGEN_RELAY_PIN = 30;
String HALOGEN_ON_COMMAND("halogen#1");
String HALOGEN_OFF_COMMAND("halogen#0");
const int AFTER_CHANGE_DELAY = 500;

int halogenButtonState;
int halogenState = LOW;

//numer IP komputera na którym jest uruchomiony serwer mqtt
byte mqtt_server[] = { 192,168, 1, 3 };


void setup() {
Serial.begin(115200);
setup_wifi();
  initializeMqtt();
  initializeHalogen();
}

void loop() {
  checkHalogen();
  checkMqtt();
}

void callback(char* topic, byte* payload, unsigned int length) {
  payload[length] = '\0';
  String strPayload = String((char*)payload);
  Serial.print("IN: ");
  Serial.println(strPayload);
  executeRemoteCommand(strPayload);  
}

WiFiClient client;
PubSubClient mqtt_client(mqtt_server, 1883, callback, client);

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(wifi_ssid);

  WiFi.begin(wifi_ssid, wifi_password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void sendMqttState(String state) {
  Serial.print("STATE: ");
  Serial.print(state);
/*
konieczna weryfikacja czy mamy aktywne połączenie
jeśli nie, trzeba je odnowić
*/
  boolean connected = mqtt_client.connected();
  if (!connected) {
     initializeMqtt();
  }
  char ssid[state.length()+1];        
  state.toCharArray(ssid, state.length()+1);
  boolean publishState = mqtt_client.publish("/houseIn", ssid); 
  Serial.print(" published: ");
  Serial.println(publishState);
}

void initializeMqtt()
{
  if (mqtt_client.connect("arduinoClient", "login", "hasło")) {
    mqtt_client.subscribe("/house");
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
  if (command == HALOGEN_ON_COMMAND) {
    setHalogenState(HIGH);
  }
  if (command == HALOGEN_OFF_COMMAND) {
    setHalogenState(LOW);
  }
}

void initializeHalogen() {
    pinMode(HALOGEN_BUTTON_PIN, INPUT);
    pinMode(HALOGEN_RELAY_PIN, OUTPUT);
    setHalogenState(LOW);
  
}
void checkHalogen() {
  halogenButtonState = digitalRead(HALOGEN_BUTTON_PIN);
  if (halogenButtonState == HIGH) {
    toogleHalogen();   
    delay(AFTER_CHANGE_DELAY);
  }
}

void setHalogenState(int state) {
     digitalWrite(HALOGEN_RELAY_PIN, state);
      halogenState = state;
      if (state == LOW) {
        sendMqttState(HALOGEN_OFF_COMMAND);
      } else {
                sendMqttState(HALOGEN_ON_COMMAND);
      }
}

void toogleHalogen() {
  if (halogenState == LOW) {
      setHalogenState(HIGH);
    } else {
      setHalogenState(LOW);
    }
}

