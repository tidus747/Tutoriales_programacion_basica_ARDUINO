/* Copyright (C) 2017 Iván Rodríguez Méndez
This software is distributed under the GNU General Public
Licence (version 3 or later); please refer to the file
Licence.txt, included with the software, for details.
*/

//Tutorial 13: Control simple de motor DC

int potPin = 1; // Pin en el que hacemos la conexion del potenciometro
int transistorPin = 9; // Pin para enviar la PWM por el transistor
int Valorpot = 0; // Valor que nos devuelve el potenciometro

void setup() {
  Serial.begin(9600);
 pinMode(transistorPin, OUTPUT); //Definimos como pin de salida el transistor
}
void loop() {
 // Leemos el valor del potenciometro y lo normaliamos entre 0 y 255
 Valorpot = analogRead(potPin) / 4;
 Serial.print(Valorpot);
 // Usamos el mismo valor que hemos leido para mandar al motor DC
 analogWrite(transistorPin, Valorpot);
 delay(500);
}
