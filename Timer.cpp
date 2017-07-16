//
// Created by lorenzo on 15/07/17.
//

#include "Timer.h"

wxString Timer::startStop() {

    timerCount++;
    if(timerCount%2)
        return "Stop";
    return "Start";
}

wxString Timer::reset() {

    Set(0,0,0);
    return FormatISOTime();
}

wxString Timer::updateTime() {

    Subtract(wxTimeSpan(0, 0, 0, 100));
    return this->FormatISOTime();
}