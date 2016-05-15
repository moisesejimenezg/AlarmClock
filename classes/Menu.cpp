//
// Created by Moises Jimenez on 14.05.2016.
//
#include "Menu.h"

MenuStruct *constructMenuStruct() {
    MenuStruct *menuStruct = (MenuStruct *) malloc(sizeof(MenuStruct));
    menuStruct->state = IDLE_STATE;
    menuStruct->timeStruct = constructTimeStruct(0, 0);
    menuStruct->handleButtons = handleButtons;
    menuStruct->handleIdleState = handleIdleState;
    menuStruct->handleTimeState = handleTimeState;
    menuStruct->handleTimeHoursState = handleTimeHoursState;
    menuStruct->handleTimeMinutesState = handleTimeMinutesState;
    menuStruct->handleAlarmState = handleAlarmState;
    menuStruct->handleAlarmHoursState = handleAlarmHoursState;
    menuStruct->handleAlarmMinutesState = handleAlarmMinutesState;
    menuStruct->handleFrequencyState = handleFrequencyState;
    return menuStruct;
}

void handleButtons(MenuStruct *self, int *buttonValues) {
    switch (self->state) {
        case IDLE_STATE:
            handleIdleState(self, buttonValues);
            break;
        case TIME_STATE:
            handleTimeState(self, buttonValues);
            break;
        case TIME_HOURS_STATE:
            break;
        case TIME_MINUTES_STATE:
            break;
        case ALARM_STATE:
            break;
        case ALARM_HOURS_STATE:
            break;
        case ALARM_MINUTES_STATE:
            break;
        case FREQUENCY_STATE:
            break;
    }
}

void handleIdleState(MenuStruct *self, int *buttonValues) {
    if (buttonValues[MENU_BUTTON]) {
        self->state = TIME_STATE;
    }
}

void handleTimeState(MenuStruct *self, int *buttonValues) {
    if (buttonValues[MENU_BUTTON]) {
        self->state = TIME_HOURS_STATE;
    } else if (buttonValues[LESS_BUTTON]) {
        self->state = FREQUENCY_STATE;
    } else if (buttonValues[MORE_BUTTON]) {
        self->state = ALARM_STATE;
    }
}

void handleTimeHoursState(MenuStruct *self, int *buttonValues) {
    if (buttonValues[MENU_BUTTON]) {
        self->state = TIME_MINUTES_STATE;
    } else if (buttonValues[LESS_BUTTON]) {
        self->timeStruct->decreaseHour(self->timeStruct);
    } else if (buttonValues[MORE_BUTTON]) {
        self->timeStruct->increaseHour(self->timeStruct);
    } else if (buttonValues[EXIT_BUTTON]) {
        self->state = TIME_STATE;
    }
}

void handleTimeMinutesState(MenuStruct *self, int *buttonValues) {
    if (buttonValues[MENU_BUTTON]) {
        self->state = TIME_HOURS_STATE;
    } else if (buttonValues[LESS_BUTTON]) {
        self->timeStruct->decreaseMinute(self->timeStruct);
    } else if (buttonValues[MORE_BUTTON]) {
        self->timeStruct->increaseMinute(self->timeStruct);
    } else if (buttonValues[EXIT_BUTTON]) {
        self->state = TIME_STATE;
    }
}

void handleAlarmState(MenuStruct *self, int *buttonValues) { }

void handleAlarmHoursState(MenuStruct *self, int *buttonValues) { }

void handleAlarmMinutesState(MenuStruct *self, int *buttonValues) { }

void handleFrequencyState(MenuStruct *self, int *buttonValues) { }
