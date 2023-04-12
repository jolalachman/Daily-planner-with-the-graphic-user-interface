#include "cDialog1.h"



wxBEGIN_EVENT_TABLE(cDialog1, wxDialog)
EVT_BUTTON(10007, onPButtonClicked)
EVT_BUTTON(10008, onCButtonClicked)
wxEND_EVENT_TABLE()

cDialog1::cDialog1() : wxDialog(nullptr, wxID_ANY, "Dodaj spotkanie", wxPoint(30, 30), wxSize(350, 600))
{
	namelabel = new wxStaticText(this, wxID_ANY, "Nazwa:", wxPoint(30, 20), wxSize(50, 25));
	namebox = new wxTextCtrl(this, wxID_ANY, "", wxPoint(100, 20), wxSize(200, 25));

	startlabel = new wxStaticText(this, wxID_ANY, "Godzina rozpoczêcia:", wxPoint(30, 70), wxSize(150, 25));
	start = new wxTimePickerCtrl(this, wxID_ANY, wxDateTime(), wxPoint(200, 70), wxSize(100, 40));
	start->SetTime(0,00,00);

	stoplabel = new wxStaticText(this, wxID_ANY, "Godzina zakoñczenia:", wxPoint(30, 120), wxSize(150, 25));
	stop = new wxTimePickerCtrl(this, wxID_ANY, wxDateTime(), wxPoint(200, 120), wxSize(100, 40));
	stop->SetTime(23, 59, 59);

	datelabel = new wxStaticText(this, wxID_ANY, "Data:", wxPoint(30, 185), wxSize(150, 25));
	date = new wxDatePickerCtrl(this, wxID_ANY, wxDateTime(), wxPoint(200, 185), wxSize(100, 40));

	participlabel = new wxStaticText(this, wxID_ANY, "Uczestnicy:", wxPoint(30, 250), wxSize(70, 25));
	participlist = new wxListBox(this, wxID_ANY, wxPoint(110, 250), wxSize(150, 75));
	participbutton1 = new wxButton(this, 10007, "+", wxPoint(270, 250), wxSize(30, 30));

	addresslabel = new wxStaticText(this, wxID_ANY, "Adres:", wxPoint(30, 350), wxSize(50, 25));
	streetbox = new wxTextCtrl(this, wxID_ANY, "Ulica", wxPoint(90, 350), wxSize(100, 40));
	citybox = new wxTextCtrl(this, wxID_ANY, "Miasto", wxPoint(200, 350), wxSize(100, 40));

	ranklabel = new wxStaticText(this, wxID_ANY, "Ranga: ", wxPoint(30, 415), wxSize(50, 25));
	//osobna klasa na to
	wxArrayString s;
	s.Add("bardzo wa¿ne");
	s.Add("s³u¿bowe");
	s.Add("prywatne");
	rank = new wxChoice(this, wxID_ANY, wxPoint(200, 415), wxSize(100, 25), wxArrayString(s));

	cyklcheck = new wxCheckBox(this, wxID_ANY, "Spotkanie cykliczne:", wxPoint(30, 465), wxSize(150, 25));
	
	confirmButton = new wxButton(this, 10008, "Dodaj", wxPoint(200, 515), wxSize(100, 25));

	waParticipant = new wektorUczestnikow();

	cykliSpotkania = new wektorSpotkan();
	tyg = new wxDateSpan(0, 0, 1, 0);
}

cDialog1::~cDialog1()
{

}

void cDialog1::onPButtonClicked(wxCommandEvent& evt_addp)
{
	dap = new cDialogAddParticip();
	if (dap->ShowModal() == 10010)
	{
		waParticipant->dodaj(dap->getUczestnik());
		participlist->AppendString(dap->getUczestnik().formatString());
	}
		
	dap->Destroy();

	evt_addp.Skip();

}
//doubleclick na liscie -> usun i czy na pewno checsz usunac dialog 

