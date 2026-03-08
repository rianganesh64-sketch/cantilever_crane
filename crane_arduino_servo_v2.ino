#include <Servo.h> //calls servo library
Servo myServo; //creates object for servo motor
const int servoPin = 8; // servo pin on arduino
const int buttonPin = 10; //button pin on arduino
int runFlag = 0; // start state at 0

// Variables
int speedValue = 180;       // 180 is down, 0 is up (180 IS ONE WAY, 0 IS THE OTHER WAY)
int stopValue = 90;         // calibrated stop position (default stop)
int stopCommand;            // variable stop value depending on mass
const float secondsPerMeter = 6.67; // assumes that 1 meter at max speed = 6.67
float metersPerRun = 8.7; // distance want to go (meters)
float addedMass = 1.5; // input added mass
int massStop = 75; // the stop value based on the mass, (WILL NEED TO CALIBRATE FOR EACH MASS)

void setup() {
  myServo.attach(servoPin);

  // Determine stop command based on added mass
  if (addedMass > 1) {
    stopCommand = massStop;
  } else {
    stopCommand = stopValue;
  }

  myServo.write(stopCommand); // Start stopped
  
  pinMode(buttonPin, INPUT_PULLUP);
  runFlag = 0;
}

void loop() {

  if (digitalRead(buttonPin) == LOW) {
    delay(50); // debouncing
    runFlag = 1;
  }

  if (runFlag == 1) {

    // Distance (m) -> time (ms)
    int runTimeMs = (int)(metersPerRun * secondsPerMeter * 1000.0);

    runServo(speedValue, runTimeMs); // run motor
    
    myServo.write(stopCommand); // stop depending on mass
    runFlag = 0;
  }
}

void runServo(int speedCmd, int durationMs) {
  myServo.write(speedCmd);
  delay(durationMs);
}
