#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

const int UP_BUTTON_PIN = 6;
const int UP_RELAY_PIN = 3;
const int DOWN_BUTTON_PIN = 5;
const int DOWN_RELAY_PIN = 2;
const int STOP_RELAY_PIN = 2;
String UP_COMMAND("UP");
String DOWN_COMMAND("DOWN");
String STOP_COMMAND("STOP");
const int AFTER_CHANGE_DELAY = 500;

int UP_ButtonState;
int UP_State = LOW;
int DOWN_ButtonState;
int DOWN_State = LOW;
int STOP_State = LOW;

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
  checkUP();
  checkDOWN();
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
  boolean publishState = mqtt_client.publish("/rfidIn", ssid);
  Serial.print(" published: ");
  Serial.println(publishState);
}

void initializeMqtt()
{
  if (mqtt_client.connect("arduinoClient", "admin", "admin")) {
    mqtt_client.subscribe("/rfid");
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
  if (command == UP_COMMAND) {
    digitalWrite(UP_RELAY_PIN, HIGH);
    delay(50);
    digitalWrite(UP_RELAY_PIN, LOW);
  }
  if (command == DOWN_COMMAND) {
    digitalWrite(DOWN_RELAY_PIN, HIGH);
    delay(50);
    digitalWrite(DOWN_RELAY_PIN, LOW);
  }
  if (command == STOP_COMMAND) {
    digitalWrite(STOP_RELAY_PIN, HIGH);
    delay(50);
    digitalWrite(STOP_RELAY_PIN, LOW); 
  }
}

void initializeOut() {
  pinMode(UP_BUTTON_PIN, INPUT_PULLUP);
  pinMode(UP_RELAY_PIN, OUTPUT);
  pinMode(DOWN_BUTTON_PIN, INPUT_PULLUP);
  pinMode(DOWN_RELAY_PIN, OUTPUT);
  digitalWrite(DOWN_RELAY_PIN, LOW);
  digitalWrite(UP_RELAY_PIN, LOW);
}

void checkUP() {
  UP_ButtonState = digitalRead(UP_BUTTON_PIN);
  if (UP_ButtonState == LOW) {
    sendMqttState(UP_COMMAND);
    delay(AFTER_CHANGE_DELAY);
  }
}

//void UP_State(int state) {
//  digitalWrite(UP_RELAY_PIN, state);
//  UP_State = state;
//  if (state == LOW) {
//    sendMqttState(UP_COMMAND);
//  } 
//}

void checkDOWN() {
  DOWN_ButtonState = digitalRead(DOWN_BUTTON_PIN);
  if (DOWN_ButtonState == LOW) {
    sendMqttState(DOWN_COMMAND);
    delay(AFTER_CHANGE_DELAY);
  }
}
//void DOWN_State(int state) {
//  digitalWrite(DOWN_RELAY_PIN, state);
//  DOWN_State = state;
//  if (state == LOW) {
//    sendMqttState(DOWN_COMMAND);
//  }
//}





