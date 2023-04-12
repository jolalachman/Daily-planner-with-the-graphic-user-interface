#pragma once
#include "Spotkanie.h"
class SpotkanieCykliczne : public Spotkanie
{
private:
	int cykl;
	Data koniec;
public:
	void setCykl(int period);
	void setKoniec(Data end);
	//int obliczIle(Data begin);
};

