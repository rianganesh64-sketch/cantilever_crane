#include <Servo.h>

Servo myServo;

const int servoPin = 8;

// USER VARIABLES
int runTime = 2000;     // milliseconds
int speedValue = 180;   // 0–180 for CW, -180-0 for CCW
int stopValue = 95;     // calibrated stop value, (may need to adjust)

void setup() {
  myServo.attach(servoPin);

  runServo(speedValue, runTime);

  myServo.write(stopValue);  // ensure stop
}

void loop() {
  // empty, doesn't loop
}

void runServo(int speedCmd, int durationMs) {
  myServo.write(speedCmd);
  delay(durationMs);
} // creates custom function used in the void setup()
