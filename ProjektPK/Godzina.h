#pragma once
#include <iostream>
#include <string>
class Godzina
{
private:
	int godzina;
	int minuta;
public:
	void setGodzina(int hour);
	void setMinuta(int min);
	int getGodzina();
	int getMinuta();
	std::string formString();
};

