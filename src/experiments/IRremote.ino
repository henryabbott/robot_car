#include <IRremote.hpp>

const int IR_RECEIVE_PIN = 2;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, DISABLE_LED_FEEDBACK);
  delay(2000);

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
  if (button == 0xf708ff00) // 4
    blinkLEDnTimes(4);
  if (button == 0xe718ff00) // 2
    blinkLEDnTimes(2);
  if (button == 0xA15EFF00) // 3
    blinkLEDnTimes(3);
  if (button == 0xE31CFF00) // 5
    blinkLEDnTimes(5);
}

void loop() {
  // put your main code here, to run repeatedly:
 // delay(1000);
  //Serial.println();
  //Serial.print("i am here");
  if (IrReceiver.decode()) {
    Serial.println("i am here");
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    buttonPressed(IrReceiver.decodedIRData.decodedRawData);
    IrReceiver.resume();
  }
}
