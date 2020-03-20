//https://www.youtube.com/watch?time_continue=739&v=MvhqtOEihDg&feature=emb_title
//https://www.mediafire.com/folder/dx6kfaasyo24l/BLHeliSuite
//-> make interface -> Arduino BLHeli Bootloader


//Battery - > GND
//Trigger > D2
// Servo Signal (PULSE) > D9
// Servo Signal (PULSE) > D10

// Don't change the below setting 

#include <Servo.h>
Servo motor1;               //ESC1
Servo motor2;               //ESC2
Servo Feeder;               //Servo feeder
float motorMIN = 950;       //motor min, motors disabled
float motorMID = 1450;      //motor MID
float motorMAX = 1960;      //motor max
float MotorCMD = motorMIN;  //Command sent to esc
int motor1PIN = 9;          //Arduino PIN D9
int motor2PIN = 10;         //Arduino PIN D10
int TogglePIN = A7;          //A High/Low toggle pin on FC, RevoltOSD is TX4 3,3v. (1023/5)*3.3=675, so to be safe we set limit to 640
int TogglePINActive = 640;  //(1023/5)*3.3=675, so to be safe we set limit to 640
int FeederPin = 8;          //Servo
int TogglePINState = 0;     // variable to store the read value
int angle = 10;             //Servo angle
int LastAction = 0;         //when button pressed
//

void setup() {
    Feeder.attach(FeederPin);           //Attach PIN
    motor1.attach(motor1PIN);           //Attach PIN
    motor2.attach(motor2PIN);           //Attach PIN
    Serial.begin(57600);                //Serial Monitor
    motor1.write(motorMIN);
    motor2.write(motorMIN);
    delay(5000);
}

void FeedDart(){
 // from 0 to 180 degrees
  for(angle = 10; angle < 180; angle = angle + 25){                                  
    Feeder.write(angle);               
    delay(5);                   
  } 
  // from 180 to 0 degrees
  for(angle = 180; angle > 10; angle = angle - 25){                                
    Feeder.write(angle);           
    delay(5);       
  } 
delay(250);
}

void EnableMotors(){

    if(LastAction == 0){
        //Ramp up motors MAX RPM
        for(MotorCMD = motorMIN; MotorCMD < motorMAX; MotorCMD = MotorCMD + 25){                                  
            Serial.println(MotorCMD);
            motor1.write(MotorCMD);
            motor2.write(MotorCMD);              
            delay(10);                   
        }

    }else{
        MotorCMD = motorMAX;
        Serial.println(MotorCMD);
        motor1.write(MotorCMD);
        motor2.write(MotorCMD);

    }
    
        MotorCMD = motorMAX;
        Serial.println(MotorCMD);
        motor1.write(MotorCMD);
        motor2.write(MotorCMD);
    LastAction = 1;
    
}

void DeactiveateMotors(){


        //Ramp down motors min RPM
        for(MotorCMD = motorMAX; MotorCMD > motorMIN; MotorCMD = MotorCMD - 10){                                  
            Serial.println(MotorCMD);
            motor1.write(MotorCMD);
            motor2.write(MotorCMD);
            delay(10);

            //Manual interrupt, check if button pressed while motors are spinning down
            ToggleState();

        }

    MotorCMD = motorMIN;        //Set motors MIN RPM
    Serial.println(MotorCMD);
    motor1.write(MotorCMD);
    motor2.write(MotorCMD);

    LastAction = 0;
}

void ToggleState(){
    
    TogglePINState = analogRead(TogglePIN);    //Read TogglePIN
    Serial.println(TogglePINState);
    
    if (TogglePINState > TogglePINActive){
        
        delay(50);
        TogglePINState = analogRead(TogglePIN);    //Read TogglePIN
        Serial.println(TogglePINState);
        //Doublecheck
        if (TogglePINState > TogglePINActive){

            //Check if motors already enabled
            if(LastAction == 1){
                FeedDart();     //Feed dart
            }else{
                EnableMotors(); //Start motors
                delay(25);     //sleep
                FeedDart();     //Feed dart
            }

            //Set last action to Enabled
            LastAction = 1;
        }
    
    }else{
      
      if(LastAction == 1){
        DeactiveateMotors(); //Start motors
        delay(25);          //sleep
      }
      
    }
}

void loop() {
    MotorCMD = motorMIN;
    //Check button
    ToggleState();
}
