#pragma once
class Data
{
private:
	int day;
	int month;
	int year;
public:
	void setDay(int dzien);
	void setMonth(int msc);
	void setYear(int rok);

	int getDay();
	int getMonth();
	int getYear();
};

