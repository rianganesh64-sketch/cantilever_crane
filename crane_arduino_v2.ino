#include <Stepper.h>

// 28BYJ-48 = 2048 steps per revolution
const int stepsPerRevolution = 2048;

int revolutions = 5;      // number of full turns
int motorspeed = 15;      // RPM (keep 5–15)
int delay_amount = 500;   // delay after each revolution (ms)

// Wiring:
// IN1 -> 8
// IN2 -> 10
// IN3 -> 11
// IN4 -> 12
Stepper myStepper(stepsPerRevolution, 8, 11, 10, 12);

void setup() {

  Serial.begin(9600);
  myStepper.setSpeed(motorspeed);

  for (int i = 0; i < revolutions; i++) {

    Serial.print("Completed revolution: ");
    Serial.println(i + 1);

    myStepper.step(stepsPerRevolution);  // exactly 1 full turn, make negative to change direction
    delay(delay_amount);
  }

  Serial.println("Finished all revolutions.");
}

void loop() {
  // Empty, motor stops after setup runs
}
