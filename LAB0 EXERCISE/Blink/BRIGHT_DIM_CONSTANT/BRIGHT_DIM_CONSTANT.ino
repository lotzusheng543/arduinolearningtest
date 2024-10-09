int LEDPin1 = 5;
int LEDPin2 = 6;
int LEDPin3 = 9;
int LEDPin4 = 10;
int LEDPin5 = 11;
int i, val;
int j, val2;
int LED[] {LEDPin1, LEDPin2, LEDPin3, LEDPin4, LEDPin5};



void setup() {
  // put your setup code here, to run once:
  pinMode(LEDPin1, OUTPUT);
  pinMode(LEDPin2, OUTPUT);
  pinMode(LEDPin3, OUTPUT);
  pinMode(LEDPin4, OUTPUT);
  pinMode(LEDPin5, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  for (i=0; i<5; i++)  {
    val= (10 * i *i);
    analogWrite(LEDPin1, val);   //turn LED bright
    delay(50);
     analogWrite(LEDPin2, val);  //turn LED bright
      delay(50);
      analogWrite(LEDPin3, val);  //turn LED bright
       delay(50);
       analogWrite(LEDPin4, val);  //turn LED bright
        delay(50);
        analogWrite(LEDPin5, val);   //turn LED bright
       
      
    delay(1000);
  }

  for (j=0; j<4; j++) {
     digitalWrite(LED[i], LOW);
    delay(50);
  }
}
