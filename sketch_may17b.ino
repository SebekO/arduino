#include <SPI.h>
#include <MFRC522.h>
#include <Ethernet.h>
byte mac[] = { 0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x01 };
EthernetClient client;
#define SS_PIN 7
#define RST_PIN 6
MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance.
byte readCard[4]; 
String rfidUid = "";
String kartaauth1="9bd37725"; // deklaracja autoryzowanej karty
void setup() 
{
 // disable RFID SPI
 pinMode(7, OUTPUT);
 digitalWrite(4, HIGH);
 // disable w5100 SPI
 pinMode(10, OUTPUT);
 digitalWrite(10, HIGH);
 Serial.begin(9600); 
 if (Ethernet.begin(mac) == 0) {
 Serial.println("Failed to configure Ethernet using DHCP"); 
}
 SPI.begin(); // Init SPI bus
 mfrc522.PCD_Init(); // Init MFRC522 card
 Serial.println("Scan PICC to see UID and type...");
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
}
void loop() {
 // Look for new cards
 if ( ! mfrc522.PICC_IsNewCardPresent()) {
 return;
 }
 // Select one of the cards
 if ( ! mfrc522.PICC_ReadCardSerial()) {
 return;
 }
for (byte i = 0; i < mfrc522.uid.size; i++) {
 rfidUid += String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
 rfidUid += String(mfrc522.uid.uidByte[i], HEX);
 mfrc522.PICC_HaltA();
}
Serial.println(rfidUid);
if(rfidUid == kartaauth1)
{
 digitalWrite(3,HIGH);
 digitalWrite(4,LOW);
 if (client.connect("127.0.0.1",80)) { // REPLACE WITH YOUR SERVER ADDRESS
 client.print("GET /rfid.php"); 
 client.print("getrfid=");
 client.print(rfidUid);
 client.println( " HTTP/1.1");
 client.println( "Host: 127.0.0.1" );
 client.println("Content-Type: application/x-www-form-urlencoded"); 
 client.println( "Connection: close" );
 client.println(); 
 client.println();
 } 
 if (client.connected()) 
 { 
 client.stop(); // DISCONNECT FROM THE SERVER
 }
 }
else
{
 digitalWrite(3,LOW);
 digitalWrite(4,HIGH);
}
 delay(3000);
 digitalWrite(3,LOW);
 digitalWrite(4,LOW);
 rfidUid = "";
}
