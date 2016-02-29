#include "Arduino.h"

class MotorShield
{
  public:
    MotorShield(uint8_t speedPinLeft, uint8_t dirPinLeft,
        uint8_t speedPinRight, uint8_t dirPinRight);
    void init();
    void forward();
    void backward();
    void stop();
    void fullSpeed();
    void stopLeft();
    void stopRight();
  private:
    int speedPinLeft,
        dirPinLeft,
        speedPinRight,
        dirPinRight,
        maxSpeed,
        minSpeed;
};
