// Based on the great code written by
// Joël Gähwiler
// https://github.com/256dpi/arduino-mqtt

#include <WiFi.h>
#include <MQTT.h>

const char ssid[] = "WIFI_SSID";
const char pass[] = "WIFI_PASSWORD";

WiFiClient net;
MQTTClient client;

unsigned long lastMillis = 0UL, lastPrint = 0UL;

long costam = 0;

unsigned long szukanie = 0;
unsigned long lastled = 0;
unsigned long lastOdczyt = 0;
bool led = 1;

String str;

  int count;
  unsigned char c;
  unsigned char high;
  bool odczytOk = 0;

void connect() {
  Serial.print("checking wifi...");
  szukanie = millis();
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
    if (millis() - szukanie > 30000UL)
    {
      ESP.restart();
    }
  }

  Serial.print("\nconnecting to MQTT broker...");
  szukanie = millis();
  while (!client.connect("MQTT_ID", "MQTT_USERNAME", "MQTT_PASSWORD")) {  // Client ID, username, pass
    Serial.print(".");                                 // ID nie jest wcale wazne
    delay(1000);
    if (millis() - szukanie > 30000UL)
    {
      ESP.restart();
    }
  }

  Serial.println("\nconnected!");

  client.subscribe("/hello");
  // client.unsubscribe("/hello");
}

void messageReceived(String &topic, String &payload) {
  Serial.println("incoming: " + topic + " - " + payload);
  if (payload == "1")
    digitalWrite(2, 1);
  if (payload == "0")
    digitalWrite(2, 0);

  // Note: Do not use the client in the callback to publish, subscribe or
  // unsubscribe as it may cause deadlocks when other things arrive while
  // sending and receiving acknowledgments. Instead, change a global variable,
  // or push to a queue and handle it in the loop after calling `client.loop()`.
}

void setup() {
  pinMode(2, OUTPUT);
  digitalWrite(2, 0);

//  Serial2.begin(9600, SERIAL_8N1, 16, 17);
  Serial.begin(115200);
  delay(5000);

  WiFi.begin(ssid, pass);

  // Note: Local domain names (e.g. "Computer.local" on OSX) are not supported
  // by Arduino. You need to set the IP address directly.
  client.begin("10.0.0.52", net);
  client.onMessage(messageReceived);

  connect();
}

void loop() {

  client.loop();
  delay(10);  // <- fixes some issues with WiFi stability

  if (!client.connected()) {
    connect();
  }

  // publish a message roughly every minute.
  if (millis() - lastMillis > 60000UL) {
//    lastMillis = millis();
//    str = String("{\"temperature\":") + String(lasttemperature) + String(", \"humidity\":") + String(lasthumandity) + String("}");
//    client.publish("homeassistant/sensor/sensorBedroom/state", str);

//    delay(5000);
//    str = String("{\"pm1\":") + String(lastpmat10) + String(", \"pm25\":") + String(lastpmat25) + String(", \"pm10\":") + String(lastpmat100) + String("}");
//    client.publish("homeassistant/sensor/sensorBedroom/state", str);
  }

  if (millis() - lastled > 1000UL)
  {
    lastled = millis();
    digitalWrite(2, led);
    led = !led;
  }

  if (millis() >= 86400000UL)   // 24 (h) * 60 (min) * 60 (s) * 1000 ms = 86 400 000 ms  
  {
    ESP.restart();
  }
}
