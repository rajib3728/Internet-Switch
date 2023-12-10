
#include "ThingSpeak.h"
#include <ESP8266WiFi.h>

//Replace your wifi credentials here
const char* ssid     = "Rounak";//Replace with your Wifi Name
const char* password = "mqwnr84333";// Replace with your wifi Password

//change your channel number here
unsigned long channel = 2365721;//Replace with your own ThingSpeak Account Channle ID

//1,2 and 3 are channel fields. You don't need to change if you are following this tutorial. However, you can modify it according to your application
unsigned int led1 = 1;


WiFiClient  client;


void setup() {
  Serial.begin(115200);
  delay(100);
  
  
  pinMode(D4, OUTPUT);
  digitalWrite(D4, 0);
 
  // We start by connecting to a WiFi network
 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());
  ThingSpeak.begin(client);

}

void loop() {
 
  //get the last data of the fields
  int led_1 = ThingSpeak.readFloatField(channel, led1);

  if(led_1 == 1){
    digitalWrite(D4, 1);
    Serial.println("D4 is On..!");
  }
  else if(led_1 == 0){
    digitalWrite(D4, 0);
    Serial.println("D1 is Off..!");
  }
 
 

    
  Serial.println(led_1);
  
  delay(5000);
 
}
