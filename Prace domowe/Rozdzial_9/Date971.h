#pragma once
#include "../stdafx.h"
#include "../std_lib_facilities_v2.h"

/*
Stroustrup PPP Chapter 9
Exercise 1 for Date struct form chapter 9.4.3

*/


namespace Date971
{
	class Year
	{
		static const int min = 1800;
		static const int max = 2200;
	public:
		class Invalid { };
		Year();
		Year(int x) : y(x) { if (x < min || x > max) throw Invalid(); }
		int year() { return y; }
	private:
		int y;
	};



	class Date
	{
	public:
		enum Month
		{
			jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
		};
		Date(Year year, Month month, int d);
		void add_day(int n);
		int month() { return m; }
		int day() { return d; }
		int year() { return y.year(); }
	private:
		Year y;
		Month m;
		int d;

	};

	bool leapyear(int year);
	const int& lapyear_february_days();
	const int& february_days();
}



