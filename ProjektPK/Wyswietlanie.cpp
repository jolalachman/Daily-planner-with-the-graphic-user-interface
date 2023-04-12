#include "Wyswietlanie.h"

Wyswietlanie::Wyswietlanie(int a, int b, int c)
{
	wdzien = a;
	wmiesiac = b;
	wrok = c;
}
Wyswietlanie::~Wyswietlanie()
{

}
wektorSpotkan Wyswietlanie::getWSpotkania()
{
	return wspotkania;
}

void Wyswietlanie::wyswietlDzien(wektorSpotkan original)
{
	if (original.size() != 0)
	{
		for (int i = 0; i < original.size(); i++)
		{
			if (original.getSpotkanie(i).getDate().getYear() == wrok)
			{
				if (original.getSpotkanie(i).getDate().getMonth() == wmiesiac)
				{
					if (original.getSpotkanie(i).getDate().getDay() == wdzien)
					{
						wspotkania.dodaj(original.getSpotkanie(i));
					}
				}
			}
		}
	}
}