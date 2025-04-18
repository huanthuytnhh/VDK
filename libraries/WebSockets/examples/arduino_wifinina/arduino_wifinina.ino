#include <Arduino.h>
#include <SPI.h>
#include <WiFiNINA.h>
#include <WebSocketsClient.h>

#define WIFI_SSID ""
#define WIFI_PASS ""

int status = WL_IDLE_STATUS;
WiFiClient client;
WebSocketsClient webSocket;

void webSocketEvent(WStype_t type, uint8_t *payload, size_t length) {

  switch (type) {
    case WStype_DISCONNECTED:
      Serial.println("[WSc] Disconnected!");
      break;
    case WStype_CONNECTED:
      Serial.println("[WSc] Connected!");

      // send message to server when Connected
      webSocket.sendTXT("Connected");
      break;
    case WStype_TEXT:
      Serial.print("[WSc] get text:");
      Serial.println((char *)payload);

      // send message to server
      // webSocket.sendTXT("message here");
      break;
    case WStype_BIN:
      // send data to server
      // webSocket.sendBIN(payload, length);
      break;
    case WStype_ERROR:
    case WStype_FRAGMENT_TEXT_START:
    case WStype_FRAGMENT_BIN_START:
    case WStype_FRAGMENT:
    case WStype_PING:
    case WStype_PONG:
    case WStype_FRAGMENT_FIN:
      break;
  }
}

void setup() {
  Serial.begin(115200);

  while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println();
  Serial.println();
  Serial.println();

  // check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
    Serial.println("Please upgrade the firmware");
  }

  // attempt to connect to WiFi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(WIFI_SSID);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(WIFI_SSID, WIFI_PASS);

    // wait 10 seconds for connection:
    delay(10000);
  }

  Serial.println("Connected to WiFi");

  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // server address, port and URL
  webSocket.begin("192.168.0.123", 8011);

  // event handler
  webSocket.onEvent(webSocketEvent);

  // try ever 5000 again if connection has failed
  webSocket.setReconnectInterval(5000);
}

void loop() {
  webSocket.loop();
}