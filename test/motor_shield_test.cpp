#include "gtest/gtest.h"
#include "motor_shield.h"

#define SPEED_L 1
#define DIR_L 2

#define SPEED_R 3
#define DIR_R 4

MotorShield mshield(SPEED_L, DIR_L, SPEED_R, DIR_R);

TEST(MotorShield, Initialization) {
  ASSERT_EQ(0, mshield.getMinSpeed());
  ASSERT_EQ(255, mshield.getMaxSpeed());

  ASSERT_EQ(SPEED_L, mshield.getLeftSpeedPin());
  ASSERT_EQ(SPEED_R, mshield.getRightSpeedPin());

  ASSERT_EQ(DIR_L, mshield.getLeftDirPin());
  ASSERT_EQ(DIR_R, mshield.getRightDirPin());
}

TEST(MotorShield, Setup) {
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

TEST(MotorShield, Forward) {
  ArduinoMock mock;

  EXPECT_CALL(mock, digitalWrite(DIR_L, LOW));
  EXPECT_CALL(mock, digitalWrite(DIR_R, LOW));

  mshield.forward();
}

TEST(MotorShield, Backward) {
  ArduinoMock mock;

  EXPECT_CALL(mock, digitalWrite(DIR_L, HIGH));
  EXPECT_CALL(mock, digitalWrite(DIR_R, HIGH));

  mshield.backward();
}

TEST(MotorShield, Stop) {
  ArduinoMock mock;

  EXPECT_CALL(mock, analogWrite(SPEED_L, 0));
  EXPECT_CALL(mock, analogWrite(SPEED_R, 0));

  mshield.stop();
}

TEST(MotorShield, FullSpeed) {
  ArduinoMock mock;

  EXPECT_CALL(mock, analogWrite(SPEED_L, 255));
  EXPECT_CALL(mock, analogWrite(SPEED_R, 255));

  mshield.fullSpeed();
}

TEST(MotorShield, StopLeft) {
  ArduinoMock mock;

  EXPECT_CALL(mock, analogWrite(SPEED_L, 0));

  mshield.stopLeft();
}

TEST(MotorShield, StopRight) {
  ArduinoMock mock;

  EXPECT_CALL(mock, analogWrite(SPEED_R, 0));

  mshield.stopRight();
}
