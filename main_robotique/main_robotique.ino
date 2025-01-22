#include <Servo.h>

Servo finger1, finger2, finger3, finger4, finger5;

int signal1, signal2, signal3, signal4, signal5;
int angle1, angle2, angle3, angle4, angle5;

void setup() {
  finger1.attach(3);  // Associer le doigt 1 à la broche 3
  finger2.attach(5);  // Associer le doigt 2 à la broche 5
  finger3.attach(6);  // Associer le doigt 3 à la broche 6
  finger4.attach(9);  // Associer le doigt 4 à la broche 9
  finger5.attach(10); // Associer le doigt 5 à la broche 10

  Serial.begin(9600); // Initialisation de la communication série
}

void loop() {
  // Lire les valeurs des signaux analogiques
  signal1 = analogRead(A0);
  signal2 = analogRead(A1);
  signal3 = analogRead(A2);
  signal4 = analogRead(A3);
  signal5 = analogRead(A4);

  // Mapper les valeurs des signaux pour obtenir des angles (0-180 degrés)
  angle1 = map(signal1, 240, 639, 0, 180);
  angle2 = map(signal2, 240, 639, 0, 180);
  angle3 = map(signal3, 240, 639, 0, 180);
  angle4 = map(signal4, 240, 639, 0, 180);
  angle5 = map(signal5, 240, 639, 0, 180);

  // Contrôler les servos avec les angles calculés
  finger1.write(angle1);
  finger2.write(angle2);
  finger3.write(angle3);
  finger4.write(angle4);
  finger5.write(angle5);

  delay(50); // Attente pour stabiliser les mouvements
}
