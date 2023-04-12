#pragma once
#include "wx/wx.h"
#include <wx/calctrl.h>
#include "cDialog1.h"
#include "listaSpotkan.h"
#include "wektorSpotkan.h"
#include "Wyswietlanie.h"
#include "Sprawdz.h"


class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

private:
	wxButton* m_btn1 = nullptr;
	wxListBox* m_list1 = nullptr;
	wxCalendarCtrl* m_calendar1 = nullptr;

	void onButton1Clicked(wxCommandEvent& evt1);
	void onDayClicked(wxCommandEvent& evt6);

	cDialog1* d1 = nullptr;

	wektorSpotkan* spotkania = nullptr;
	Wyswietlanie* wys = nullptr;
	Sprawdz* spr = nullptr;
	listaSpotkan* lista = nullptr;

	wxDECLARE_EVENT_TABLE();
};

