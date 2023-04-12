#pragma once
#include <vector>
#include "SpotkanieCykliczne.h"
class wektorSpotkan
{
private:
	std::vector<Spotkanie> vs;
public:
	void dodaj(Spotkanie s);
	void dodajisortuj(Spotkanie spotkanie);
	void dodajisortujWektor(wektorSpotkan spotkania);
	Spotkanie getSpotkanie(int i);
	int size();
};

