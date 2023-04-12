#include "SpotkanieCykliczne.h"

void SpotkanieCykliczne::setCykl(int period)
{
	cykl = period;
}

void SpotkanieCykliczne::setKoniec(Data end)
{
	koniec = end;
}

/*int SpotkanieCykliczne::obliczIle(Data begin)
{
	int i = 0;

	//tydzien
	if (cykl == 0)
	{
		return -1;
	}

	//miesiac
	else if (cykl == 1)
	{
		while (begin.getYear() < koniec.getYear())
		{
			i += 12;
			begin.setYear(begin.getYear() + 1);
		}

		/*if (begin.getYear() == koniec.getYear())
		{
			if(beginisEarlierThan(koniec))
			{
				if(begin.getDay()<=koniec.getDay())
				{
					i+=(koniec.getMonth()-begin.getMonth())+1;
					return i;
				}
				else
				{
					i+=(koniec.getMonth()-begin.getMonth());
					return i;				
				}
			}
			else
			{
				return i;
			}

		}

		

	}
	//rok
	else
	{
		while (begin.getYear() < koniec.getYear())
		{
			i++;
			begin.setYear(begin.getYear() + 1);
		}
		/*if (begin.getYear() == koniec.getYear())
		{
			if(beginisEarlierThan(koniec)
			{
			i++;
			return i;
			}
			else
			{
			return i;
			}
		}
	}
}*/