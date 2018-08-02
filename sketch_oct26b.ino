#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

//PIERWSZA LITERA FUNKCJA S-PRZEŁĄCZNIK, H-GRZEJNIK, R-ROLETA
//PIERWSZA CYFRA- POZIOM 0-PARTER, 1-PIETRO
//2CYFRA POMIESZCZENIE 1-SALON, 2-KUCHNIA 3-ŁAZIENKA, 4-KORYTARZ, 5-SCHOWEK, 6-PRACOWNIA 7-SYPIALNIA, 8-1POKÓJ, 9-2POKÓJ
//

//swiatła 22
//SALON
//STÓŁ
const int S011B = 5;
const int S011 = 38;
String S011_1("S011_1");
String S011_0("S011_0");
//KINKIET LED
const int S012B = 2;
const int S012 = 39;
String S012_1("S012_1");
String S012_0("S012_0");
//KUCHNIA
//SUFIT
const int S021B = 2;
const int S021 = 40;
String S021_1("S021_1");
String S021_0("S021_0");
//BLAT
const int S022B = 2;
const int S022 = 41;
String S022_1("S022_1");
String S022_0("S022_0");
//BLAT1
const int S023B = 2;
const int S023 = 42;
String S023_1("S023_1");
String S023_0("S023_0");
//ŁAZIENKA
//SUFIT
const int S031B = 2;
const int S031 = 43;
String S031_1("S031_1");
String S031_0("S031_0");
//LUSTRO
const int S032B = 2;
const int S032 = 44;
String S032_1("S032_1");
String S032_0("S032_0");
//KABINA
const int S033B = 2;
const int S033 = 45;
String S033_1("S033_1");
String S033_0("S033_0");
//KORYTARZ
//SCHODY
const int S041B = 2;
const int S041 = 46;
String S041_1("S041_1");
String S041_0("S041_0");
//SUFIT
const int S042B = 2;
const int S042 = 47;
String S042_1("S042_1");
String S042_0("S042_0");
//KINKIET LED
const int S043B = 2;
const int S043 = 48;
String S043_1("S043_1");
String S043_0("S043_0");
//KINKIET LED1
const int S044B = 2;
const int S044 = 49;
String S044_1("S044_1");
String S044_0("S044_0");

const int AFTER_CHANGE_DELAY = 500;

//PIERWSZA LITERA FUNKCJA S-PRZEŁĄCZNIK, H-GRZEJNIK, R-ROLETA
//PIERWSZA CYFRA- POZIOM 0-PARTER, 1-PIETRO
//2CYFRA POMIESZCZENIE 1-SALON, 2-KUCHNIA 3-ŁAZIENKA, 4-KORYTARZ, 5-SCHOWEK, 6-PRACOWNIA 7-SYPIALNIA, 8-1POKÓJ, 9-2POKÓJ
//OSWIETLENIE
//SALON
//STÓŁ
int S011BS;
int S011S = LOW;
//KINKIET
int S012BS;
int S012S = LOW;
//KUCHNIA
//SUFIT
int S021BS;
int S021S = LOW;
//BLAT1
int S022BS;
int S022S = LOW;
//BLAT2
int S023BS;
int S023S = LOW;
//ŁAZIENKA
//SUFIT
int S031BS;
int S031S = LOW;
//LUSTRO
int S032BS;
int S032S = LOW;
//KABINA
int S033BS;
int S033S = LOW;
//KORYTARZ
//SCHODY
int S041BS;
int S041S = LOW;
//SUFIT
int S042BS;
int S042S = LOW;
//KINKIET1
int S043BS;
int S043S = LOW;
//KINKIET2
int S044BS;
int S044S = LOW;


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
checkS011SS();
  checkS012SS();
  checkS021SS();
  checkS022SS();
  checkS023SS();
  checkS031SS();
  checkS032SS();
  checkS033SS();
  checkS041SS();
  checkS042SS();
  checkS043SS();
  checkS044SS();

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
  boolean publishState = mqtt_client.publish("/lightsIn", ssid);
  Serial.print(" published: ");
  Serial.println(publishState);
}

