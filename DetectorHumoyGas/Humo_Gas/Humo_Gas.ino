int pin_mq = D2;
int redpin = D4;
int greenpin = D7;
int buzzer = D3;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin_mq, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  boolean mq_estado = digitalRead(pin_mq); // Leemos el sensor
  if(mq_estado) // Si la salida del sensor es 1
  {
    digitalWrite(redpin, HIGH); // Encendemos el LED rojo
    digitalWrite(greenpin, LOW);
    noTone(buzzer); // Silenciar el buzzer 
  }else // Si la salida del sensor es 0
  {
    digitalWrite(redpin, LOW);
    digitalWrite(greenpin, HIGH); // Encender el LED verde
    tone(buzzer, 1000); // Hacemos sonar el buzzer
    delay(500);
    noTone(buzzer); // Silenciar el buzzer
  }

  delay(100);
}
