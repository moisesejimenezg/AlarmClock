// Libraries
#include <LiquidCrystal.h>
#include "lib/time/Time.h"

// classes
#include "classes/Menu.h"
#include "classes/Alarm.h"

// TIME VARIABLES
struct AlarmTime_st currentAlarm;
const int enterButton = 22;
const int lessButton = 23;
const int moreButton = 24;
const int exitButton = 25;

void setup() {
    pinMode(enterButton,INPUT);
    pinMode(lessButton,INPUT);
    pinMode(moreButton,INPUT);
    pinMode(exitButton,INPUT);
}

void loop() {
    handleButtons();
}

void handleButtons () {
    if(digitalRead(enterButton) == HIGH){

    }
}
