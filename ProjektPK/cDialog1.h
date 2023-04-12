#pragma once
#include "wx/wx.h"
#include <wx/timectrl.h>
#include <wx/datectrl.h>
#include "cDialogAddParticip.h"
#include "cDialogCykl.h"
#include "wektorSpotkan.h"



class cDialog1 : public wxDialog
{
public:
	cDialog1();
	~cDialog1();

private:
	//wyswietlanie
	wxStaticText* namelabel = nullptr;
	wxTextCtrl* namebox = nullptr;

	wxStaticText* startlabel = nullptr;
	wxTimePickerCtrl* start = nullptr;

	wxStaticText* stoplabel = nullptr;
	wxTimePickerCtrl* stop = nullptr;

	wxStaticText* datelabel = nullptr;
	wxDatePickerCtrl* date = nullptr;

	wxStaticText* participlabel = nullptr;
	wxListBox* participlist = nullptr;
	wxButton* participbutton1 = nullptr;

	wxStaticText* addresslabel = nullptr;
	wxTextCtrl* streetbox = nullptr;
	wxTextCtrl* citybox = nullptr;

	wxStaticText* ranklabel = nullptr;
	wxChoice* rank = nullptr;

	wxCheckBox* cyklcheck = nullptr;

	wxButton* confirmButton = nullptr;

	//program

	Data* d = nullptr;
	Miejsce* a = nullptr;
	Ranga* r = nullptr;


	int* h = nullptr;
	int* m = nullptr;
	int* s = nullptr;

	Godzina* pocz = nullptr;
	Godzina* kon = nullptr;
	czasTrwania* cz = nullptr;

	wektorUczestnikow* waParticipant = nullptr;

	wektorSpotkan* cykliSpotkania = nullptr;
	
	Spotkanie* spotkanie1 = nullptr;
	SpotkanieCykliczne* spotkanie2 = nullptr;

	cDialogAddParticip* dap = nullptr;
	cDialogCykl* dc = nullptr;

	wxDateSpan* tyg = nullptr;
	wxDateSpan* mie = nullptr;
	wxDateSpan* yr = nullptr;

	void onCButtonClicked(wxCommandEvent& evt_conf);

	void onPButtonClicked(wxCommandEvent& evt_addp);

	

	wxDECLARE_EVENT_TABLE();
public:
	Spotkanie getSpotkanie();
	wektorSpotkan getSpotkania();
	bool czyCykl();

};

