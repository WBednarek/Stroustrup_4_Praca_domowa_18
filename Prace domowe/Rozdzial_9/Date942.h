#pragma once
#include "../stdafx.h"
#include "../std_lib_facilities_v2.h"

/*
Stroustrup PPP Chapter 9
Exercise 1 for Date struct form chapter 9.4.1

*/


namespace Date942
{
	struct Date
	{
		int y, m, d;
		Date(int y, int m, int d);
		void add_day(int n);

	};

	bool leapyear(int year);
	const int& lapyear_february_days();
	const int& february_days();
}



