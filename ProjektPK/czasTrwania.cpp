#include "czasTrwania.h"

void czasTrwania::setStart(Godzina a)
{
	start = a;
}

void czasTrwania::setStop(Godzina b)
{
	stop = b;
}

Godzina czasTrwania::getStart()
{
	return start;
}

Godzina czasTrwania::getStop()
{
	return stop;
}