#include <Servo.h>

Servo servo;
Servo servo1;
int L1=20;
int L2=20;
int Q=90;
int Q1,Q2;
float X,Y,q1,q2;


void setup()
{
  servo.attach(6);
  servo1.attach(9);
  Serial.begin(9600);
  servo.write(0);
  servo1.write(0);
}

void loop()
{ Serial.println("\n\n welcom\n To control the arm enter \n  -(i)indicatoin for inverse\n  -(f)indicatoin for forward ");
 while (Serial.available()==0){}
 String type=Serial.readString();
 Serial.println (type);
 if(type=="i"){
  Serial.println("Please inter X");
   while (Serial.available()==0){}
  X=Serial.parseFloat();
  Serial.println("Please inter Y");
  while (Serial.available()==0){}
  Y=Serial.parseFloat();
  
   float a=(pow(X,2)+pow(Y,2)-pow(L1,2)-pow(L2,2))/(2*L1*L2);
   q2=acos(a);
   Q2=q2*180/PI;
   Q1=Q-Q2;
   
   Serial.print("\nX=");
   Serial.print(X);
   Serial.print("\tY=");
   Serial.println(Y);
   Serial.print("\nQ1=");
   Serial.print(Q1);
   Serial.print("\tQ2=  ");
   Serial.println(Q2);
   servo.write(Q1);
   servo1.write(Q2);
   delay(5000);
 }
 
  else if(type=="f"){
  Serial.println("Please inter Q1");
  while (Serial.available()==0){}
  q1=Serial.parseInt();
  Serial.println("Please inter Q2");
  while (Serial.available()==0){}
  q2=Serial.parseInt();
  servo.write(q1);
  servo1.write(q2);
    
  Q1=q1*PI/180;
  Q2=q2*PI/180;
  X=(L1*cos(Q1))+(L2*cos(Q1+Q2));
  Y=(L1*sin(Q1))+(L2*sin(Q1+Q2));
    
  Serial.print("\nX=");
  Serial.print(X);   Serial.print("\tY=");
  Serial.println(Y);
  Serial.print("\nQ1=");
  Serial.print(q1);
  Serial.print("\tQ2=  ");
  Serial.println(q2);
  delay(5000);
 }
 else {Serial.print("Please inter the correct choice ");delay(5000);}
}
