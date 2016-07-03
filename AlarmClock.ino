// LIBRARIES
// ARDUINO
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

// C
#include <string.h>

// CLASSES
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

// HARDWARE
SoftwareSerial softwareSerial0(0, 1);

// LOGIC
MenuStruct *menuStruct;

bool readButtons();

void serialPrintArrayOfChar(char *String, size_t size);

void setup() {
    // HARDWARE INITS
    pinMode(MENU_BUTTON_PIN, INPUT);
    pinMode(LESS_BUTTON_PIN, INPUT);
    pinMode(MORE_BUTTON_PIN, INPUT);
    pinMode(EXIT_BUTTON_PIN, INPUT);
    softwareSerial0.begin(9600);

    // LOGIC INITS
    menuStruct = constructMenuStruct();
}

void loop() {
    bool buttonStateChanged = readButtons();
    if (buttonStateChanged) {
        State newState = menuStruct->handleButtons(menuStruct, buttonValues);
        char *nameOfState = (char *) malloc(25 * sizeof(char));
        size_t sizeOfName = getStringValue(newState, nameOfState);
        softwareSerial0.println();
        softwareSerial0.print("Enter ");
        serialPrintArrayOfChar(nameOfState, sizeOfName);
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
        if (buttonValues[i] != oldButtonValues[i] && !oldButtonValues[i]) {
            buttonStateChanged = true;
            break;
        }
    }
    return buttonStateChanged;
}

void serialPrintArrayOfChar(char *String, size_t size) {
    for (int i = 1; i <= size; i++) {
        softwareSerial0.print(String[i]);
    }
    free(String);
}