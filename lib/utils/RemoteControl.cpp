#include <RemoteControl.h>
#include <IRremote.hpp>

const int IR_RECEIVE_PIN = 2;
const unsigned long DEBOUNCE_DELAY_MS = 500;
uint32_t last_remote_cmd = BUTTON_NONE;
unsigned long last_cmd_millis = millis();

void setup_remote_control() {
    IrReceiver.begin(IR_RECEIVE_PIN, DISABLE_LED_FEEDBACK);
}

uint32_t checkRemoteControl(){
    uint32_t result = BUTTON_NONE;
    if (IrReceiver.decode()) {
        unsigned long current_millis = millis();
        if( (current_millis - last_cmd_millis) > DEBOUNCE_DELAY_MS
            && (IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT) ){
            // only return last_remote_cmd (i.e., repeats)
            // if a certain amount of time has elapsed since first button press
            result = last_remote_cmd;
            last_cmd_millis = current_millis;
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
                    last_cmd_millis = current_millis;
        }
        
        // Serial.println("IR Remote Message Decoded:");
        // Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
        // // Serial.println("Is Repeat:");
        // Serial.println(IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT);

        IrReceiver.resume();
    }

    return result;
}
