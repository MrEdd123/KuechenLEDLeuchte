//ESP NodeMcu

// variablen


#include <EEPROM.h>
uint16_t PWM;
uint8_t Hoch = 0;
uint8_t Runter = 0;


void setup()
{
	Serial.begin(115200);
	EEPROM.begin(64);
	pinMode(D6, OUTPUT);
	 
	pinMode(D3, INPUT_PULLUP);
	pinMode(D2, INPUT_PULLUP);
	pinMode(D1, OUTPUT);				//Blink LED
	digitalWrite(D1, HIGH);
	
	EEPROM.get(0, PWM);
	EEPROM.commit();
	EEPROM.end();
	analogWrite(D6, PWM);				// LED Startwert
}

void loop()
{
	Serial.println(PWM);
	 //Tasterrauf abfrage
	Hoch = digitalRead(D3);
	if (Hoch == LOW & Runter == HIGH) {

		if (PWM < 1023, PWM++);
		if (PWM >= 1024) { PWM = 1023; blink(); }
		Serial.print("Rauf:");
		Serial.println(PWM);
		analogWrite(D6, PWM);
		
		delay(10);

	}
	

	//Tasterunter abfrage
	Runter = digitalRead(D2);
	if (Runter == LOW & Hoch == HIGH) {

		if (PWM >= 1023, PWM--);
		if (PWM <= 11) { PWM = 10; blink() ; }
		Serial.print("Runter:");
		Serial.println(PWM);
		analogWrite(D6, PWM);

		delay(10);
	}

	// Tasten für Speicher

	if (Hoch == LOW & Runter == LOW) {

		EEPROM.begin(64);
		EEPROM.put(0, PWM);
		EEPROM.commit();
		EEPROM.end();
		blink();

	}
}

void blink() {
	
	for (int i = 0; i < 2; i++) {

		digitalWrite(D1, LOW);
		delay(50);
		digitalWrite(D1, HIGH);
		delay(50);

	}
}
