void setup() {  
  for (int i = 5; i <= 11; i += 1) {
    pinMode(i, OUTPUT);           // set PWM pins as output
  }
}

void loop() {
  // First behavior: full brightness and then turn off
  for (int i = 5; i <= 11; i += 1) {
    analogWrite(i, 255);          // set full brightness
  }
  delay(1000); // wait for a second
  for (int i = 5; i <= 11; i += 1) {
    analogWrite(i, 0);            // turn all the lights off
  }
  delay(1000);

  // Second behavior: fade in and out
  for (int brightness = 0; brightness <= 255; brightness++) {
    for (int i = 5; i <= 11; i += 1) {
      analogWrite(i, brightness);
    }
    delay(20);
  }

  for (int brightness = 255; brightness >= 0; brightness--) {
    for (int i = 5; i <= 11; i += 1) {
      analogWrite(i, brightness);
    }
    delay(20);
  }

  // Third behavior: different fading speeds
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(5, brightness);               // LED on pin 5
    
    analogWrite(6, 255 - brightness);         // LED on pin 6 fades inversely
     
    analogWrite(9, (brightness / 2) % 256);   // LED on pin 9 dims slower
     
    analogWrite(10, (brightness / 4) % 256);  // LED on pin 10 dims slower
     
    analogWrite(11, (brightness / 3) % 256);  // LED on pin 11 dims slower
    delay(1000);                              // Adjust the speed of the fade
  }
}
