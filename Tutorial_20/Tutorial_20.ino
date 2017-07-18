/* Copyright (C) 2017 Kevin Meneses
This software is distributed under the GNU General Public
Licence (version 3 or later); please refer to the file
Licence.txt, included with the software, for details.
*/

// Tutorial 20: ¿Cómo utilizar un acelerómetro con ARDUINO?

#define ejeX 3
#define ejeY 2
#define ejeZ 1
#define YellowLed 2
#define RedLed 3
#define GreenLed 4
int x,y,z;
void setup() {
  pinMode(ejeX,INPUT);
   pinMode(ejeY,INPUT);
    pinMode(ejeZ,INPUT);
     pinMode(YellowLed,OUTPUT);
   pinMode(RedLed,OUTPUT);
    pinMode(GreenLed,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  x=analogRead(ejeX);
  y=analogRead(ejeY);
  z=analogRead(ejeZ);
 Serial.print(" El valor del eje X es: ");
 Serial.println(x);
 Serial.print(" El valor del eje Y es: ");
 Serial.println(y);
 Serial.print(" El valor del eje Z es: ");
 Serial.println(z);
 if( x>400){
  digitalWrite(GreenLed,HIGH);
 }
 else{
  digitalWrite(GreenLed,LOW);
 }
 if(z>400){
   digitalWrite(RedLed,HIGH);
 }
  else{
  digitalWrite(RedLed,LOW);
 }
 if(y>400){
   digitalWrite(YellowLed,HIGH);
 }
 else{
  digitalWrite(YellowLed,LOW);
 }


}
