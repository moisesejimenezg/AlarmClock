//
// Created by Moises Jimenez on 14.05.2016.
//
#include <stdlib.h>

#ifndef ALARMCLOCK_TIMEOPERATIONS_H
#define ALARMCLOCK_TIMEOPERATIONS_H

typedef struct TimeStruct {
    int *day, *hour, *minute;

    void (*increaseHour)(TimeStruct *);

    void (*decreaseHour)(TimeStruct *);

    void (*increaseMinute)(TimeStruct *);

    void (*decreaseMinute)(TimeStruct *);
} TimeStruct;

TimeStruct *constructTimeStruct(int hour, int minute);

void increaseHour(TimeStruct *self);

void decreaseHour(TimeStruct *self);

void increaseMinute(TimeStruct *self);

void decreaseMinute(TimeStruct *self);

#endif //ALARMCLOCK_TIMEOPERATIONS_H
