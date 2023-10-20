 /*
  testBraccio90.ino

 // 	testBraccio90 is a setup sketch to check the alignment of all the servo motors
 	This is the first sketch you need to run on Braccio
	When you start this sketch Braccio will be positioned perpendicular to the base
	If you can't see the Braccio in this exact position you need to reallign the servo motors position

 Created on 18 Nov 2015
 by Andrea Martino

 This example is in the public domain.
 */

#include <Braccio.h>
#include <Servo.h>
int roll = 90;
int pitch = 90;


Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;

void setup() {  
  //Initialization functions and set up the initial position for Braccio
  //All the servo motors will be positioned in the "safety" position:
  //Base (M1):90 degrees
  //Shoulder (M2): 45 degrees
  //Elbow (M3): 180 degrees
  //Wrist vertical (M4): 180 degrees
  //Wrist rotation (M5): 90 degrees
  //gripper (M6): 10 degrees
  Braccio.begin();
  Serial.begin(115200); 
}

void loop() {
  /*
   Step Delay: a milliseconds delay between the movement of each servo.  Allowed values from 10 to 30 msec.
   M1=base degrees. Allowed values from 0 to 180 degrees
   M2=shoulder degrees. Allowed values from 15 to 165 degrees
   M3=elbow degrees. Allowed values from 0 to 180 degrees
   M4=wrist vertical degrees. Allowed values from 0 to 180 degrees
   M5=wrist rotation degrees. Allowed values from 0 to 180 degrees
   M6=gripper degrees. Allowed values from 10 to 73 degrees. 10: the toungue is open, 73: the gripper is closed.
  */
  
  // the arm is aligned upwards  and the gripper is closed
                     //(step delay, M1, M2, M3, M4, M5, M6);
                    




  if (Serial.available() > 0) {
   
    String inputString = Serial.readString(); // Read the string up to the '/' character
	//Serial.print(String(inputString));
    if (inputString.length() > 0) {
      // Parse the string into two integers
      int slashIndex = inputString.indexOf('/');
      if (slashIndex >= 0) {
        String firstPart = inputString.substring(0, slashIndex);
        String secondPart = inputString.substring(slashIndex + 1);
        roll = firstPart.toInt();
        pitch = secondPart.toInt();

        // Check if the parsed integers are valid
        if (roll >= 0 && roll <= 180 && pitch >= 0 && pitch <= 180) {
          // Process the received integers
          Serial.print("Roll value: ");
          Serial.println(roll);
          Serial.print("pitch value: ");
          Serial.println(pitch);
        } else {
          Serial.println("Received values are out of range (0 to 180).");
        }
      } else {
        Serial.println("Invalid input format. Please use 'integer/integer' format.");
      }
    }
  }
  Serial.println("Roll: " + String(roll) + ", ptich: " + String(pitch));
  Braccio.ServoMovement(20,         90, 90, 90, roll, pitch,  73);  
  delay(500);
	 
}
