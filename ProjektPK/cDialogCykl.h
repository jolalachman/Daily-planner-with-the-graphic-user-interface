#pragma once
#include "wx/wx.h"
#include <wx/datectrl.h>
#include"Data.h"


class cDialogCykl: public wxDialog
{
public:
	cDialogCykl();
	~cDialogCykl();
private:
	int wyborc;
	Data wybork;
	wxStaticText* cykllabel = nullptr;
	wxChoice* cykl = nullptr;
	wxStaticText* endlabel = nullptr;
	wxDatePickerCtrl* end = nullptr;
	wxArrayString str;
	wxButton* ok = nullptr;

	void onOkButtonClicked(wxCommandEvent& evt_ok);

	wxDECLARE_EVENT_TABLE();

public:
	int getWyborc();
	Data getWybork();
	wxDateTime getPick();
};

