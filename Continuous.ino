#include <Servo.h>

Servo myservo;

#define PUMPPIN 9    //peristaltic pump control pin, connect to arduino digital pin 9
int power;//power level of pump, between 90 and 180
void setup() 
{
  myservo.attach(PUMPPIN);
  power = 180;//set power level
}

void loop() 
{
    myservo.write(power);   //set motor to speed
}
