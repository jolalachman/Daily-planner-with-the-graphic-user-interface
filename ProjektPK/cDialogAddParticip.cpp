#include "cDialogAddParticip.h"

wxBEGIN_EVENT_TABLE(cDialogAddParticip, wxDialog)
EVT_BUTTON(10010, onAddButtonClicked)
wxEND_EVENT_TABLE()


cDialogAddParticip::cDialogAddParticip() :wxDialog(nullptr, wxID_ANY, "Dodaj uczestnika", wxPoint(30, 30), wxSize(350, 250))
{
	fnamelabel = new wxStaticText(this, wxID_ANY, "Imiê:", wxPoint(20, 20), wxSize(70, 25));
	firstnamebox = new wxTextCtrl(this, wxID_ANY, "", wxPoint(100, 20), wxSize(200, 25));

	lnamelabel = new wxStaticText(this, wxID_ANY, "Nazwisko:", wxPoint(20, 70), wxSize(70, 25));
	lastnamebox = new wxTextCtrl(this, wxID_ANY, "", wxPoint(100, 70), wxSize(200, 25));

	tellabel = new wxStaticText(this, wxID_ANY, "Telefon:", wxPoint(20, 120), wxSize(70, 25));
	telbox = new wxTextCtrl(this, wxID_ANY, "", wxPoint(100, 120), wxSize(200, 25));

	addButton = new wxButton(this, 10010, "Dodaj", wxPoint(200, 170), wxSize(100, 25));

}

cDialogAddParticip::~cDialogAddParticip()
{

}

void cDialogAddParticip::onAddButtonClicked(wxCommandEvent& evt_addpp)
{
	participant = new Uczestnik();
	participant->setImie(firstnamebox->GetValue().ToStdString());
	participant->setNazwisko(lastnamebox->GetValue().ToStdString());
	participant->setTelefon(telbox->GetValue().ToStdString());
	evt_addpp.Skip();
	EndModal(10010);
	
	//sprawdz czy przynajmniej jeden nie jest pusty 
	//tworzymy obiekt uczestnik, gdzie nic nie ma dajemy "-"
	// ew dodatek jak sa ci sami uczestnicy do messagebox
	// nr telefnu 6-9 znakow
	//Imie i nazwsko z duzej litery
	
}

Uczestnik cDialogAddParticip::getUczestnik()
{
	return *participant;
}