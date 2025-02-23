#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <Arduino.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

#define ROTATE_RIGHT 1
#define ROTATE_LEFT 2

void setup_motor_control();
void setAllMotorSpeeds(uint8_t speed);
void moveForward(uint8_t speed);
void moveBackward(uint8_t speed);
void rotate(uint8_t speed, uint8_t rotate_dir);

uint8_t getCurrentSpeed();
uint8_t getCurrentDirection();

#endif // MOTOR_CONTROL_H