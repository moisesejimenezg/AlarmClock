//
// Created by Moises Jimenez on 14.05.2016.
//
#include "Menu.h"

MenuStruct *constructMenuStruct() {
    MenuStruct *menuStruct = (MenuStruct *) malloc(sizeof(MenuStruct));
    menuStruct->state = IDLE_STATE;
    menuStruct->timeStruct = constructTimeComponent(0, 0, 0);
    menuStruct->handleButtons = handleButtons;
    menuStruct->handleIdleState = handleIdleState;
    menuStruct->handleTimeState = handleTimeState;
    menuStruct->handleTimeHoursState = handleTimeHoursState;
    menuStruct->handleTimeMinutesState = handleTimeMinutesState;
    menuStruct->handleAlarmState = handleAlarmState;
    menuStruct->handleAlarmHoursState = handleAlarmHoursState;
    menuStruct->handleAlarmMinutesState = handleAlarmMinutesState;
    menuStruct->handleAlarmSettingState = handleAlarmSettingState;
    menuStruct->handleFrequencyState = handleFrequencyState;
    return menuStruct;
}

states_t handleButtons(MenuStruct *self, int *buttonValues) {
    switch (self->state) {
        case IDLE_STATE:
            self->handleIdleState(self, buttonValues);
            break;
        case TIME_STATE:
            self->handleTimeState(self, buttonValues);
            break;
        case TIME_HOURS_STATE:
            self->handleTimeHoursState(self, buttonValues);
            break;
        case TIME_MINUTES_STATE:
            self->handleTimeMinutesState(self, buttonValues);
            break;
        case ALARM_STATE:
            self->handleAlarmState(self, buttonValues);
            break;
        case ALARM_HOURS_STATE:
            self->handleAlarmHoursState(self, buttonValues);
            break;
        case ALARM_MINUTES_STATE:
            self->handleAlarmMinutesState(self, buttonValues);
            break;
        case ALARM_SETTING_STATE:
            self->handleAlarmSettingState(self, buttonValues);
            break;
        case FREQUENCY_STATE:
            self->handleFrequencyState(self, buttonValues);
            break;
    }
    return self->state;
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

void handleAlarmState(MenuStruct *self, int *buttonValues) {
    if (buttonValues[MENU_BUTTON]) {
        self->state = ALARM_HOURS_STATE;
    } else if (buttonValues[LESS_BUTTON]) {
        self->state = TIME_STATE;
    } else if (buttonValues[MORE_BUTTON]) {
        self->state = FREQUENCY_STATE;
    }
}

void handleAlarmHoursState(MenuStruct *self, int *buttonValues) {
    //TODO: handle configuration
    if (buttonValues[MENU_BUTTON]) {
        self->state = ALARM_MINUTES_STATE;
    } else if (buttonValues[LESS_BUTTON]) {
        // self->timeStruct->decreaseHour(self->timeStruct);
    } else if (buttonValues[MORE_BUTTON]) {
        // self->timeStruct->increaseHour(self->timeStruct);
    } else if (buttonValues[EXIT_BUTTON]) {
        self->state = ALARM_STATE;
    }
}

void handleAlarmMinutesState(MenuStruct *self, int *buttonValues) {
    //TODO: handle configuration
    if (buttonValues[MENU_BUTTON]) {
        self->state = ALARM_SETTING_STATE;
    } else if (buttonValues[LESS_BUTTON]) {
        // self->timeStruct->decreaseHour(self->timeStruct);
    } else if (buttonValues[MORE_BUTTON]) {
        // self->timeStruct->increaseHour(self->timeStruct);
    } else if (buttonValues[EXIT_BUTTON]) {
        self->state = ALARM_STATE;
    }
}

void handleAlarmSettingState(MenuStruct *self, int *buttonValues) {
    //TODO: handle configuration
    if (buttonValues[MENU_BUTTON]) {
        self->state = ALARM_HOURS_STATE;
    } else if (buttonValues[LESS_BUTTON]) {
        // self->timeStruct->decreaseHour(self->timeStruct);
    } else if (buttonValues[MORE_BUTTON]) {
        // self->timeStruct->increaseHour(self->timeStruct);
    } else if (buttonValues[EXIT_BUTTON]) {
        self->state = ALARM_STATE;
    }
}

void handleFrequencyState(MenuStruct *self, int *buttonValues) {
    //TODO: implement frequency state machine
    if (buttonValues[MENU_BUTTON]) {
        self->state = FREQUENCY_STATE;
    } else if (buttonValues[LESS_BUTTON]) {
        self->state = ALARM_STATE;
    } else if (buttonValues[MORE_BUTTON]) {
        self->state = TIME_STATE;
    }
}
