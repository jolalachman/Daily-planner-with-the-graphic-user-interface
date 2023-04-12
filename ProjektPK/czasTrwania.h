#pragma once
#include "Godzina.h"
class czasTrwania
{
private:
	Godzina start;
	Godzina stop;

public:
	void setStart(Godzina a);
	void setStop(Godzina b);

	Godzina getStart();
	Godzina getStop();
};

