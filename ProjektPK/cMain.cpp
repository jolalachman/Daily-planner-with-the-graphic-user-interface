#include "cMain.h"


BEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_BUTTON(10001, cMain::onButton1Clicked)
END_EVENT_TABLE()



cMain::cMain() : wxFrame(nullptr, wxID_ANY, "TERMINARZ", wxPoint(30, 30), wxSize(800, 600))
{
	m_btn1 = new wxButton(this, 10001, "Dodaj spotkanie", wxPoint(380, 420), wxSize(390, 40));

	m_list1 = new wxListBox(this, wxID_ANY, wxPoint(10, 10), wxSize(350, 540));

	m_calendar1 = new wxCalendarCtrl(this, 10006, wxDateTime(), wxPoint(430, 10), wxSize(300, 300));
	Bind(wxEVT_CALENDAR_DAY_CHANGED, &cMain::onDayClicked, this);
	spotkania = new wektorSpotkan();
	lista = new listaSpotkan();
}
cMain::~cMain()
{
}

void cMain::onDayClicked(wxCommandEvent& evt6)
{
	wys = new Wyswietlanie(m_calendar1->GetDate().GetDay(), m_calendar1->GetDate().GetMonth(), m_calendar1->GetDate().GetYear());
	m_list1->Clear();
	wys->wyswietlDzien(*spotkania);
	for (int j = 0; j < wys->getWSpotkania().size(); j++)
	{
		m_list1->AppendString(wys->getWSpotkania().getSpotkanie(j).getName() + " " + wys->getWSpotkania().getSpotkanie(j).getCzas().getStart().formString() + " (...)");
	}
	
}

void cMain::onButton1Clicked(wxCommandEvent& evt1)
{
	d1 = new cDialog1();

	if (d1->ShowModal() == 10008)
	{
		if (!(d1->czyCykl()))
		{
			spr = new Sprawdz(*spotkania, d1->getSpotkanie());
			if (spr->wykryjKonflikt())
			{
				if (spr->czyToSamo())
				{
					wxMessageBox("Ju¿ istnieje takie spotkanie");
				}
				else
				{
					wxMessageBox("Nie mo¿na dodaæ spotkanie, poniewa¿ jest w konflikcie z: " + spr->getKNazwa() + " (" + spr->getKStart().formString() + "-" + spr->getKStop().formString() + ")");
				}
			}
			else
			{
				spotkania->dodajisortuj(d1->getSpotkanie());
				lista->dodajSpotkanie(d1->getSpotkanie());
			}
		}
		else
		{
			spr = new Sprawdz(*spotkania, d1->getSpotkanie());
			if (spr->wykryjKonflikt())
			{
				if (spr->czyToSamo())
				{
					wxMessageBox("Ju¿ istnieje takie spotkanie");
				}
				else
				{
					wxMessageBox("Nie mo¿na dodaæ spotkanie, poniewa¿ jest w konflikcie z: " + spr->getKNazwa() + " (" + spr->getKStart().formString() + "-" + spr->getKStop().formString() + ")");
				}
			}
			else
			{
				spotkania->dodajisortujWektor(d1->getSpotkania());
			}			
		}
		wys = new Wyswietlanie(m_calendar1->GetDate().GetDay(), m_calendar1->GetDate().GetMonth(), m_calendar1->GetDate().GetYear());
		m_list1->Clear();
		wys->wyswietlDzien(*spotkania);
		for (int j = 0; j < wys->getWSpotkania().size(); j++)
		{
			m_list1->AppendString(wys->getWSpotkania().getSpotkanie(j).getName() + " " + wys->getWSpotkania().getSpotkanie(j).getCzas().getStart().formString() + " (...)");
		}
	}
	d1->Destroy();
	evt1.Skip();
}





