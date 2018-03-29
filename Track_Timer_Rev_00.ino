/* Open Track Timer
** MIT License
** Copyright (c) 2018 opentracktimer
** Charles McNall opentracktimer@gmail.com
*/

#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

double time0 = 0;
double time1 = 0;
double time2 = 0;
double time3 = 0;

int timer0Pin = 8;  // use pin 8 as start of timer 
int timer1Pin = 9;  // use pin 9 as first timer gate
int timer2Pin = 10;  // use pin 10 as second timer gate
int timer3Pin = 11;  // use pin 11 as third timer gate

int ledPin = 13;  // use the built in LED on pin 13 of the Uno
int state = 0;
int flag = 0;        // make sure that you return the state only once

void setup() {
    // sets the pins:
    pinMode(ledPin, OUTPUT);
    pinMode(timer0Pin, INPUT);
    pinMode(timer1Pin, INPUT);
    pinMode(timer2Pin, INPUT);
    pinMode(timer3Pin, INPUT);
    
    digitalWrite(ledPin, LOW);
    Serial.begin(115200);
    // Serial.begin(9600); // Default connection rate for my BT module
}

void loop(){

  //if some data is sent, read it and save it in the state variable
    if(Serial.available() > 0){
      state = Serial.read();
      flag=0;
    }
    while (state == '1') {
        Serial.println("Timer Ready!");
        while (digitalRead(timer0Pin) != HIGH) {
          // Do nothing
        }
        time0 = millis();
        digitalWrite(ledPin, HIGH);
        while (digitalRead(timer1Pin) != HIGH) {
          // Do nothing
        }
        time1 = (millis() - time0)/1000;
        Serial.println(time1,3);
        digitalWrite(ledPin, LOW);
        while (digitalRead(timer2Pin) != HIGH) {
          // Do nothing
        }
        time2 = (millis() - time0)/1000;
        Serial.println(time2,3);
        digitalWrite(ledPin, HIGH);
        while (digitalRead(timer3Pin) != HIGH) {
          // Do nothing
        }
        time3 = (millis() - time0)/1000;
        Serial.println(time3,3);
        digitalWrite(ledPin, LOW);
    
        Serial.println("");
        Serial.println("Your Times:");
        Serial.println(time1,3);
        Serial.println(time2,3);
        Serial.println(time3,3);
        Serial.println("");
     }
}




