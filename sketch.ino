#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "ESP";
const char* password = "12345678";

ESP8266WebServer server(80);

void handleRoot() {
 server.send(200, "text/html", "hello World");
}

void setup(void){
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  Serial.println("");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP()); 
 
  server.on("/", handleRoot);     

  server.begin();                 
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();  
}
