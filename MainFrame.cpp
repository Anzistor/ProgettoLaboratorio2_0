//
// Created by lorenzo on 15/07/17.
//

#include "MainFrame.h"

MainFrame::MainFrame(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size,
                     long style)
        : wxFrame(parent, id, title, pos, size, style) {

    time = new Time;
    date = new Date;
    timer = new Timer;


    wxBoxSizer *MainboxSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(MainboxSizer);

    wxBoxSizer *NotebookBoxSizer = new wxBoxSizer(wxVERTICAL);

    MainboxSizer->Add(NotebookBoxSizer, 1, wxALL | wxEXPAND, 5);

    Notebook = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxBK_DEFAULT);
    Notebook->SetName(wxT("Notebook"));

    NotebookBoxSizer->Add(Notebook, 0, wxALL | wxEXPAND, 5);

    DateTimePanel = new wxPanel(Notebook, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(Notebook, wxSize(-1, -1)),
                                wxTAB_TRAVERSAL);
    Notebook->AddPage(DateTimePanel, _("Date/Time"), false);

    wxBoxSizer *DateTimeBoxSizer = new wxBoxSizer(wxVERTICAL);
    DateTimePanel->SetSizer(DateTimeBoxSizer);

    DateText = new wxStaticText(DateTimePanel, wxID_ANY, _("1 January 1970"), wxDefaultPosition,
                                wxDLG_UNIT(DateTimePanel, wxSize(400, 100)), wxALIGN_CENTRE);
    wxFont DateTextFont(36, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Ubuntu"));
    DateText->SetFont(DateTextFont);

    DateTimeBoxSizer->Add(DateText, 0, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL, 10);

    TimeText = new wxStaticText(DateTimePanel, wxID_ANY, _("00:00:00"), wxDefaultPosition,
                                wxDLG_UNIT(DateTimePanel, wxSize(400, 100)), wxALIGN_CENTRE);
    wxFont TimeTextFont(36, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Ubuntu"));
    TimeText->SetFont(TimeTextFont);

    DateTimeBoxSizer->Add(TimeText, 0, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 10);

    DateTimeLine = new wxStaticLine(DateTimePanel, wxID_ANY, wxDefaultPosition,
                                    wxDLG_UNIT(DateTimePanel, wxSize(-1, -1)), wxLI_HORIZONTAL);

    DateTimeBoxSizer->Add(DateTimeLine, 0, wxALL | wxEXPAND, 5);

    DateFormatButton = new wxButton(DateTimePanel, wxID_ANY, _("Change Date Format"), wxDefaultPosition,
                                    wxDLG_UNIT(DateTimePanel, wxSize(-1, -1)), 0);

    DateTimeBoxSizer->Add(DateFormatButton, 0, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL,
                          20);

    TimeFormatButton = new wxButton(DateTimePanel, wxID_ANY, _("Change Time Format"), wxDefaultPosition,
                                    wxDLG_UNIT(DateTimePanel, wxSize(-1, -1)), 0);

    DateTimeBoxSizer->Add(TimeFormatButton, 0, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL,
                          20);

    TimerPanel = new wxPanel(Notebook, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(Notebook, wxSize(-1, -1)),
                             wxTAB_TRAVERSAL);
    Notebook->AddPage(TimerPanel, _("Timer"), false);

    wxBoxSizer *TimerSizer = new wxBoxSizer(wxVERTICAL);
    TimerPanel->SetSizer(TimerSizer);

    TimerText = new wxStaticText(TimerPanel, wxID_ANY, _("00:00:00"), wxDefaultPosition,
                                 wxDLG_UNIT(TimerPanel, wxSize(400, 150)), wxALIGN_CENTRE);
    wxFont TimerTextFont(72, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Ubuntu"));
    TimerText->SetFont(TimerTextFont);

    TimerSizer->Add(TimerText, 0, wxLEFT | wxRIGHT | wxTOP | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 30);

    TimerBoxLine = new wxStaticLine(TimerPanel, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(TimerPanel, wxSize(-1, -1)),
                                    wxLI_HORIZONTAL);

    TimerSizer->Add(TimerBoxLine, 0, wxALL | wxEXPAND, 5);

    wxBoxSizer *SpinCtrlSizer = new wxBoxSizer(wxHORIZONTAL);

    TimerSizer->Add(SpinCtrlSizer, 1, wxALL | wxEXPAND, 5);

    HourSpinCtrl = new wxSpinCtrl(TimerPanel, wxID_ANY, wxT("0"), wxDefaultPosition,
                                  wxDLG_UNIT(TimerPanel, wxSize(-1, -1)), wxSP_ARROW_KEYS);
    HourSpinCtrl->SetRange(0, 23);
    HourSpinCtrl->SetValue(0);

    SpinCtrlSizer->Add(HourSpinCtrl, 0, wxLEFT | wxRIGHT | wxTOP | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, 15);

    MinuteSpinCtrl = new wxSpinCtrl(TimerPanel, wxID_ANY, wxT("0"), wxDefaultPosition,
                                    wxDLG_UNIT(TimerPanel, wxSize(-1, -1)), wxSP_ARROW_KEYS);
    MinuteSpinCtrl->SetRange(0, 59);
    MinuteSpinCtrl->SetValue(0);

    SpinCtrlSizer->Add(MinuteSpinCtrl, 0,
                       wxLEFT | wxRIGHT | wxTOP | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 15);

    SecondSpinCtrl = new wxSpinCtrl(TimerPanel, wxID_ANY, wxT("0"), wxDefaultPosition,
                                    wxDLG_UNIT(TimerPanel, wxSize(-1, -1)), wxSP_ARROW_KEYS);
    SecondSpinCtrl->SetRange(0, 59);
    SecondSpinCtrl->SetValue(0);

    SpinCtrlSizer->Add(SecondSpinCtrl, 0, wxLEFT | wxRIGHT | wxTOP | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, 15);

    wxBoxSizer *ButtonsBoxSizer = new wxBoxSizer(wxVERTICAL);

    TimerSizer->Add(ButtonsBoxSizer, 1, wxALL | wxEXPAND, 5);

    StartStopTimerButton = new wxButton(TimerPanel, wxID_ANY, _("Start"), wxDefaultPosition,
                                        wxDLG_UNIT(TimerPanel, wxSize(-1, -1)), 0);

    ButtonsBoxSizer->Add(StartStopTimerButton, 0, wxALL | wxALIGN_CENTER | wxALIGN_CENTER_HORIZONTAL, 20);

    ResetTimerButton = new wxButton(TimerPanel, wxID_ANY, _("Reset"), wxDefaultPosition,
                                    wxDLG_UNIT(TimerPanel, wxSize(-1, -1)), 0);

    ButtonsBoxSizer->Add(ResetTimerButton, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 20);

    DateTimeTimer = new wxTimer;
    DateTimeTimer->Start(100, false);

    TimerTimer = new wxTimer;


    SetName(wxT("MainFrame"));
    SetSize(500, 500);
    if (GetSizer()) {
        GetSizer()->Fit(this);
    }
    if (GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }

    // Connect events
    DateFormatButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnDateFormatButtonClicked),
                              NULL, this);
    TimeFormatButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnTimeFormatButtonClicked),
                              NULL, this);
    HourSpinCtrl->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MainFrame::OnHourspinctrlTextUpdated), NULL,
                          this);
    MinuteSpinCtrl->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MainFrame::OnMinutespinctrlTextUpdated),
                            NULL, this);
    SecondSpinCtrl->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MainFrame::OnSecondspinctrlTextUpdated),
                            NULL, this);
    StartStopTimerButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
                                  wxCommandEventHandler(MainFrame::OnStartStopTimerButtonClicked), NULL, this);
    ResetTimerButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
                              wxCommandEventHandler(MainFrame::OnResettimerbuttonButtonClicked), NULL, this);
    DateTimeTimer->Connect(wxEVT_TIMER, wxTimerEventHandler(MainFrame::OnDateTimeTimer), NULL, this);
    TimerTimer->Connect(wxEVT_TIMER, wxTimerEventHandler(MainFrame::OnTimerTimer), NULL, this);

}

