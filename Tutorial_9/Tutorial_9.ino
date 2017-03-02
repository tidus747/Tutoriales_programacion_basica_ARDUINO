/* Copyright (C) 2017 Iván Rodríguez Méndez
This software is distributed under the GNU General Public
Licence (version 3 or later); please refer to the file
Licence.txt, included with the software, for details.
*/

// Tutorial 9: Señal de alarma ARDUINO

float sinVal;
int toneVal;

void setup() {
  pinMode(8, OUTPUT);
}

void loop() {
  for (int x=0; x<180; x++) {
  // pasamos de grados a radianes
  sinVal = (sin(x*(3.1412/180)));

  // Generamos el tono, o mejor dicho la frecuencia

  toneVal = 2000+(int(sinVal*1000));
  tone(8, toneVal,2);

  }
}
