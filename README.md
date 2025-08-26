**1. Introduction**   
ESP32 Apple HomeKit Smart Home-DIY Switch & Temperature+Humidity Sensor   
🚀 In this tutorial, I’ll show you how to set up a DIY smart switch &amp; and temperature &amp; humidity sensor module for a typical bedroom — with 2 light switches and 1 temperature &amp; humidity sensor — all connected directly to Apple HomeKit. No hub required! 🔥

**What you’ll be able to do:** <br>
✅ 2 physical light switches (works with both switch & Home app).<br>
✅ Temperature & humidity sensor for real-time room monitoring.<br>
✅ Direct Apple HomeKit integration — works with Siri voice control.<br>
✅ 100% local network setup, fully private & secure.<br>

You don’t need to be an expert in coding or electronics. I explain everything clearly so anyone can follow along.

📌 What you’ll learn in this video:<br>
• How to configure an ESP32 as a HomeKit device.<br>
• How to wire and program physical light switches.<br>
• How to read temperature & humidity data from a sensor.<br>
• How to pair ESP32 directly with Apple HomeKit.<br>
• How to control devices via Apple Home, Siri, and physical switches.<br>

👍This project is perfect if you love DIY Smart Home, want a budget-friendly Apple HomeKit device, and prefer to keep everything private & under your control.

**2. Schematics** <br>
<img src="https://github.com/user-attachments/assets/8b9ebcf7-0ed7-4ccd-b72c-e762525205af" width="60%"> <br>
<img src="https://github.com/user-attachments/assets/6e1df6da-3073-4fa4-82e7-8ed8bbaf0151" width="50%"> <br>
<img src="https://github.com/user-attachments/assets/d84ffc5b-9110-40b4-81e3-dfdc14090edf" width="70%"> <br>

📦 Hardware Used:<br>
- ESP32 board (e.g. ESP32-S3, ESP32DEV, or similar)<br>
- DHT22 or BMP/BME280 sensor<br>
- ON/OFF switches<br>
- Solid state relay module SSR 5VDC 2A/240VAC (high level trigger)<br>
- Lightbulbs<br>
- Breadboard, jumper wires<br>

**3. Demo** <br>
<img src="https://github.com/user-attachments/assets/239fd733-9cd0-4a1a-89f8-86effe944a5d" width="60%">

- Add a accessory Apple Homekit:<br>
  <img width="679" height="326" alt="image" src="https://github.com/user-attachments/assets/7e2f6afb-1d61-4c33-bb11-42beaa00e51a" />

**4. Code**
- Please change GPIO follow your pins:
  ```cpp
    //In HOMEKIT8_3_BEDROOM_DHT.ino file:
        // Pin assignments for each light:
        #define LIGHT1_OUT 10  
        #define LIGHT2_OUT 11  
        #define LIGHT1_IN 12   
        #define LIGHT2_IN 13 
     //In DHT22_Sens file:
        // -------- DHT Sensor Configuration --------  
        #define DHTPIN 5  
        #define DHTTYPE DHT22
  
- This project also includes optimized sampling intervals for both the toggle switches and the DHT22 sensor, ensuring fast response and reliable data updates. You can change the reading cycle if you want.<br>
```cpp
       // In HOMEKIT8_3_BEDROOM_DHT.ino file:
        const int SW_INTERVAL= 50;  // milliseconds, reading cycle of toggle switch   
        const int DHT_INTERVAL = 5000;  // milliseconds, reading cycle of DHT22 sensor
```
  
💬 Questions? Leave a comment below!
🔔 Don’t forget to LIKE 👍 and SUBSCRIBE for more DIY ESP32 + Apple HomeKit tutorials.

YOUTUBE CHANNEL: [here](https://www.youtube.com/watch?v=1pKa1jMmEFA)

#ESP32 #HomeKit #SmartHome #DIYHomeAutomation #AppleHomeKit #TemperatureSensor #HumiditySensor #HomeSpan #IoTProject #ArduinoHomeKit #DIYIoT #SmartSwitch #DIY #DIYSmartHome #ESP32Projects
