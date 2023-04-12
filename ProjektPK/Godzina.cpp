#include "Godzina.h"

void Godzina::setGodzina(int hour)
{
	godzina = hour;
}

void Godzina::setMinuta(int min)
{
	minuta = min;
}

int Godzina::getGodzina()
{
	return godzina;
}

int Godzina::getMinuta()
{
	return minuta;
}

std::string Godzina::formString()
{
	if (minuta == 0)
		return std::to_string(godzina) + ":" + std::to_string(minuta)+"0";
	else
		return std::to_string(godzina) + ":" + std::to_string(minuta);
}
