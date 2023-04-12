#pragma once
#include <iostream>
#include "wektorSpotkan.h"
class Sprawdz
{
public:
	Sprawdz(wektorSpotkan, Spotkanie);
	~Sprawdz();
private:
	wektorSpotkan wek;
	Spotkanie sptk;
	std::string k_nazwa;
	Godzina k_start;
	Godzina k_stop;
public:
	bool wykryjKonflikt();
	bool czyToSamo();
	std::string getKNazwa();
	Godzina getKStart();
	Godzina getKStop();
};

