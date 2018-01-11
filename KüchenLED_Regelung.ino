//ESP NodeMcu

// variablen


uint16_t PWM = 800;
uint8_t Hoch = 0;
uint8_t Runter = 0;


void setup()
{
	analogWrite(2, PWM);				// LED Startwert 
	pinMode(D3, INPUT_PULLUP);
	pinMode(D2, INPUT_PULLUP);
	
}

void loop()
{

	 //Tasterrauf abfrage
	Hoch = digitalRead(D3);
	if (Hoch == LOW) {

		if (PWM < 1023, PWM++);
		if (PWM == 1024) { PWM = 1023; }
		Serial.print("Rauf:");
		Serial.println(PWM);
		analogWrite(2, PWM);
		
		delay(10);

	}
	

	//Tasterunter abfrage
	Runter = digitalRead(D2);
	if (Runter == LOW) {

		if (PWM >= 1023, PWM--);
		if (PWM <= 20) { PWM = 20; }
		Serial.print("Runter:");
		Serial.println(PWM);
		analogWrite(2, PWM);

		delay(10);
	}
}
