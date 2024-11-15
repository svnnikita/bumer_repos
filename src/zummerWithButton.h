// Зуммер работает от тактовой кнопки

// частота звучания зуммера
const float zummerFreq = 440.0;

enum mode {
    OFF,
    ON,
} State;

// функция инициализации необходимых выводов
void initialization(const int diodPin, const int zummerPin) { 

    // инициализация вывода, который считывает аналоговый сигнал
    pinMode(A5, INPUT_PULLUP);

    // управляющий вывод, с которого пойдет сигнал на светодиод L 
    pinMode(diodPin, OUTPUT);

    // управляющий вывод, сигнал с которого пойдет на зуммер
    pinMode(zummerPin, OUTPUT);

}

// функция работы зуммера с кнопки
void zummerBut(const int diodPin, const int zummerPin) {

    // инициализация переменных, которые будут выводится
    // в последовательный монитор и которые будут хранить 
    // значения сигналов
    boolean b1 = !digitalRead(A5); // кнопка разомкнута - значение 0, замкнута - 1
    boolean b2 = digitalRead(13); 

    // условия при которых загорается светодиод и звучит зуммер
    if (b1 == ON) { // зуммер звучит, когда на вход светодиода подан высокий сигнал
        digitalWrite(diodPin, ON);
        tone(zummerPin, zummerFreq); 
    }
    else { // в противном случае зуммер молчит и не горит светодиод
        digitalWrite(diodPin, OFF);
        noTone(zummerPin);
    }

    // вывод состояний в последовательный монитор
    Serial.print("button1: "); Serial.print(b1);
    Serial.print(", button2: "); Serial.println(b2);

}