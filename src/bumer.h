// Ноты и частота, на которых они играются
float A = 440.0;    // Ля
float E = 329.63;   // Ми
float G = 392.0;    // Соль
float C = 493.88;

int output_pin{10};

int delay1{250};
int delay2{1000};
int delay3{850};


void bumer() {

    tone(output_pin, E);
    delay(delay1);

    tone(output_pin, G);
    delay(delay3);

    noTone(output_pin);
    delay(delay2);

    tone(output_pin, G);
    delay(delay1);

    tone(output_pin, E);
    delay(delay3);

    noTone(output_pin);
    delay(delay3);

    int count = 3;
    for (int i = 0; i < count + 1; i++) { 
        tone(output_pin, A);
        delay(delay1);

        tone(output_pin, G);
        delay(delay1);
    }
    
    tone(output_pin, A);
    delay(delay1);

    tone(output_pin, C);
    delay(delay3);

    noTone(output_pin);
    delay(delay2);
}