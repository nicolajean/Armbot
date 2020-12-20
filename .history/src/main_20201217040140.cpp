/*

 ARMBOT v1.0 - 2020

 Controlling a Robot arm position using :
 - 6 Servo, 
 - 1 potentiometer,
 - 3 analog joytick
 by nj1337 <https://github.com/nicolajean>
*/


/* --------------------------------------------------------
 INCLUDE
 ---------------------------------------------------------- */

#include <Arduino.h>
#include <Servo.h>


/* --------------------------------------------------------
 VARIABLES
 ---------------------------------------------------------- */

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
// Variables Servo
int pinPince = 8;
int pinRotationPince = 7;
int pinBras1 = 6;
int pinBras2 = 5;
int pinBras3 = 4;
int pinRotationBras = 3;
Servo pince;
Servo RotationPince;
Servo Bras1;
Servo Bras2;
Servo Bras3;
Servo RotationBras;

// Variables potentiometre
int potPin = A6;
int potVal;


/* --------------------------------------------------------
 SETUP
 ---------------------------------------------------------- */

void setup() {
    // Servo
    pince.attach(pinPince);
    RotationPince.attach(pinRotationPince);
    Bras1.attach(pinBras1);
    Bras2.attach(pinBras2);
    Bras3.attach(pinBras3);
    RotationBras.attach(pinRotationBras);

    // Set initial servo postion
    pince.write(180);
    RotationPince.write(90);
    Bras1.write(90);
    Bras2.write(90);
    Bras3.write(90);
    RotationBras.write(90);

    // potentionmetre
    pinMode(potPin, INPUT);

    // Serial
    Serial.begin(9600);
}

void loop() {

  potVal = analogRead(potPin);
  int delayServo = map(potVal, 0, 1024, 15, 50);
  Serial.print("delay:"); Serial.print(potVal); Serial.print(" - "); Serial.println(delayServo); 

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







}