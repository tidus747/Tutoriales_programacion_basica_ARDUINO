/* Copyright (C) 2017 Kevin Meneses
This software is distributed under the GNU General Public
Licence (version 3 or later); please refer to the file
Licence.txt, included with the software, for details.
*/

// Tutorial 19: Funcionamiento de tarjeta SD con Arduino

/*
Conexiones Modulo tarjetas SD
Conexiones para Arduino Uno o nano 
 CS----> D12
 SCK---> D13
 MOSI ---> D11
 MISO--> D10
 VCC--> VCC
 GND--> GND


 */

#include <SPI.h>
#include <SD.h>

File myFile;

void setup() {
  // Habilitamos el puerto serie a 9600
  Serial.begin(9600);

  Serial.print("Empezamos el tutorial, Comunicando con tarjeta SD!..."); // Mensaje de bienvenida

  if (!SD.begin(10)) { //
    Serial.println("Fallo en la inicializacion, Compruebe las conexiones"); // Se comprueba que si la inicialización es correcta.
    return;
  }
  Serial.println("Inicializacion realizada con exito.");

  myFile = SD.open("test.txt", FILE_WRITE); // Creamos un archivo con el nombre test y la extension de texto.txt

  if (myFile) { // Si se ha creado correctamente el archivo, escribimo en el
    Serial.println("Piensa 3D");
    myFile.println("Un canal donde aprenderas todo lo relacionado con la electronica y mucho mas !"); // Salto de linea
    myFile.println(" No olvides Compartir el video y Suscribirte tu apoyo es nuestro oxigeno");
    // close the file:
    myFile.close(); 
    Serial.println("Archivo cerrado con exito .");
  } else {
    Serial.println("No se ha podido abrir el archivo");
  }
}
 

void loop() {
  // nothing happens after setup
}


