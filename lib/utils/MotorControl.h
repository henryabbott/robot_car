#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <Arduino.h>

#define ROTATE_RIGHT 1
#define ROTATE_LEFT 2

void setup_motor_control();

void moveForward(uint8_t speed);
void moveBackward(uint8_t speed);
void rotate(uint8_t speed, uint8_t rotate_dir);

#endif // MOTOR_CONTROL_H