#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

#define motor1_pin1 = 12;
#define motor1_pin2 = 10;
#define motor1_em1 = 11;
#define motor2_pin1 = 4;
#define motor2_pin2 = 2;
#define motor2_em1 = 3;



void setup() {
  
 Serial.begin(9600);
 Dabble.begin(38400);

    pinMode(motor1_pin1, OUTPUT);
    pinMode(motor1_pin2, OUTPUT);
    pinMode(motor1_em1, OUTPUT);
    pinMode(motor2_pin1, OUTPUT);
    pinMode(motor2_pin2, OUTPUT);
    pinMode(motor2_em1, OUTPUT);

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

// forward
     void forward()
     {
        digitalWrite(motor1_pin1, HIGH);
        digitalWrite(motor1_pin2, LOW); 
        digitalWrite(motor2_pin1, LOW);
        digitalWrite(motor2_pin2, HIGH);
        digitalWrite(motor1_em1, HIGH);
        digitalWrite(motor2_em1, HIGH);

     }   
         
        
         // left
     void left()
     {
        digitalWrite(motor1_pin1, HIGH);
        digitalWrite(motor1_pin2, LOW); 
        digitalWrite(motor2_pin1, HIGH);
        digitalWrite(motor2_pin2, LOW);
        digitalWrite(motor1_em1, HIGH);
        digitalWrite(motor2_em1, LOW);
         
     }  
        
    // right
     void right()
     {
        digitalWrite(motor1_pin1, LOW); 
        digitalWrite(motor1_pin2, HIGH); 
        digitalWrite(motor2_pin1, LOW);
        digitalWrite(motor2_pin2, HIGH);
        digitalWrite(motor1_em1, LOW);
        digitalWrite(motor2_em1, HIGH);
        
     }  
       
    
    // backward
    void backward()
    {
        digitalWrite(motor1_pin1, LOW); 
        digitalWrite(motor1_pin2, HIGH);
        digitalWrite(motor2_pin1, HIGH);
        digitalWrite(motor2_pin2, LOW);
        digitalWrite(motor1_em1, HIGH);
        digitalWrite(motor2_em1, HIGH);
        
    }   
    
     // Stop
     void Stop()
     {
        digitalWrite(motor1_pin1, LOW); 
        digitalWrite(motor1_pin2, LOW); 
        digitalWrite(motor2_pin1, LOW);
        digitalWrite(motor2_pin2, LOW);
        digitalWrite(motor1_em1, LOW);
        digitalWrite(motor2_em1, LOW); 
     } 
