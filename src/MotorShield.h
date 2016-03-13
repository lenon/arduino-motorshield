#include "Motor.h"

class MotorShield
{
public:
    MotorShield(uint8_t leftSpeedPin, uint8_t leftDirPin,
                uint8_t rightSpeedPin, uint8_t rightDirPin);

    // Initialization method. Must be called in Arduino's setup() function.
    void setup();

    Motor* getLeftMotor();
    Motor* getRightMotor();

    // Makes left and right motors go in the forward direction.
    void forward();

    // Makes left and right motors go in the backward direction.
    void backward();

    // Stops both left and right motors.
    void stop();

    // Puts both left and right motors at the maximum speed.
    void fullSpeed();

    // Sets the speed of both left and right motors.
    void setSpeed(uint8_t);

private:
    Motor* leftMotor;
    Motor* rightMotor;
};