void initializeMqtt()
{
  if (mqtt_client.connect("arduinoClient", "admin", "admin")) {
    mqtt_client.subscribe("/lights");
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
  //SWIATŁA
  //SALON
  //STÓŁ
    if (command == S011_1) {
    S011SS(HIGH);
  }
  if (command == S011_0) {
    S011SS(LOW);
  }
  //KINKIET LED
  if (command == S012_1) {
    S012SS(HIGH);
  }
  if (command == S012_0) {
    S012SS(LOW);
  }
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
  //BLAT1
    if (command == S023_1) {
    S023SS(HIGH);
  }
  if (command == S023_0) {
    S023SS(LOW);
  }
  //ŁAZIENKA
  //SUFIT
  if (command == S031_1) {
    S031SS(HIGH);
  }
  if (command == S031_0) {
    S031SS(LOW);
  }
  //LUSTRO
    if (command == S032_1) {
    S032SS(HIGH);
  }
  if (command == S032_0) {
    S032SS(LOW);
  }
  //KABINA
  if (command == S033_1) {
    S033SS(HIGH);
  }
  if (command == S033_0) {
    S033SS(LOW);
  }
  //KORYTARZ
  //SCHODY
    if (command == S041_1) {
    S041SS(HIGH);
  }
  if (command == S041_0) {
    S041SS(LOW);
  }
  //SUFIT
    if (command == S042_1) {
    S042SS(HIGH);
  }
  if (command == S042_0) {
    S042SS(LOW);
  }
  //KINKET LED1
    if (command == S043_1) {
    S043SS(HIGH);
  }
  if (command == S043_0) {
    S043SS(LOW);
  }
  //KINKET LED2
    if (command == S044_1) {
    S044SS(HIGH);
  }
  if (command == S044_0) {
    S044SS(LOW);
  }

}

void initializeOut() {
//ŚWIATŁA 22
  //SALON
  pinMode(S011, OUTPUT);
  pinMode(S011B, INPUT_PULLUP);
  //KINKIET LED
  pinMode(S012, OUTPUT);
  pinMode(S012B, INPUT_PULLUP);
  //KUCHNIA
  //SUFIT
  pinMode(S021, OUTPUT);
  pinMode(S021B, INPUT_PULLUP);
  //BLAT
  pinMode(S022, OUTPUT);
  pinMode(S022B, INPUT_PULLUP);
  //BLAT1
  pinMode(S023, OUTPUT);
  pinMode(S023B, INPUT_PULLUP);
  //ŁAZIENKA
  //SUFIT
  pinMode(S031, OUTPUT);
  pinMode(S031B, INPUT_PULLUP);
  //LUSTRO
  pinMode(S032, OUTPUT);
  pinMode(S032B, INPUT_PULLUP);
  //KABINA
  pinMode(S033, OUTPUT);
  pinMode(S033B, INPUT_PULLUP);
  //KORYTARZ
  //SCHODY
  pinMode(S041, OUTPUT);
  pinMode(S041B, INPUT_PULLUP);
  //SUFIT
  pinMode(S042, OUTPUT);
  pinMode(S042B, INPUT_PULLUP);
  //KINKIET LED1
  pinMode(S043, OUTPUT);
  pinMode(S043B, INPUT_PULLUP);
  //KINKIET LED2
  pinMode(S044, OUTPUT);
  pinMode(S044B, INPUT_PULLUP);
 S011SS(LOW);
 S012SS(LOW);
 S021SS(LOW);
 S022SS(LOW);
 S023SS(LOW);
 S031SS(LOW);
 S032SS(LOW);
 S033SS(LOW);
 S041SS(LOW);
 S042SS(LOW);
 S043SS(LOW);
 S044SS(LOW);

}
//SALON
//STÓŁ
void checkS011SS(){
  S011BS = digitalRead(S011B);
  if (S011BS == LOW) {
    toogleS011();
    delay(AFTER_CHANGE_DELAY);
  }
}
void S011SS(int state) {
  digitalWrite(S011, state);
  S011S = state;
  if (state == LOW) {
    sendMqttState(S011_0);
  } else {
    sendMqttState(S011_1);
  }
}
void toogleS011() {
  if (S011S == LOW) {
    S011SS(HIGH);
  } else {
    S011SS(LOW);
  }
}
//KINKIET LED
void checkS012SS(){
  S012BS = digitalRead( S012B);
  if ( S012BS == LOW) {
    toogleS012();
    delay(AFTER_CHANGE_DELAY);
  }
}
void S012SS(int state) {
  digitalWrite(S012, state);
  S012S = state;
  if (state == LOW) {
    sendMqttState(S012_0);
  } else {
    sendMqttState(S012_1);
  }
}
void toogleS012() {
  if (S012S == LOW) {
    S012SS(HIGH);
  } else {
    S012SS(LOW);
  }
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
//BLAT1
void checkS023SS(){
  S023BS = digitalRead(S023B);
  if (S023BS == LOW) {
    toogleS023();
    delay(AFTER_CHANGE_DELAY);
  }
}
void S023SS(int state) {
  digitalWrite(S023, state);
  S023S = state;
  if (state == LOW) {
    sendMqttState(S023_0);
  } else {
    sendMqttState(S023_1);
  }
}
void toogleS023() {
  if (S023S == LOW) {
    S023SS(HIGH);
  } else {
    S023SS(LOW);
  }
}
//ŁAZIENKA
//SUFIT
void checkS031SS(){
  S031BS = digitalRead(S031B);
  if (S031BS == LOW) {
    toogleS031();
    delay(AFTER_CHANGE_DELAY);
  }
}
void S031SS(int state) {
  digitalWrite(S031, state);
  S031S = state;
  if (state == LOW) {
    sendMqttState(S031_0);
  } else {
    sendMqttState(S031_1);
  }
}
void toogleS031() {
  if (S031S == LOW) {
    S031SS(HIGH);
  } else {
    S031SS(LOW);
  }
}
//LUSTRO
void checkS032SS(){
  S032BS = digitalRead(S032B);
  if (S032BS == LOW) {
    toogleS032();
    delay(AFTER_CHANGE_DELAY);
  }
}
void S032SS(int state) {
  digitalWrite(S032, state);
  S032S = state;
  if (state == LOW) {
    sendMqttState(S032_0);
  } else {
    sendMqttState(S032_1);
  }
}
void toogleS032() {
  if (S032S == LOW) {
    S032SS(HIGH);
  } else {
    S032SS(LOW);
  }
}
//KABINA
void checkS033SS(){
  S033BS = digitalRead(S033B);
  if (S033BS == LOW) {
    toogleS033();
    delay(AFTER_CHANGE_DELAY);
  }
}
void S033SS(int state) {
  digitalWrite(S033, state);
  S033S = state;
  if (state == LOW) {
    sendMqttState(S033_0);
  } else {
    sendMqttState(S033_1);
  }
}
void toogleS033() {
  if (S033S == LOW) {
    S033SS(HIGH);
  } else {
    S033SS(LOW);
  }
}
//KORYTARZ
//SCHODY
void checkS041SS(){
  S041BS = digitalRead(S041B);
  if (S041BS == LOW) {
    toogleS041();
    delay(AFTER_CHANGE_DELAY);
  }
}
void S041SS(int state) {
  digitalWrite(S041, state);
  S041S = state;
  if (state == LOW) {
    sendMqttState(S041_0);
  } else {
    sendMqttState(S041_1);
  }
}
void toogleS041() {
  if (S041S == LOW) {
    S041SS(HIGH);
  } else {
    S041SS(LOW);
  }
}
//SUFIT
void checkS042SS(){
  S042BS = digitalRead(S042B);
  if (S042BS == LOW) {
    toogleS042();
    delay(AFTER_CHANGE_DELAY);
  }
}
void S042SS(int state) {
  digitalWrite(S042, state);
  S042S = state;
  if (state == LOW) {
    sendMqttState(S042_0);
  } else {
    sendMqttState(S042_1);
  }
}
void toogleS042() {
  if (S042S == LOW) {
    S042SS(HIGH);
  } else {
    S042SS(LOW);
  }
}
//KINKIET LED
void checkS043SS(){
  S043BS = digitalRead(S043B);
  if (S043BS == LOW) {
    toogleS043();
    delay(AFTER_CHANGE_DELAY);
  }
}
void S043SS(int state) {
  digitalWrite(S043, state);
  S043S = state;
  if (state == LOW) {
    sendMqttState(S043_0);
  } else {
    sendMqttState(S043_1);
  }
}
void toogleS043() {
  if (S043S == LOW) {
    S043SS(HIGH);
  } else {
    S043SS(LOW);
  }
}
//KINKIET LED1
void checkS044SS(){
  S044BS = digitalRead(S044B);
  if (S044BS == LOW) {
    toogleS044();
    delay(AFTER_CHANGE_DELAY);
  }
}
void S044SS(int state) {
  digitalWrite(S044, state);
  S044S = state;
  if (state == LOW) {
    sendMqttState(S044_0);
  } else {
    sendMqttState(S044_1);
  }
}
void toogleS044() {
  if (S044S == LOW) {
    S044SS(HIGH);
  } else {
    S044SS(LOW);
  }
}

