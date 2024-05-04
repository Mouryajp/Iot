/*
  WriteSingleField
  
  Description: Writes a value to a channel on ThingSpeak every 20 seconds.
  
  Hardware: ESP32 based boards
  
  !!! IMPORTANT - Modify the secrets.h file for this project with your network connection and ThingSpeak channel details. !!!
  
  Note:
  - Requires installation of EPS32 core. See https://github.com/espressif/arduino-esp32/blob/master/docs/arduino-ide/boards_manager.md for details. 
  - Select the target hardware from the Tools->Board menu
  - This example is written for a network using WPA encryption. For WEP or WPA, change the WiFi.begin() call accordingly.
  
  ThingSpeak ( https://www.thingspeak.com ) is an analytic IoT platform service that allows you to aggregate, visualize, and 
  analyze live data streams in the cloud. Visit https://www.thingspeak.com to sign up for a free account and create a channel.  
  
  Documentation for the ThingSpeak Communication Library for Arduino is in the README.md folder where the library was installed.
  See https://www.mathworks.com/help/thingspeak/index.html for the full ThingSpeak documentation.
  
  For licensing information, see the accompanying license file.
  
  Copyright 2020, The MathWorks, Inc.
*/

// #include <WiFi.h>
// #include "secrets.h"
// #include "ThingSpeak.h" // always include thingspeak header file after other header files and custom macros

// char ssid[] = SECRET_SSID;   // your network SSID (name) 
// char pass[] = SECRET_PASS;   // your network password
// int keyIndex = 0;            // your network key Index number (needed only for WEP)
// WiFiClient  client;

// unsigned long myChannelNumber = SECRET_CH_ID;
// const char * myWriteAPIKey = SECRET_WRITE_APIKEY;

// int number = 0;

// void setup() {
//   Serial.begin(115200);  //Initialize serial
//   while (!Serial) {
//     ; // wait for serial port to connect. Needed for Leonardo native USB port only
//   }
  
//   WiFi.mode(WIFI_STA);   
//   ThingSpeak.begin(client);  // Initialize ThingSpeak
// }

// void loop() {

//   // Connect or reconnect to WiFi
//   if(WiFi.status() != WL_CONNECTED){
//     Serial.print("Attempting to connect to SSID: ");
//     Serial.println(SECRET_SSID);
//     while(WiFi.status() != WL_CONNECTED){
//       WiFi.begin(ssid, pass); // Connect to WPA/WPA2 network. Change this line if using open or WEP network
//       Serial.print(".");
//       delay(5000);     
//     } 
//     Serial.println("\nConnected.");
//   }

//   // Write to ThingSpeak. There are up to 8 fields in a channel, allowing you to store up to 8 different
//   // pieces of information in a channel.  Here, we write to field 1.
//   int x = ThingSpeak.writeField(myChannelNumber, 1, number, myWriteAPIKey);
//   if(x == 200){
//     Serial.println("Channel update successful.");
//   }
//   else{
//     Serial.println("Problem updating channel. HTTP error code " + String(x));
//   }
  
//   // change the value
//   number++;
//   if(number > 99){
//     number = 0;
//   }
  
//   delay(20000); // Wait 20 seconds to update the channel again
// }


// Temperature
#include <WiFi.h>
#include "secrets.h"
#include "ThingSpeak.h" // always include thingspeak header file after other header files and custom macros
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 7
#define DHTTYPE    DHT11     // DHT 11
// #define DHTTYPE    DHT22     // DHT 22 (AM2302)
// #define DHTTYPE    DHT21     // DHT 21 (AM2301)

DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;

char ssid[] = SECRET_SSID;   // your network SSID (name) 
char pass[] = SECRET_PASS;   // your network password
int keyIndex = 0;            // your network key Index number (needed only for WEP)
WiFiClient  client;

unsigned long myChannelNumber = SECRET_CH_ID;
const char * myWriteAPIKey = SECRET_WRITE_APIKEY;

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
  Serial.println(""); 
  ThingSpeak.begin(client);  // Initialize ThingSpeak
  sensor_t sensor;
  dht.begin();
}

void loop() {
  // Connect or reconnect to WiFi
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(SECRET_SSID);
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass); // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);     
    } 
    Serial.println("\nConnected.");
  }

  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    Serial.print(F("Temperature: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));

    int x = ThingSpeak.writeField(myChannelNumber, 1, event.temperature, myWriteAPIKey);
    // Write to ThingSpeak. There are up to 8 fields in a channel, allowing you to store up to 8 different
    // pieces of information in a channel.  Here, we write to field 1.
    if(x == 200){
      Serial.println("Channel update successful.");
    }
    else{
      Serial.println("Problem updating channel. HTTP error code " + String(x));
    }
  }  
  delay(20000); // Wait 20 seconds to update the channel again

 
dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    Serial.print(F("Humidity: "));
    Serial.print(event.relative_humidity);
    Serial.println(F("%"));

    int y = ThingSpeak.writeField(myChannelNumber, 2, event.relative_humidity, myWriteAPIKey);
    // Write to ThingSpeak. There are up to 8 fields in a channel, allowing you to store up to 8 different
    // pieces of information in a channel.  Here, we write to field 1.
    if(y == 200){
      Serial.println("Channel update successful.");
    }
    else{
      Serial.println("Problem updating channel. HTTP error code " + String(y));
    }
  }  
  delay(20000); // Wait 20 seconds to update the channel again
}