#include <Servo.h> //calls servo library
Servo myServo; //creates object for servo motor
const int servoPin = 10; // servo pin on arduino
const int buttonPin = 8; //button pin on arduino
int runFlag = 0; // start state at 0

// Variables
int speedValue = 180;       // 180 is up, 0 is down (180 IS ONE WAY, 0 IS THE OTHER WAY)
int stopValue = 90;         // calibrated stop position, (DONT ADJUST)
const float secondsPerMeter = 6.67; // assumes that 1 meter at max speed = 6.67;
float metersPerRun = 10; // distance want to go (meters) (THIS IS WHAT YOU CHANGE FOR RUNTIME) 1.345

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

    myServo.write(stopValue); // stopping servo
    runFlag = 0;              // Reset so it waits for next press
  }
}

void runServo(int speedCmd, int durationMs) {
  myServo.write(speedCmd);
  delay(durationMs); // keeps servo moving for set duration
} //custom function
