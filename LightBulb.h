#ifndef LIGHT_BULB_H
#define LIGHT_BULB_H


const int DEBOUNCE_DELAY = 50;  // milliseconds=160 (old value)

class LightBulb : public Service::LightBulb {
  public:
    SpanCharacteristic *power;
    int outputPin;
    int inputPin;
    bool lastSwitchState;
    unsigned long lastChangeTime = 0;

    LightBulb(int outPin, int inPin, const char* name) : Service::LightBulb() {
      new Characteristic::Name(name);  // ✅ assign name here
      outputPin = outPin;
      inputPin = inPin;

      power = new Characteristic::On();
      //new Characteristic::Name(name);      // 🔹 Add custom name

      pinMode(outputPin, OUTPUT);
      digitalWrite(outputPin, LOW);  // RELAY OFF initially // CHANGE WHEN ACTIVE LOW (=HIGH) OR HIGH (=LOW)

      pinMode(inputPin, INPUT_PULLUP);
      lastSwitchState = digitalRead(inputPin);
    }

    boolean update() override {
      digitalWrite(outputPin, power->getNewVal() ? HIGH : LOW); // CHANGE WHEN ACTIVE LOW (=LOW : HIGH) OR HIGH (=HIGH : LOW)
      return true;
    }

    void poll() {
      int currentState = digitalRead(inputPin);

      if (currentState != lastSwitchState) {
          lastSwitchState = currentState;

          bool newState = (currentState == LOW);  // 

          if (power->getVal<bool>() != newState) {
            //unsigned long t1 = millis(); // debug duration to connect homekit  
            power->setVal(newState);
            Serial.printf("Set newState = %d, notify HomeKit\n", newState);
            digitalWrite(outputPin, newState ? HIGH : LOW); // CHANGE WHEN ACTIVE LOW (=LOW : HIGH) OR HIGH (=HIGH : LOW)
            //Serial.printf("INPUT %d → Light %s\n", inputPin , "OUTPUT:", outputPin, newState ? "ON" : "OFF");
            //Serial.printf("Time for setValue + update: %lu ms\n", millis() - t1);// debug duration to connect homekit         
          }
      }
    } // end of void poll();
};

#endif
