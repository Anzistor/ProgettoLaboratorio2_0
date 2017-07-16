//
// Created by lorenzo on 15/07/17.
//

#include "Date.h"

wxString Date::changeDateFormat() {

    switch (dateCount % 4){

        case 1:
            return currentDate.FormatISODate();
        case 2:
            return currentDate.Format("%g %B %G");
        case 3:
            return currentDate.Format("%a %g %h %G");
        default:
            return currentDate.FormatDate();
    }
}

wxString Date::updateDate() {

    currentDate=Today();
    return changeDateFormat();
}

void Date::updateDateCount(){

    dateCount++;
}