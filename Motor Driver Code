#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

#define motor1_en 10
#define motor2_en 11
#define motor1_dir1 4
#define motor1_dir2 5
#define motor2_dir1 6
#define motor2_dir2 7

// connect bluetooth 
//  Tx --> 2
//  Rx --> 3

void setup() 
    {
       // put your setup code here, to run once:
       Serial.begin(250000);
       Dabble.begin(38400);  

       for(unsigned int i=4;i<8;i++)
         {
             pinMode(i,OUTPUT);
         }
         pinMode(motor1_en,OUTPUT);
         pinMode(motor2_en,OUTPUT);

       
        
    }

void loop() 
     {
        // put your main code here, to run repeatedly:
        Dabble.processInput();
        if (GamePad.isUpPressed())
          {
            Serial.print("UP");
            forward();
          }

        else if (GamePad.isDownPressed())
          {
             Serial.print("DOWN");
             backward();
          }

       else  if (GamePad.isLeftPressed())
           {
              Serial.print("Left");
              left();
           }

       else  if (GamePad.isRightPressed())
           {
               Serial.print("Right");
               right();
           }

           else 
           {
            Serial.println("strop");
            Stop();
           }


     }

     void forward()
     {
        analogWrite(motor1_en,255);
        analogWrite(motor2_en,255);
        digitalWrite(motor1_dir1,HIGH);
        digitalWrite(motor1_dir2,LOW);
        digitalWrite(motor2_dir1,HIGH);
        digitalWrite(motor2_dir2,LOW);
      
     }
     void backward()
     {
        analogWrite(motor1_en,255);
        analogWrite(motor2_en,255);
        digitalWrite(motor1_dir1,LOW);
        digitalWrite(motor1_dir2,HIGH);
        digitalWrite(motor2_dir1,LOW);
        digitalWrite(motor2_dir2,HIGH);
      
     }
     void left()
     {
        analogWrite(motor1_en,255);
        analogWrite(motor2_en,255);
        digitalWrite(motor1_dir1,LOW);
        digitalWrite(motor1_dir2,HIGH);
        digitalWrite(motor2_dir1,HIGH);
        digitalWrite(motor2_dir2,LOW);
      
     }
     void right()
     {
        analogWrite(motor1_en,255);
        analogWrite(motor2_en,255);
        digitalWrite(motor1_dir1,HIGH);
        digitalWrite(motor1_dir2,LOW);
        digitalWrite(motor2_dir1,LOW);
        digitalWrite(motor2_dir2,HIGH);
      
     }
     void Stop()
     {
        analogWrite(motor1_en,0);
        analogWrite(motor2_en,0);
        digitalWrite(motor1_dir1,LOW);
        digitalWrite(motor1_dir2,LOW);
        digitalWrite(motor2_dir1,LOW);
        digitalWrite(motor2_dir2,LOW);
      
     }
