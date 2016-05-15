// Libraries
#include <LiquidCrystal.h>

// classes
#include "classes/Menu.h"

// TIME VARIABLES
const int enterButton = 22;
const int lessButton = 23;
const int moreButton = 24;
const int exitButton = 25;
int buttonValues[4];

// LOGIC
MenuStruct *menuStruct;

void readButtons();

void setup() {
    // HARDWARE INITS
    pinMode(enterButton, INPUT);
    pinMode(lessButton, INPUT);
    pinMode(moreButton, INPUT);
    pinMode(exitButton, INPUT);

    // LOGIC INITS
    menuStruct = constructMenuStruct();
}

void loop() {
    readButtons();
    menuStruct->handleButtons(menuStruct, buttonValues);
}

void readButtons() {
    buttonValues[MENU_BUTTON] = digitalRead(enterButton);
    buttonValues[LESS_BUTTON] = digitalRead(lessButton);
    buttonValues[MORE_BUTTON] = digitalRead(moreButton);
    buttonValues[EXIT_BUTTON] = digitalRead(exitButton);
}
