#pragma once
#include<iostream>


class Uczestnik
{
private:
	std::string imie;
	std::string nazwisko;
	std::string telefon;

public:
	void setImie(std::string fname);
	void setNazwisko(std::string lname);
	void setTelefon(std::string tel);

	std::string getImie();
	std::string getNazwisko();
	std::string getTelefon();

	std::string formatString();
};

