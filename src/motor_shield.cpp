#include "motor_shield.h"

MotorShield::MotorShield(uint8_t speedPinLeft, uint8_t dirPinLeft,
    uint8_t speedPinRight, uint8_t dirPinRight)
{
  this->speedPinLeft = speedPinLeft;
  this->dirPinLeft = dirPinLeft;
  this->speedPinRight = speedPinRight;
  this->dirPinRight = dirPinRight;
  this->maxSpeed = 255;
  this->minSpeed = 0;
}

void MotorShield::init()
{
  pinMode(speedPinLeft, OUTPUT);
  pinMode(dirPinLeft, OUTPUT);
  pinMode(speedPinRight, OUTPUT);
  pinMode(dirPinRight, OUTPUT);

  stop();
  forward();
}

void MotorShield::forward()
{
  digitalWrite(dirPinLeft, LOW);
  digitalWrite(dirPinRight, LOW);
}

void MotorShield::backward()
{
  digitalWrite(dirPinLeft, HIGH);
  digitalWrite(dirPinRight, HIGH);
}

void MotorShield::stop()
{
  analogWrite(speedPinLeft, minSpeed);
  analogWrite(speedPinRight, minSpeed);
}

void MotorShield::fullSpeed()
{
  analogWrite(speedPinLeft, maxSpeed);
  analogWrite(speedPinRight, maxSpeed);
}

void MotorShield::stopLeft()
{
  analogWrite(speedPinLeft, 0);
}

void MotorShield::stopRight()
{
  analogWrite(speedPinRight, 0);
}
