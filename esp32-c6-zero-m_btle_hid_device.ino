/*
  esp32-c6-zero-m_ble_hid_device

  This is my test attempt to create a Bluetooth LE Device which
  is supposed to emulate a mouse vscroll and hscroll
*/

#include <BleKeyboard.h>

// this is the array the library takes to configure the device
// containing (device_name, oem, battery_default_level)
BleKeyboard bleKeyboard("ESP32 HID Dial", "Espressif", 100);

// my mapping for the pins, prone to change
const int upArrowPin = 0;
const int downArrowPin = 1;
const int enterKeyPin = 2;
const int volumeUpPin = 3;
const int volumeDownPin = 4;

// setup code that runs before the loop
void setup() {
  pinMode(upArrowPin, INPUT_PULLUP);
  pinMode(downArrowPin, INPUT_PULLUP);
  pinMode(enterKeyPin, INPUT_PULLUP);
  pinMode(volumeUpPin, INPUT_PULLUP);
  pinMode(volumeDownPin, INPUT_PULLUP);
  
  pinMode(LED_BUILTIN, OUTPUT); // on board led
  
  // calls a library function
  bleKeyboard.begin();
}

// main loop
void loop() {
  // enables the reading of GPIO when it is connected
  if (bleKeyboard.isConnected()) {
    if (digitalRead(upArrowPin) == LOW) {
      bleKeyboard.write(KEY_UP_ARROW);
      blinkLED();
    }
    
    if (digitalRead(downArrowPin) == LOW) {
      bleKeyboard.write(KEY_DOWN_ARROW);
      blinkLED();
    }
    
    if (digitalRead(enterKeyPin) == LOW) {
      bleKeyboard.write(KEY_RETURN);
      blinkLED();
    }
    
    if (digitalRead(volumeUpPin) == LOW) {
      bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
      blinkLED();
    }
    
    if (digitalRead(volumeDownPin) == LOW) {
      bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
      blinkLED();
    }
  }
  
  delay(10);  // small delay to avoid bouncing
}

// visual feedback for button actions
void blinkLED() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(50);
  digitalWrite(LED_BUILTIN, LOW);
}
