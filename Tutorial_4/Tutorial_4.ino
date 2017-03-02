/* Copyright (C) 2017 Iván Rodríguez Méndez
This software is distributed under the GNU General Public
Licence (version 3 or later); please refer to the file
Licence.txt, included with the software, for details.
*/

// Semáforo para coches y peatones (entradas digitales) ARDUINO

int carRed = 12 ;
int carYellow = 11;
int carGreen = 10;
int peaRed = 9;
int peaGreen = 8;

int button = 2;

int TiempoCruce = 5000;
unsigned long TiempoCambio = 0;

void setup(){

  pinMode(carRed, OUTPUT);
  pinMode(carYellow, OUTPUT);
  pinMode(carGreen, OUTPUT);
  pinMode(peaRed, OUTPUT);
  pinMode(peaGreen, OUTPUT);

  pinMode(button, INPUT);

  digitalWrite(carGreen, HIGH);
  digitalWrite(peaRed, HIGH);
}

void loop() {

  int estado = digitalRead(button);

  if (estado == HIGH && (millis() - TiempoCambio) > 5000 ){
   cambioLuz();
  }
}

void cambioLuz() {

  digitalWrite(carGreen,LOW);
  digitalWrite(carYellow, HIGH);
  delay(2000);

  digitalWrite(carYellow, LOW);
  digitalWrite(carRed, HIGH);
  delay(1000);

  digitalWrite(peaRed, LOW);
  digitalWrite(peaGreen, HIGH);
  delay(TiempoCruce);

  for (int x=0; x<10; x++) {
  digitalWrite(peaGreen, HIGH);
  delay(250);
  digitalWrite(peaGreen, LOW);
  delay(250);

  }

  digitalWrite(peaRed, HIGH);
  delay(500);

  digitalWrite(carYellow, HIGH);
  digitalWrite(carRed, LOW);
  delay(1000);

  digitalWrite(carGreen, HIGH);
  digitalWrite(carYellow, LOW);

  TiempoCambio = millis();

}
