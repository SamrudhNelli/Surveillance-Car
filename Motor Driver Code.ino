// Using ESP32 DEVKIT V1 //
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>
int motor1ena = 12;
int motor1in2 = 27;
int motor1in1 = 26;
int motor2enb = 32;
int motor2in4 = 25;
int motor2in3 = 33;
int turn_count =0;

void setup() {
Serial.begin(9600);
Dabble.begin("DIY TEAM 18");
pinMode(motor1ena,OUTPUT);
pinMode(motor1in1,OUTPUT);
pinMode(motor1in2,OUTPUT);
pinMode(motor2enb,OUTPUT);
pinMode(motor2in3,OUTPUT);
pinMode(motor2in4,OUTPUT);
}

void stop(){
analogWrite(motor1ena,0);
analogWrite(motor2enb,0);
digitalWrite(motor1in1,LOW);
digitalWrite(motor1in2,LOW);
digitalWrite(motor2in3,LOW);
digitalWrite(motor2in4,LOW);

}
void move_forward(int a,int b){
  
analogWrite(motor1ena,b);
analogWrite(motor2enb,a);
digitalWrite(motor1in1,HIGH);
digitalWrite(motor1in2,LOW);
digitalWrite(motor2in3,HIGH);
digitalWrite(motor2in4,LOW);
}

void move_forward(){
  
digitalWrite(motor1in1,HIGH);
digitalWrite(motor1in2,LOW);
digitalWrite(motor2in3,HIGH);
digitalWrite(motor2in4,LOW);
}

void rotate(int a,int b){
  
analogWrite(motor1ena,b);
analogWrite(motor2enb,a);
digitalWrite(motor1in1,HIGH);
digitalWrite(motor1in2,LOW);
digitalWrite(motor2in3,HIGH);
digitalWrite(motor2in4,LOW);
}

void rotate2(int a,int b){
  
analogWrite(motor1ena,b);
analogWrite(motor2enb,a);
digitalWrite(motor1in1,LOW);
digitalWrite(motor1in2,HIGH);
digitalWrite(motor2in3,LOW);
digitalWrite(motor2in4,HIGH);
}

void move_backward(int a,int b){
  
analogWrite(motor1ena,b);
analogWrite(motor2enb,a);
digitalWrite(motor1in1,LOW);
digitalWrite(motor1in2,HIGH);
digitalWrite(motor2in3,LOW);
digitalWrite(motor2in4,HIGH);
}

void move_backward(){
  
digitalWrite(motor1in1,LOW);
digitalWrite(motor1in2,HIGH);
digitalWrite(motor2in3,LOW);
digitalWrite(motor2in4,HIGH);
}



void loop(){
Dabble.processInput(); 
int a = GamePad.getAngle();
if (GamePad.isUpPressed())
  {
    Serial.print("UP");
    move_forward();
  }

  if (GamePad.isDownPressed())
  {
    Serial.print("DOWN");
    move_backward();
  }

  Serial.print("Angle: ");
  Serial.print(a);
  Serial.print('\t');
  int b = GamePad.getRadius();
  Serial.print("Radius: ");
  Serial.print(b);
  Serial.print('\t');
  float c = GamePad.getXaxisData();
  Serial.print("x_axis: ");
  Serial.print(c);
  Serial.print('\t');
  float d = GamePad.getYaxisData();
  Serial.print("y_axis: ");
  Serial.println(d);
  Serial.println();
  //fdgdng

    float r,l;
    if (c>0){
      r=c;
      l=0;
    }
    else{
      r=0;
      l=-1*c;
    }
    float main_vel = (36.42 * b);
    int right_front = floor(main_vel- 35 * r);
    int left_front  = floor(main_vel- 35 * l);
  if (a>60 && a<120){
    move_forward(main_vel,main_vel);
  }
  else if(a>240 && a<300){
    move_backward(main_vel,main_vel);
  }
  else if ((a>=0 && a<=210)||(a>300 && a<=360)){
     move_forward(right_front,left_front);
  }
  else{
     move_backward(right_front,left_front);
  }
if(GamePad.isCirclePressed()){
   move_forward(0,150);
  }
  else if(GamePad.isSquarePressed()){
   move_forward(150,0);
  }
  
if(GamePad.isCrossPressed()){
   rotate(150,150);
   turn_count ++;
  }
  
  else if (GamePad.isTrianglePressed()){
   
      rotate2(150,150);
    }
  
}
