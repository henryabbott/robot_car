#include <RemoteControl.h>

// #include <Arduino.h>
#include <IRremote.hpp>

const int IR_RECEIVE_PIN = 2;
uint32_t last_remote_cmd = BUTTON_NONE;

void setup_remote_control() {
    IrReceiver.begin(IR_RECEIVE_PIN, DISABLE_LED_FEEDBACK);
}

uint32_t checkRemoteControl(){
    uint32_t result = BUTTON_NONE;
    if (IrReceiver.decode()) {
        if(IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT){
            result = last_remote_cmd;
        }else if(  IrReceiver.decodedIRData.decodedRawData == BUTTON_A
                || IrReceiver.decodedIRData.decodedRawData == BUTTON_B
                || IrReceiver.decodedIRData.decodedRawData == BUTTON_C
                || IrReceiver.decodedIRData.decodedRawData == BUTTON_UP
                || IrReceiver.decodedIRData.decodedRawData == BUTTON_DOWN
                || IrReceiver.decodedIRData.decodedRawData == BUTTON_LEFT
                || IrReceiver.decodedIRData.decodedRawData == BUTTON_RIGHT
                || IrReceiver.decodedIRData.decodedRawData == BUTTON_POWER
                || IrReceiver.decodedIRData.decodedRawData == BUTTON_CENTER ){
                    result = IrReceiver.decodedIRData.decodedRawData;
                    last_remote_cmd = result;
        }
        
        // Serial.println("IR Remote Message Decoded:");
        // Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
        // // Serial.println("Is Repeat:");
        // Serial.println(IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT);

        IrReceiver.resume();
    }
    return result;
}
