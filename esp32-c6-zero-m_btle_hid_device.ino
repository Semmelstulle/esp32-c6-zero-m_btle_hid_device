/*
  esp32-c6-zero-m_ble_hid_device

  This is my test attempt to create a Bluetooth LE Device which
  is supposed to emulate a mouse vscroll and hscroll
*/

// constants won't change. They're used here to set pin numbers:
const int mouseClickPin = 0;  // the number of the pushbutton pin

// variables will change:
int mouseClickPinState = 0;  // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(mouseClickPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  mouseClickPinState = digitalRead(mouseClickPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (mouseClickPinState == HIGH) {
    // turn LED on:
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    // turn LED off:
    digitalWrite(LED_BUILTIN, LOW);
  }
}
