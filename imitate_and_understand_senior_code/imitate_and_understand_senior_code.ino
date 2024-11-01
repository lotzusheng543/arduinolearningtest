#include <Servo.h>


Servo servo1;
Servo servo2;
Servo servotail;
Servo servo3;
#define trigPin 6
#define echoPin 5
#define LDR1_reading A0
#define LDR2_reading A1
#define EYES_LED 4
#define speakerPin 7
#define BLINKING_LED1 12
#define BLINKING_LED2 2
#define BLINKING_LED3 3
int distance = 15; // distance in cm
int dis = 90;
int dis2 = 90;
int distail = 90;
int sensorValue = 0;
int sensorValue2 = 0;
int pos = 0;
int deg = 35;
int T_LDR1 = 45;
int T_LDR2 = 60;
int LDR1_val;
int LDR2_val;
int REF_LDR;
int REF_LDR2;
int bd = 0;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(8);
  servo2.attach(9);
  servo3.attach(10);
  servotail.attach(11);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(BLINKING_LED1,OUTPUT);
  pinMode(BLINKING_LED2,OUTPUT);
  pinMode(BLINKING_LED3,OUTPUT);
  pinMode(EYES_LED,OUTPUT);
  pinMode(speakerPin,OUTPUT);
  //pinMode(LED10,OUTPUT);
  //pinMode(LED11,OUTPUT);
  Serial.begin(9600);
  REF_LDR = analogRead(LDR1_reading);
  REF_LDR = analogRead(LDR2_reading);
}

void loop() {
  // put your main code here, to run repeatedly:
   long duration, cm;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(20);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  cm = duration / 58;
  delay(0);
  Serial.print(cm);
  Serial.print("cm");
  Serial.print(dis);
  Serial.print(dis2);
  LDR1_val = analogRead(LDR1_reading);
  LDR2_val = analogRead(LDR2_reading);
  if (dis > 180){
    dis = 180;
  }
  if (dis < 0){
    dis = 0;
  }
  if (dis2 > 180){
    dis2 = 180;
  }
  if (dis2 < 0){
    dis2 = 0;
  }
  if (distail >= 180){
    distail = 180;
  }
  if (distail <= 90){
    distail = 90;
  }
  if (cm >= 50){
    if((REF_LDR - LDR1_val) > T_LDR1){ // when ultra see nothing; mouth and body see something
    Serial.print("1");
    delay(100);
    servo3.write(80);
    for (pos = 90; pos < 180; pos += 5){
      servotail.write(pos);
      delay(50);
    }
    for (pos = 180; pos > 90; pos -= 5){
      servotail.write(pos);
      delay(50);
    }
    tone(speakerPin, 329, 1500);
    delay(250);
    tone(speakerPin, 392, 1500);
    delay(250);
    tone(speakerPin, 329, 1500);
    delay(250);
    tone(speakerPin, 392, 1500);
    delay(250);
    tone(speakerPin, 523, 1500);
    delay(400);
    tone(speakerPin, 493, 1500);
    digitalWrite(EYES_LED, HIGH);
    digitalWrite(BLINKING_LED1, HIGH);
    digitalWrite(BLINKING_LED2, HIGH);
    digitalWrite(BLINKING_LED3, HIGH);
    servotail.write(180);
    delay(100);
    servotail.write(90);
    delay(100);
    servotail.write(180);
    delay(100);
    servotail.write(90);
    delay(100);
    servotail.write(180);
    delay(100);
    servotail.write(90);
    delay(100);
    delay(700);
    }
    else{              //2 when ultra see nothing, mouth see somrthing; body no see thing
    Serial.print("2");
    delay(100);
    servo3.write(80);
    servotail.write(90);      
    }
  }
  else{
    if ((REF_LDR2 - LDR2_val) > T_LDR2){   // 3 When ultra see nothing; mouth no see; back see something
    Serial.print("3");
    Serial.println(LDR2_val);
    delay(0);
    servo3.write(35);
    for (pos = 90; pos <180; pos += 5){
      servotail.write(pos);
      delay(50);
    }
  }

  else{      // 4 nothing see anything
    Serial.print("4");
    delay(0);
    servo3.write(90);
    servotail.write(35); 
    digitalWrite(EYES_LED, LOW);
    digitalWrite(BLINKING_LED1, LOW);
    digitalWrite(BLINKING_LED2, LOW);
    digitalWrite(BLINKING_LED3, LOW);
  }
  if (dis > 92 && dis2 < 88){
    dis = dis - 4;
    dis2 = dis2 + 4;
    servo2.write(dis);
    servo1.write(dis2);
  }
  else if (dis < 88 && dis2 >92){
    dis = dis + 4;
    dis2 = dis2 -4;
    servo2.write(dis);
    servo1.write(dis2);
  }
  else{
    servo2.write(90);
    servo1.write(90);
  }
  }



}


  
  

