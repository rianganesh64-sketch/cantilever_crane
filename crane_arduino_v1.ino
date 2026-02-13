#include <Stepper.h>


const int stepsPerRevolution = 200; //change based on motor, usually 200 or 400
int revolutions = 5; //amount of revolutions want to do
int motorspeed = 20; //motor speed
int delay_amount = 500; //delay after each revolution


Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);


void setup() {
 myStepper.setSpeed(motorspeed); //set motor speed
 Serial.begin(9600);




 for (int i = 0; i < revolutions; i++) { //loop for running motor for n revolutions
   Serial.println("clockwise"); //indicate one clockwise rotation has been completed
   Serial.println(i + 1); //add 1 to the rotation counter
   myStepper.step(stepsPerRevolution); // Moves 1 full turn each loop
   delay(delay_amount); //delay for accuracy, can change if needed
 }
}


void loop() {} //empty --> stops movement after 5 turns

