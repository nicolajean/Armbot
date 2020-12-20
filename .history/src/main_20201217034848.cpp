/*

 ARMBOT v1.0 - 2020

 Controlling a Robot arm position using :
 - 6 Servo, 
 - 1 potentiometer,
 - 3 analog joytick
 by nj1337 <https://github.com/nicolajean>
*/

#include <Arduino.h>
#include <Servo.h>

// Variables Joystick
const int X1 = A0;
const int Y1 = A1;
const int X2 = A2;
const int Y2 = A3;
const int X3 = A4;
const int Y3 = A5;
int calX1, calY1, rawX1, rawY1;
int calX2, calY2, rawX2, rawY2;
int calX3, calY3, rawX3, rawY3;
int servoPin = 4;

Servo myservo;
int pos = 0;             // variable permettant de conserver la position du servo
int angle_initial = 0;   //angle initial
int angle_final = 180;   //angle final
int increment = 1;       //incrément entre chaque position
bool angle_actuel = false;//Envoi sur le port série la position courante du servomoteur

// Variables potentiometre
int potPin = A7;
int potVal;

void setup() {
    // Calibration des axes
    //calX = analogRead(VRx);
    //calY = analogRead(VRy);
    // Servo
    myservo.attach(servoPin);
    // potentionmetre
    pinMode(potPin, INPUT);

    // Serial
    Serial.begin(9600);
}

void loop() {

  /*

  // Mesure des valeurs en X et YnrawX = analogRead(VRx)- calX;
  rawX = analogRead(VRx)- calX;
  rawY = analogRead(VRy)- calY;
  rawSW = digitalRead(SW);
  // Affichage des valeurs lues
  Serial.println("--- Nouvelles lectures --- ");
  Serial.print("Valeur X : ");  Serial.println((int)(rawX));
  Serial.print("Valeur y : ");  Serial.println((int)(rawY));
  Serial.print("Switch : ");
  if(rawSW == HIGH) {
    Serial.println("ON");
  } else {
    Serial.println("OFF");
  }
  delay(500);// Temps de pause entre lecture
  */

potVal = analogRead(potPin);
Serial.println(potVal);
int delayServo = map(potVal, 0, 1024, 15, 50);
Serial.println(delayServo);

for (pos = angle_initial; pos <= angle_final; pos += increment) {   // Déplace le servo de 0 à 180 degréespar pas de 1 degrée 
    myservo.write(pos);                                             // Demande au servo de se déplacer à cette position angulaire
    delay(delayServo);                                                      // Attend 30ms entre chaque changement de position
    //Serial.println(myservo.read());
}
for (pos = angle_final; pos >= angle_initial; pos -= increment) { // Fait le chemin inverse
  myservo.write(pos);              
  delay(delayServo);   
  //Serial.println(myservo.read());
}



}