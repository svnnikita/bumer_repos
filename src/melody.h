// Ноты и частота, на которых они играются
float A = 440.0;    // Ля
float E = 329.63;   // Ми
float G = 392.0;    // Соль
float C = 493.88;   // До

int output_pin{10};

int any_key;

void command() {
    if (Serial.available()) {
        any_key = Serial.parseInt();
        switch (any_key)
        {
        case 1:
            tone(output_pin, C);
            break;
        case 2:
            tone(output_pin, E);
            break;
        default:
            break;
        }
    }
    else {
        Serial.println("пищит");
    }
}