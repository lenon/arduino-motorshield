#include "gtest/gtest.h"
#include "MotorShield.h"

#define SPEED_L 1
#define DIR_L 2

#define SPEED_R 3
#define DIR_R 4

MotorShield mshield(SPEED_L, DIR_L, SPEED_R, DIR_R);

TEST(MotorShield, constructor)
{
    ASSERT_EQ(0, mshield.getMinSpeed());
    ASSERT_EQ(255, mshield.getMaxSpeed());

    ASSERT_EQ(SPEED_L, mshield.getLeftSpeedPin());
    ASSERT_EQ(SPEED_R, mshield.getRightSpeedPin());

    ASSERT_EQ(DIR_L, mshield.getLeftDirPin());
    ASSERT_EQ(DIR_R, mshield.getRightDirPin());

    ASSERT_EQ(0, mshield.getLeftSpeed());
    ASSERT_EQ(0, mshield.getRightSpeed());
}

TEST(MotorShield, init)
{
    ArduinoMock mock;

    EXPECT_CALL(mock, pinMode(SPEED_L, OUTPUT));
    EXPECT_CALL(mock, pinMode(DIR_L, OUTPUT));
    EXPECT_CALL(mock, pinMode(SPEED_R, OUTPUT));
    EXPECT_CALL(mock, pinMode(DIR_R, OUTPUT));

    EXPECT_CALL(mock, analogWrite(SPEED_L, 0));
    EXPECT_CALL(mock, analogWrite(SPEED_R, 0));

    EXPECT_CALL(mock, digitalWrite(DIR_L, LOW));
    EXPECT_CALL(mock, digitalWrite(DIR_R, LOW));

    mshield.init();
}

TEST(MotorShield, forward)
{
    ArduinoMock mock;

    EXPECT_CALL(mock, digitalWrite(DIR_L, LOW));
    EXPECT_CALL(mock, digitalWrite(DIR_R, LOW));

    mshield.forward();
}

TEST(MotorShield, backward)
{
    ArduinoMock mock;

    EXPECT_CALL(mock, digitalWrite(DIR_L, HIGH));
    EXPECT_CALL(mock, digitalWrite(DIR_R, HIGH));

    mshield.backward();
}

TEST(MotorShield, stop)
{
    ArduinoMock mock;

    EXPECT_CALL(mock, analogWrite(SPEED_L, 0));
    EXPECT_CALL(mock, analogWrite(SPEED_R, 0));

    mshield.stop();

    ASSERT_EQ(0, mshield.getLeftSpeed());
    ASSERT_EQ(0, mshield.getRightSpeed());
}

TEST(MotorShield, fullSpeed)
{
    ArduinoMock mock;

    EXPECT_CALL(mock, analogWrite(SPEED_L, 255));
    EXPECT_CALL(mock, analogWrite(SPEED_R, 255));

    mshield.fullSpeed();

    ASSERT_EQ(255, mshield.getLeftSpeed());
    ASSERT_EQ(255, mshield.getRightSpeed());
}

TEST(MotorShield, stopLeft)
{
    ArduinoMock mock;

    EXPECT_CALL(mock, analogWrite(SPEED_L, 0));

    mshield.stopLeft();

    ASSERT_EQ(0, mshield.getLeftSpeed());
}

TEST(MotorShield, stopRight)
{
    ArduinoMock mock;

    EXPECT_CALL(mock, analogWrite(SPEED_R, 0));

    mshield.stopRight();

    ASSERT_EQ(0, mshield.getRightSpeed());
}

TEST(MotorShield, setSpeed)
{
    ArduinoMock mock;

    EXPECT_CALL(mock, analogWrite(SPEED_L, 101));
    EXPECT_CALL(mock, analogWrite(SPEED_R, 101));

    mshield.setSpeed(101);

    ASSERT_EQ(101, mshield.getLeftSpeed());
    ASSERT_EQ(101, mshield.getRightSpeed());
}

TEST(MotorShield, setLeftSpeed)
{
    ArduinoMock mock;

    EXPECT_CALL(mock, analogWrite(SPEED_L, 99));

    mshield.setLeftSpeed(99);

    ASSERT_EQ(99, mshield.getLeftSpeed());
}

TEST(MotorShield, setRightSpeed)
{
    ArduinoMock mock;

    EXPECT_CALL(mock, analogWrite(SPEED_R, 100));

    mshield.setRightSpeed(100);

    ASSERT_EQ(100, mshield.getRightSpeed());
}
