//
// Created by Moises Jimenez on 14.05.2016.
//

#ifndef ALARMCLOCK_ALARM_H
#define ALARMCLOCK_ALARM_H

struct AlarmTime_st {
    int hour, minute;
    int *days;
};

void setAlarm(AlarmTime_st *currentAlarm, int hour, int minute);
void setFrecuency(AlarmTime_st *currentAlarm, int *days);

#endif //ALARMCLOCK_ALARM_H
