#pragma once
#include<iostream>
#include"wektorUczestnikow.h"
#include"Data.h"
#include"czasTrwania.h"
#include "Miejsce.h"
#include "Ranga.h"

class Spotkanie
{
private:
	std::string nazwa;
	Data data;
	czasTrwania czas;
	wektorUczestnikow uczestnicy;
	Miejsce adres;
	Ranga ranga;
public:
	void setName(std::string name);
	void setDate(Data date);
	void setTime(czasTrwania time);
	void setVector(wektorUczestnikow vector);
	void setAddress(Miejsce address);
	void setRank(Ranga rank);

	std::string getName();
	czasTrwania getCzas();
	Data getDate();

};

