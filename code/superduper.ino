/* 
Super Duper servo controlling program.

when a voltage is sensed on the motion sensor pin,
twirl the servos and blink the lasor 5 times.
*/ 

#include <Servo.h> 
 
Servo myservo;
Servo myservo2;

const int sensorpin=A0; //A0 is the sensor pin
const int laserpin =8;  //D8 is the lasor pin

int pos = 0;   
int pos2 = 0;
int i = 0;
 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 10 to the servo object 
  myservo2.attach(10);  // attaches the servo on pin 11 to the servo object 
  pinMode(laserpin, OUTPUT);
} 
 
void loop() 
{ 
  if(analogRead(sensorpin)>=400){
    for(i=0;i<4;i++){
        digitalWrite(laserpin, HIGH);  
      //move both servos back and forth so fast that it blends into a circle.
      for(pos = 0; pos <= 180; pos += 1)
      {
        myservo.write(pos);               
        delay(1);
      } 
      for(pos2 = 0; pos2 <= 180; pos2 += 1)  
      {                                   
        myservo2.write(pos2);               
        delay(1);                        
      }
          digitalWrite(laserpin, LOW);
      for(pos = 180; pos>=0; pos-=1)      
      {                                
        myservo.write(pos);               
        delay(1);                        
      } 
      for(pos2 = 180; pos2>=0; pos2-=1)     
      {                                
        myservo2.write(pos2);             
        delay(1);                        
      }
      
      
      
    } 
  } 
}
