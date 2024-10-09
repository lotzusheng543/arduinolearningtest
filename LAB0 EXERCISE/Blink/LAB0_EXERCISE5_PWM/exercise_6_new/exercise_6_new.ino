int LEDPin1 = 5;
int LEDPin2 = 6;
int LEDPin3 = 9;
int LEDPin4 = 10;
int LEDPin5 = 11;
int i, val;
int j, val2;



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

  for (i=0; i<10; i++)  {
    val= (25 * i);
    analogWrite(LEDPin1, val);   //turn LED bright
     analogWrite(LEDPin2, val);  //turn LED bright
      analogWrite(LEDPin3, val);  //turn LED bright
       analogWrite(LEDPin4, val);  //turn LED bright
        analogWrite(LEDPin5, val);   //turn LED bright
       
      
    delay(1000);
  }

  for (j=0; j<10; j++) {
    val2= (250 - 25*j);
     analogWrite(LEDPin1, val2);   //turn LED bright
        analogWrite(LEDPin2, val2);   //turn LED bright
        analogWrite(LEDPin3, val2);   //turn LED bright
        analogWrite(LEDPin4, val2);   //turn LED bright
        analogWrite(LEDPin5, val2);   //turn LED bright
    delay(1000);
  }
}
