
// -------- DHT Sensor Configuration --------
#define DHTPIN 5
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// -------- Shared Data BME280 state --------
static float sharedTemp = 0;
static float sharedHumid = 0;

// -------- DHT22 Reading Function --------
void updateDHTReading() {
    unsigned long startTime = millis();
    float t = dht.readTemperature();
    float h = dht.readHumidity();

    if (!isnan(t) && !isnan(h) && t >= 0.0 && t <= 100.0 && h >= 0.0 && h <= 100.0) {
      sharedTemp = t;
      sharedHumid = h;
      Serial.printf("🌡 Temp: %.1f°C | 💧 Humidity: %.1f%%\n", t, h);
    } else {
      Serial.println("❌ Failed to read from DHT22!");
      sharedTemp=0; sharedHumid=0;
    }
    Serial.printf("update DHT Reading took %lu ms\n", millis() - startTime);
}

// -------- Temperature Service --------
struct DHT22Temperature : Service::TemperatureSensor {
  SpanCharacteristic *tempChar;
  DHT22Temperature() {
    tempChar = new Characteristic::CurrentTemperature(0.0);
  }
  void loop() override {
    tempChar->setVal(sharedTemp);
  }
};
// -------- Humidity Service --------
struct DHT22Humidity : Service::HumiditySensor {
  SpanCharacteristic *humidChar;
  DHT22Humidity() {
    humidChar = new Characteristic::CurrentRelativeHumidity(0.0);
  }
  void loop() override {
    humidChar->setVal(sharedHumid);
  }
};
