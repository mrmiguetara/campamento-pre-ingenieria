#include <LiquidCrystal.h>
#include <Adafruit_NeoPixel.h>
#define BUTTON 3
#define ALARMA_ON 4
#define ACTIVED 5
#define RING 6 
#define PIR 13
#define NUMLED 16

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);   // Configura pines de salida para el LCD
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMLED, RING, NEO_GRB + NEO_KHZ800);

int melody[] = {523, 0, 392, 392, 440, 392, 0, 494, 523}; //(SOL 392, LA 440, SI  494, DO 523)
int SLong[] = {2, 2, 2, 2, 3, 2, 3, 2, 2}; 

int red = 0;
int green = 0;
int blue = 0;

void setup() {
  lcd.begin(16, 2);
  pixels.begin();
  pinMode(BUTTON, INPUT);
  pinMode(PIR, INPUT);
  pinMode(ALARMA_ON, OUTPUT);
  pinMode(ACTIVED, OUTPUT);
  pinMode(RING, OUTPUT);
  
//**************************************************  
//***********      INICIE AQUI      ****************  
  
  LCD_WELCOME();         //LETRERO DE BIENVENIDA
  LCD_ACTIVAR_ALARMA();  //LETRERO DE ACTIVAR ALARMA
}

//-----------------NO CAMBIAR ------------------------  
void loop() {
    if (digitalRead(BUTTON)== 1){
//---------------------------------------------------  
//*****************CONTINUE AQUI  ********************  
      
    LED_ALARMA_ON ();       // INDICADOR DE ALARMA ON
  	LCD_ALARMA_ACTIVADA();  // LETRERO DE ALARMA ON 
  
  }
//-----------------NO CAMBIAR ------------------------  
   if (digitalRead(ALARMA_ON)== 1){
//---------------------------------------------------       
//*****************CONTINUE AQUI  ********************  
       
   CIRCULO_LUZ_ACTIVA();   // ANILLO ALARMA ON

 //-----------------NO CAMBIAR ------------------------ 
    if (digitalRead(PIR)== 1){ 
 //---------------------------------------------------  
 //*****************CONTINUE AQUI  ********************    
     
 LED_ACTIVADO ();     //INDICADOR DE ALARMA ACTIVADA
 LCD_ADVERTENCIA();   // LETRERO DE ALARMA ACTIVADA
 CIRCULO_LUZ_ROJA();  // ANILLO INDICADOR DE INTRUSO
 AUDIO_FINAL();       // AUDIO INTRUSO DETECTADO
 LCD_FINAL();         // INDICADOR DE FINAL DE LA ACTIVIDAD
      
//***********PROGRAMACION FINALIZADA ***************  
//**************************************************        
      

    
    
    
    }
  }
}
void LED_ALARMA_ON () {
 digitalWrite(ALARMA_ON, HIGH); 
}  
void LED_ACTIVADO () {
 digitalWrite(ACTIVED, HIGH); 
}
void CIRCULO_LUZ_ACTIVA(){  
  red = random(0, 255);
  green = random(0,255);
  blue = random(0, 255);
  for (int i=0; i < NUMLED; i++)  {
    pixels.setPixelColor(i, pixels.Color(red, green, blue));
    pixels.show();
    delay(50);
  }
}
void CIRCULO_LUZ_ROJA(){  
  red = 255;
  green = 0;
  blue = 0;
  for (int i=0; i < NUMLED; i++)  {
    pixels.setPixelColor(i, pixels.Color(red, green, blue));
    pixels.show();
    delay(0);
  }digitalWrite(ALARMA_ON, LOW);
}
// LCD welcome and other messages

void LCD_WELCOME(){
    lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("WELCOME TO UPRM");
    lcd.setCursor(1,1);
  lcd.print("CAMP. ICOM 2023");
   delay(3000);
}
void LCD_ACTIVAR_ALARMA(){
    lcd.clear();
  lcd.setCursor(0,0);
   lcd.print("ACTIVE LA ALARMA");
    delay(1000);
  for(int o=0; o<3; o++){
  lcd.setCursor(1,1);
   lcd.print("PULSE EL BOTON");
    delay(300);
   lcd.setCursor(0,1);
   lcd.print("               ");
    delay(300);
   } 
   lcd.setCursor(1,1);
   lcd.print("PULSE EL BOTON");
}

void LCD_ALARMA_ACTIVADA(){
 	lcd.clear();
  	lcd.setCursor(1, 0);
    lcd.print("ALARMA ACTIVADA");
    lcd.setCursor(1,1);
   lcd.print("*  *  *  *  *  *  ");
 }
  
void LCD_ADVERTENCIA(){
 	lcd.clear();
  	lcd.setCursor(2, 0);
    lcd.print("ADVERTENCIA");
   delay(1500);
  for(int o=0; o<5; o++){
   lcd.setCursor(0,1);
   lcd.print("AREA RESTRINGIDA");
    delay(300);
   lcd.setCursor(0,1);
   lcd.print("                ");
    delay(300);
  }
   lcd.setCursor(2,1);
   lcd.print(">..<  :(  >..<");
}
void LCD_FINAL(){
    delay(1000);
 	lcd.clear();
  	lcd.setCursor(4, 0);
    lcd.print("ACTIVIDAD");
    lcd.setCursor(3,1);
   lcd.print("FINALIZADA");
 }
  
// MODULE 2: BUTTON - LED - BUZZER

void LED_ALARMA_ACTIVADA() { 
   
  if (digitalRead(13)== 1){
    digitalWrite(5, HIGH);
	    //delay(1000);
     }
}
void AUDIO_FINAL() {
    for (int sound = 0; sound < 9; sound++) {
    int Long = 100 * SLong[sound];
    tone(A5, melody[sound], Long);
    int pauses = Long * 0.85;
    delay(pauses);
    noTone(9);  
    } digitalWrite(ACTIVED, LOW); 
}
