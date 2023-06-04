
//****Diseñó Ing. Yohan Aparicio UPRM junio 2021*** 
//****Con colaboración librerías de Tinkercad****
//-----------------NO CAMBIAR ------------------------ 
  #include <Adafruit_NeoPixel.h>
#define RING 6
#define NUMLED 12
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMLED, RING, NEO_GRB + NEO_KHZ800);
int red = 0;
int green = 0;
int blue = 0;
void setup() {
  pixels.begin();
}
void loop() {
//-----------------SE PUEDE CAMBIAR ------------------------
 
  CIRCULO_LUZ_ACTIVA();
 
//----------------------NO CAMBIAR ------------------------
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
