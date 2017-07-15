//
// Created by lorenzo on 15/07/17.
//

#include "Time.h"

wxString Time::changeTimeFormat() {

    switch (timeCount%2){

        case 1:
            return currentTime.Format("%r");

        default:
            return currentTime.FormatTime();
    }

}

wxString Time::updateTime() {

    currentTime = GetTimeNow();
    return changeTimeFormat();

}

void Time::updateTimeCount() {

    timeCount++;
}
