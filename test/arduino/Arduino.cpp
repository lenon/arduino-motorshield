#include "Arduino.h"

ArduinoMock* instance;

ArduinoMock::ArduinoMock() {
  instance = this;
}

void pinMode(uint8_t a, uint8_t b) {
  instance->pinMode(a, b);
}

void digitalWrite(uint8_t a, uint8_t b) {
  instance->digitalWrite(a, b);
}

void analogWrite(uint8_t a, int b) {
  instance->analogWrite(a, b);
}
