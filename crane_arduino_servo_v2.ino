#include <Servo.h>

Servo myServo;

const int servoPin = 8;
Servo myservo;

//USER VARIABLES
int runTime = 500000;     // milliseconds
int speedValue = 0;   // 0 is down, 180 is up
int stopValue = 90;     // calibrated stop value, (90 is current value)

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
} // creates custom function used in the void setup()*/
