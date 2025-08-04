#include <Arduino.h>

// LED Pins
const int redPin    = 2;   // G2
const int yellowPin = 4;   // G4
const int greenPin  = 5;   // G5
const int bluePin   = 15;  // G15
const int whitePin  = 18;  // G18

// PWM Channels
const int redChannel    = 0;
const int yellowChannel = 1;
const int greenChannel  = 2;
const int blueChannel   = 3;
const int whiteChannel  = 4;

// PWM Config
const int freq = 50000;
const int resolution = 8; // 8-bit: 0–255 brightness levels

void setup() {
  ledcSetup(redChannel, freq, resolution);
  ledcAttachPin(redPin, redChannel);

  ledcSetup(yellowChannel, freq, resolution);
  ledcAttachPin(yellowPin, yellowChannel);

  ledcSetup(greenChannel, freq, resolution);
  ledcAttachPin(greenPin, greenChannel);

  ledcSetup(blueChannel, freq, resolution);
  ledcAttachPin(bluePin, blueChannel);

  ledcSetup(whiteChannel, freq, resolution);
  ledcAttachPin(whitePin, whiteChannel);

  Serial.begin(115200);
}

// Function to fade multiple LEDs simultaneously
void fadeMultipleLEDs(int channels[], int count) {
  // Fade in
  for (int brightness = 0; brightness <= 255; brightness++) {
    for (int i = 0; i < count; i++) {
      ledcWrite(channels[i], brightness);
    }
    delay(3);
  }
  // Fade out
  for (int brightness = 255; brightness >= 0; brightness--) {
    for (int i = 0; i < count; i++) {
      ledcWrite(channels[i], brightness);
    }
    delay(3);
  }
}

void loop() {
  int group1[] = {greenChannel};
  fadeMultipleLEDs(group1, 1);

  int group2[] = {blueChannel, yellowChannel};
  fadeMultipleLEDs(group2, 2);

  int group3[] = {whiteChannel, redChannel};
  fadeMultipleLEDs(group3, 2);

  int group4[] = {blueChannel, yellowChannel};
  fadeMultipleLEDs(group4, 2);

}

