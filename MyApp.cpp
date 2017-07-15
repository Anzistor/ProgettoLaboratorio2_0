//
// Created by lorenzo on 15/07/17.
//

#include "MyApp.h"

bool MyApp::OnInit() {

    MainFrame* mainframe = new MainFrame(0);
    mainframe->Show(true);

    return true;
}
