#include  "FirebaseESP8266.h" // biblioteca Firebase ESP8266
#include  <ESP8266WiFi.h>   //bibloteca ESP8266

#define FIREBASE_HOST "url firebase" //direccion file base sin http:// o https:// 
#define FIREBASE_AUTH "clave" //clave firebase
#define WIFI_SSID "nombre wifi"// nombre la red wifi
#define WIFI_PASSWORD "clave wifi" //clave wifi

int led = D5; //conectar anodo del led a la placa

FirebaseData ledData; // variable led



void setup()
{
  Serial.begin(9600);
  pinMode(led,OUTPUT); //inicializar led
  
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
  if (Firebase.getString(ledData, "/led")){ //valor de la bbdd firebase
    Serial.println(ledData.stringData()); 
    if (ledData.stringData() == "1") {
      digitalWrite(led, HIGH);
    }
    else if (ledData.stringData() == "0"){
      digitalWrite(led, LOW);
    }
  }
  delay(100);

}
