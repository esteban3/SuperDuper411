/* 
Super Duper servo controlling program.  This program is based on the
  Arduino 'Sweep' program.  Arduino is an open-source project, courtesy
  of Massimo Banzi, David Cuartielles, Tom Igoe, Gianluca Martino, David
  Mellis, Casey Reas, and Ben Fry.  (http://arcuiono.cc/)
  
  The Sweep program was developed by BARRAGAN <http://barraganstudio.com>, 
  modified 8 Nov 2013 by Scott Fitzgerald

Modified for SuperDuper: Nov-Dec 2014
Modified By: Evan Sprecher & Jennifer Carr

SuperDuper modification:
  When a voltage is sensed on the motion sensor pin, the servos will rotate,
  and the attached laser will spin and blink 5 times.
*/ 

#include <Servo.h> 
 
Servo myservo1;
Servo myservo2;

const int sensorpin = A0; // A0 is the sensor pin
const int laserpin = 8;  // D8 is the lasor pin

int pos1 = 0;           // Variable to store myservo1 position
int pos2 = 0;           // Variable to store myservo2 position
int i = 0;
 
void setup() 
{ 
  myservo1.attach(9);     // Attach the servo on pin 9 to the servo object 
  myservo2.attach(10);    // Attach the servo on pin 10 to the servo object 
  pinMode(laserpin, OUTPUT);
} 
 
void loop() 
{ 
  if(analogRead(sensorpin) >= 400){
    for(i=0; i<4; i++){
      digitalWrite(laserpin, HIGH);
      // Move both servos back and forth so fast that it blends into a circle
      for(pos1=0; pos1<=60; pos1+=1)
      {
        myservo1.write(pos1);               
        delay(20);
      } 
      for(pos2=0; pos2<=90; pos2+=1)  
      {                                   
        myservo2.write(pos2);               
        delay(20);                        
      }
      for(pos1=60; pos1>=0; pos1-=1)      
      {                                
        myservo1.write(pos1);
        delay(20);                        
      } 
      for(pos2=90; pos2>=0; pos2-=1)     
      {                                
        myservo2.write(pos2);             
        delay(20);                        
      }
    } 
    digitalWrite(laserpin, LOW);  
    delay(3000);   
  }
}

