#include <stdlib.h>

#define HIGH 0x1
#define LOW 0x0

#define INPUT 0x0
#define OUTPUT 0x1

extern "C" {
  void pinMode(uint8_t, uint8_t);
  void digitalWrite(uint8_t, uint8_t);
  void analogWrite(uint8_t, int);
}
