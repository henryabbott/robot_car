#ifndef REMOTE_CONTROL_H
#define REMOTE_CONTROL_H

#include <Arduino.h>

const uint32_t BUTTON_NONE  = 0x00000000;
const uint32_t BUTTON_UP    = 0xE619FF00;
const uint32_t BUTTON_DOWN  = 0xE31CFF00;
const uint32_t BUTTON_LEFT  = 0xF30CFF00;
const uint32_t BUTTON_RIGHT = 0xA15EFF00;
const uint32_t BUTTON_CENTER = 0xE718FF00;
const uint32_t BUTTON_POWER  = 0xB946FF00;
const uint32_t BUTTON_A = 0xBB44FF00;
const uint32_t BUTTON_B = 0xBF40FF00;
const uint32_t BUTTON_C = 0xBC43FF00;

void setup_remote_control();
uint32_t checkRemoteControl();

#endif // REMOTE_CONTROL_H