#include "Servo.h" 
#include <Pixy2.h> 
#include <Ultrasonic.h>
// Pin and Variable Definitions

const int IN1 = 3; // Motor control pin
const int IN2 = 4; // Motor control pin
const int servoPin = 5; // Servo motor control pin
const int buttonPin = 2; // Button pin to start the program
int speed = 250; // Robot speed variable (0-255)
bool run = false; // Program state, false for not running
Servo servoMotor; // Creates a Servo object to control the servo motor
Pixy2 pixy; // Creates a Pixy object for the vision sensor
Ultrasonic ultrasonicLeft(6, 7); // Left ultrasonic sensor (trigger, echo)
Ultrasonic ultrasonicRight(8, 9); // Right ultrasonic sensor (trigger, echo)
unsigned long startTime; // Stores the program start time
const unsigned long stopTime = 50000; // Program stop time in milliseconds (50 seconds)
int firstDetectedColor = 0; // Stores the first color detected by Pixy2


void setup() {
  // Initialize pins and devices
  pinMode(IN1, OUTPUT); // Set IN1 as output
  pinMode(IN2, OUTPUT); // Set IN2 as output
  pinMode(buttonPin, INPUT_PULLUP); // Set the button as input with pull-up resistor
  servoMotor.attach(servoPin); // Attach the servo motor to its pin
  servoMotor.write(78); // Initial position of the servo motor
  pixy.init(); // Initialize the Pixy sensor
  pixy.setLamp(1, 0); // Turn on the Pixy's LED
}

void loop() {
  // Check if the button is pressed and change the 'run' state
  if (digitalRead(buttonPin) == LOW && !run) {
    run = true; // Activate program execution
    startTime = millis(); // Set the start time
    delay(500); // Delay to avoid button bounce
  }

  // Execute the code if 'run' is true and the stop time has not been reached
  if (run && (millis() - startTime < stopTime)) {
    // Main code that executes after pressing the button
    int leftDistance = ultrasonicLeft.read(); // Read the distance from the left sensor
    int rightDistance = ultrasonicRight.read(); // Read the distance from the right sensor

    // If there is an object near the left sensor, move the servo motor
    if (leftDistance >= 3 && leftDistance <= 12) {
      servoMotor.write(104); // Turn right
      delay(500); // Wait for half a second
      servoMotor.write(60); // Turn left to level
      delay(200); // Wait for 200 milliseconds
      servoMotor.write(78); // Return to the initial position
    }
    // If there is an object near the right sensor, move the servo motor
    else if (rightDistance >= 3 && rightDistance <= 12) {
      servoMotor.write(50); // Turn left
      delay(500); // Wait for half a second
      servoMotor.write(120); // Turn right to level
      delay(200); // Wait for 200 milliseconds
      servoMotor.write(78); // Return to the initial position
    } 
    // If there are no objects nearby, check if Pixy detects colors
    else {
      pixy.ccc.getBlocks(); // Request color blocks detected by Pixy

      // If Pixy detects at least one color block
      if (pixy.ccc.numBlocks > 0) {
        // If a color hasn't been detected yet, store the first detected color
        if (firstDetectedColor == 0) {
          firstDetectedColor = pixy.ccc.blocks[0].m_signature; // Store the signature of the detected color
        }

        // If the first detected color was blue
        if (firstDetectedColor == 1) {
          // If Pixy detects blue, move the servo motor to the left
          if (pixy.ccc.blocks[0].m_signature == 1) {
            servoMotor.write(50);
          }
          // If Pixy detects orange, wait and return to the initial position
          else if (pixy.ccc.blocks[0].m_signature == 2) {
            delay(1000); // Wait for one second
            servoMotor.write(78);
          }
        }
        // If the first detected color was orange
        else if (firstDetectedColor == 2) {
          // If Pixy detects orange, move the servo motor to the right
          if (pixy.ccc.blocks[0].m_signature == 2) {
            servoMotor.write(104);
          }
          // If Pixy detects blue, wait and return to the initial position
          else if (pixy.ccc.blocks[0].m_signature == 1) {
            delay(1000); // Wait for one second
            servoMotor.write(78);
          }
        }
      }
    }

    // Turn on the motor
    analogWrite(IN1, 0);
    analogWrite(IN2, speed);
  }
  // If the stop time is reached, stop execution
  else if (run && (millis() - startTime >= stopTime)) {
    run = false; // Deactivate execution
    analogWrite(IN1, 0); // Stop the motor
    analogWrite(IN2, 0); // Stop the motor
  }
}
