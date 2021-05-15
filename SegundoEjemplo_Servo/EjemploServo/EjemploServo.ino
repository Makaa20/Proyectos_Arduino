#include <Servo.h>

Servo servo1;
int PIN = 8;

void setup(){
  servo1.attach(PIN); // inicializar el servo
  servo1.write(0); // mover el servo al punto inicial
  delay(2000);
}

void loop(){
  servo1.write(90); // mover el servo 90°
  delay(1000); // esperar 1 seg
  servo1.write(0); // mover el servo al punto inicial
  delay(1000);
}
