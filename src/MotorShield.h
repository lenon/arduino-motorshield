#include <Arduino.h>

class MotorShield
{
  public:
    MotorShield(uint8_t leftSpeedPin, uint8_t leftDirPin,
        uint8_t rightSpeedPin, uint8_t rightDirPin);
    void init();
    void forward();
    void backward();
    void stop();
    void fullSpeed();
    void stopLeft();
    void stopRight();
    uint8_t getMaxSpeed();
    uint8_t getMinSpeed();
    uint8_t getLeftSpeedPin();
    uint8_t getLeftDirPin();
    uint8_t getRightSpeedPin();
    uint8_t getRightDirPin();
  private:
    uint8_t leftSpeedPin,
            leftDirPin,
            rightSpeedPin,
            rightDirPin,
            maxSpeed,
            minSpeed;
};