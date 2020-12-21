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
int rawX1, rawY1, rawX2, rawY2, rawX3, rawY3;

// Variables Servo
int pinPince            = 8;
int pinRotationPince    = 7;
int pinBras1            = 6;
int pinBras2            = 5;
int pinBras3            = 4;
int pinRotationBras     = 3;
int PinceValue          = 90;
int RotationPinceValue  = 90;
int Bras1Value          = 90;
int Bras2Value          = 90;
int Bras3Value          = 90;
int RotationBrasValue   = 90;
Servo pince;
Servo RotationPince;
Servo Bras1;
Servo Bras2;
Servo Bras3;
Servo RotationBras;

// Variables potentiometre
int potPin      = A6;
int delayServo  = 15;
int potVal, increment;      


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
    pince.write(PinceValue);
    RotationPince.write(RotationPinceValue);
    Bras1.write(Bras1Value);
    Bras2.write(Bras2Value);
    Bras3.write(Bras3Value);
    RotationBras.write(RotationBrasValue);

    // potentionmetre
    pinMode(potPin, INPUT);

    // Serial
    Serial.begin(9600);
}

void loop() {

  // calcul de la vitesse de mouvement.
  potVal = analogRead(potPin);
  if (potVal <= 205) ( increment = 1);
  if ((potVal > 205) && (potVal <= 410))  ( increment = 2);
  if ((potVal > 410) && (potVal <= 615))  ( increment = 3);
  if ((potVal > 615) && (potVal <= 820))  ( increment = 4);
  if ((potVal > 820) && (potVal <= 1024)) ( increment = 5);
  
  Serial.print("delay:"); Serial.print(potVal); Serial.print(" - "); 

  // Mesure des valeurs en X et Y des joysticks
  rawX1 = analogRead(X1);
  rawX2 = analogRead(X2);
  rawX3 = analogRead(X3);
  rawY1 = analogRead(Y1);
  rawY2 = analogRead(Y2);
  rawY3 = analogRead(Y3);

  // Bouger le servo pince
  if (rawX1 > 520 || rawX1 < 500) {
    int val1 = map(rawX1, 0, 1023, -1, +1);  
    PinceValue = PinceValue + val1;       
    if (PinceValue <= 180) { pince.write(PinceValue);  }
    if (PinceValue > 180)  { PinceValue = 180; }
    if (PinceValue < 0)    { PinceValue = 0;   }  
  }
  // Bouger le servo pince
  if (rawY1 > 520 || rawY1 < 500) {
    int val2 = map(rawY1, 0, 1023, -1, +1); 
    RotationPinceValue = RotationPinceValue + val2;       
    if (RotationPinceValue <= 180) { pince.write(RotationPinceValue);  }
    if (RotationPinceValue > 180)  { RotationPinceValue = 180; }
    if (RotationPinceValue < 0)    { RotationPinceValue = 0;   }  
  }



  delay(delayServo);






}