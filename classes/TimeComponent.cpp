//
// Created by Moises Jimenez on 14.05.2016.
//

#include "TimeComponent.h"
#include <stdlib.h>

TimeStruct *constructTimeStruct(int day, int hour, int minute) {
    TimeStruct *timeStruct = (TimeStruct *) malloc(sizeof(TimeStruct));
    *timeStruct->day = day;
    *timeStruct->hour = hour;
    *timeStruct->minute = minute;

    timeStruct->increaseHour = increaseHour;
    timeStruct->decreaseHour = decreaseHour;
    timeStruct->increaseMinute = increaseMinute;
    timeStruct->decreaseMinute = decreaseMinute;
}

void increaseHour(TimeStruct *self) {
    self->hour++;
}

void decreaseHour(TimeStruct *self) {
    self->hour--;
}

void increaseMinute(TimeStruct *self) {
    self->minute++;
}

void decreaseMinute(TimeStruct *self) {
    self->minute--;
}