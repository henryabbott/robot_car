
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

#define ROTATE_RIGHT 1
#define ROTATE_LEFT 2

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);
Adafruit_DCMotor *myMotor3 = AFMS.getMotor(3);
Adafruit_DCMotor *myMotor4 = AFMS.getMotor(4);

void setAllMotorSpeeds(uint8_t speed){
  myMotor1->setSpeed(speed);
  myMotor2->setSpeed(speed);
  myMotor3->setSpeed(speed);
  myMotor4->setSpeed(speed);
}

void setAllMotorDir(uint8_t dir){
  myMotor1->run(dir);
  myMotor2->run(dir);
  myMotor3->run(dir);
  myMotor4->run(dir);
}

void moveForward(uint8_t speed) {
  setAllMotorSpeeds(speed);
  setAllMotorDir(FORWARD);
}

void neutral() {
  setAllMotorDir(RELEASE);
}

void applyBrakes() {
  setAllMotorDir(BRAKE);
}

void moveBackward(uint8_t speed) {
  setAllMotorSpeeds(speed);
  setAllMotorDir(BACKWARD);
}

void rotate(uint8_t speed, uint8_t dir) {
  setAllMotorSpeeds(speed);
  switch(dir){
    case ROTATE_RIGHT:
      myMotor1->run(FORWARD);
      myMotor2->run(FORWARD);
      myMotor3->run(BACKWARD);
      myMotor4->run(BACKWARD);
      break;
    case ROTATE_LEFT:
      myMotor1->run(BACKWARD);
      myMotor2->run(BACKWARD);
      myMotor3->run(FORWARD);
      myMotor4->run(FORWARD);
      break;
  }
}

void stopMoving();

void rotateRightDegrees(int degrees){
  // rotating at speed 100 right for 2500ms is approx 180 degrees
  int duration = degrees / 180.0 * 2300;
  
  Serial.print("Degrees: ");
  Serial.print(degrees);
  Serial.print("\n");
  Serial.print("Duration: ");
  Serial.print(duration);
  Serial.print("\n");
  
  rotate(100, ROTATE_RIGHT);
  delay(duration);
  stopMoving();
}

void stopMoving() {
  myMotor1->fullOff();
  myMotor2->fullOff();
  myMotor3->fullOff();
  myMotor4->fullOff();
}

void setup_motor_exp() {
  // put your setup code here, to run once:
  AFMS.begin();
  Serial.begin(115200);
  Serial.println("Setup complete.");
}

void loop_motor_exp() {
  // put your main code here, to run repeatedly:
  delay(1000);
//  moveForward(120);
//  delay(1000);
//  stopMoving();
//  delay(1000);
//  moveBackward(120);
//  delay(1000);
//  stopMoving();
//  delay(500);
//  rotate(200, ROTATE_RIGHT);
//  delay(1250);
//  stopMoving();
//  delay(500);
//  rotate(200, ROTATE_LEFT);
//  delay(1250);
//  stopMoving();

  // rotating at 100 speed for 2500ms was approx 180 degrees
  delay(2000);
  rotateRightDegrees(180);
  delay(2000);
  rotateRightDegrees(90);
  delay(2000);
  rotateRightDegrees(360);
  delay(2000);
//  myMotor1->run(RELEASE);
}
