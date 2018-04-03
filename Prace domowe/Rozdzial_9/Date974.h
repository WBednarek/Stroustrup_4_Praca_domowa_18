#pragma once
#include "../stdafx.h"
#include "../std_lib_facilities_v2.h"

/*
Stroustrup PPP Chapter 9
Exercise 1 for Date class form chapter 9.7.4

*/


namespace Date974
{
	class Year
	{
		static const int min = 1800;
		static const int max = 2200;
	public:
		class Invalid { };
		Year();
		Year(int x) : y(x) { if (x < min || x > max) throw Invalid(); }
		int year() const { return y; }
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
		int month() const;
		int day() const;
		int year() const;

		void add_day(int n);
		void add_month(int n);
		void add_year(int n);
	private:
		Year y;
		Month m;
		int d;

	};

	bool leapyear(int year);
	const int& lapyear_february_days();
	const int& february_days();
}



