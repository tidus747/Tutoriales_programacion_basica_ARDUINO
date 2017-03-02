/* Copyright (C) 2017 Iván Rodríguez Méndez
This software is distributed under the GNU General Public
Licence (version 3 or later); please refer to the file
Licence.txt, included with the software, for details.
*/


// Tutorial 11 - Pulsador con zumbador

int ledPin = 9;
int piezoPin = 5;
int threshold = 15; // Valor para el que se activa el LED
int sensorValue = 0; // Variable para almacenar el valor del sensor
float ledValue = 0; // Regulacin del brillo

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

  // Parpadeo inicial
  digitalWrite(ledPin, HIGH); delay(150); digitalWrite(ledPin, LOW); delay(150);
  digitalWrite(ledPin, HIGH); delay(150); digitalWrite(ledPin, LOW); delay(150);
}

void loop() {

  sensorValue = analogRead(piezoPin);
  Serial.print(sensorValue);
  if (sensorValue >= threshold) {
    ledValue = 255;
  }
  analogWrite(ledPin, int(ledValue) );
  ledValue = ledValue - 0.05;
  if (ledValue <= 0) {
    ledValue = 0;
   }
}
