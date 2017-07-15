//
// Created by lorenzo on 15/07/17.
//

#ifndef PROGETTOLABORATORIO2_0_TIMER_H
#define PROGETTOLABORATORIO2_0_TIMER_H


#include <wx/wx.h>

class Timer : public wxDateTime {

public:
    Timer() : wxDateTime(0,0,0) {

        timerCount = 0;
        label = "";
    }

    wxString& getLabel(){
        return label;
    }

    wxString startStop();
    wxString reset();
    wxString updateTime();

private:
    int timerCount;
    wxString label;
};


#endif //PROGETTOLABORATORIO2_0_TIMER_H
