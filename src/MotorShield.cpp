#include "MotorShield.h"

MotorShield::MotorShield(
    uint8_t leftSpeedPin, uint8_t leftDirPin,
    uint8_t rightSpeedPin, uint8_t rightDirPin)
{
    this->leftMotor = new Motor(leftSpeedPin, leftDirPin);
    this->rightMotor = new Motor(rightSpeedPin, rightDirPin);
}

Motor* MotorShield::getLeftMotor()
{
    return leftMotor;
}

Motor* MotorShield::getRightMotor()
{
    return rightMotor;
}

void MotorShield::setup()
{
    leftMotor->setup();
    rightMotor->setup();
}

void MotorShield::forward()
{
    leftMotor->forward();
    rightMotor->forward();
}

void MotorShield::backward()
{
    leftMotor->backward();
    rightMotor->backward();
}

void MotorShield::stop()
{
    leftMotor->stop();
    rightMotor->stop();
}

void MotorShield::fullSpeed()
{
    leftMotor->fullSpeed();
    rightMotor->fullSpeed();
}

void MotorShield::setSpeed(uint8_t value)
{
    leftMotor->setSpeed(value);
    rightMotor->setSpeed(value);
}
