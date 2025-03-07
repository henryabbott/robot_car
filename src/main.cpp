#include <Arduino.h>
#include <RemoteControl.h>
#include <MotorControl.h>
 
void setup() {
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
    if(getCurrentDirection()==FORWARD){
      moveForward(min(255, getCurrentSpeed()+50));
    }else{
      moveForward(50);
    }
  }
  if (cmd == BUTTON_DOWN){
    Serial.println("DOWN was pressed");
    if(getCurrentDirection()==BACKWARD){
      moveBackward(min(255, getCurrentSpeed()+50));
    }else{
      moveBackward(50);
    }
  }
  if (cmd == BUTTON_RIGHT)
    Serial.println("RIGHT was pressed");
  if (cmd == BUTTON_LEFT)
    Serial.println("LEFT was pressed");
  if (cmd == BUTTON_CENTER)
    Serial.println("CENTER was pressed");
  if (cmd == BUTTON_POWER){
    Serial.println("POWER was pressed");
    setAllMotorSpeeds(0); 
  }
}

void loop() {
  uint32_t remote_cmd = checkRemoteControl();
  if(remote_cmd != BUTTON_NONE){
    handle_remote_command(remote_cmd);
  }
}
