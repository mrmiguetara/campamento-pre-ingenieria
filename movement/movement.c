
 //****Diseñó Ing. Yohan Aparicio UPRM junio 2021*** 
//****Con colaboración librerías de Tinkercad****
//-----------------NO CAMBIAR ------------------------
void setup()
{
  pinMode(13, INPUT);
  pinMode(6, OUTPUT);
}
void loop()
{
//***********  	INICIE AQUÍ  	****************  
 
 
PIRS(); // SENSOR DE MOVIMIENTO
 //-----------------NO CAMBIAR ------------------------ 
}
 void PIRS() 
 {
 if (digitalRead(13)== 1)
{
  	digitalWrite(6, HIGH);
        	delay(1000);
	digitalWrite(6, LOW);
}
}
