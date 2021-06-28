#include <LiquidCrystal.h> // libreria del LCD
#include <DHT.h> // libreria dht11
#define DHTPIN 13
#define DHTTYPE DHT11

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // esta linea muestra en que pines debe ir conectado a la pantalla LCD a nuestro Arduino
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  dht.begin(); // comenzamos el sensor DHT
  lcd.begin(16, 2); // con esta instrucción indicamos cuál es la proporción de nuestro LCD


}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  lcd.clear();
  lcd.setCursor(2,0); // Fila 1, Columna 2
  lcd.print("Arduino Citt");

  // Leemos la temperatura en grados centígrados
  int t = dht.readTemperature();
  // Leemos la humedad relativa
  float h = dht.readHumidity();

  // Comprobamos si ha habido algún error en la lectura
  if(isnan(t)){
    lcd.setCursor(0,1); // Fila 2, Columna 1
    lcd.print("Error en el sensor");
    return;
  }

  // Calcular el indice de calor en grados centígrados
  int hic = dht.computeHeatIndex(t, false);

  lcd.setCursor(0,1); // Fila 2, Columna 1
  lcd.print("Temp: ");
  lcd.setCursor(5,1); // Fila 2 Columna 5
  lcd.print(t);
  lcd.setCursor(7,1); // Fila 2, Columna 7
  lcd.print("C");
  lcd.setCursor(9,1); // Fila 2, Columna 9
  lcd.print("H");
  lcd.setCursor(11,1); // Fila 2, Columna 11
  lcd.print(h); 
}
