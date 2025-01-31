#include "Motorclock.h"


MotorClock::MotorClock(int hour, int minutes, uint8_t servoP, uint8_t stepperN1P, uint8_t
           stepperN2P, uint8_t stepperN3P, uint8_t stepperN4P, uint8_t buzzerP, uint8_t
           button1P, uint8_t button2P, uint8_t rgbRP, uint8_t rgbGP, uint8_t rgbBP){
            
    Hour = hour;
    Minutes = minutes;
    ServoP = servoP;
    StepperN1P = stepperN1P;
    StepperN2P = stepperN2P;
    StepperN3P = stepperN3P;
    StepperN4P = stepperN4P; 
    BuzzerP = buzzerP;
    Button1P = button1P;
    Button2P = button2P;
    RgbRP = rgbRP;
    RgbGP = rgbGP;
    RgbBP = rgbBP;

    startHour = Hour;
    startMinute = Minutes;

    setAlarm1 = false;
    setHandAlarm1 = false;

    alarmHour = 0;
    alarmMinutes = 0;
    
   


    pinMode(Button1P, INPUT);
    pinMode(Button2P, INPUT);
    
    pinMode(BuzzerP, OUTPUT);
    
    pinMode(ServoP, OUTPUT);

    pinMode(RgbRP, OUTPUT);
    pinMode(RgbGP, OUTPUT);
    pinMode(RgbBP, OUTPUT);
    
}

String MotorClock::showTime(){
      Stepper myStepper(2038, StepperN1P, StepperN2P, StepperN3P, StepperN4P);
      myStepper.setSpeed(6);

      myServo.attach(ServoP);
      
      updateTime();
      
      myServo.write(Hour*15);

      myStepper.step((2038 / 60.0) * (Minutes - startMinute));

      return String(Hour) + ":" + String(Minutes);
}

void MotorClock::updateTime(){
      unsigned long timePassed = millis();                      //    7:50 -> 6:40 13:20        // 17:30 20

      int hoursPassed = timePassed / 1000 / 3600;
      int minutesPassed = (timePassed / 1000 - hoursPassed * 3600) / 60;

      Hour = startHour + hoursPassed;
      Minutes = startMinute + minutesPassed;

      while(Minutes >= 60){
        Hour ++;
        Minutes -= 60;    
      }

      while(Hour >= 12){
          Hour -= 12;  
      }
  }


void MotorClock::setTimer(double minutes){
      delay(minutes * 60 * 1000);
      tone(BuzzerP, 1000); //fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
      while(digitalRead(Button2P) != HIGH){
        // wait for them to press button.
        }
      noTone(BuzzerP);
}

void MotorClock::setTimerByHand(){
      analogWrite(RgbRP, HIGH);
      int minuteCounter = 0;
      bool button1Pressed = false;
      while(digitalRead(Button2P) != HIGH){
         if(digitalRead(Button1P) == HIGH && !button1Pressed){
               minuteCounter++;
               button1Pressed = true;    
         }
         if(digitalRead(Button1P) == LOW){
             button1Pressed = false;
         }
      }
      delay(minuteCounter * 60 * 1000);
      tone(BuzzerP, 1000);
      while(digitalRead(Button2P) != HIGH){
        // wait for them to press button.
      }
      noTone(BuzzerP);
      analogWrite(RgbRP, LOW);
}

void MotorClock::setAlarm(int hour, int minutes){ // 17:05   18:20 19:00  20:12
      alarmHour = hour % 12;
      alarmMinutes = minutes % 60;
      setAlarm1 = true;
}

void MotorClock::setAlarmByHand(){
      analogWrite(RgbGP, HIGH);
      int hour = 0;
      int minutes = 0;
      bool button1Pressed = false;
      while(digitalRead(Button2P) != HIGH){
         if(digitalRead(Button1P) == HIGH && !button1Pressed){
               hour++;
               button1Pressed = true;    
         }
         if(digitalRead(Button1P) == LOW){
             button1Pressed = false;
         }
         if(hour >= 12){
            hour -= 12;
         }
      }
      while(digitalRead(Button2P) == HIGH){
          //wait for them to unpress button 
      }
      while(digitalRead(Button2P) != HIGH){
        if(digitalRead(Button1P) == HIGH && !button1Pressed){ 
               minutes+= 10;
               button1Pressed = true;    
         }
         if(digitalRead(Button1P) == LOW){
             button1Pressed = false;
         }
         if(minutes >= 60){
            minutes -= 60;
         }
      }
          alarmHour = hour % 12;
          alarmMinutes = minutes % 60;
          setHandAlarm1 = true;
      analogWrite(RgbGP, LOW);
}

void MotorClock::checkAlarm(){
    if(setAlarm1 || setHandAlarm1){
      updateTime();
      if(alarmHour < Hour || (alarmHour == Hour && alarmMinutes < Minutes) || (alarmHour == Hour && alarmMinutes == Minutes)){ // 6:30 7:29 6:50 
        while(digitalRead(Button2P) == HIGH){
              
        }
        tone(BuzzerP, 1000);
        while(digitalRead(Button2P) != HIGH){
          // wait for them to press button.
        }
        noTone(BuzzerP);
        setAlarm1 = false;
        setHandAlarm1 = false;
       } // 5:40       check 6:30
     }
}

double MotorClock::setStopWatch(){  // 11:23 -> 11:30;
        Stepper myStepper(2038, StepperN1P, StepperN2P, StepperN3P, StepperN4P);
        myStepper.setSpeed(6);
        unsigned long startTimer = millis();
        while(digitalRead(Button2P) != HIGH){
                 
        }
        unsigned long timerOff = millis();
        double timerMinutes = (timerOff - startTimer) / 60000.0;
        myStepper.step((2038/60.0) * timerMinutes);
        delay(1000);
        myStepper.step(-(2038/60.0) * timerMinutes);
        return timerMinutes; 
        // 5:7 5:10
}
double MotorClock::setStopWatchByHand(){
   analogWrite(RgbBP, HIGH);
   Stepper myStepper(2038, StepperN1P, StepperN2P, StepperN3P, StepperN4P);
   myStepper.setSpeed(6);
   while(digitalRead(Button1P) != HIGH){
        
   }
   unsigned long startTimer = millis();
   while(digitalRead(Button2P) != HIGH){
                 
   }
   unsigned long timerOff = millis();
   double timerMinutes = (timerOff - startTimer) / 60000.0;
   myStepper.step((2038/60.0) * timerMinutes);
   delay(1000);
   myStepper.step(-(2038/60.0) * timerMinutes);
   analogWrite(RgbBP, LOW);
   return timerMinutes; 
}


         
