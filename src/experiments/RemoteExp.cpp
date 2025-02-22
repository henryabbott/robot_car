#include <Arduino.h>
//#include <IRremote.hpp>

const int IR_RECEIVE_PIN = 2;


void setup_remote_exp() {
  // put your setup code here, to run once:
  Serial.begin(115200);
 // IrReceiver.begin(IR_RECEIVE_PIN, DISABLE_LED_FEEDBACK);
  delay(2000); // may be required for some reason??

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  
  Serial.println("Setup complete.");
}

void blinkOnce() {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW  
}

void blinkLEDnTimes(const int n){
  for (int i = 0; i < n-1; ++i) {
    blinkOnce();
    delay(500);    
  }
  blinkOnce();
}

void buttonPressed(const uint32_t button) {
  // if (button == 0xf708ff00) // 4
  //   blinkLEDnTimes(4);
  // if (button == 0xe718ff00) // 2
  //   blinkLEDnTimes(2);
  // if (button == 0xA15EFF00) // 3
  //   blinkLEDnTimes(3);
  // if (button == 0xE31CFF00) // 5
  //   blinkLEDnTimes(5);

  if(button == 0xBB44FF00)
    Serial.println("A was pressed");
  if(button == 0xBF40FF00)
    Serial.println("B was pressed");
  if (button == 0xBC43FF00)
    Serial.println("C was pressed");
  if (button == 0xE619FF00)
    Serial.println("UP was pressed");
  if (button == 0xE31CFF00)
    Serial.println("DOWN was pressed");
  if (button == 0xA15EFF00)
    Serial.println("RIGHT was pressed");
  if (button == 0xF30CFF00)
    Serial.println("LEFT was pressed");
  if (button == 0xE718FF00)
    Serial.println("CENTER was pressed");
  if (button == 0xB946FF00)
    Serial.println("POWER was pressed");
}

void loop_remote_exp() {
  // put your main code here, to run repeatedly:
 // delay(1000);
  //Serial.println();
  //Serial.print("i am here");
  // if (IrReceiver.decode()) {
  //   // Serial.println("IR Remote Message Decoded:");
  //   // Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
  //   // Serial.println("Is Repeat:");
  //   // Serial.println(IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT);
  //   buttonPressed(IrReceiver.decodedIRData.decodedRawData);
  //   IrReceiver.resume();
  // }
}
