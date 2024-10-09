int inletpin=1;
int LEDPin=11;
int val;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(11, OUTPUT);
  pinMode(inletpin, INPUT);
}

// the loop function runs over and over again forever
void loop() {
val = digitalRead (inletpin);

if (val = HIGH){
  digitalWrite(11, HIGH);
  delay(2000);
}

else{
  digitalWrite(LEDPin, LOW);
}
  
  digitalWrite(11, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(2000);                      // wait for a second
  digitalWrite(11, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}
