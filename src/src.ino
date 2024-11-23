//#include "bumer.h"
//#include "melody.h"
//#include "zummer.h"
//#include "zummerWithButton.h"

//const int outputDiodPin = 13;
//const int outputZumPin = 8;
//const int analogDiodPin = 19;

bool zumFlag = 0;
bool flag = 0;

//unsigned long timer = millis();

const int piezoPin = 10; // Пин, к которому подключен пьезоэлектрический динамик

// Частоты сигналов
const int lowFrequency = 300; // Низкая частота (300 Гц)
const int highFrequency = 440; // Высокая частота (440 Гц)

// Продолжительность сигналов (в микросекундах)
const unsigned long signalDuration = 500; // 500 микросекунд
// Пауза между сигналами (в миллисекундах)
const unsigned long pauseDuration = 200; // 200 миллисекунд

unsigned long previousMillis = 0; // Переменная для хранения времени предыдущего сигнала
int signalCount = 0; // Счетчик сигналов
bool isPlaying = false; // Флаг, указывающий, идет ли воспроизведение

void setup() {
  pinMode(piezoPin, OUTPUT); // Настраиваем пин динамика как выход
}

void loop() {
  unsigned long currentMillis = millis(); // Получаем текущее время

  if (isPlaying) {
    // Проверяем, прошло ли время для окончания сигнала
    if (currentMillis - previousMillis >= signalDuration / 1000) {
      // Останавливаем сигнал
      noTone(piezoPin);
      previousMillis = currentMillis; // Обновляем время
      signalCount++; // Увеличиваем счетчик сигналов
      
      // Проверяем, нужно ли воспроизводить следующий сигнал
      if (signalCount < 3) {
        tone(piezoPin, lowFrequency); // Издаем низкий сигнал
      } else if (signalCount == 3) {
        tone(piezoPin, highFrequency); // Издаем высокий сигнал
      } else {
        // Все сигналы воспроизведены, сбрасываем состояние
        isPlaying = false;
        signalCount = 0; // Сбрасываем счетчик сигналов
      }
    }
  } else {
    // Проверяем, прошло ли время паузы
    if (currentMillis - previousMillis >= pauseDuration) {
      // Запускаем воспроизведение первого сигнала
      isPlaying = true;
      previousMillis = currentMillis; // Обновляем время
      tone(piezoPin, lowFrequency); // Издаем первый низкий сигнал
    }
  }
}
