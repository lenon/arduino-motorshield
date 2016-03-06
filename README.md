# arduino-motorshield

An Arduino library for [Robocore's Arduino Motor Driver 2x2A][1]. This shield
contains a L298P chip and can be used to control 2 motors.

## Usage

```arduino
#include <motor_shield.h>

// 5 is the pin that controls the speed of the left motor
// 7 is the pin that controls the direction of the left motor
// 6 is the pin that controls the speed of the right motor
// 8 is the pin that controls the direction of the right motor
MotorShield mshield(5, 7, 6, 8);

void setup() {
  // shield initialization
  mshield.init();
}

void loop() {
  delay(2000);
  // go forward at maximum speed
  mshield.forward();
  mshield.fullSpeed();

  delay(2000);
  // go backwards
  mshield.backward();

  delay(2000);
  // go forward and stop left motor
  mshield.forward();
  mshield.stopLeft();

  delay(2000);
  // go forward and stop right motor
  mshield.fullSpeed();
  mshield.stopRight();
}
```

## Development

```shell
mkdir build
cd build
cmake ..
make
make test
```

[1]: https://www.robocore.net/modules.php?name=GR_LojaVirtual&prod=200
