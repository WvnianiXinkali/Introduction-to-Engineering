#ifndef MotorClock_H
#define MotorClock_H
#include "Arduino.h"
#include <Stepper.h>
#include <Servo.h>


class MotorClock {

public:

  MotorClock(int hour, int minutes, uint8_t servoP, uint8_t stepperN1P, uint8_t
             stepperN2P, uint8_t stepperN3P, uint8_t stepperN4P, uint8_t buzzerP, uint8_t
             button1P, uint8_t button2P, uint8_t rgbRP, uint8_t rgbGP, uint8_t rgbBP);

  String showTime();

  void setTimer(double minutes);

  void setTimerByHand();

  void setAlarm(int hour, int minutes);

  void setAlarmByHand();

  void checkAlarm();

  double setStopWatch();

  double setStopWatchByHand();

private:

    int Hour;
    int Minutes;
    uint8_t ServoP;
    uint8_t StepperN1P;
    uint8_t StepperN2P;
    uint8_t StepperN3P;
    uint8_t StepperN4P; 
    uint8_t BuzzerP;
    uint8_t Button1P;
    uint8_t Button2P;
    uint8_t RgbRP;
    uint8_t RgbGP;
    uint8_t RgbBP;

    int startHour;
    int startMinute;

    bool setAlarm1;
    bool setHandAlarm1;

    int alarmHour;
    int alarmMinutes;

    
    Servo myServo;

    void updateTime();
};
#endif
