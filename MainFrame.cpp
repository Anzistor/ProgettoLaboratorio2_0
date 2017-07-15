//
// Created by lorenzo on 15/07/17.
//

#include "MainFrame.h"

MainFrame::MainFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
        : wxFrame(parent, id, title, pos, size, style)
{

    time = new Time;
    date = new Date;
    timer = new Timer;

    wxBoxSizer* MainboxSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(MainboxSizer);

    wxBoxSizer* NotebookBoxSizer = new wxBoxSizer(wxVERTICAL);

    MainboxSizer->Add(NotebookBoxSizer, 1, wxALL|wxEXPAND, 5);

    Notebook = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), wxBK_DEFAULT);
    Notebook->SetName(wxT("Notebook"));

    NotebookBoxSizer->Add(Notebook, 0, wxALL|wxEXPAND, 5);

    DateTimePanel = new wxPanel(Notebook, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(Notebook, wxSize(-1,-1)), wxTAB_TRAVERSAL);
    Notebook->AddPage(DateTimePanel, _("Date/Time"), false);

    wxBoxSizer* DateTimeBoxSizer = new wxBoxSizer(wxVERTICAL);
    DateTimePanel->SetSizer(DateTimeBoxSizer);

    DateText = new wxStaticText(DateTimePanel, wxID_ANY, _(date->changeDateFormat()), wxDefaultPosition, wxDLG_UNIT(DateTimePanel, wxSize(400,100)), wxALIGN_CENTRE);
    wxFont DateTextFont(36, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Ubuntu"));
    DateText->SetFont(DateTextFont);

    DateTimeBoxSizer->Add(DateText, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 10);

    TimeText = new wxStaticText(DateTimePanel, wxID_ANY, _("00:00:00"), wxDefaultPosition, wxDLG_UNIT(DateTimePanel, wxSize(400,100)), wxALIGN_CENTRE);
    wxFont TimeTextFont(36, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Ubuntu"));
    TimeText->SetFont(TimeTextFont);

    DateTimeBoxSizer->Add(TimeText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 10);

    DateTimeLine = new wxStaticLine(DateTimePanel, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(DateTimePanel, wxSize(-1,-1)), wxLI_HORIZONTAL);

    DateTimeBoxSizer->Add(DateTimeLine, 0, wxALL|wxEXPAND, 5);

    DateFormatButton = new wxButton(DateTimePanel, wxID_ANY, _("Change Date Format"), wxDefaultPosition, wxDLG_UNIT(DateTimePanel, wxSize(-1,-1)), 0);

    DateTimeBoxSizer->Add(DateFormatButton, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 20);

    TimeFormatButton = new wxButton(DateTimePanel, wxID_ANY, _("Change Time Format"), wxDefaultPosition, wxDLG_UNIT(DateTimePanel, wxSize(-1,-1)), 0);

    DateTimeBoxSizer->Add(TimeFormatButton, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 20);

    TimerPanel = new wxPanel(Notebook, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(Notebook, wxSize(-1,-1)), wxTAB_TRAVERSAL);
    Notebook->AddPage(TimerPanel, _("Timer"), false);

    wxBoxSizer* TimerSizer = new wxBoxSizer(wxVERTICAL);
    TimerPanel->SetSizer(TimerSizer);

    TimerText = new wxStaticText(TimerPanel, wxID_ANY, _("00:00:00"), wxDefaultPosition, wxDLG_UNIT(TimerPanel, wxSize(400,150)), wxALIGN_CENTRE);
    wxFont TimerTextFont(72, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Ubuntu"));
    TimerText->SetFont(TimerTextFont);

    TimerSizer->Add(TimerText, 0, wxLEFT|wxRIGHT|wxTOP|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 30);

    TimerBoxLine = new wxStaticLine(TimerPanel, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(TimerPanel, wxSize(-1,-1)), wxLI_HORIZONTAL);

    TimerSizer->Add(TimerBoxLine, 0, wxALL|wxEXPAND, 5);

    wxBoxSizer* TextCtrlSizer = new wxBoxSizer(wxHORIZONTAL);

    TimerSizer->Add(TextCtrlSizer, 1, wxALL|wxEXPAND, 5);

    HoursTextCtrl = new wxTextCtrl(TimerPanel, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(TimerPanel, wxSize(-1,-1)), 0);
#if wxVERSION_NUMBER >= 3000
    HoursTextCtrl->SetHint(_("Hours"));
#endif

    TextCtrlSizer->Add(HoursTextCtrl, 0, wxLEFT|wxRIGHT|wxTOP|wxALIGN_CENTER_HORIZONTAL|wxALIGN_TOP, 30);

    MinutesTextCtrl = new wxTextCtrl(TimerPanel, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(TimerPanel, wxSize(-1,-1)), 0);
#if wxVERSION_NUMBER >= 3000
    MinutesTextCtrl->SetHint(_("Minutes"));
#endif

    TextCtrlSizer->Add(MinutesTextCtrl, 0, wxLEFT|wxRIGHT|wxTOP, 30);

    SecondsTextCtrl = new wxTextCtrl(TimerPanel, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(TimerPanel, wxSize(-1,-1)), 0);
#if wxVERSION_NUMBER >= 3000
    SecondsTextCtrl->SetHint(_("Seconds"));
#endif

    TextCtrlSizer->Add(SecondsTextCtrl, 0, wxLEFT|wxRIGHT|wxTOP|wxALIGN_RIGHT, 30);

    wxBoxSizer* ButtonsBoxSizer = new wxBoxSizer(wxVERTICAL);

    TimerSizer->Add(ButtonsBoxSizer, 1, wxALL|wxEXPAND, 5);

    StartStopTimerButton = new wxButton(TimerPanel, wxID_ANY, _("Start"), wxDefaultPosition, wxDLG_UNIT(TimerPanel, wxSize(-1,-1)), 0);

    ButtonsBoxSizer->Add(StartStopTimerButton, 0, wxALL|wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL, 20);

    ResetTimerButton = new wxButton(TimerPanel, wxID_ANY, _("Reset"), wxDefaultPosition, wxDLG_UNIT(TimerPanel, wxSize(-1,-1)), 0);

    ButtonsBoxSizer->Add(ResetTimerButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 20);

    DateTimeTimer = new wxTimer;
    DateTimeTimer->Start(100, false);

    TimerTimer = new wxTimer;


    SetName(wxT("MainFrame"));
    SetSize(500,500);
    if (GetSizer()) {
        GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }

    // Connect events
    DateFormatButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnDateFormatButtonClicked), NULL, this);
    TimeFormatButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnTimeFormatButtonClicked), NULL, this);
    HoursTextCtrl->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MainFrame::OnHourstextctrlTextUpdated), NULL, this);
    MinutesTextCtrl->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MainFrame::OnMinutestextctrlTextUpdated), NULL, this);
    SecondsTextCtrl->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MainFrame::OnSecondstextctrlTextUpdated), NULL, this);
    StartStopTimerButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnStartStopTimerButtonClicked), NULL, this);
    ResetTimerButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnResettimerbuttonButtonClicked), NULL, this);
    DateTimeTimer->Connect(wxEVT_TIMER, wxTimerEventHandler(MainFrame::OnDateTimeTimer), NULL, this);
    TimerTimer->Connect(wxEVT_TIMER, wxTimerEventHandler(MainFrame::OnTimerTimer), NULL, this);

}

