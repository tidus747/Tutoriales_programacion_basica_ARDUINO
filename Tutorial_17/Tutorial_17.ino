/* Copyright (C) 2017 Iván Rodríguez Méndez
This software is distributed under the GNU General Public
Licence (version 3 or later); please refer to the file
Licence.txt, included with the software, for details.
*/

// Tutorial 17: Funcionamiento basico de un LCD

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Inicia el LCD en la dirección 0x27, con 16 caracteres y 2 líneas
int i;
 
void setup()
{
   lcd.begin();                      
   lcd.backlight();
   lcd.setCursor(0, 0);
   lcd.print("Bienvenidos");
   lcd.setCursor(0, 1);
   lcd.print("al tutorial 17!");
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
  lcd.setCursor(0,0);
  lcd.print("Cargando...");
  for (i=0;i<16;i++){
    lcd.setCursor(i,1);
    lcd.print("-");
    delay(500);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Pruebas con LCD");
  lcd.setCursor(0,1);
  lcd.print("de 16x2 con I2C");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("No olvides");
  lcd.setCursor(0,1);
  lcd.print("  suscribirte");
  delay(3000);
  lcd.clear();
}


