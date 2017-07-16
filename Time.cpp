//
// Created by lorenzo on 15/07/17.
//

#include "Time.h"

wxString Time::changeTimeFormat() {

    if(timeCount%2)
        return currentTime.Format("%r");
    else
        return currentTime.FormatTime();
}

wxString Time::updateTime() {

    currentTime = GetTimeNow();
    return changeTimeFormat();

}

void Time::updateTimeCount() {

    timeCount++;
}
