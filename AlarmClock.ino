// Libraries
#include <LiquidCrystal.h>
#include <string.h>

// classes
#include "classes/Menu.h"

// INPUT OUTPUT CONSTANTS
const int MENU_BUTTON_PIN = 22;
const int LESS_BUTTON_PIN = 23;
const int MORE_BUTTON_PIN = 24;
const int EXIT_BUTTON_PIN = 25;
const int NUMBER_OF_BUTTONS = 4;

// INPUT OUTPUT VARIABLES
int buttonValues[NUMBER_OF_BUTTONS];
int oldButtonValues[NUMBER_OF_BUTTONS];

// LOGIC
MenuStruct *menuStruct;

bool readButtons();

void setup() {
    // HARDWARE INITS
    pinMode(MENU_BUTTON_PIN, INPUT);
    pinMode(LESS_BUTTON_PIN, INPUT);
    pinMode(MORE_BUTTON_PIN, INPUT);
    pinMode(EXIT_BUTTON_PIN, INPUT);

    // LOGIC INITS
    menuStruct = constructMenuStruct();
}

void loop() {
    bool buttonStateChanged = readButtons();
    if (buttonStateChanged) {
        menuStruct->handleButtons(menuStruct, buttonValues);
    }
}

bool readButtons() {
    memcpy(oldButtonValues, buttonValues, NUMBER_OF_BUTTONS * sizeof(int));
    bool buttonStateChanged = false;
    buttonValues[MENU_BUTTON] = digitalRead(MENU_BUTTON_PIN);
    buttonValues[LESS_BUTTON] = digitalRead(LESS_BUTTON_PIN);
    buttonValues[MORE_BUTTON] = digitalRead(MORE_BUTTON_PIN);
    buttonValues[EXIT_BUTTON] = digitalRead(EXIT_BUTTON_PIN);
    for (int i = 0; i < NUMBER_OF_BUTTONS; i++) {
        if (buttonValues[i] != oldButtonValues[i]) {
            buttonStateChanged = true;
            break;
        }
    }
    return buttonStateChanged;
}
