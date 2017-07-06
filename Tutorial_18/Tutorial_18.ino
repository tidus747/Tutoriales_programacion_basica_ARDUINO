/* Copyright (C) 2017 Iván Rodríguez Méndez
This software is distributed under the GNU General Public
Licence (version 3 or later); please refer to the file
Licence.txt, included with the software, for details.
*/

// Tutorial 18: Imprimiendo variables en un LCD

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Inicia el LCD en la dirección 0x27, con 16 caracteres y 2 líneas
int i,x;
float y;

void setup()
{
   lcd.begin();                      
   lcd.backlight();
   lcd.setCursor(0, 0);
   lcd.print("Bienvenidos");
   lcd.setCursor(0, 1);
   lcd.print("al tutorial 18!");
   delay(5000);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("de");
   lcd.setCursor(4,1);
   lcd.print("Piensa 3D");
   delay(5000);
   lcd.clear();
}
 
void loop()
{
  x = 1; 
  y = 2;
  lcd.setCursor(0,0);
  lcd.print("Sumando:");
  for (i=0;i<10;i++){
    lcd.setCursor(9,0);
    x= x+x;
    lcd.print(x);
    delay(300);
  }
  lcd.setCursor(0,1);
  lcd.print("Multi:");
  for (i=0;i<16;i++){
    lcd.setCursor(7,1);
    y= y*float(1.5);
    lcd.print(y,2);
    delay(300);
  }
  delay(2500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("No olvides");
  lcd.setCursor(0,1);
  lcd.print("  suscribirte");
  delay(3000);
  lcd.clear();
}

