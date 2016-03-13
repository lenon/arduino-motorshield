#include <Arduino.h>

class Motor
{
public:
    Motor(uint8_t speedPin, uint8_t dirPin);

    // Initialization method. Must be called in Arduino's setup() function.
    void setup();

    // Returns the pin used to control the direction.
    uint8_t getDirPin();

    // Returns the pin used to control the speed.
    uint8_t getSpeedPin();

    // Returns the maximum allowed speed.
    uint8_t getMaxSpeed();

    // Returns the minimum allowed speed.
    uint8_t getMinSpeed();

    // Returns the current speed.
    uint8_t getSpeed();

    // Sets the maximum allowed speed.
    void setMaxSpeed(uint8_t);

    // Sets the minimum allowed speed.
    void setMinSpeed(uint8_t);

    // Puts motor in the forward direction.
    void forward();

    // Puts motor in the backward direction.
    void backward();

    // Stops the motor engine.
    void stop();

    // Puts motor at its maximum speed.
    void fullSpeed();

    // Sets motor speed.
    void setSpeed(uint8_t);

private:
    uint8_t dirPin,
            maxSpeed,
            minSpeed,
            speed,
            speedPin;
};
