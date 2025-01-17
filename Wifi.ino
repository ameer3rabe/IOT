#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

IPAddress apIP(55, 55, 55, 55); 
const char* src_ssid = "AmeerArduno"; 

ESP8266WebServer server(80); 
int pressCount = 0;
const int maxPresses = 10;
unsigned long pressDurations[maxPresses] = {0};
bool isImprovement[maxPresses] = {false};
unsigned long overallBestTime = ULONG_MAX;

void WifiSetup() {
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  WiFi.softAP(src_ssid); 
  server.on("/", handleRoot); 
  server.onNotFound(handleNotFound); 
  server.begin(); 
}

void wifi_loop() {
  server.handleClient();
  delay(10);
} 

void handleNotFound(){
  String message = "File Not Found \n \n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

  for (uint8_t i = 0; i < server.args(); i++) {
      message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }

  server.send(404, "text/plain", message);
}
void handleRoot() {
  String html = "<html><body><h1>Button Clicks</h1><table border='1'>";
  html += "<tr><th>Press Timeingg</th><th>Improved/Not</th></tr>";

  for (int i = 0; i < pressCount; i++) {
    html += "<tr>";
    html += "<td>" + String(pressDurations[i]) + "</td>";
    html += "<td>" + String(isImprovement[i] ? "Yes" : "No") + "</td>";
    html += "</tr>";
  }

  html += "</table></body></html>";
  server.send(200, "text/html", html);
}


void addPressEntry(unsigned long pressTime) {
  bool improvement = pressTime < overallBestTime;
  overallBestTime = min(overallBestTime, pressTime);

  for (int i = maxPresses - 1; i > 0; i--) {
    pressDurations[i] = pressDurations[i - 1];
    isImprovement[i] = isImprovement[i - 1];
  }

  pressDurations[0] = pressTime;
  isImprovement[0] = improvement;
  pressCount = min(pressCount + 1, maxPresses);
}