
//****Diseñó Ing. Yohan Aparicio UPRM junio 2021*** 
//****Con colaboración librerías de Tinkercad****
//-----------------NO CAMBIAR ------------------------
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); 
void setup() {
  lcd.begin(16, 2);
}
void loop()
{
//-----------------SE PUEDE  CAMBIAR ------------------------  
LCDWEL();
  LCDALARM();
  // LCDDET();
 
//-----------------NO CAMBIAR ------------------------ 
}
void LCDWEL(){
	lcd.clear();
	lcd.setCursor(1,0);
  lcd.print("WELCOME TO UPRM");
   delay(2000);
	lcd.clear();
  lcd.setCursor(2,0);
   lcd.print("BIENVENID@S");
	delay(1000);
  for(int o=0; o<5; o++){
  lcd.setCursor(0,1);
   lcd.print("CAMPING RUM 2021");
	delay(300);
   lcd.setCursor(0,1);
   lcd.print("            	");
	delay(300);
  }   
  lcd.clear();
}
  void LCDALARM(){
	lcd.clear();
  lcd.setCursor(0,0);
   lcd.print("ACTIVE LA ALARMA");
	delay(1000);
  for(int o=0; o<5; o++){
  lcd.setCursor(1,1);
   lcd.print("PULSE EL BOTON");
	delay(300);
   lcd.setCursor(0,1);
   lcd.print("           	");
	delay(300);
  } 
	lcd.clear();
}
void LCDDET(){
        	lcd.clear();
        	lcd.setCursor(2, 0);
	lcd.print("ADVERTENCIA");
   delay(1500);
  for(int o=0; o<5; o++){
   lcd.setCursor(0,1);
   lcd.print("AREA RESTRINGIDA");
	delay(300);
   lcd.setCursor(0,1);
   lcd.print("            	");
	delay(300);
  }}
