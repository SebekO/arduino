#define MY_DEBUG  
#define MY_GATEWAY_SERIAL
 
#include <SPI.h>
#include <Ethernet.h>
#include <MySensors.h>
#include <DHT.h>
#include <Bounce2.h>
 
 
#define DHT_DATA_PIN 8
#define SENSOR_TEMP_OFFSET 0
 
// Sleep time between sensor updates (in milliseconds)
// Must be >1000ms for DHT22 and >2000ms for DHT11
static const uint64_t UPDATE_INTERVAL = 1000;
 
static const uint8_t FORCE_UPDATE_N_READS = 10;
 
#define CHILD_ID_HUM 0
#define CHILD_ID_TEMP 1
#define CHILD_ID 3
 
float lastTemp;
float lastHum;
uint8_t nNoUpdatesTemp;
uint8_t nNoUpdatesHum;
bool metric = true;
 
MyMessage msgHum(CHILD_ID_HUM, V_HUM);
MyMessage msgTemp(CHILD_ID_TEMP, V_TEMP);
DHT dht;
 
// Change to V_LIGHT if you use S_LIGHT in presentation below
MyMessage msg(CHILD_ID,V_TRIPPED);
 
void before() {
 
  }
void presentation()  
{
  // Send the sketch version information to the gateway
  sendSketchInfo("S-tmp", "1.1");
 
  // Register all sensors to gw (they will be created as child devices)
  present(CHILD_ID_HUM, S_HUM);
  present(CHILD_ID_TEMP, S_TEMP);
 
  }
 
 
 
void setup()
{
  dht.setup(DHT_DATA_PIN); // set data pin of DHT sensor
  if (UPDATE_INTERVAL <= dht.getMinimumSamplingPeriod()) {
    Serial.println("Warning: UPDATE_INTERVAL is smaller than supported by the sensor!");
  }
 
}
 
 
void loop()      
{
 
 
  dht.readSensor(true);
 
  // Get temperature from DHT library
  float temperature = dht.getTemperature();
  if (isnan(temperature)) {
    Serial.println("Failed reading temperature from DHT!");
  } else if (temperature != lastTemp || nNoUpdatesTemp == FORCE_UPDATE_N_READS) {
    // Only send temperature if it changed since the last measurement or if we didn't send an update for n times
    lastTemp = temperature;
    if (!metric) {
      temperature = dht.toFahrenheit(temperature);
    }
    // Reset no updates counter
    nNoUpdatesTemp = 0;
    temperature += SENSOR_TEMP_OFFSET;
    send(msgTemp.set(temperature, 1));
 
    #ifdef MY_DEBUG
    Serial.print("T: ");
    Serial.println(temperature);
    #endif
  } else {
    // Increase no update counter if the temperature stayed the same
    nNoUpdatesTemp++;
  }
 
  // Get humidity from DHT library
  float humidity = dht.getHumidity();
  if (isnan(humidity)) {
    Serial.println("Failed reading humidity from DHT");
  } else if (humidity != lastHum || nNoUpdatesHum == FORCE_UPDATE_N_READS) {
    // Only send humidity if it changed since the last measurement or if we didn't send an update for n times
    lastHum = humidity;
    // Reset no updates counter
    nNoUpdatesHum = 0;
    send(msgHum.set(humidity, 1));
   
    #ifdef MY_DEBUG
    Serial.print("H: ");
    Serial.println(humidity);
    #endif
  } else {
    // Increase no update counter if the humidity stayed the same
    nNoUpdatesHum++;
  }
 
  // Sleep for a while to save energy
  sleep(UPDATE_INTERVAL);
}
