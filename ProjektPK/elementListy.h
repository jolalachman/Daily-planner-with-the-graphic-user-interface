#pragma once
#include "Spotkanie.h"
class elementListy
{
public:
	Spotkanie s;
	elementListy* next;
public:
/*	elementListy getNext();
	void setSpotkanie(Spotkanie x);
	void setNext(elementListy* y);*/
	std::string toString();
};

