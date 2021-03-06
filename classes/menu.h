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

typedef enum State {
    IDLE_STATE,
    TIME_STATE,
    TIME_HOURS_STATE,
    TIME_MINUTES_STATE,
    ALARM_STATE,
    ALARM_HOURS_STATE,
    ALARM_MINUTES_STATE,
    ALARM_SETTING_STATE,
    FREQUENCY_STATE
} State;

typedef struct MenuStruct {
    TimeStruct *timeStruct;

    State state;

    State (*handleButtons)(MenuStruct *self, int *buttonValues);

    void (*handleIdleState)(MenuStruct *self, int *buttonValues);

    void (*handleTimeState)(MenuStruct *self, int *buttonValues);

    void (*handleTimeHoursState)(MenuStruct *self, int *buttonValues);

    void (*handleTimeMinutesState)(MenuStruct *self, int *buttonValues);

    void (*handleAlarmState)(MenuStruct *self, int *buttonValues);

    void (*handleAlarmHoursState)(MenuStruct *self, int *buttonValues);

    void (*handleAlarmMinutesState)(MenuStruct *self, int *buttonValues);

    void (*handleAlarmSettingState)(MenuStruct *self, int *buttonValues);

    void (*handleFrequencyState)(MenuStruct *self, int *buttonValues);
} MenuStruct;

MenuStruct *constructMenuStruct();

State handleButtons(MenuStruct *self, int *buttonValues);

void handleIdleState(MenuStruct *self, int *buttonValues);

void handleTimeState(MenuStruct *self, int *buttonValues);

void handleTimeHoursState(MenuStruct *self, int *buttonValues);

void handleTimeMinutesState(MenuStruct *self, int *buttonValues);

void handleAlarmState(MenuStruct *self, int *buttonValues);

void handleAlarmHoursState(MenuStruct *self, int *buttonValues);

void handleAlarmMinutesState(MenuStruct *self, int *buttonValues);

void handleAlarmSettingState(MenuStruct *self, int *buttonValues);

void handleFrequencyState(MenuStruct *self, int *buttonValues);

size_t getStringValue(State state, char *stringValue);

#endif //ALARMCLOCK_MENU_H