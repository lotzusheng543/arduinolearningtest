int inletpin =0;
int LEDPin=13;
int val;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LEDPin, OUTPUT);
  pinMode(inletpin, INPUT);
}

// the loop function runs over and over again forever
void loop() {
 
val= digitalRead(inletpin);
 
if (val==HIGH){
  digitalWrite(LEDPin, HIGH);  // turn the LED on (HIGH is the voltage level)

}

else {
  digitalWrite(LEDPin, LOW);   // turn the LED off by making the voltage LOW

}


}