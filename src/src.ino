//#include "bumer.h"
//#include "melody.h"
//#include "zummer.h"
#include "zummerWithButton.h"

const int outputDiodPin = 13;
const int outputZumPin = 8;

void setup() {
    initialization(outputDiodPin, outputZumPin);
    Serial.begin(9600);
}

void loop() {
    initialization(outputDiodPin, outputZumPin);
    zummerBut(outputDiodPin, outputZumPin);
}