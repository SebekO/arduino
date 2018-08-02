
#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

const int HALOGEN_BUTTON_PIN = 7;
const int HALOGEN_RELAY_PIN = 6;
String HALOGEN_ON_COMMAND("halogen#1");
String HALOGEN_OFF_COMMAND("halogen#0");
const int AFTER_CHANGE_DELAY = 500;

int halogenButtonState;
int halogenState = LOW;

//numer IP komputera na którym jest uruchomiony serwer mqtt
byte mac[]    = {  0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 5);
IPAddress server(192,168, 1, 103);

void setup() {
  Serial.begin(9600);
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
EthernetClient ethClient;

PubSubClient mqtt_client(server, 1883, callback, ethClient);

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
  if (mqtt_client.connect("arduinoClient", "login", "haslo")) {
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

