#include <Servo.h>
#define RightMotorSpeed 5
#define RightMotorDir   0
#define LeftMotorSpeed  4
#define LeftMotorDir    2
int minRange = 312;
int maxRange = 712;
Servo servomoteur;
unsigned long temps;
int minSpeed = 450;
int maxSpeed = 1020;
int noSpeed = 0;
const int trigPin = 12;
const int echoPin = 13;

long duration;
int distance;
int distancecm=0;

int pin_servo = 13;

int mdistance()
{

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
Serial.print("Distance: ");

}
 
void setup() {
  Serial.begin(115200);
  pinMode(RightMotorSpeed, OUTPUT);
  pinMode(LeftMotorSpeed, OUTPUT);
  pinMode(RightMotorDir, OUTPUT);
  pinMode(LeftMotorDir, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 servomoteur.attach(pin_servo); 
}

void loop(){
 temps=millis();
  //  if(temps==100){
  servomoteur.write(0);
//}


 if(temps<15000){

  digitalWrite(RightMotorDir,HIGH); // avancer
  digitalWrite(LeftMotorDir,HIGH);
  analogWrite(RightMotorSpeed,maxSpeed);
  analogWrite(LeftMotorSpeed,maxSpeed);
  delay(4000);
  digitalWrite(RightMotorDir,LOW); // reculer
  digitalWrite(LeftMotorDir,LOW);
  analogWrite(RightMotorSpeed,maxSpeed);
  analogWrite(LeftMotorSpeed,maxSpeed);
  delay(2000);
  digitalWrite(RightMotorDir,LOW); //tourner droite
  digitalWrite(LeftMotorDir,HIGH);
  analogWrite(RightMotorSpeed,0);
  analogWrite(LeftMotorSpeed,maxSpeed);
  delay(1500);
  digitalWrite(RightMotorDir,HIGH); //tourner gauche
  digitalWrite(LeftMotorDir,LOW);
  analogWrite(RightMotorSpeed,maxSpeed);
  analogWrite(LeftMotorSpeed,0);
  delay(1500);
  digitalWrite(RightMotorDir,HIGH); // avancer
  digitalWrite(LeftMotorDir,HIGH);
  analogWrite(RightMotorSpeed,maxSpeed);
  analogWrite(LeftMotorSpeed,maxSpeed);
  }
  if(temps>=15000)
  {digitalWrite(RightMotorDir,LOW);
  digitalWrite(LeftMotorDir,LOW);
  analogWrite(RightMotorSpeed,0);
  analogWrite(LeftMotorSpeed,0);
  if(temps==89000){
 servomoteur.write(90);
 delay(1000);
 servomoteur.write(0);
}
  
  }
}