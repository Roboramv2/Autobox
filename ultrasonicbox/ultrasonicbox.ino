#include <Servo.h>
Servo servo;
int angle;
int distance;
long duration;
int d;

int ping() {
  digitalWrite(10, LOW); delayMicroseconds(2); digitalWrite(10, HIGH); delayMicroseconds(10); digitalWrite(10, LOW);
  duration = pulseIn(11, HIGH); distance = duration * 0.034 / 2;
  return distance;
}

void closelid() {
  servo.write(0);
  delay(2000);
}

void openlid() {
  servo.write(20);
  delay(500);
  servo.write(40);
  delay(500);
  servo.write(60);
  delay(500);
}

void setup() {
  servo.attach(12);
  pinMode(10, OUTPUT);
  pinMode(11, INPUT);
}

void loop() {
  closelid();
  d = ping();
  if (d<10) {
    openlid();
    delay(6000);
    closelid();  
  }
}
