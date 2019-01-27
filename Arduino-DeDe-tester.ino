/*
 * Test sketch for the Arduino Debugger & Development Shield - DeDe
 * Bray Almini 2019.01.26
 *
 * Cycle through all the pins in both digital and analog.
 *
 * https://github.com/Brayyy/Arduino-DeDe-tester
 * https://www.kickstarter.com/projects/ellutions/dede-debug-and-development-shield-for-arduinos-and
 */

int timer1 = 150;
int timer2 = 50;
int myPins[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0, A1, A2, A3, A4, A5};
int myPinCount = 20;
int toggleState = 0;

void setup() {
  // use a for loop to initialize each pin as an output:
  for (int count=0; count < myPinCount; count++) {
    pinMode(myPins[count], OUTPUT);
  }
}

void loop() {

  // Toggle digital HIGH, then LOW
  for (int j = 0; j < 2; j++) {
    // Flip the toggle state
    toggleState = !toggleState;

    // loop from the lowest pin to the highest:
    for (int i = 0; i < myPinCount; i++) {
      digitalWrite(myPins[i], toggleState);
      delay(timer1);
    }
  }

  delay(1000);

  // Fade analog 0-255 across all pins. Pins not supporting analog PWM output will go directly HIGH
  // Loop from the lowest pin to the highest:
  for (int i = 0; i < myPinCount; i++) {
    for (int brightness = 0; brightness <= 255; brightness += 15) {
      analogWrite(myPins[i], brightness);
      delay(timer2);
    }
  }

  delay(1000);

  // Return all pins to LOW
  for (int i = 0; i < myPinCount; i++) {
    digitalWrite(myPins[i], 0);
  }

  delay(1000);
}
