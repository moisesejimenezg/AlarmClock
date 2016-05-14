// Libraries
#include <LiquidCrystal.h>
#include "lib/time/Time.h"

// classes
#include "classes/Menu.h"

// TIME VARIABLES
struct AlarmTime_st currentAlarm;
const int enterButton = 22;
const int lessButton = 23;
const int moreButton = 24;
const int exitButton = 25;
int buttonValues[4];
states_t currentState = IDLE_STATE;

void setup() {
    pinMode(enterButton, INPUT);
    pinMode(lessButton, INPUT);
    pinMode(moreButton, INPUT);
    pinMode(exitButton, INPUT);
}

void loop() {
    readButtons();
    handleButtons();
}

void handleButtons() {


}

void readButtons() {
    buttonValues[MENU_BUTTON] = digitalRead(enterButton);
    buttonValues[LESS_BUTTON] = digitalRead(lessButton);
    buttonValues[MORE_BUTTON] = digitalRead(moreButton);
    buttonValues[EXIT_BUTTON] = digitalRead(exitButton);
}
