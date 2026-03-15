#include <Servo.h> //calls servo library
Servo myServo; //creates object for servo motor
const int servoPin = 10; // servo pin on arduino
const int buttonPin = 8; //button pin on arduino
int runFlag = 0; // start state at 0

// Variables
int speedValue = 0;       // 180 is up, 0 is down
int stopValue = 90;         // calibrated stop position
const float secondsPerMeter = 3.654; // calibrate for each mass value
float metersPerRun = 1; // distance want to go (meters)
void setup() {
  myServo.attach(servoPin);
  myServo.write(stopValue); // Start in stopped position

  pinMode(buttonPin, INPUT_PULLUP);
  runFlag = 0; //Flag starts at zero, not moving
}

void loop() {

  if (digitalRead(buttonPin) == LOW) {
    delay(50); // debouncing to prevent double click errors
    runFlag = 1; // when button pressed, Flag goes to 1
  }

  if (runFlag == 1) {
    // Distance (m) -> time (ms): timeMs = meters * (metersPerRun sec/m) * (1000 ms/sec)
    int runTimeMs = (int)(metersPerRun * secondsPerMeter * 1000.0);

    runServo(speedValue, runTimeMs); //if Flag=1, run motor

    myServo.write(180); // stopping servo, 180 if countertorque applied
    runFlag = 0;              // Reset so it waits for next press
  }
}

void runServo(int speedCmd, int durationMs) {
  myServo.write(speedCmd);
  delay(durationMs); // keeps servo moving for set duration
} //custom function
