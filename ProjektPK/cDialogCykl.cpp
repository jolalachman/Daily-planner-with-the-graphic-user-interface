#include "cDialogCykl.h"

wxBEGIN_EVENT_TABLE(cDialogCykl, wxDialog)
EVT_BUTTON(10022, onOkButtonClicked)
wxEND_EVENT_TABLE()

cDialogCykl::cDialogCykl() : wxDialog(nullptr, wxID_ANY, "Cykl", wxPoint(30, 30), wxSize(300, 200))
{
	cykllabel = new wxStaticText(this, wxID_ANY, "Cykl:", wxPoint(30, 20), wxSize(50, 25));
	str.Add("cotygodniowy");
	str.Add("comiesiêczny");
	str.Add("coroczny");
	cykl = new wxChoice(this, wxID_ANY, wxPoint(100, 20), wxSize(100, 25), wxArrayString(str));

	endlabel= new wxStaticText(this, wxID_ANY, "Koniec:", wxPoint(30, 60), wxSize(50, 25));
	end = new wxDatePickerCtrl(this, wxID_ANY, wxDateTime(), wxPoint(100, 60), wxSize(100, 40));
	ok= new wxButton(this, 10022, "Ok", wxPoint(150, 125), wxSize(100, 25));
}

void cDialogCykl::onOkButtonClicked(wxCommandEvent& evt_ok)
{
	if (!(cykl->GetSelection() == wxNOT_FOUND))
	{
		wyborc = cykl->GetSelection();
		wybork.setDay(end->GetValue().GetDay());
		wybork.setMonth(end->GetValue().GetMonth());
		wybork.setYear(end->GetValue().GetYear());
		EndModal(10022);
	}
	else
	{
		wxMessageBox("Nie wybrano cyklu");
		EndModal(20000);
	}
	
}

int cDialogCykl::getWyborc()
{
	return wyborc;
}

Data cDialogCykl::getWybork()
{
	return wybork;
}

wxDateTime cDialogCykl::getPick()
{
	return end->GetValue();
}

cDialogCykl::~cDialogCykl()
{

}
