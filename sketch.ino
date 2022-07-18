#include <Arduino.h>
#if defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#endif  // ESP8266
#if defined(ESP32)
#include <WiFi.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#endif  // ESP32
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <WiFiClient.h>

const char* kSsid = "ESP";
const char* kPassword = "12345678";
MDNSResponder mdns;

#if defined(ESP8266)
ESP8266WebServer server(80);
#undef HOSTNAME
#define HOSTNAME "ESP8266"
#endif  // ESP8266
#if defined(ESP32)
WebServer server(80);
#undef HOSTNAME
#define HOSTNAME "ESP32"
#endif  // ESP32

const uint16_t kIrLed = D5; //GPIO pin:(D5).

String ALLi = "OFF";

String Light0 = "OFF";

String Light1 = "OFF";

String Light2 = "OFF";

String Light3 = "OFF";

String Light4 = "OFF";

String FanSpeedi = "OFF";

String ACi = "OFF";

IRsend irsend(kIrLed);  // Set the GPIO to be used to sending the message.

void handleRoot() {
  String ALL = String("All: ") + Str ing(ALLi) + "\n";
  String Relay0 = String("Light0: ") + String(Light0) + "\n";
  String Relay1 = String("Light1: ") + String(Light1) + "\n";
  String Relay2 = String("Light2: ") + String(Light2) + "\n";
  String Relay3 = String("Light3: ") + String(Light3) + "\n";
  String Relay4 = String("Light4: ") + String(Light4) + "\n";
  String FanSpeed = String("Fan: ") + String(FanSpeedi) + "\n";
  String AC = String("AC: ") + String(ACi) + "\n";
  server.send(200, "text/html",
              "<html>" \
                "<head><title>" HOSTNAME "</title>" \
                "<meta http-equiv=\"refresh\"content=\"20; URL=/\">" \
                "<meta name=\"viewport\" content=\"width=device-width," \
                    "initial-scale=1.0,minimum-scale=1.0," \
                    "maximum-scale=5.0\">" \
                "</head>" \
                "<body>"\
                  "<h1>Home Automation</h1>" + String(ALL) + \
                  "<p><a href=\"/AllON\"><button class=\"button\">ALL ON</button></a></p>"\
                  "<p><a href=\"/AllOFF\"><button class=\"button\">ALL OFF</button></a></p>" + String(Relay0) + \
                  "<p><a href=\"/Light0ON\"><button class=\"button\">LIGHT 0 ON</button></a></p>"\
                  "<p><a href=\"/Light0OFF\"><button class=\"button\">LIGHT 0 OFF</button></a></p>" + String(Relay1) + \
                  "<p><a href=\"/Light1ON\"><button class=\"button\">LIGHT 1 ON</button></a></p>"\
                  "<p><a href=\"/Light1OFF\"><button class=\"button\">LIGHT 1 OFF</button></a></p>"+ String(Relay2) + \
                  "<p><a href=\"/Light2ON\"><button class=\"button\">LIGHT 2 ON</button></a></p>"\
                  "<p><a href=\"/Light2OFF\"><button class=\"button\">LIGHT 2 OFF</button></a></p>" + String(Relay3) + \
                  "<p><a href=\"/Light3ON\"><button class=\"button\">LIGHT 3 ON</button></a></p>"\
                  "<p><a href=\"/Light3OFF\"><button class=\"button\">LIGHT 3 OFF</button></a></p>"+ String(Relay4) + \
                  "<p><a href=\"/Light4ON\"><button class=\"button\">LIGHT 4 ON</button></a></p>"\
                  "<p><a href=\"/Light4OFF\"><button class=\"button\">LIGHT 4 OFF</button></a></p>" + String(FanSpeed) + \
                  "<p><a href=\"/Fan4\"><button class=\"button\">FAN 4</button></a></p>"\
                  "<p><a href=\"/Fan3\"><button class=\"button\">FAN 3</button></a></p>"\
                  "<p><a href=\"/Fan2\"><button class=\"button\">FAN 2</button></a></p>"\
                  "<p><a href=\"/Fan1\"><button class=\"button\">FAN 1</button></a></p>"\
                  "<p><a href=\"/Fanoff\"><button class=\"button\">FAN OFF</button></a></p>" + String(AC) + \
                  "<p><a href=\"/AcON\"><button class=\"button\">AC ON</button></a></p>"\
                  "<p><a href=\"/AcHC\"><button class=\"button\">AC HC</button></a></p>"\
                  "<p><a href=\"/AcLight\"><button class=\"button\">AC Light</button></a></p>"\
                  "<p><a href=\"/AcOFF\"><button class=\"button\">AC OFF</button></a></p>"\
                  "<p><a href=\"/Ac18\"><button class=\"button\">AC 18</button></a></p>"\
                  "<p><a href=\"/Ac19\"><button class=\"button\">AC 19</button></a></p>"\
                  "<p><a href=\"/Ac20\"><button class=\"button\">AC 20</button></a></p>"\
                  "<p><a href=\"/Ac21\"><button class=\"button\">AC 21</button></a></p>"\
                  "<p><a href=\"/Ac22\"><button class=\"button\">AC 22</button></a></p>"\
                  "<p><a href=\"/Ac23\"><button class=\"button\">AC 23</button></a></p>"\
                  "<p><a href=\"/Ac24\"><button class=\"button\">AC 24</button></a></p>"\
                  "<p><a href=\"/Ac25\"><button class=\"button\">AC 25</button></a></p>"\
                  "<p><a href=\"/Ac26\"><button class=\"button\">AC 26</button></a></p>"\
                  "<p><a href=\"/Ac27\"><button class=\"button\">AC 27</button></a></p>"\
                  "<p><a href=\"/Ac28\"><button class=\"button\">AC 28</button></a></p>"\
                  "<p><a href=\"/Ac29\"><button class=\"button\">AC 29</button></a></p>"\
                  "<p><a href=\"/Ac30\"><button class=\"button\">AC 30</button></a></p>"\
                "</body>" \
              "</html>");
}

