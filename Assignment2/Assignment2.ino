/*
  IoT HW01 - Assignment 2
  202334273 Kim Yeseo
*/

#define LED_PIN        4     // GPIO 04 pin connected to the LED
#define BUTTON_PIN     15    // GPIO 15 pin connected to the push button

// Current state of the LED
bool isLedOn = false;        

void setup() {
  // Set LED pin as output
  pinMode(LED_PIN, OUTPUT);       

  // Set button pin as input with internal pull-up resistor
  pinMode(BUTTON_PIN, INPUT_PULLUP);      
}

void loop() {
  // Check if the button is pressed (LOW means pressed)
  if (digitalRead(BUTTON_PIN) == LOW) {
    delay(20);  // Simple debounce delay

    // Check again after delay to confirm the button press
    if (digitalRead(BUTTON_PIN) == LOW) {
      toggleLed(LED_PIN);  // Toggle the LED state
    }

    // Wait until the button is released to avoid multiple toggles
    while (digitalRead(BUTTON_PIN) == LOW);
  }
}

// Function to toggle the LED on or off
void toggleLed(int pin) {
  isLedOn = !isLedOn;
  digitalWrite(pin, isLedOn);
}