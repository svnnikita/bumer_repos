//#include "bumer.h"
//#include "melody.h"
//#include "zummer.h"
#include "zummerWithButton.h"

const int outputDiodPin = 13;
const int outputZumPin = 8;
const int analogDiodPin = 19;

void setup() {
    initialization(analogDiodPin, outputDiodPin, outputZumPin);
    Serial.begin(9600);
}

void loop() {
    zummerBut(analogDiodPin, outputDiodPin, outputZumPin);
}