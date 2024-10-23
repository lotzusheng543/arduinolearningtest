/* SHP 2013 */


int val;    // store analog value read from IR sensor
int distance;     // use int instead of float as it's cheaper on the memory budget
int sum = 0;

void setup() {
  pinMode(11, OUTPUT); // use pin 13 for LED
  Serial.begin(9600);
  Serial.println("Infrared Distance Sensor!");
}

void loop() {
  // sample 10 readings
  for (int i = 0; i <= 10; i++) {
    val = analogRead(0); // read the value from the IR sensor
    distance = 12343.85 * pow(val, -1.15);    // distance in cm; for accurate sensor measurements, calibration is required
    sum = sum + distance;
    delay(10);   // sampling interval
  }
  
  // average the 10 readings
  distance = sum/10;
  sum = 0;    // reset the value of sum
  Serial.print(distance);    // Use print out to check sensor functionality
  Serial.println();

  if (distance < 16){
    digitalWrite(11,HIGH);
    delay(1000);
    digitalWrite(11, LOW);
    delay(1000);
    digitalWrite(13,HIGH);
    tone(13,320);
    delay(50);
    tone(13,450);
    delay(50);
    tone(13,777);
    delay(50);
    tone(13,320);
    delay(50);
    noTone(13);
  } 
  
  else if (distance < 30){
    analogWrite(11, 255);
    delay(2000);
    analogWrite(11,122);
    delay(2000);
    tone(13,777);
    delay(100);
    tone(13,777);
    delay(100);
    tone(13,865);
    delay(100);
    tone(13,1320);
    delay(100);
    tone(13, 444);
    delay(10);
    noTone(13);

  }
  else{
    digitalWrite(11, LOW);
    delay(1000);
    tone(13,329.628);
    delay(100);
    tone(13,329.628);
    delay(500);
    noTone(13);
    delay(10);
    tone(13,349.228);
    delay(500);
    noTone(13);
    delay(10);
    tone(13,391.995);
    delay(500);
    noTone(13);
    delay(10);
    tone(13,391.995);
    delay(500);
    noTone(13);
    delay(10);
    tone(13,349.228);
    delay(500);
    tone(13,329.628);
    delay(500);
    noTone(13);
    delay(10);
    tone(13,293.665);
    delay(500);
    noTone(13);
  }
  }    