MainFrame::~MainFrame() {
    DateFormatButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
                                 wxCommandEventHandler(MainFrame::OnDateFormatButtonClicked), NULL, this);
    TimeFormatButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
                                 wxCommandEventHandler(MainFrame::OnTimeFormatButtonClicked), NULL, this);
    HourSpinCtrl->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MainFrame::OnHourspinctrlTextUpdated),
                             NULL, this);
    MinuteSpinCtrl->Disconnect(wxEVT_COMMAND_TEXT_UPDATED,
                               wxCommandEventHandler(MainFrame::OnMinutespinctrlTextUpdated), NULL, this);
    SecondSpinCtrl->Disconnect(wxEVT_COMMAND_TEXT_UPDATED,
                               wxCommandEventHandler(MainFrame::OnSecondspinctrlTextUpdated), NULL, this);
    StartStopTimerButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
                                     wxCommandEventHandler(MainFrame::OnStartStopTimerButtonClicked), NULL, this);
    ResetTimerButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
                                 wxCommandEventHandler(MainFrame::OnResettimerbuttonButtonClicked), NULL, this);
    DateTimeTimer->Disconnect(wxEVT_TIMER, wxTimerEventHandler(MainFrame::OnDateTimeTimer), NULL, this);
    TimerTimer->Disconnect(wxEVT_TIMER, wxTimerEventHandler(MainFrame::OnTimerTimer), NULL, this);

    DateTimeTimer->Stop();
    wxDELETE(DateTimeTimer);

    TimerTimer->Stop();
    wxDELETE(TimerTimer);

}

