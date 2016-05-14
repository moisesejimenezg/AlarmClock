//
// Created by Moises Jimenez on 14.05.2016.
//
#include "Menu.h"

void handleButtons(states_t *state, int *buttonValues) {
    switch (*state) {
        case IDLE_STATE:
            handleIdleState(state, buttonValues);
            break;
        case TIME_STATE:
            handleTimeState(state, buttonValues);
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

void handleIdleState(states_t *state, int *buttonValues) {
    if (buttonValues[MENU_BUTTON]) {
        *state = TIME_STATE;
    }
}

void handleTimeState(states_t *state, int *buttonValues) {
    if (buttonValues[MENU_BUTTON]) {
        *state = TIME_HOURS_STATE;
    } else if (buttonValues[LESS_BUTTON]) {
        *state = FREQUENCY_STATE;
    } else if (buttonValues[MORE_BUTTON]) {
        *state = ALARM_STATE;
    }
}