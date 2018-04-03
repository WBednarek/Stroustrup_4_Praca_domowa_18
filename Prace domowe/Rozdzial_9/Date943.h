#pragma once
#include "../stdafx.h"
#include "../std_lib_facilities_v2.h"

/*
Stroustrup PPP Chapter 9
Exercise 1 for Date class form chapter 9.4.3

*/


namespace Date943
{
	class Date
	{
		int y, m, d;
	public:
		Date(int y, int m, int d);
		void add_day(int n);
		int month() { return m; }
		int day() { return d; }
		int year() { return y; }

	};

	bool leapyear(int year);
	const int& lapyear_february_days();
	const int& february_days();
}



