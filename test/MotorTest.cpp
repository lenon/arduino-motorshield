#include "gtest/gtest.h"
#include "Motor.h"

#define SPEED_PIN 1
#define DIRECTION_PIN 2

TEST(Motor, constructor)
{
    Motor motor(SPEED_PIN, DIRECTION_PIN);

    ASSERT_EQ(SPEED_PIN, motor.getSpeedPin());
    ASSERT_EQ(DIRECTION_PIN, motor.getDirPin());
    ASSERT_EQ(0, motor.getSpeed());
    ASSERT_EQ(0, motor.getMinSpeed());
    ASSERT_EQ(255, motor.getMaxSpeed());
}

TEST(Motor, setup)
{
    ArduinoMock mock;
    Motor motor(SPEED_PIN, DIRECTION_PIN);

    EXPECT_CALL(mock, pinMode(SPEED_PIN, OUTPUT));
    EXPECT_CALL(mock, pinMode(DIRECTION_PIN, OUTPUT));

    EXPECT_CALL(mock, analogWrite(SPEED_PIN, 0));
    EXPECT_CALL(mock, digitalWrite(DIRECTION_PIN, LOW));

    motor.setup();
}

TEST(Motor, setMaxSpeed)
{
    Motor motor(SPEED_PIN, DIRECTION_PIN);
    motor.setMaxSpeed(100);
    ASSERT_EQ(100, motor.getMaxSpeed());
}

TEST(Motor, setMinSpeed)
{
    Motor motor(SPEED_PIN, DIRECTION_PIN);
    motor.setMinSpeed(10);
    ASSERT_EQ(10, motor.getMinSpeed());
}

TEST(Motor, forward)
{
    ArduinoMock mock;
    Motor motor(SPEED_PIN, DIRECTION_PIN);

    EXPECT_CALL(mock, digitalWrite(DIRECTION_PIN, LOW));

    motor.forward();
}

TEST(Motor, backward)
{
    ArduinoMock mock;
    Motor motor(SPEED_PIN, DIRECTION_PIN);

    EXPECT_CALL(mock, digitalWrite(DIRECTION_PIN, HIGH));

    motor.backward();
}

TEST(Motor, stop)
{
    ArduinoMock mock;
    Motor motor(SPEED_PIN, DIRECTION_PIN);

    EXPECT_CALL(mock, analogWrite(SPEED_PIN, 0));

    motor.stop();

    ASSERT_EQ(0, motor.getSpeed());
}

TEST(Motor, fullSpeed)
{
    ArduinoMock mock;
    Motor motor(SPEED_PIN, DIRECTION_PIN);

    EXPECT_CALL(mock, analogWrite(SPEED_PIN, 255));

    motor.fullSpeed();

    ASSERT_EQ(255, motor.getSpeed());
}

TEST(Motor, setSpeed)
{
    ArduinoMock mock;
    Motor motor(SPEED_PIN, DIRECTION_PIN);

    EXPECT_CALL(mock, analogWrite(SPEED_PIN, 101));

    motor.setSpeed(101);

    ASSERT_EQ(101, motor.getSpeed());
}

TEST(Motor, setSpeedGreaterThanMaximum)
{
    ArduinoMock mock;
    Motor motor(SPEED_PIN, DIRECTION_PIN);
    motor.setMaxSpeed(100);

    EXPECT_CALL(mock, analogWrite(SPEED_PIN, 100));

    motor.setSpeed(101);

    ASSERT_EQ(100, motor.getSpeed());
}

TEST(Motor, setSpeedLowerThanMinimum)
{
    ArduinoMock mock;
    Motor motor(SPEED_PIN, DIRECTION_PIN);
    motor.setMinSpeed(10);

    EXPECT_CALL(mock, analogWrite(SPEED_PIN, 10));

    motor.setSpeed(9);

    ASSERT_EQ(10, motor.getSpeed());
}
