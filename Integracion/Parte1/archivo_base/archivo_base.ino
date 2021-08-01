#include  "FirebaseESP8266.h" // biblioteca Firebase ESP8266
#include  <ESP8266WiFi.h>   //bibloteca ESP8266

#define FIREBASE_HOST "" //direccion file base sin http:// o https:// 
#define FIREBASE_AUTH "" //clave firebase
#define WIFI_SSID ""// nombre la red wifi
#define WIFI_PASSWORD "" //clave wifi





void setup()
{

  Serial.begin(9600);
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

}

void loop() {
}
