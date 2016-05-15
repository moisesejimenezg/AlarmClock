//
// Created by Moises Jimenez on 14.05.2016.
//
#include <stdlib.h>
#include "TimeComponent.h"

#ifndef ALARMCLOCK_MENU_H
#define ALARMCLOCK_MENU_H

#define MENU_BUTTON 0
#define LESS_BUTTON 1
#define MORE_BUTTON 2
#define EXIT_BUTTON 3

typedef enum states_t {
    IDLE_STATE,
    TIME_STATE,
    TIME_HOURS_STATE,
    TIME_MINUTES_STATE,
    ALARM_STATE,
    ALARM_HOURS_STATE,
    ALARM_MINUTES_STATE,
    FREQUENCY_STATE
} states_t;

typedef struct MenuStruct {
    TimeStruct *timeStruct;

    states_t state;

    void (*handleButtons)(MenuStruct *self, int *buttonValues);

    void (*handleIdleState)(MenuStruct *self, int *buttonValues);

    void (*handleTimeState)(MenuStruct *self, int *buttonValues);

    void (*handleTimeHoursState)(MenuStruct *self, int *buttonValues);

    void (*handleTimeMinutesState)(MenuStruct *self, int *buttonValues);

    void (*handleAlarmState)(MenuStruct *self, int *buttonValues);

    void (*handleAlarmHoursState)(MenuStruct *self, int *buttonValues);

    void (*handleAlarmMinutesState)(MenuStruct *self, int *buttonValues);

    void (*handleFrequencyState)(MenuStruct *self, int *buttonValues);
} MenuStruct;

MenuStruct *constructMenuStruct();

void handleButtons(MenuStruct *self, int *buttonValues);

void handleIdleState(MenuStruct *self, int *buttonValues);

void handleTimeState(MenuStruct *self, int *buttonValues);

void handleTimeHoursState(MenuStruct *self, int *buttonValues);

void handleTimeMinutesState(MenuStruct *self, int *buttonValues);

void handleAlarmState(MenuStruct *self, int *buttonValues);

void handleAlarmHoursState(MenuStruct *self, int *buttonValues);

void handleAlarmMinutesState(MenuStruct *self, int *buttonValues);

void handleFrequencyState(MenuStruct *self, int *buttonValues);

#endif //ALARMCLOCK_MENU_H