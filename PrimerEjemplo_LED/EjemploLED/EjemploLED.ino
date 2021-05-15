int PINLED = 8;
void setup() { 
  pinMode(PINLED, OUTPUT); // inicializar pin como output
}
void loop() {
   digitalWrite(PINLED, HIGH); // encenderá el LED
   delay(1000); // esperar 1 segundo
   digitalWrite(PINLED, LOW); // apagará el LED
   delay(1000); // esperar 1 segundo
}
