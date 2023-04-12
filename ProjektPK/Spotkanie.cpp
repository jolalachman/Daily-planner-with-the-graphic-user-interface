#include "Spotkanie.h"

void Spotkanie::setName(std::string name)
{
	nazwa = name;
}
void Spotkanie::setDate(Data date)
{
	data = date;
}
void Spotkanie::setTime(czasTrwania time)
{
	czas = time;
}
void Spotkanie::setVector(wektorUczestnikow vector)
{
	uczestnicy = vector;
}
void Spotkanie::setAddress(Miejsce address)
{
	adres = address;
}
void Spotkanie::setRank(Ranga rank)
{
	ranga = rank;
}

std::string Spotkanie::getName()
{
	return nazwa;
}

czasTrwania Spotkanie::getCzas()
{
	return czas;
}

Data Spotkanie::getDate()
{
	return data;
}