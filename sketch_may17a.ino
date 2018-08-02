#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

IPAddress ip(192, 168, 2, 177);
byte gateway[] = { 192 ,168 ,2 ,1 };
byte subnet[] = { 255 ,255 ,255 ,0 };

EthernetServer server(80);

float temp;

String readString = String(30);

void setup() {
  Ethernet.begin(mac, ip, gateway, subnet);
  delay(1000);
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  Serial.begin(57600);
   
}

void loop(){
  EthernetClient client = server.available();
  if (client) {
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        if (readString.length() < 30)
        {
          readString = readString + c;
        }
        if (c == '\n') {
          Serial.print(readString);
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println();          
          
          if(readString.startsWith("GET /?out=4&status=1"))
          {
            Serial.print("\n 3 HIGH \n");
            digitalWrite(4, HIGH);
            client.print("{\"status\" : \"1\" , \"out\" : \"");
            client.print(4);
            client.print("\"}");
          }
          
          if(readString.startsWith("GET /?out=4&status=0"))
          {
            Serial.print("\n 3 LOW \n");
            digitalWrite(4, LOW);
            client.print("{\"status\" : \"0\" , \"out\" : \"");
            client.print(4);
            client.print("\"}");
          }          
          
          readString="";
          client.stop();
        }
      }
    }
  }
}
