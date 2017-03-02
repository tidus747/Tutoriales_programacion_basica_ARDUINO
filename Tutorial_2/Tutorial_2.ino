/* Copyright (C) 2017 Iván Rodríguez Méndez
This software is distributed under the GNU General Public
Licence (version 3 or later); please refer to the file
Licence.txt, included with the software, for details.
*/

// Hablemos en MORSE con ARDUINO

// Definimos el pin del LED
int led = 13;

//Inicializacion

void setup(){
  pinMode(led,OUTPUT);
}

void loop() {
 // 3 puntos, letra S
for (int x=0; x < 3 ; x++){
   digitalWrite(led, HIGH);
   delay(150);
   digitalWrite(led, LOW);
   delay(100);
}

// Cambio de letra
delay(100);

// 3 Lineas, letra O
for (int x=0; x<3 ; x++){
   digitalWrite(led, HIGH);
   delay(400);
   digitalWrite(led, LOW);
   delay(100);
}

//Cambio de letra
delay(100);

// 3 puntos, letra S
for (int x=0; x < 3 ; x++){
   digitalWrite(led, HIGH);
   delay(150);
   digitalWrite(led, LOW);
   delay(100);
}

//Esperar un tiempo antes de volver a emitir el SOS
delay(2000);

}