void cDialog1::onCButtonClicked(wxCommandEvent& evt_conf)
{
	if (!(cyklcheck->GetValue()))
	{
		spotkanie1 = new Spotkanie();

		//nazwa
		spotkanie1->setName(namebox->GetValue().ToStdString());

		//czas

		h = new int;
		m = new int;
		s = new int;

		start->GetTime(h, m, s);
		pocz = new Godzina();
		pocz->setGodzina(*h);
		pocz->setMinuta(*m);

		stop->GetTime(h, m, s);
		kon = new Godzina();
		kon->setGodzina(*h);
		kon->setMinuta(*m);

		cz = new czasTrwania();
		cz->setStart(*pocz);
		cz->setStop(*kon);
		spotkanie1->setTime(*cz);

		//data
		d = new Data();
		d->setDay(date->GetValue().GetDay());
		d->setMonth(date->GetValue().GetMonth());
		d->setYear(date->GetValue().GetYear());
		spotkanie1->setDate(*d);

		//uczestnicy
		spotkanie1->setVector(*waParticipant);

		//adres
		a = new Miejsce();
		a->setStreet(streetbox->GetValue().ToStdString());
		a->setCity(citybox->GetValue().ToStdString());
		spotkanie1->setAddress(*a);

		//ranga
		r = new Ranga();
		if (!(rank->GetSelection() == wxNOT_FOUND))
		{
			r->setRank(rank->GetSelection());
			spotkanie1->setRank(*r);
		}
		else
		{
			wxMessageBox("Nie wybrano rangi");
		}

		evt_conf.Skip();
	}
	else
	{
		dc = new cDialogCykl();
		if (dc->ShowModal() == 10022)
		{
			if (dc->getPick().IsEarlierThan(date->GetValue()) or dc->getPick().IsSameDate(date->GetValue()))
			{
				wxMessageBox("B³¹d: Data koñca cyklu jest wczeœniejsza lub taka sama jak data jego rozpoczêcia");
			}
			else
			{
				if (dc->getWyborc() == 0)
				{
					wxDateTime x = date->GetValue();
					while (x.IsEarlierThan(dc->getPick()) or x.IsSameDate(dc->getPick()))
					{
						//dodawanie spotkania do wektora
						spotkanie2 = new SpotkanieCykliczne();

						//nazwa
						spotkanie2->setName(namebox->GetValue().ToStdString());

						//czas
						h = new int;
						m = new int;
						s = new int;

						start->GetTime(h, m, s);
						pocz = new Godzina();
						pocz->setGodzina(*h);
						pocz->setMinuta(*m);

						stop->GetTime(h, m, s);
						kon = new Godzina();
						kon->setGodzina(*h);
						kon->setMinuta(*m);

						cz = new czasTrwania();
						cz->setStart(*pocz);
						cz->setStop(*kon);
						spotkanie2->setTime(*cz);

						//data
						d = new Data();
						d->setDay(x.GetDay());
						d->setMonth(x.GetMonth());
						d->setYear(x.GetYear());
						spotkanie2->setDate(*d);

						//uczestnicy
						spotkanie2->setVector(*waParticipant);

						//adres
						a = new Miejsce();
						a->setStreet(streetbox->GetValue().ToStdString());
						a->setCity(citybox->GetValue().ToStdString());
						spotkanie2->setAddress(*a);

						//ranga
						r = new Ranga();
						if (!(rank->GetSelection() == wxNOT_FOUND))
						{
							r->setRank(rank->GetSelection());
							spotkanie2->setRank(*r);
						}
						else
						{
							wxMessageBox("Nie wybrano rangi");
						}

						//cykl
						spotkanie2->setCykl(dc->getWyborc());
						spotkanie2->setKoniec(dc->getWybork());

						cykliSpotkania->dodaj(*spotkanie2);

						x.Add(*tyg);
					}
				}
				else if (dc->getWyborc() == 1)
				{
					wxDateTime x = date->GetValue();
					mie = new wxDateSpan(0, 1, 0, 0);
					while (x.IsEarlierThan(dc->getPick()) or x.IsSameDate(dc->getPick()))
					{
						//dodawanie spotkania do wektora
						spotkanie2 = new SpotkanieCykliczne();

						//nazwa
						spotkanie2->setName(namebox->GetValue().ToStdString());

						//czas
						h = new int;
						m = new int;
						s = new int;

						start->GetTime(h, m, s);
						pocz = new Godzina();
						pocz->setGodzina(*h);
						pocz->setMinuta(*m);

						stop->GetTime(h, m, s);
						kon = new Godzina();
						kon->setGodzina(*h);
						kon->setMinuta(*m);

						cz = new czasTrwania();
						cz->setStart(*pocz);
						cz->setStop(*kon);
						spotkanie2->setTime(*cz);

						//data
						d = new Data();
						d->setDay(x.GetDay());
						d->setMonth(x.GetMonth());
						d->setYear(x.GetYear());
						spotkanie2->setDate(*d);

						//uczestnicy
						spotkanie2->setVector(*waParticipant);

						//adres
						a = new Miejsce();
						a->setStreet(streetbox->GetValue().ToStdString());
						a->setCity(citybox->GetValue().ToStdString());
						spotkanie2->setAddress(*a);

						//ranga
						r = new Ranga();
						if (!(rank->GetSelection() == wxNOT_FOUND))
						{
							r->setRank(rank->GetSelection());
							spotkanie2->setRank(*r);
						}
						else
						{
							wxMessageBox("Nie wybrano rangi");
						}

						//cykl
						spotkanie2->setCykl(dc->getWyborc());
						spotkanie2->setKoniec(dc->getWybork());

						cykliSpotkania->dodaj(*spotkanie2);

						x.Add(*mie);
					}
				}
				else
				{
					wxDateTime x = date->GetValue();
					yr = new wxDateSpan(1, 0, 0, 0);
					while (x.IsEarlierThan(dc->getPick()) or x.IsSameDate(dc->getPick()))
					{
						//dodawanie spotkania do wektora
						spotkanie2 = new SpotkanieCykliczne();

						//nazwa
						spotkanie2->setName(namebox->GetValue().ToStdString());

						//czas
						h = new int;
						m = new int;
						s = new int;

						start->GetTime(h, m, s);
						pocz = new Godzina();
						pocz->setGodzina(*h);
						pocz->setMinuta(*m);

						stop->GetTime(h, m, s);
						kon = new Godzina();
						kon->setGodzina(*h);
						kon->setMinuta(*m);

						cz = new czasTrwania();
						cz->setStart(*pocz);
						cz->setStop(*kon);
						spotkanie2->setTime(*cz);

						//data
						d = new Data();
						d->setDay(x.GetDay());
						d->setMonth(x.GetMonth());
						d->setYear(x.GetYear());
						spotkanie2->setDate(*d);

						//uczestnicy
						spotkanie2->setVector(*waParticipant);

						//adres
						a = new Miejsce();
						a->setStreet(streetbox->GetValue().ToStdString());
						a->setCity(citybox->GetValue().ToStdString());
						spotkanie2->setAddress(*a);

						//ranga
						r = new Ranga();
						if (!(rank->GetSelection() == wxNOT_FOUND))
						{
							r->setRank(rank->GetSelection());
							spotkanie2->setRank(*r);
						}
						else
						{
							wxMessageBox("Nie wybrano rangi");
						}

						//cykl
						spotkanie2->setCykl(dc->getWyborc());
						spotkanie2->setKoniec(dc->getWybork());

						cykliSpotkania->dodaj(*spotkanie2);

						x.Add(*yr);
					}
				}
			}			
		}
		dc->Destroy();
		evt_conf.Skip();
	}	
	EndModal(10008);
}

Spotkanie cDialog1::getSpotkanie()
{
	return *spotkanie1;
}

wektorSpotkan cDialog1::getSpotkania()
{
	return *cykliSpotkania;
}

bool cDialog1::czyCykl()
{
	return cyklcheck->GetValue();
}