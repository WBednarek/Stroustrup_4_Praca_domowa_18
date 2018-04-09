#pragma once
#include "../stdafx.h"
#include "../std_lib_facilities_v2.h"

/*
Stroustrup PPP Chapter 9 
Exercise 1 for Date struct form chapter 9.4.1

*/


namespace Date941
{
	struct Date
	{
		int y;
		int m;
		int d;
	};

	void init_day(Date& dd, int y, int m, int d);
	void add_day(Date& dd);
	bool leapyear(int year);
	const int& num_of_february_days_lapyear();
	const int& num_of_february_days();
}



