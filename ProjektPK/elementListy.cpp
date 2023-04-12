#include "elementListy.h"

/*elementListy elementListy::getNext()
{
	return *next;
}

void elementListy::setSpotkanie(Spotkanie x)
{
	s = x;
}

void elementListy::setNext(elementListy* y)
{
	next = y;
}*/
std::string elementListy::toString()
{
	return s.getName();
}
