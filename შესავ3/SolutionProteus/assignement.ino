#include <LiquidCrystal.h>
#define lampPin 7
#define inputPin A0
LiquidCrystal  led (12, 11, 5, 4, 3, 2);

int Vmax;
int Vmin;
double freq;
bool gavzome = false;
bool gavzomeNaturistvis = false;

void setup() {
   led.begin(16,2);
   pinMode(lampPin, OUTPUT);
   pinMode(inputPin, INPUT);
   Vmax = 0;
   Vmin = 0;
   freq = 0;
}

void loop() { // maglidan dablis shuashi, dablidan maglis shuashi, dabaltan magaltan.
   long ganaxleba = millis();
   int currSec = ganaxleba / 1000; 
   if(gavzomeNaturistvis) lightLamp(); // მას შემდეგ დაიწყოს სიგნალის მიწოდება რაც პირველად გავზომეთ მაქსიმალური და მინიმალური ძაბვა.
   if(currSec % 5 == 0 && !gavzome){ // ყოველ 5 წამში გაზომოს და თუ გაზომა 1 ხელ გამოიტანოს ქვედა იფით დახატვის ფუნქციით.
        calculateMaxMinAndFreq();
   }
   
   if(gavzome){
      daxate();
      while((millis() / 1000) % 5 == 0){
        
      }
      gavzome = false;
   }
  
}
// ეს ფუნქცია ითვლის მაქსიმუმს მინიმუმს და სიხშირეს.
// ჯერ ამოწმებს ფუნქციის კლებადობის შუალედში ხომ არ ვართ პირველი ვაილით,
// თუ ვართ ეს ვაილი მიგვიყვანს მინიმუმამდე და დაიწყება ზრდადობის ვაილი რომელიც მიგვიყვანს მაქსიმუმადე,
// შემდეგ ჩავინიშნავთ მაქსიმუმს და დავიწყებთ დროის ათვლას შემდეგ მაქსიმუმამდე.
// სანამ შემდეგ მაქსიმუმამდე მივა ვიპოვით მინიმუმსაც და ჩავინიშნავთ და მაქსიმუმამდე რო მივა ესეიგი ვიპოვეთ პერიოდი.
// სიხშირეს გამოვითვლით 1 ის პერიოდზე გაყოფით.
void calculateMaxMinAndFreq(){
      int v1 = analogRead(inputPin);
      int v2;  
      while(true){                               
          v2 = v1;
          v1 = analogRead(inputPin);
          if(v2 < v1){
              break;
          }
      }
      while(true){
          v2 = v1;
          v1 = analogRead(inputPin);
          if(v2 > v1){
              break;
          }
      }
      Vmax = v2;
      long timeStart = micros();
      v1 = analogRead(inputPin);
      while(true){
          v2 = v1;
          v1 = analogRead(inputPin);
          if(v2 < v1){
            break;  
          }
      }   
      Vmin = v2;
      v1 = analogRead(inputPin);
      while(true){
          v2 = v1;
          v1 = analogRead(inputPin);
          if(v2 > v1){
              break;
          }
      }
      Vmax = v2;
      long timeEnd = micros();
      long sxvaoba = timeEnd - timeStart;
      freq = 1000000.0 / sxvaoba;
      gavzome = true;
      if(!gavzomeNaturistvis){
            gavzomeNaturistvis = true;
      }  
}
// ეს ფუნქცია ანათებს ლამპას ანუ აწვდის ოთხკუთხა სიგნალს.
void lightLamp(){
   int Vcurr = analogRead(inputPin);
   if(((Vmax + Vmin) / 2048.0) * 5 > (Vcurr / 1024.0) * 5){
        digitalWrite(lampPin, LOW);
   } else {
        digitalWrite(lampPin, HIGH);
   }
}
// ამ ფუნქციას გამოაქვს დისფლეიზე სიხშირე და მაქსიმალური ვოლტი.
void daxate(){
    led.setCursor(0,0);
    led.print("Vmax: " + String((Vmax / 1024.0) * 5));
    led.setCursor(0,1);
    led.print("Frequency: " + String(freq));
}
