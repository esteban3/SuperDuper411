/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
 
Servo myservo;
Servo myservo2;

const int sensorpin=5;

int pos = 0;   
int pos2 = 0;
int i = 0;
 
void setup() 
{ 
  myservo.attach(10);  // attaches the servo on pin 10 to the servo object 
  myservo2.attach(11);  // attaches the servo on pin 11 to the servo object 
  pinMode(sensorpin, INPUT);
} 
 
void loop() 
{ 
  if(digitalRead(sensorpin)){
    for(i=0;i<4;i++){
      for(pos = 0; pos <= 180; pos += 1)
      {
        myservo.write(pos);               
        delay(1);
      } 
      for(pos2 = 0; pos2 <= 180; pos2 += 1) // goes from 0 degrees to 180 degrees 
      {                                  // in steps of 1 degree 
        myservo2.write(pos2);              // tell servo to go to position in variable 'pos' 
        delay(1);                       // waits 15ms for the servo to reach the position 
      } 
      for(pos = 180; pos>=0; pos-=1)     // goes from 180 degrees to 0 degrees 
      {                                
        myservo.write(pos);              // tell servo to go to position in variable 'pos' 
        delay(1);                       // waits 15ms for the servo to reach the position 
      } 
      for(pos2 = 180; pos2>=0; pos2-=1)     // goes from 180 degrees to 0 degrees 
      {                                
        myservo2.write(pos2);              // tell servo to go to position in variable 'pos' 
        delay(1);                       // waits 15ms for the servo to reach the position 
      }
    } 
  } 
}
