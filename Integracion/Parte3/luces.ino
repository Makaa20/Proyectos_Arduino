#include  "FirebaseESP8266.h" // biblioteca Firebase ESP8266
#include  <ESP8266WiFi.h>   //bibloteca ESP8266

#define FIREBASE_HOST "" //direccion file base sin http:// o https:// 
#define FIREBASE_AUTH "" //clave firebase
#define WIFI_SSID ""// nombre la red wifi
#define WIFI_PASSWORD "" //clave wifi

int luz1 = D5;
int luz2 = D6;
FirebaseData luzData;

void setup()
{

  Serial.begin(9600);

  pinMode(luz1, OUTPUT);
  pinMode(luz2, OUTPUT);
  
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
  // LUZ 1
  if(Firebase.getString(luzData, "luces/luz1")){
    if(luzData.stringData() == "1"){
      digitalWrite(luz1, HIGH);
    }else if(luzData.stringData() == "0"){
      digitalWrite(luz1, LOW);
    }
  }else{
    Serial.println("Error de conexión con Firebase Luz1");
  }

  // LUZ 2

  if(Firebase.getString(luzData, "luces/luz2")){
    if(luzData.stringData() == "1"){
      digitalWrite(luz2, HIGH);
    }else if(luzData.stringData() == "0"){
      digitalWrite(luz2, LOW);
    }
  }else{
    Serial.println("Error de conexión con Firebase Luz2");
  }
}
