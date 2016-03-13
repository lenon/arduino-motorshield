#include "Motor.h"

Motor::Motor(uint8_t speedPin, uint8_t dirPin)
{
    this->speedPin = speedPin;
    this->dirPin = dirPin;
    this->speed = 0;
    this->minSpeed = 0;
    this->maxSpeed = 255;
}

void Motor::setup()
{
    pinMode(speedPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
    analogWrite(speedPin, 0);
    forward();
}

uint8_t Motor::getSpeedPin()
{
    return speedPin;
}

uint8_t Motor::getDirPin()
{
    return dirPin;
}

uint8_t Motor::getSpeed()
{
    return speed;
}

uint8_t Motor::getMaxSpeed()
{
    return maxSpeed;
}

uint8_t Motor::getMinSpeed()
{
    return minSpeed;
}

void Motor::setMaxSpeed(uint8_t value)
{
    this->maxSpeed = value;
}

void Motor::setMinSpeed(uint8_t value)
{
    this->minSpeed = value;
}

void Motor::forward()
{
    digitalWrite(dirPin, LOW);
}

void Motor::backward()
{
    digitalWrite(dirPin, HIGH);
}

void Motor::stop()
{
    analogWrite(speedPin, 0);
}

void Motor::fullSpeed()
{
    setSpeed(maxSpeed);
}

void Motor::setSpeed(uint8_t value)
{
    if (value > maxSpeed) {
        value = maxSpeed;
    }

    if (value < minSpeed) {
        value = minSpeed;
    }

    this->speed = value;
    analogWrite(speedPin, speed);
}
