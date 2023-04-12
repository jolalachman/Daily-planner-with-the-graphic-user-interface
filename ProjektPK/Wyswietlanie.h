#pragma once
#include "wektorSpotkan.h"
class Wyswietlanie
{
private:
	int wdzien;
	int wmiesiac;
	int wrok;
	wektorSpotkan wspotkania;
public:
	wektorSpotkan getWSpotkania();
	void wyswietlDzien(wektorSpotkan original);

	Wyswietlanie(int, int, int);
	~Wyswietlanie();
};

