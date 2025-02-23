#include <MotorControl.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

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

void setup_motor_control(){
    AFMS.begin();
}

void moveForward(uint8_t speed){
    setAllMotorSpeeds(speed);
    setAllMotorDir(FORWARD);
}

void moveBackward(uint8_t speed){
    setAllMotorSpeeds(speed);
    setAllMotorDir(BACKWARD);
}

void rotate(uint8_t speed, uint8_t dir){
    setAllMotorSpeeds(speed);
    switch (dir)
    {
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
