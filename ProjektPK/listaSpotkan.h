#pragma once
#include <iostream>
#include "elementListy.h"
class listaSpotkan
{
private:
	elementListy* head;
	elementListy* tail;
public:
	listaSpotkan();
	void dodajSpotkanie(Spotkanie a);
	std::string wypisz();
};

