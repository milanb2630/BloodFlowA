#include <Servo.h>

Servo myservo;
float x;//function of time that is fed into the sin function
float a;//constant that converts period of sine wave from 2 PI milliseconds into 1 / bps  
float bps;//variable controlling beats per second of the pump
int avgValue;//average power value of the pump, should be between 90 and 180
int amplitude;//amplitude of fluctuation of power level: max power value = avgValue + amplitude (should be 180), min power value = avgValue - amplitude
#define PUMPPIN 9    //peristaltic pump control pin, connect to arduino digital pin 9

void setup() 
{
  myservo.attach(PUMPPIN);//initializes peristaltic control pin
  bps = 1.5; //user sets beats per second
  a = (.001) * bps * 2 * PI;//initializes constant using bps
  x = a * millis();//initializes x
  avgValue = 150;//initializes avgValue
  amplitude = 30;//initializes amplitude
}

void loop() 
{
    x = a * millis();//for each run through of the loop, x is reset based on the current time value
    myservo.write(avgValue + (amplitude * sin(x)));//sets pump power to desired value based on avgValue, amplitude, and time passed    
}
