#include <Servo.h> // calls servo library
Servo myServo; // creates object for servo motor

const int servoPin = 8;   // servo pin on arduino
const int buttonPin = 10; // button pin on arduino

int runFlag = 0; // start state at 0

// Variables
int speedValue = 0;       // 0 is down, 180 is up
int stopValue = 90;         // calibrated neutral stop
int holdValue = 180;         // counteracting value for heavy mass
const float secondsPerMeter = 6.67; // assumes 1 meter at max speed = 6.67 s
float metersPerRun = 8.7;   // distance to travel (meters)
float addedMass = 1.5;      // added mass in kg

void setup() {
  myServo.attach(servoPin);

  myServo.write(stopValue); // start at normal stop only

  pinMode(buttonPin, INPUT_PULLUP);
  runFlag = 0;
}

void loop() {

  if (digitalRead(buttonPin) == LOW) {
    delay(50); // debounce
    runFlag = 1;
  }

  if (runFlag == 1) {
    int runTimeMs = (int)(metersPerRun * secondsPerMeter * 1000.0);

    runServo(speedValue, runTimeMs); // move downward

    // Only after movement finishes, decide how to hold
    if (addedMass > 1.0) {
      myServo.write(holdValue);   // apply counteracting force
    } else {
      myServo.write(stopValue);   // normal stop
    }

    runFlag = 0;
  }
}

void runServo(int speedCmd, int durationMs) {
  myServo.write(speedCmd);
  delay(durationMs);
}
