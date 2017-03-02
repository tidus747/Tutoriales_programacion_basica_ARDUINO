/* Copyright (C) 2017 Iván Rodríguez Méndez
This software is distributed under the GNU General Public
Licence (version 3 or later); please refer to the file
Licence.txt, included with the software, for details.
*/

// Tutorial 8: Controlar LED RGB por SERIAL

char buffer[18]; //Aqui guardaremos todos los caracteres necesarios
int red, green, blue;

int RedPin = 11;
int GreenPin = 10;
int BluePin = 9;

void setup() {
  Serial.begin(9600);
  while(Serial.available()){
    Serial.read();
  }
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
  Serial.println("Preparado para recibir datos!");
}


void loop() {
  if (Serial.available() > 0) {
    int i = 0; //indice para movernos por el array
    delay(100); // Esperamos para asegurarnos de recibir los datos
    int numChar = Serial.available(); //Guardamos el numero de caracteres disponibles
    if (numChar>15) { //Comprobamos que el numero de caracteres es mayor al menos que 15, lo que significar que esta bien introducido
      numChar=15;
    }

    while (numChar--) { //Siempre que sea mayor que cero
      buffer[i++] = Serial.read(); //Vamos guardando los caracteres que hemos recibido
    }
    dividirString(buffer); //Hacemos la llamada a la funcion que hemos creado, pasando el parametro por referencia
  }
}



void dividirString(char* datos) { //La funcion trabaja con un puntero a nuestro array de datos, por lo cual pasamos el parametro por referencia
  Serial.println(" ");
  Serial.print("Color de entrada: ");
  Serial.println(datos);
  char* parameter; //Creamos un nuevo puntero para acceder a los datos almacenados
  parameter = strtok (datos, " ,"); //Quitamos lo que hay despues de encontrar la primera coma
  while (parameter != NULL) {
    setLED(parameter); //Encendemos la componente de color tal y como queremos
    parameter = strtok (NULL, " ,"); // Al poner NULL seguimos donde nos habiamos quedado y seguimos recortando
  }

  // Re-inicializamos todo
  for (int x=0; x<16; x++) {
    buffer[x]='\0';
  }
  while(Serial.available())
    Serial.read();
  Serial.println(" ");
  Serial.println("Preparado para recibir nuevos datos!");
}

void setLED(char* datos) { //Funcion para encender la componente de color del LED que queremos
  if ((datos[0] == 'r') || (datos[0] == 'R')) {
    int Ans = strtol(datos+1, NULL, 10);
    Ans = constrain(Ans,0,255); //Nos aseguramos de que el resultado este entre 0 y 255
    analogWrite(RedPin, Ans);
    Serial.print("Componente de rojo en: ");
    Serial.println(Ans);
  }
  if ((datos[0] == 'g') || (datos[0] == 'G')) {
    int Ans = strtol(datos+1, NULL, 10);
    Ans = constrain(Ans,0,255);
    analogWrite(GreenPin, Ans);
    Serial.print("Componente de verde en: ");
    Serial.println(Ans);
  }
  if ((datos[0] == 'b') || (datos[0] == 'B')) {
    int Ans = strtol(datos+1, NULL, 10);
    Ans = constrain(Ans,0,255);
    analogWrite(BluePin, Ans);
    Serial.print("Componente de azul en: ");
    Serial.println(Ans);
  }
}
