#include <Arduino.h>
#include <RemoteControl.h>
#include <MotorControl.h>

void setup() {
  // put your setup code here, to run once:
  // setup_remote_exp();
  // setup_motor_exp();
  Serial.begin(115200);
  
  setup_remote_control();
  setup_motor_control();
  Serial.println("Setup complete.");
}

void handle_remote_command(uint32_t cmd){
  if(cmd == BUTTON_A)
    Serial.println("A was pressed");
  if(cmd == BUTTON_B)
    Serial.println("B was pressed");
  if (cmd == BUTTON_C)
    Serial.println("C was pressed");
  if (cmd == BUTTON_UP){
    Serial.println("UP was pressed");
    moveForward(50);
  }
  if (cmd == BUTTON_DOWN){
    Serial.println("DOWN was pressed");
    moveBackward(50);
  }
  if (cmd == BUTTON_RIGHT)
    Serial.println("RIGHT was pressed");
  if (cmd == BUTTON_LEFT)
    Serial.println("LEFT was pressed");
  if (cmd == BUTTON_CENTER)
    Serial.println("CENTER was pressed");
  if (cmd == BUTTON_POWER)
    Serial.println("POWER was pressed");
}

void loop() {
  // put your main code here, to run repeatedly:
  // loop_remote_exp();
  // loop_motor_exp();

  uint32_t remote_cmd = checkRemoteControl();
  if(remote_cmd != BUTTON_NONE)
    handle_remote_command(remote_cmd);
}
