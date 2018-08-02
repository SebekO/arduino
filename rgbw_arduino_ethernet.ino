#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

// Set the MAC address
byte mac[] = { 0x90, 0xA2, 0xDA, 0x0F, 0x5E, 0x69 };
 
// Set fallback IP address if DHCP fails
IPAddress ip(192,168,1,101);

// Set the broker server IP
byte server[] = { 192,168,1,103 };

EthernetClient ethClient;
PubSubClient client(server, 1883, callback, ethClient);

int SoffitR;
int SoffitG;
int SoffitB;
int BLUE = 6;                   
int GREEN = 5; 
int RED = 3; 


void setup()
{
    // Open serial communications
  Serial.begin(9600);
  
    // Start with a hard-coded address:
    Serial.println("Assigning Static IP address:");
    Ethernet.begin(mac, ip);
  
     Serial.print("My address:");
  Serial.println(Ethernet.localIP());
  
  // Connect to Broker, give it arduino as the name
  if (client.connect("arduino_LED2")) {
    
    // Publish a message to the status topic
    client.publish("status/arduino_LED","Arduino LED2 is now online");
    
    // Listen for messages on the control topic
    client.subscribe("control/arduino_LED/#");
   }
}

void loop()
{
  client.loop();
}

void callback(char* topic, byte* payload, unsigned int length) {
  // check for messages on subscribed topics
  payload[length] = '\0';
  Serial.print("Topic: ");
  Serial.println(String(topic));
  


  // check topic to identify type of content
  if(String(topic) == "control/arduino_LED/livingroom/color") {
    // convert payload to String
    String value = String((char*)payload);
    //value.trim();
    Serial.print (value);
    //Serial.flush();
    // split string at every "," and store in proper variable
    // convert final result to integer
    SoffitR = value.substring(0,value.indexOf(',')).toInt();
    SoffitG = value.substring(value.indexOf(',')+1,value.lastIndexOf(',')).toInt();
    SoffitB = value.substring(value.lastIndexOf(',')+1).toInt();

    // print obtained values for debugging
Serial.print("RED: ");
Serial.println(SoffitR);
//client.publish("status/arduino_LED", SoffitR);

Serial.print("GREEN: ");
Serial.println(SoffitG);
//client.publish("status/arduino_LED", SoffitG);

Serial.print("BLUE: ");
Serial.println(SoffitB);
//client.publish("status/arduino_LED/soffit/color/blue", int SoffitB);
//Serial.flush();
   
  analogWrite(GREEN, SoffitG);
  analogWrite(RED, SoffitR);
  analogWrite(BLUE, SoffitB);
  
   while(Serial.available())
  Serial.read();
    
  }
}
