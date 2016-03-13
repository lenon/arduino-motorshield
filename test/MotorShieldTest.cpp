#include "gtest/gtest.h"
#include "MotorShield.h"

#define SPEED_L 1
#define DIR_L 2

#define SPEED_R 3
#define DIR_R 4

TEST(MotorShield, constructor)
{
    MotorShield mshield(SPEED_L, DIR_L, SPEED_R, DIR_R);

    ASSERT_EQ(SPEED_L, mshield.getLeftMotor()->getSpeedPin());
    ASSERT_EQ(DIR_L, mshield.getLeftMotor()->getDirPin());

    ASSERT_EQ(SPEED_R, mshield.getRightMotor()->getSpeedPin());
    ASSERT_EQ(DIR_R, mshield.getRightMotor()->getDirPin());

    ASSERT_EQ(0, mshield.getLeftMotor()->getSpeed());
    ASSERT_EQ(0, mshield.getRightMotor()->getSpeed());

    ASSERT_EQ(0, mshield.getLeftMotor()->getMinSpeed());
    ASSERT_EQ(0, mshield.getRightMotor()->getMinSpeed());

    ASSERT_EQ(255, mshield.getLeftMotor()->getMaxSpeed());
    ASSERT_EQ(255, mshield.getRightMotor()->getMaxSpeed());
}

TEST(MotorShield, init)
{
    ArduinoMock mock;
    MotorShield mshield(SPEED_L, DIR_L, SPEED_R, DIR_R);

    EXPECT_CALL(mock, pinMode(SPEED_L, OUTPUT));
    EXPECT_CALL(mock, pinMode(DIR_L, OUTPUT));

    EXPECT_CALL(mock, pinMode(SPEED_R, OUTPUT));
    EXPECT_CALL(mock, pinMode(DIR_R, OUTPUT));

    EXPECT_CALL(mock, analogWrite(SPEED_L, 0));
    EXPECT_CALL(mock, analogWrite(SPEED_R, 0));

    EXPECT_CALL(mock, digitalWrite(DIR_L, LOW));
    EXPECT_CALL(mock, digitalWrite(DIR_R, LOW));

    mshield.setup();
}

TEST(MotorShield, forward)
{
    ArduinoMock mock;
    MotorShield mshield(SPEED_L, DIR_L, SPEED_R, DIR_R);

    EXPECT_CALL(mock, digitalWrite(DIR_L, LOW));
    EXPECT_CALL(mock, digitalWrite(DIR_R, LOW));

    mshield.forward();
}

TEST(MotorShield, backward)
{
    ArduinoMock mock;
    MotorShield mshield(SPEED_L, DIR_L, SPEED_R, DIR_R);

    EXPECT_CALL(mock, digitalWrite(DIR_L, HIGH));
    EXPECT_CALL(mock, digitalWrite(DIR_R, HIGH));

    mshield.backward();
}

TEST(MotorShield, stop)
{
    ArduinoMock mock;
    MotorShield mshield(SPEED_L, DIR_L, SPEED_R, DIR_R);

    EXPECT_CALL(mock, analogWrite(SPEED_L, 0));
    EXPECT_CALL(mock, analogWrite(SPEED_R, 0));

    mshield.stop();

    ASSERT_EQ(0, mshield.getLeftMotor()->getSpeed());
    ASSERT_EQ(0, mshield.getRightMotor()->getSpeed());
}

TEST(MotorShield, fullSpeed)
{
    ArduinoMock mock;
    MotorShield mshield(SPEED_L, DIR_L, SPEED_R, DIR_R);

    EXPECT_CALL(mock, analogWrite(SPEED_L, 255));
    EXPECT_CALL(mock, analogWrite(SPEED_R, 255));

    mshield.fullSpeed();

    ASSERT_EQ(255, mshield.getLeftMotor()->getSpeed());
    ASSERT_EQ(255, mshield.getRightMotor()->getSpeed());
}

TEST(MotorShield, setSpeed)
{
    ArduinoMock mock;
    MotorShield mshield(SPEED_L, DIR_L, SPEED_R, DIR_R);

    EXPECT_CALL(mock, analogWrite(SPEED_L, 101));
    EXPECT_CALL(mock, analogWrite(SPEED_R, 101));

    mshield.setSpeed(101);

    ASSERT_EQ(101, mshield.getLeftMotor()->getSpeed());
    ASSERT_EQ(101, mshield.getRightMotor()->getSpeed());
}
