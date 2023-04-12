#include <Servo.h>  
Servo myservo;      
#define trigPin 6 
#define echoPin 5 
#define servoPin 7   
long last_time; 
  
void setup()   
{  
  myservo.attach(servoPin);  
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);   
  myservo.write(0);  
}  
  
void loop()   
{ 
  if(millis() - last_time > 300){ 
  last_time = millis(); 
  digitalWrite(trigPin, LOW); //подаємо низьку напругу на trig     
  digitalWrite(trigPin, HIGH);//Подаємо високу напругу на trig     
  digitalWrite(trigPin, LOW); //подаємо низьку напругу на trig  
  int duration = pulseIn(echoPin, HIGH);  //визначаємо скільки часу було затрачено  
  int distance = duration*0.034/2;        //вираховуємо відстань  
  if (distance <= 45)  
  {  
    myservo.write(90);    
  }  
  else  
  {  
      myservo.write(0);  
  }  
 } 
}