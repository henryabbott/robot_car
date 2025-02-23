#include <MotorControl.h>


Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);
Adafruit_DCMotor *myMotor3 = AFMS.getMotor(3);
Adafruit_DCMotor *myMotor4 = AFMS.getMotor(4);

uint8_t current_speed = 0;
uint8_t current_dir = RELEASE;

uint8_t getCurrentSpeed(){
    return current_speed;
}

uint8_t getCurrentDirection(){
    return current_dir;
}

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

void allMotorsOff(){
    myMotor1->fullOff();
    myMotor2->fullOff();
    myMotor3->fullOff();
    myMotor4->fullOff();
}

void setup_motor_control(){
    AFMS.begin();
    allMotorsOff();
}

void moveForward(uint8_t speed){
    setAllMotorSpeeds(speed);
    setAllMotorDir(FORWARD);
    current_speed = speed;
    current_dir = FORWARD;
}

void moveBackward(uint8_t speed){
    setAllMotorSpeeds(speed);
    setAllMotorDir(BACKWARD);
    current_speed = speed;
    current_dir = BACKWARD;
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
