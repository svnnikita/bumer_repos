
void setup() {	
	Serial.begin(9600);
}

void loop() {
	Serial.println("please, enter the time");
	while (Serial.available() == 0) {
	}	
	
	int set = Serial.parseInt();

	if (set > 0) {
		int i = 0;
		for ( ; i < 3; i++) {
			tone(2, 440);
			delay(1000);
			noTone(2);
			delay(1000);
		}
		if (i = 3) {
			tone(2, 540);
			delay(1000);
			noTone(2);
			delay(1000);
		}
	}
}
