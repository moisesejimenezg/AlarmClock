//
// Created by Moises Jimenez on 14.05.2016.
//

#ifndef ALARMCLOCK_MENU_H
#define ALARMCLOCK_MENU_H

#define MENU_BUTTON 0
#define LESS_BUTTON 1
#define MORE_BUTTON 2
#define EXIT_BUTTON 3

enum states_t {
    IDLE_STATE,
    TIME_STATE,
    TIME_HOURS_STATE,
    TIME_MINUTES_STATE,
    ALARM_STATE,
    ALARM_MINUTES_STATE,
    ALARM_HOURS_STATE,
    FREQUENCY_STATE
};

void handleButtons(states_t *state, int *buttonValues);

void handleIdleState(states_t *state, int *buttonValues);

void handleTimeState(states_t *state, int *buttonValues);

#endif //ALARMCLOCK_MENU_H