#include "Uczestnik.h"


void Uczestnik::setImie(std::string fname)
{
	imie = fname;
}

void Uczestnik::setNazwisko(std::string lname)
{
	nazwisko = lname;
}

void Uczestnik::setTelefon(std::string tel)
{
	telefon = tel;
}

std::string Uczestnik::getImie()
{
	return imie;
}

std::string Uczestnik::getNazwisko()
{
	return nazwisko;
}

std::string Uczestnik::getTelefon()
{
	return telefon;
}

std::string Uczestnik::formatString()
{
	return imie + " " + nazwisko + " " + telefon;
}