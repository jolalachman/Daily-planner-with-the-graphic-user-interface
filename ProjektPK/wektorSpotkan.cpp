#include "wektorSpotkan.h"
void wektorSpotkan::dodaj(Spotkanie s)
{
	vs.push_back(s);
}
void wektorSpotkan::dodajisortuj(Spotkanie spotkanie)
{
	if (vs.size() == 0)
	{
		vs.push_back(spotkanie);
	}
	else
	{
		int i = 0;
		while (i < vs.size())
		{
			if (vs[i].getDate().getYear() == spotkanie.getDate().getYear())
			{
				if (vs[i].getDate().getMonth() == spotkanie.getDate().getMonth())
				{
					if (vs[i].getDate().getDay() == spotkanie.getDate().getDay())
					{
						if (vs[i].getCzas().getStart().getGodzina() == spotkanie.getCzas().getStart().getGodzina())
						{
							if (vs[i].getCzas().getStart().getMinuta() == spotkanie.getCzas().getStart().getMinuta())
							{
								auto itPos = vs.begin() + i;
								auto newIt = vs.insert(itPos, spotkanie);
								i = vs.size();
							}
							else if (vs[i].getCzas().getStart().getMinuta() > spotkanie.getCzas().getStart().getMinuta())
							{
								auto itPos = vs.begin() + i;
								auto newIt = vs.insert(itPos, spotkanie);
								i = vs.size();
							}
							else if (vs[i].getCzas().getStart().getMinuta() < spotkanie.getCzas().getStart().getMinuta())
							{
								if (i + 1 == vs.size())
								{
									vs.push_back(spotkanie);
									i = vs.size();
								}
								else
								{
									i++;
								}
							}
						}
						else if (vs[i].getCzas().getStart().getGodzina() > spotkanie.getCzas().getStart().getGodzina())
						{
							auto itPos = vs.begin() + i;
							auto newIt = vs.insert(itPos, spotkanie);
							i = vs.size();
						}
						else if (vs[i].getCzas().getStart().getGodzina() < spotkanie.getCzas().getStart().getGodzina())
						{
							if (i + 1 == vs.size())
							{
								vs.push_back(spotkanie);
								i = vs.size();
							}
							else
							{
								i++;
							}
						}
					}
					else if (vs[i].getDate().getDay() > spotkanie.getDate().getDay())
					{
						auto itPos = vs.begin() + i;
						auto newIt = vs.insert(itPos, spotkanie);
						i = vs.size();
					}
					else if (vs[i].getDate().getDay() < spotkanie.getDate().getDay())
					{
						if (i + 1 == vs.size())
						{
							vs.push_back(spotkanie);
							i = vs.size();
						}
						else
						{
							i++;
						}
					}
				}
				else if (vs[i].getDate().getMonth() > spotkanie.getDate().getMonth())
				{
					auto itPos = vs.begin() + i;
					auto newIt = vs.insert(itPos, spotkanie);
					i = vs.size();
				}
				else if (vs[i].getDate().getMonth() < spotkanie.getDate().getMonth())
				{
					if (i + 1 == vs.size())
					{
						vs.push_back(spotkanie);
						i = vs.size();
					}
					else
					{
						i++;
					}
				}
			}
			else if (vs[i].getDate().getYear() > spotkanie.getDate().getYear())
			{
				auto itPos = vs.begin() + i;
				auto newIt = vs.insert(itPos, spotkanie);
				i = vs.size();
			}
			else if (vs[i].getDate().getYear() < spotkanie.getDate().getYear())
			{
				if (i + 1 == vs.size())
				{
					vs.push_back(spotkanie);
					i = vs.size();
				}
				else
				{
					i++;
				}
			}
		}
	}	
}

