int ledPin1 = 11;
int ledPin2 = 10;
int ledPin3 = 9;
int ledPin4 = 6;
int ledPin5 = 5;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  analogWrite(ledPin1, 255);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  analogWrite(ledPin1, 0);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
  analogWrite(ledPin2, 250);
  delay(1000);
  analogWrite(ledPin2, 0);
  delay(1000);
  analogWrite(ledPin3, 233);   
  delay(1000); 
  analogWrite(ledPin3, 0);   
  delay(1000);
  analogWrite(ledPin4, 222);   
  delay(1000);
  analogWrite(ledPin4, 0);   
  delay(1000);
  analogWrite(ledPin5, 206);   
  delay(1000);
  analogWrite(ledPin5, 0);   
  delay(1000); 
}
