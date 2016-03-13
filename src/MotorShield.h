#include <Arduino.h>

class MotorShield
{
public:
    MotorShield(uint8_t leftSpeedPin, uint8_t leftDirPin,
                uint8_t rightSpeedPin, uint8_t rightDirPin);

    // Initialization method. Must be called in Arduino's setup() function.
    void init();

    // Makes left and right motors go in the forward direction.
    void forward();

    // Makes left and right motors go in the backward direction.
    void backward();

    // Stops both left and right motors.
    void stop();

    // Puts both left and right motors at the maximum speed.
    void fullSpeed();

    // Stops left motor.
    void stopLeft();

    // Stops right motor.
    void stopRight();

    // Returns the maximum allowed speed.
    uint8_t getMaxSpeed();

    // Returns the minimum allowed speed.
    uint8_t getMinSpeed();

    // Returns the pin used to control left motor speed.
    uint8_t getLeftSpeedPin();

    // Returns the pin used to control left motor direction.
    uint8_t getLeftDirPin();

    // Returns the pin used to control right motor speed.
    uint8_t getRightSpeedPin();

    // Returns the pin used to control right motor direction.
    uint8_t getRightDirPin();

    // Returns the current speed of the left motor.
    uint8_t getLeftSpeed();

    // Returns the current speed of the right motor.
    uint8_t getRightSpeed();

    // Sets the speed of both left and right motors.
    void setSpeed(uint8_t);

    // Sets the speed of the left motor.
    void setLeftSpeed(int);
    void setLeftSpeed(uint8_t);

    // Sets the speed of the right motor.
    void setRightSpeed(int);
    void setRightSpeed(uint8_t);
private:
    uint8_t leftSpeedPin,
            leftDirPin,
            rightSpeedPin,
            rightDirPin,
            maxSpeed,
            minSpeed,
            leftSpeed,
            rightSpeed;
};
