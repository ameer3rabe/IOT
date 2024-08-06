//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx NOT NEEDED IT CHANGED TO SERVERINTERACTION.INO XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

//#include <ESP8266WiFi.h>
//#include <WiFiClient.h>
//#include <ESP8266HTTPClient.h>

//const char* ssid = "Ameer";
//const char* pswd = "0522485513";
//const int deviceId = 1121;
//const int channel = 1;

//WiFiClient client;

//void wifiClient_Setup() {
 // Serial.println("wifiSetup");
 // WiFi.begin(ssid, pswd);
 // while (WiFi.status() != WL_CONNECTED) {
   // Serial.println("trying ...");
   // delay(100);
 // }
//  Serial.println("Connected to network");
//}

//String sendPressTimeToServer(unsigned long pressTime) {
//  String serverUrl = "http://api.kits4.me/GEN/api.php?ACT=SET&DEV=" + String(deviceId) + "&CH=" + String(channel) + "&VAL=" + String(pressTime);
 // String response = "";

//  if (WiFi.status() == WL_CONNECTED) {
  //  HTTPClient http;
  //  http.begin(client, serverUrl);

//int httpCode = http.GET();
//
 //   if (httpCode > 0) {
   //   response = http.getString();
   //   Serial.println("Server Response: " + response);
   //// } else {
    //  Serial.println("HTTP GET failed");
   //   response = "Error";
  //  }
  //  http.end();
  //} else {
  //  Serial.println("WiFi not connected");
   // response = "Error";
 // }

 // return response;
//}

//String getShortestPressTimeFromServer() {
//  String serverUrl = "http://api.kits4.me/GEN/api.php?ACT=GET&DEV=" + String(deviceId) + "&CH=" + String(channel);
//  String response = "";

 // if (WiFi.status() == WL_CONNECTED) {
   // HTTPClient http;
   // http.begin(client, serverUrl);

  //  int httpCode = http.GET();

   // if (httpCode > 0) {
     // response = http.getString();
     // Serial.println("Server Response: " + response);
  //  } else {
  //    Serial.println("HTTP GET failed");
   //   response = "Error";
    }
  //  http.end();
 // } else {
 //   Serial.println("WiFi not connected");
 //   response = "Error";
 // }
//
//  return response;
//}