void MainFrame::OnDateTimeTimer(wxTimerEvent &event) {

    TimeText->SetLabel(time->updateTime());
    DateText->SetLabel(date->updateDate());
}

void MainFrame::OnTimeFormatButtonClicked(wxCommandEvent &event) {

    time->updateTimeCount();
    TimeText->SetLabel(time->changeTimeFormat());
}

void MainFrame::OnDateFormatButtonClicked(wxCommandEvent &event) {

    date->updateDateCount();
    DateText->SetLabel(date->changeDateFormat());
}


void MainFrame::OnStartStopTimerButtonClicked(wxCommandEvent &event) {

    StartStopTimerButton->SetLabel(timer->startStop());
    if (StartStopTimerButton->GetLabel().IsSameAs(wxString("Stop"))) {
        TimerTimer->Start(100, false);
        TimerText->SetForegroundColour(wxColour(0, 0, 0));
    }
    else
        TimerTimer->Stop();
}

void MainFrame::OnResettimerbuttonButtonClicked(wxCommandEvent &event) {

    TimerText->SetLabel(timer->reset());
    TimerText->SetForegroundColour(wxColour(0, 0, 0));
    if (TimerText->GetLabel() == "Stop")
        TimerText->SetLabel(timer->startStop());
}

void MainFrame::OnTimerTimer(wxTimerEvent &event) {

    if (!timer->IsSameTime(wxDateTime(0, 0, 0)))
        TimerText->SetLabel(timer->updateTime());
    else {
        TimerText->SetForegroundColour(wxColour(255, 0, 3));
        StartStopTimerButton->SetLabel(timer->startStop());
        TimerTimer->Stop();
    }

}


void MainFrame::OnHourspinctrlTextUpdated(wxCommandEvent &event) {

    if(!TimerTimer->IsRunning()) {
        timer->SetHour(HourSpinCtrl->GetValue());
        TimerText->SetLabel(timer->FormatISOTime());
    }

}


void MainFrame::OnMinutespinctrlTextUpdated(wxCommandEvent &event) {

    if(!TimerTimer->IsRunning()) {
        timer->SetMinute(MinuteSpinCtrl->GetValue());
        TimerText->SetLabel(timer->FormatISOTime());
    }
}


void MainFrame::OnSecondspinctrlTextUpdated(wxCommandEvent &event) {

    if (!TimerTimer->IsRunning()) {
        timer->SetSecond(SecondSpinCtrl->GetValue());
        TimerText->SetLabel(timer->FormatISOTime());
    }
}
