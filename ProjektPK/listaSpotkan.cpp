#include "listaSpotkan.h"
listaSpotkan::listaSpotkan()
{
	head = NULL;
	tail = NULL;
}

void listaSpotkan::dodajSpotkanie(Spotkanie a)
{
	elementListy* tmp = new elementListy();
	tmp->s = a;
	tmp->next = NULL;

	if (head == NULL)
	{
		head = tmp;
		tail = tmp;
	}
	else
	{
		tail->next = tmp;
		tail = tail->next;
	}

}

std::string listaSpotkan::wypisz()
{
	std::string s="Spotkania:   ";
	
	while (head != NULL)
	{
		s.append(head->toString() + "    ");
		head = head->next;
	}
		
	return s;
}