void Light0ON() {
  Light0 = "ON";
  digitalWrite(D0, LOW);
  handleRoot();
}

void Light0OFF() {
  Light0 = "OFF";
  digitalWrite(D0, HIGH);
  handleRoot();
}

void Light1ON() {
  Light1 = "ON";
  digitalWrite(D1, LOW);
  handleRoot();
}

void Light1OFF() {
  Light1 = "OFF";
  digitalWrite(D1, HIGH);
  handleRoot();
}
void Light2ON() {
  Light2 = "ON";
  digitalWrite(D2, LOW);
  handleRoot();
}

void Light2OFF() {
  Light2 = "OFF";
  digitalWrite(D2, HIGH);
  handleRoot();
}

void Light3ON() {
  Light3 = "ON";
  digitalWrite(D3, LOW);
  handleRoot();
}

void Light3OFF() {
  Light3 = "OFF";
  digitalWrite(D3, HIGH);
  handleRoot();
}

void Light4ON() {
  Light4 = "ON";
  digitalWrite(D4, LOW);
  handleRoot();
}

void Light4OFF() {
  Light4 = "OFF";
  digitalWrite(D4, HIGH);
  handleRoot();
}
void FanOFF() {
  FanSpeedi = "OFF";
  digitalWrite(D6, HIGH);
  digitalWrite(D7, HIGH);
  digitalWrite(D8, HIGH);
  handleRoot();
}

void Fan1() {
  FanSpeedi = "Speed 1";
  digitalWrite(D7, HIGH);
  digitalWrite(D8, HIGH);
  delay(500);
  digitalWrite(D6, LOW);
  handleRoot();
}

void Fan2() {
  FanSpeedi = "Speed 2";
  digitalWrite(D6, HIGH);
  digitalWrite(D8, HIGH);
  delay(500);
  digitalWrite(D7, LOW);
  handleRoot();
}

void Fan3() {
  FanSpeedi = "Speed 3";
  digitalWrite(D7, HIGH); // No Need
  digitalWrite(D8, HIGH);
  delay(500);
  digitalWrite(D6, LOW);
  digitalWrite(D7, LOW);
  handleRoot();
}

void Fan4() {
  FanSpeedi = "Speed 4";
  digitalWrite(D6, HIGH);
  digitalWrite(D7, HIGH);
  delay(500);
  digitalWrite(D8, LOW);
  handleRoot();
}

void AcON() {
  ACi = "Temp 18";
  irsend.sendNEC(142607175, 28); // AC 18
  handleRoot();
}

void AcOFF() {
  ACi = "OFF";
  irsend.sendNEC(143392849, 28); // AC OFF
  handleRoot();
}

void AcHC() {
  ACi = "HC";
  irsend.sendNEC(142672094, 28); // AC HC
  handleRoot();
}

void AcLight() {
  irsend.sendNEC(143392934, 28); // AC Light
  handleRoot();
}

void Ac18() {
  ACi = "Temp 18";
  irsend.sendNEC(142607175, 28); // AC 18
  handleRoot();
}

void Ac19() {
  ACi = "Temp 19";
  irsend.sendNEC(142640192, 28); // AC 19
  handleRoot();
}

void Ac20() {
  ACi = "Temp 20";
  irsend.sendNEC(142640449, 28); // AC 20
  handleRoot();
}

void Ac21() {
  ACi = "Temp 21";
  irsend.sendNEC(142640706, 28); // AC 21
  handleRoot();
}

void Ac22() {
  ACi = "Temp 22";
  irsend.sendNEC(142640963, 28); // AC 22
  handleRoot();
}

void Ac23() {
  ACi = "Temp 23";
  irsend.sendNEC(142641220, 28); // AC 23
  handleRoot();
}

