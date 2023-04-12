#include "Sprawdz.h"
Sprawdz::Sprawdz(wektorSpotkan a, Spotkanie b)
{
	wek = a;
	sptk = b;
}
Sprawdz::~Sprawdz()
{

}
bool Sprawdz::wykryjKonflikt()
{
	for (int i = 0; i < wek.size(); i++)
	{
		if (sptk.getDate().getYear() == wek.getSpotkanie(i).getDate().getYear() and sptk.getDate().getMonth() == wek.getSpotkanie(i).getDate().getMonth() and sptk.getDate().getDay() == wek.getSpotkanie(i).getDate().getDay())
		{
			if (sptk.getCzas().getStart().getGodzina() < wek.getSpotkanie(i).getCzas().getStop().getGodzina())
			{
				if (sptk.getCzas().getStop().getGodzina() < wek.getSpotkanie(i).getCzas().getStart().getGodzina())
				{
					return false;
				}
				else if (sptk.getCzas().getStop().getGodzina() == wek.getSpotkanie(i).getCzas().getStart().getGodzina())
				{
					if (sptk.getCzas().getStop().getMinuta() > wek.getSpotkanie(i).getCzas().getStart().getMinuta())
					{
						k_nazwa = wek.getSpotkanie(i).getName();
						k_start = wek.getSpotkanie(i).getCzas().getStart();
						k_stop = wek.getSpotkanie(i).getCzas().getStop();
						return true;
					}
					else if (sptk.getCzas().getStop().getMinuta() <= wek.getSpotkanie(i).getCzas().getStart().getMinuta())
					{
						return false;
					}
				}
				else
				{
					k_nazwa = wek.getSpotkanie(i).getName();
					k_start = wek.getSpotkanie(i).getCzas().getStart();
					k_stop = wek.getSpotkanie(i).getCzas().getStop();
					return true;
				}
			}
			else if (sptk.getCzas().getStart().getGodzina() == wek.getSpotkanie(i).getCzas().getStop().getGodzina())
			{
				if (sptk.getCzas().getStart().getMinuta() >= wek.getSpotkanie(i).getCzas().getStop().getMinuta())
				{
					return false;
				}
				else if (sptk.getCzas().getStart().getMinuta() < wek.getSpotkanie(i).getCzas().getStop().getMinuta())
				{
					k_nazwa = wek.getSpotkanie(i).getName();
					k_start = wek.getSpotkanie(i).getCzas().getStart();
					k_stop = wek.getSpotkanie(i).getCzas().getStop();
					return true;
				}
			}
			else
			{
				return false;
			}				
		}
	}
	return false;
}
bool Sprawdz::czyToSamo()
{
	for (int j = 0; j < wek.size(); j++)
	{
		if (sptk.getDate().getYear() == wek.getSpotkanie(j).getDate().getYear() and sptk.getDate().getMonth() == wek.getSpotkanie(j).getDate().getMonth() and sptk.getDate().getDay() == wek.getSpotkanie(j).getDate().getDay())
		{
			if (sptk.getName() == wek.getSpotkanie(j).getName() and sptk.getCzas().getStart().getGodzina() == wek.getSpotkanie(j).getCzas().getStart().getGodzina() and sptk.getCzas().getStart().getMinuta() == wek.getSpotkanie(j).getCzas().getStart().getMinuta())
			{
				k_nazwa = wek.getSpotkanie(j).getName();
				k_start = wek.getSpotkanie(j).getCzas().getStart();
				k_stop = wek.getSpotkanie(j).getCzas().getStop();
				return true;
			}			
		}
	}
	return false;
}

std::string Sprawdz::getKNazwa()
{
	return k_nazwa;
}

Godzina Sprawdz::getKStart()
{
	return k_start;
}

Godzina Sprawdz::getKStop()
{
	return k_stop;
}