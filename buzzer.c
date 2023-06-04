
//****Diseñó Ing. Yohan Aparicio UPRM junio 2021*** 
//****Con colaboración librerías de Tinkercad****
//-----------------NO CAMBIAR ------------------------ 
int melody[] = {523, 0, 392, 392, 440, 392, 0, 494, 523}; //(SOL 392, LA 440, SI  494, DO 523)
int SLong[] = {2, 1, 2, 2, 3, 2, 3, 2, 2};
void setup() {
  pinMode(A5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, INPUT);
 }
 // MODULE 2: BUTTON - LED - BUZZER
void loop() {
   if (digitalRead(3)== 1){
 	digitalWrite(4, HIGH);
  //*****************SE PUEDE CAMBIAR  ********************
	AUDIO_FINAL();
 	//-----------------NO SE DEBE CAMBIAR ------------------------     
	delay(1200);
 	digitalWrite(4, LOW);
	}
}
void AUDIO_FINAL(){
    for (int sound = 0; sound < 9; sound++) {
	int Long = 100 * SLong[sound];
	tone(A5, melody[sound], Long);
	int pauses = Long * 0.85;
	delay(pauses);
	noTone(9); 
	} 
}

