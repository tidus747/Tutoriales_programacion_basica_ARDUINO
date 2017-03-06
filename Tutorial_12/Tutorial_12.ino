/* Copyright (C) 2017 Iván Rodríguez Méndez
This software is distributed under the GNU General Public
Licence (version 3 or later); please refer to the file
Licence.txt, included with the software, for details.
*/

// Tutorial 12- Sensor de luz
 
int ledPin = 9; // Piezo on Pin 8
int ldrPin = 0; // LDR en el pin analogico 0

int ldrValue = 0;
 
void setup() {
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
}
 
void loop() {
  ldrValue = analogRead(ldrPin); 
  Serial.print(ldrValue);
  if (ldrValue >= 1010){
    digitalWrite(ledPin,HIGH);
  }
  else {
    digitalWrite(ledPin,LOW);
  }
  delay(500);



}