void wektorSpotkan:: dodajisortujWektor(wektorSpotkan spotkania)
{
	if (vs.size() == 0)
	{
		for (int k = 0; k < spotkania.size(); k++)
		{
			vs.push_back(spotkania.getSpotkanie(k));
		}
	}
	else
	{
		for (int m = 0; m < spotkania.size(); m++)
		{
			int i = 0;
			while (i < vs.size())
			{
				if (vs[i].getDate().getYear() == spotkania.getSpotkanie(m).getDate().getYear())
				{
					if (vs[i].getDate().getMonth() == spotkania.getSpotkanie(m).getDate().getMonth())
					{
						if (vs[i].getDate().getDay() == spotkania.getSpotkanie(m).getDate().getDay())
						{
							if (vs[i].getCzas().getStart().getGodzina() == spotkania.getSpotkanie(m).getCzas().getStart().getGodzina())
							{
								if (vs[i].getCzas().getStart().getMinuta() == spotkania.getSpotkanie(m).getCzas().getStart().getMinuta())
								{
									auto itPos = vs.begin() + i;
									auto newIt = vs.insert(itPos, spotkania.getSpotkanie(m));
									i = vs.size();
								}
								else if (vs[i].getCzas().getStart().getMinuta() > spotkania.getSpotkanie(m).getCzas().getStart().getMinuta())
								{
									auto itPos = vs.begin() + i;
									auto newIt = vs.insert(itPos, spotkania.getSpotkanie(m));
									i = vs.size();
								}
								else if (vs[i].getCzas().getStart().getMinuta() < spotkania.getSpotkanie(m).getCzas().getStart().getMinuta())
								{
									if (i + 1 == vs.size())
									{
										vs.push_back(spotkania.getSpotkanie(m));
										i = vs.size();
									}
									else
									{
										i++;
									}
								}
							}
							else if (vs[i].getCzas().getStart().getGodzina() > spotkania.getSpotkanie(m).getCzas().getStart().getGodzina())
							{
								auto itPos = vs.begin() + i;
								auto newIt = vs.insert(itPos, spotkania.getSpotkanie(m));
								i = vs.size();
							}
							else if (vs[i].getCzas().getStart().getGodzina() < spotkania.getSpotkanie(m).getCzas().getStart().getGodzina())
							{
								if (i + 1 == vs.size())
								{
									vs.push_back(spotkania.getSpotkanie(m));
									i = vs.size();
								}
								else
								{
									i++;
								}
							}
						}
						else if (vs[i].getDate().getDay() > spotkania.getSpotkanie(m).getDate().getDay())
						{
							auto itPos = vs.begin() + i;
							auto newIt = vs.insert(itPos, spotkania.getSpotkanie(m));
							i = vs.size();
						}
						else if (vs[i].getDate().getDay() < spotkania.getSpotkanie(m).getDate().getDay())
						{
							if (i + 1 == vs.size())
							{
								vs.push_back(spotkania.getSpotkanie(m));
								i = vs.size();
							}
							else
							{
								i++;
							}
						}
					}
					else if (vs[i].getDate().getMonth() > spotkania.getSpotkanie(m).getDate().getMonth())
					{
						auto itPos = vs.begin() + i;
						auto newIt = vs.insert(itPos, spotkania.getSpotkanie(m));
						i = vs.size();
					}
					else if (vs[i].getDate().getMonth() < spotkania.getSpotkanie(m).getDate().getMonth())
					{
						if (i + 1 == vs.size())
						{
							vs.push_back(spotkania.getSpotkanie(m));
							i = vs.size();
						}
						else
						{
							i++;
						}
					}
				}
				else if (vs[i].getDate().getYear() > spotkania.getSpotkanie(m).getDate().getYear())
				{
					auto itPos = vs.begin() + i;
					auto newIt = vs.insert(itPos, spotkania.getSpotkanie(m));
					i = vs.size();
				}
				else if (vs[i].getDate().getYear() < spotkania.getSpotkanie(m).getDate().getYear())
				{
					if (i + 1 == vs.size())
					{
						vs.push_back(spotkania.getSpotkanie(m));
						i = vs.size();
					}
					else
					{
						i++;
					}
				}
			}
		}
	}
}

Spotkanie wektorSpotkan::getSpotkanie(int i)
{
	return vs[i];
}

int wektorSpotkan::size()
{
	return vs.size();
}