/* Copyright (C) 2017 Iván Rodríguez Méndez
This software is distributed under the GNU General Public
Licence (version 3 or later); please refer to the file
Licence.txt, included with the software, for details.
*/

// Creación de un semáforo con ARDUINO

int tiempoCambio = 5000;
int rojoPin = 10 ;
int amarilloPin = 9;
int verdePin = 8;

void setup(){
 pinMode(rojoPin, OUTPUT);
 pinMode(amarilloPin, OUTPUT);
 pinMode(verdePin, OUTPUT);
}

void loop() {
 digitalWrite(rojoPin, HIGH);
 delay(tiempoCambio);

 digitalWrite(amarilloPin, HIGH);
 delay(1000);

 digitalWrite(verdePin, HIGH);
 digitalWrite(amarilloPin, LOW);
 digitalWrite(rojoPin, LOW);
 delay(tiempoCambio);

 digitalWrite(amarilloPin, HIGH);
 digitalWrite(verdePin, LOW);
 delay(1000);

 digitalWrite(amarilloPin, LOW);
}
