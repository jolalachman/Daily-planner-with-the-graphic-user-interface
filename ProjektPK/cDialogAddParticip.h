#pragma once
#include "wx/wx.h"
#include "Uczestnik.h"
#include "wektorUczestnikow.h"

class cDialogAddParticip : public wxDialog
{
public:
	cDialogAddParticip();
	~cDialogAddParticip();
private:
	wxStaticText* fnamelabel = nullptr;
	wxTextCtrl* firstnamebox = nullptr;
	wxStaticText* lnamelabel = nullptr;
	wxTextCtrl* lastnamebox = nullptr;
	wxStaticText* tellabel = nullptr;
	wxTextCtrl* telbox = nullptr;
	wxButton* addButton = nullptr;
	Uczestnik* participant = nullptr;

	void onAddButtonClicked(wxCommandEvent& evt_addpp);
	wxDECLARE_EVENT_TABLE();

public: 
	Uczestnik getUczestnik();
	
	
};

