//
// Created by lorenzo on 15/07/17.
//

#ifndef PROGETTOLABORATORIO2_0_DATE_H
#define PROGETTOLABORATORIO2_0_DATE_H

#include <wx/wx.h>

class Date : public wxDateTime {

public:
    Date() {
        dateCount = 0;
        currentDate = Today();
    }

    wxString changeDateFormat();

private:
    int dateCount;
    wxDateTime currentDate;
};


#endif //PROGETTOLABORATORIO2_0_DATE_H
