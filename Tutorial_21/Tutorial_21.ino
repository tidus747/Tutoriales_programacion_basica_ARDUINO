/* Copyright (C) 2017 Iván Rodríguez Méndez
This software is distributed under the GNU General Public
Licence (version 3 or later); please refer to the file
Licence.txt, included with the software, for details.
*/

// Tutorial 21: Sensor de ultrasonidos

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Inicia el LCD en la dirección 0x27, con 16 caracteres y 2 líneas

const int EchoPin = 5;
const int TriggerPin = 6;
const int LedPin = 13;
 
void setup() {
   Serial.begin(9600);
   pinMode(LedPin, OUTPUT);
   pinMode(TriggerPin, OUTPUT);
   pinMode(EchoPin, INPUT);
   
   // Inicializamos el display con el mensaje de bienvenida
   
   lcd.begin();                      
   lcd.backlight();
   lcd.setCursor(0, 0);
   lcd.print("Bienvenidos");
   lcd.setCursor(0, 1);
   lcd.print("al tutorial 21!");
   delay(5000);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("de");
   lcd.setCursor(4,1);
   lcd.print("Piensa 3D");
   delay(5000);
   lcd.clear();
}
 
void loop() {
   int cm = ping(TriggerPin, EchoPin);
   lcd.setCursor(0,0);
   lcd.print("Distancia: ");
   lcd.setCursor(11,1);
   lcd.print(cm);
   lcd.setCursor(14,1);
   lcd.print("cm");
   delay(1000);
   lcd.clear();
}
 
int ping(int TriggerPin, int EchoPin) {
   long duration, distanceCm;
   
   digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);
   
   duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
   
   distanceCm = duration * 10 / 292/ 2;   //convertimos a distancia, en cm
   return distanceCm;
}