MainFrame::~MainFrame()
{
    DateFormatButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnDateFormatButtonClicked), NULL, this);
    TimeFormatButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnTimeFormatButtonClicked), NULL, this);
    HoursTextCtrl->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MainFrame::OnHourstextctrlTextUpdated), NULL, this);
    MinutesTextCtrl->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MainFrame::OnMinutestextctrlTextUpdated), NULL, this);
    SecondsTextCtrl->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MainFrame::OnSecondstextctrlTextUpdated), NULL, this);
    StartStopTimerButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnStartStopTimerButtonClicked), NULL, this);
    ResetTimerButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnResettimerbuttonButtonClicked), NULL, this);
    DateTimeTimer->Disconnect(wxEVT_TIMER, wxTimerEventHandler(MainFrame::OnDateTimeTimer), NULL, this);
    TimerTimer->Disconnect(wxEVT_TIMER, wxTimerEventHandler(MainFrame::OnTimerTimer), NULL, this);

    DateTimeTimer->Stop();
    wxDELETE( DateTimeTimer );

    TimerTimer->Stop();
    wxDELETE( TimerTimer );

}

void MainFrame::OnDateTimeTimer(wxTimerEvent& event) {

    TimeText->SetLabel(time->updateTime());
}

void MainFrame::OnTimeFormatButtonClicked(wxCommandEvent& event) {

    time->updateTimeCount();
    time->changeTimeFormat();
}

void MainFrame::OnDateFormatButtonClicked(wxCommandEvent &event) {

    DateText->SetLabel(date->changeDateFormat());
}


void MainFrame::OnHourstextctrlTextUpdated(wxCommandEvent &event) {

    long hours;
    HoursTextCtrl->GetValue().ToLong(&hours);
    if(hours >= 0 && hours <= 23)
        timer->SetHour(hours);
    else
        timer->SetHour(0);
    TimerText->SetLabel(timer->FormatISOTime());
}

void MainFrame::OnMinutestextctrlTextUpdated(wxCommandEvent &event) {

    long minutes;
    MinutesTextCtrl->GetValue().ToLong(&minutes);
    if(minutes >= 0 && minutes <= 59 )
        timer->SetMinute(minutes);
    else
        timer->SetMinute(0);
    TimerText->SetLabel(timer->FormatISOTime());
}

void MainFrame::OnSecondstextctrlTextUpdated(wxCommandEvent &event) {

    long seconds;
    SecondsTextCtrl->GetValue().ToLong(&seconds);
    if(seconds >= 0 && seconds <= 59)
        timer->SetSecond(seconds);
    else
        timer->SetSecond(0);
    TimerText->SetLabel(timer->FormatISOTime());
}

void MainFrame::OnStartStopTimerButtonClicked(wxCommandEvent &event) {

    StartStopTimerButton->SetLabel(timer->startStop());
    if(StartStopTimerButton->GetLabel() == "Stop")
        TimerTimer->Start(100, false);
    else
        TimerTimer->Stop();
}

void MainFrame::OnResettimerbuttonButtonClicked(wxCommandEvent &event) {

    TimerText->SetLabel(timer->reset());
    if(TimerText->GetLabel() == "Stop")
        TimerText->SetLabel(timer->startStop());
}

void MainFrame::OnTimerTimer(wxTimerEvent &event) {

    while(timer->GetHour() != 0 || timer->GetMinute() != 0 && timer->GetSecond() != 0)
        TimerText->SetLabel(timer->updateTime());

    TimerText->SetForegroundColour(wxColour(255, 0, 3));
}
