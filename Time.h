//
// Created by lorenzo on 15/07/17.
//

#ifndef PROGETTOLABORATORIO2_0_TIME_H
#define PROGETTOLABORATORIO2_0_TIME_H


#include <wx/wx.h>

class Time : wxDateTime {

public:
    Time() {

        timeCount = 0;
        currentTime = GetTimeNow();
    }

    wxString changeTimeFormat();
    wxString updateTime();

    void updateTimeCount();

private:
    int timeCount;
    wxDateTime currentTime;
};


#endif //PROGETTOLABORATORIO2_0_TIME_H