void Ac24() {
  ACi = "Temp 24";
  irsend.sendNEC(142641477, 28); // AC 24
  handleRoot();
}

void Ac25() {
  ACi = "Temp 25";
  irsend.sendNEC(142641734, 28); // AC 25
  handleRoot();
}

void Ac26() {
  ACi = "Temp 26";
  irsend.sendNEC(142641991, 28); // AC 26
  handleRoot();
}

void Ac27() {
  ACi = "Temp 27";
  irsend.sendNEC(142642248, 28); // AC 27
  handleRoot();
}

void Ac28() {
  ACi = "Temp 28";
  irsend.sendNEC(142642505, 28); // AC 28
  handleRoot();
}

void Ac29() {
  ACi = "Temp 29";
  irsend.sendNEC(142642762, 28); // AC 29
  handleRoot();
}

void Ac30() {
  ACi = "Temp 30";
  irsend.sendNEC(142643019, 28); // AC 30
  handleRoot();
}

void AllON() {
  ALLi = "ON";
  Light0 = "ON";
  Light1 = "ON";
  Light2 = "ON";
  Light3 = "ON";
  Light4 = "ON";
  FanSpeedi = "ON";
  Light0ON();
  Light1ON();
  Light2ON();
  Light3ON();
  Light4ON();
  Fan4();
  AcON();
  delay(500);
  AcHC();
  handleRoot();
}

void AllOFF() {
  ALLi = "OFF";
  Light0 = "OFF";
  Light1 = "OFF";
  Light2 = "OFF";
  Light3 = "OFF";
  Light4 = "OFF";
  FanSpeedi = "OFF";
  Light0OFF();
  Light1OFF();
  Light2OFF();
  Light3OFF();
  Light4OFF();
  FanOFF();
  AcOFF();
  handleRoot();
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++)
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  server.send(404, "text/plain", message);
}

void setup(void) {
  pinMode(A0, INPUT); // Analog input for Buttons
  pinMode(D0, OUTPUT); // Light0
  pinMode(D1, OUTPUT); // Light1
  pinMode(D2, OUTPUT); // Light2
  pinMode(D3, OUTPUT); // Light3
  pinMode(D4, OUTPUT); // Light4
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT); // Fan capacitor 1
  pinMode(D7, OUTPUT); // Fan capacitor 2
  pinMode(D8, OUTPUT); // Fan direct line
  digitalWrite(D0, HIGH);
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
  digitalWrite(D6, HIGH);
  digitalWrite(D7, HIGH);
  digitalWrite(D8, HIGH);
  
  irsend.begin();

  Serial.begin(115200);
  WiFi.begin(kSsid, kPassword);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(kSsid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP().toString());

#if defined(ESP8266)
  if (mdns.begin(HOSTNAME, WiFi.localIP())) {
#else  // ESP8266
  if (mdns.begin(HOSTNAME)) {
#endif  // ESP8266
    Serial.println("MDNS responder started");
    // Announce http tcp service on port 80
    mdns.addService("http", "tcp", 80);
  }

  server.on("/", handleRoot);
  server.on("/AllON", AllON);
  server.on("/AllOFF", AllOFF);
  server.on("/Light0ON", Light0ON);
  server.on("/Light0OFF", Light0OFF);
  server.on("/Light1ON", Light1ON);
  server.on("/Light1OFF", Light1OFF);
  server.on("/Light2ON", Light2ON);
  server.on("/Light2OFF", Light2OFF);
  server.on("/Light3ON", Light3ON);
  server.on("/Light3OFF", Light3OFF);
  server.on("/Light4ON", Light4ON);
  server.on("/Light4OFF", Light4OFF);
  server.on("/Fanoff", FanOFF);
  server.on("/Fan1", Fan1);
  server.on("/Fan2", Fan2);
  server.on("/Fan3", Fan3);
  server.on("/Fan4", Fan4);
  server.on("/AcON", AcON);
  server.on("/AcOFF", AcOFF);
  server.on("/AcHC", AcHC);
  server.on("/AcLight", AcLight);
  server.on("/Ac18", Ac18);
  server.on("/Ac19", Ac19);
  server.on("/Ac20", Ac20);
  server.on("/Ac21", Ac21);
  server.on("/Ac22", Ac22);
  server.on("/Ac23", Ac23);
  server.on("/Ac24", Ac24);
  server.on("/Ac25", Ac25);
  server.on("/Ac26", Ac26);
  server.on("/Ac27", Ac27);
  server.on("/Ac28", Ac28);
  server.on("/Ac29", Ac29);
  server.on("/Ac30", Ac30);
  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
int x = analogRead(A0);
  Serial.print(x);
  Serial.print("\n");
  delay(200);
  if (1000 < x && x < 1100) {
    Light0ON();
  }
  if (900 < x && x < 1000) {
    Light0OFF();
  }
#if defined(ESP8266)
  mdns.update();
#endif
  server.handleClient();
}
