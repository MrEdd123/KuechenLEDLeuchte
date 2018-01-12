//ESP NodeMcu

// variablen


uint16_t PWM = 800;
uint8_t Hoch = 0;
uint8_t Runter = 0;


void setup()
{
	
	pinMode(D6, OUTPUT);
	analogWrite(D6, PWM);				// LED Startwert 
	pinMode(D3, INPUT_PULLUP);
	pinMode(D2, INPUT_PULLUP);
	pinMode(D1, OUTPUT);				//Blink LED
	
}

void loop()
{

	 //Tasterrauf abfrage
	Hoch = digitalRead(D3);
	if (Hoch == LOW) {

		if (PWM < 1023, PWM++);
		if (PWM >= 1024) { PWM = 1023; blink(); }
		/*Serial.print("Rauf:");
		Serial.println(PWM);*/
		analogWrite(D6, PWM);
		
		delay(10);

	}
	

	//Tasterunter abfrage
	Runter = digitalRead(D2);
	if (Runter == LOW) {

		if (PWM >= 1023, PWM--);
		if (PWM <= 21) { PWM = 20; blink() ; }
		/*Serial.print("Runter:");
		Serial.println(PWM);*/
		analogWrite(D6, PWM);

		delay(10);
	}
}

void blink() {
	
	for (int i = 0; i < 2; i++) {

		digitalWrite(D1, HIGH);
		delay(50);
		digitalWrite(D1, LOW);
		delay(50);

	}
}
