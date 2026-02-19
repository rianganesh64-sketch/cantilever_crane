#include <Servo.h>
#include <Time.h>

Servo myServo; // Create servo object

const int servoPin = 8;
const int runTime = 1000; // 1 second
const int cwSpeed = 180;
const int stopSpeed = 95;

void setup() {
  myServo.attach(servoPin); // Attaches the servo on pin 8
  
  // The code inside setup() runs once
  myServo.write(cwSpeed); // Start CW at max speed
  delay(runTime);         // Run for the set time
  myServo.write(stopSpeed); // Stop
}

void loop() {
  // This loop is intentionally empty if the goal is to stop forever after setup()
}
