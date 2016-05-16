//
// Created by Moises Jimenez on 14.05.2016.
//

#include "TimeComponent.h"

TimeStruct *constructTimeComponent(int day, int hour, int minute) {
    TimeStruct *timeStruct = (TimeStruct *) malloc(sizeof(TimeStruct));
    *timeStruct->day = day;
    *timeStruct->hour = hour;
    *timeStruct->minute = minute;

    timeStruct->increaseHour = increaseHour;
    timeStruct->decreaseHour = decreaseHour;
    timeStruct->increaseMinute = increaseMinute;
    timeStruct->decreaseMinute = decreaseMinute;
    return timeStruct;
}

void increaseHour(TimeStruct *self) {
    *self->hour = (*self->hour + 1) % 24;
}

void decreaseHour(TimeStruct *self) {
    *self->hour = (*self->hour - 1) % 24;
}

void increaseMinute(TimeStruct *self) {
    *self->minute = (*self->minute + 1) % 60;
}

void decreaseMinute(TimeStruct *self) {
    *self->minute = (*self->minute - 1) % 60;
}