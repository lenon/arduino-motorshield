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
