#include <stdint.h>
#include <gmock/gmock.h>

#define HIGH 0x1
#define LOW 0x0

#define INPUT 0x0
#define OUTPUT 0x1

class ArduinoMock
{
public:
    ArduinoMock();
    MOCK_METHOD2(pinMode, void(uint8_t, uint8_t));
    MOCK_METHOD2(digitalWrite, void(uint8_t, uint8_t));
    MOCK_METHOD2(analogWrite, void(uint8_t, int));
};

extern "C" {
    void pinMode(uint8_t, uint8_t);
    void digitalWrite(uint8_t, uint8_t);
    void analogWrite(uint8_t, int);
}
