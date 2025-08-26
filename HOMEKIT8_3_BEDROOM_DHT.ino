/*
- Version 6.0: development from HOMEKIT8, AN ACCESSORY APPLE HOMEKIT FOR A TYPICAL BEDROOM WITH
1 MAIN LIGHT, 1 BED LIGHT, 1 ROOM SENSORS, 2 TOGGLE SWITCHES 
FOR TRIGGER HIGH LEVEL (MODULE 2 RELAY TRIGGER HIGH LEVEL)
*/

#include <HomeSpan.h>
#include <DHT.h>
#include "DHT22_Sens.h"  // 👈 Include the accessory classes
#include "LightBulb.h"  // 👈 Include the accessory classes

// Pin assignments for each light
#define LIGHT1_OUT 10
#define LIGHT2_OUT 11
#define LIGHT1_IN   12
#define LIGHT2_IN   13

const int SW_INTERVAL= 50;  // milliseconds
const int DHT_INTERVAL = 5000;  // milliseconds


LightBulb *light1, *light2;

// -------- Setup --------
void setup() {
  Serial.begin(115200);
  dht.begin();
  delay(100);

  //homeSpan.setLogLevel(1);
  homeSpan.setStatusPin(48);
  homeSpan.begin(Category::Bridges, "Main BedRoom Bridge", "PhamKS");

  // -------- Single Device with Multiple Services --------
  new SpanAccessory();// ONE device in HomeKit
    new Service::AccessoryInformation();
      new Characteristic::Name("");
      new Characteristic::Identify();

// Add Temperature Sensor
    new DHT22Temperature();   // Temperature
    new DHT22Humidity();    // Humidity

// Lights
    light1 = new LightBulb(LIGHT1_OUT, LIGHT1_IN,"First Light");
    light2 = new LightBulb(LIGHT2_OUT, LIGHT2_IN,"Second light");
}
// -------- Loop --------
void loop() {
  homeSpan.poll();

  static unsigned long lastSWPoll = 0;
  static unsigned long lastDHTPoll = 0;
  
  if (millis() - lastSWPoll >= SW_INTERVAL) {
    lastSWPoll = millis();
    light1->poll();
    light2->poll();
  }
  if (millis() - lastDHTPoll >= DHT_INTERVAL) {  // Read every 5 seconds
    lastDHTPoll = millis();
    updateDHTReading();  // call the sensor read manually
  }
}


