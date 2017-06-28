/* Copyright (C) 2017 Iván Rodríguez Méndez
This software is distributed under the GNU General Public
Licence (version 3 or later); please refer to the file
Licence.txt, included with the software, for details.
*/

//Tutorial 16: Simbolos en matriz de LEDS

#include "LedControlMS.h" 

LedControl lc=LedControl(12,11,10,1); // Los numeros se refieren a que pin de ARDUINO tienes en cada uno de los terminales
/* 12 para el DIN, 11 para el CLK, 10 para el CS y el 1 se refiere a la asignacion de la matriz*/ 

//Corazón pequeño
byte Corazon_datos[] = {
B00000000,
B01100110,
B11111111,
B11111111,
B01111110,
B00111100,
B00011000,
B00000000};

byte Cara_datos[] = 
{B00111100,
B01000010,
B10100101,
B10000001,
B10100101,
B10011001,
B01000010,
B00111100};

byte Mensaje_datos[] = 
{B00000000,
B00000100,
B00000000,
B01010100,
B01110100,
B01010100,
B00000000,
B00000000};

void setup()
{
  // El numero que colocamos como argumento de la funcion se refiere a la direccion del decodificador
  lc.shutdown(0,false);
  lc.setIntensity(0,8);// La valores estan entre 1 y 15 
  lc.clearDisplay(0);
  
}
void loop()
{
  Representar(Mensaje_datos,5000);
  trans();
  delay(500);
  Representar(Corazon_datos,5000);
  Representar(Cara_datos,3000);
  lc.clearDisplay(0);
}

// Funcion para representar una transicion animada

void trans(){ //Funcion de transicion para llenar y vaciar la pantalla de puntos
  for (int row=0; row<8; row++)
  {
    for (int col=0; col<8; col++)
    {
      lc.setLed(0,col,row,true); // 
      delay(25);
    }
  }
 
  for (int row=0; row<8; row++)
  {
    for (int col=0; col<8; col++)
    {
      lc.setLed(0,col,row,false); // 
      delay(25);
    }
  }
}

// Definimos una funcion para representar las figuras

void Representar(byte *Datos,int retardo) //Funcion para la representacion de bytes de datos para una matriz de 8x8 
{
  for (int i = 0; i < 8; i++)  
  {
    lc.setColumn(0,i,Datos[7-i]);
  }
  delay(retardo);
}


  
