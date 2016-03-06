# build the fake arduino library
file(GLOB ARDUINO_FILES arduino/*.h arduino/*.cpp)
add_library(ArduinoLib ${ARDUINO_FILES})

# build src files as a library
include_directories(arduino)
include_directories(../src)
file(GLOB SRC_FILES ../src/*.h ../src/*.cpp)
add_library(MotorShieldLib ${SRC_FILES})

# build test runner
set(GTEST_DIR ../vendor/googletest)
file(GLOB TESTS_FILES *.h *.cpp)
include_directories(
  ${GTEST_DIR}
  ${GTEST_DIR}/include)
add_executable(MotorShieldTests
  ${TESTS_FILES}
  ${GTEST_DIR}/src/gtest-all.cc
  ${GTEST_DIR}/src/gtest_main.cc)
target_link_libraries(MotorShieldTests
  ArduinoLib
  MotorShieldLib)
add_test(MotorShieldTests MotorShieldTests)
