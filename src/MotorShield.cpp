#include "MotorShield.h"

MotorShield::MotorShield(
    uint8_t leftSpeedPin, uint8_t leftDirPin,
    uint8_t rightSpeedPin, uint8_t rightDirPin)
{
  this->leftSpeedPin = leftSpeedPin;
  this->leftDirPin = leftDirPin;

  this->rightSpeedPin = rightSpeedPin;
  this->rightDirPin = rightDirPin;

  this->maxSpeed = 255;
  this->minSpeed = 0;
}

void MotorShield::init()
{
  pinMode(leftSpeedPin, OUTPUT);
  pinMode(leftDirPin, OUTPUT);
  pinMode(rightSpeedPin, OUTPUT);
  pinMode(rightDirPin, OUTPUT);

  stop();
  forward();
}

uint8_t MotorShield::getMaxSpeed() {
  return maxSpeed;
}

uint8_t MotorShield::getMinSpeed() {
  return minSpeed;
}

uint8_t MotorShield::getLeftSpeedPin() {
  return leftSpeedPin;
}

uint8_t MotorShield::getLeftDirPin() {
  return leftDirPin;
}

uint8_t MotorShield::getRightSpeedPin() {
  return rightSpeedPin;
}

uint8_t MotorShield::getRightDirPin() {
  return rightDirPin;
}

void MotorShield::forward()
{
  digitalWrite(leftDirPin, LOW);
  digitalWrite(rightDirPin, LOW);
}

void MotorShield::backward()
{
  digitalWrite(leftDirPin, HIGH);
  digitalWrite(rightDirPin, HIGH);
}

void MotorShield::stop()
{
  analogWrite(leftSpeedPin, minSpeed);
  analogWrite(rightSpeedPin, minSpeed);
}

void MotorShield::fullSpeed()
{
  analogWrite(leftSpeedPin, maxSpeed);
  analogWrite(rightSpeedPin, maxSpeed);
}

void MotorShield::stopLeft()
{
  analogWrite(leftSpeedPin, 0);
}

void MotorShield::stopRight()
{
  analogWrite(rightSpeedPin, 0);
}
