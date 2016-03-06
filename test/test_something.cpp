#include "gtest/gtest.h"
#include "motor_shield.h"

MotorShield mshield(1, 3, 4, 5);

TEST(MotorShield, Initialization) {
  ASSERT_TRUE(1 == 1);
}
