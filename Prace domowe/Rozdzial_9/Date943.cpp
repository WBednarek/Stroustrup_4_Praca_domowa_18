#include "stdafx.h"
#include "Date943.h"


namespace Date943
{

	Date::Date(int year, int month, int day)
	{
		const int max_days_num = 31;
		const int max_months_num = 12;
		if (day <= 0 || day > max_days_num) error("error: days number has to be bigger than 0, or less than 32");
		if (month <= 0 || month > max_months_num) error("error: months number has to be bigger than 0, or less than 13");

		switch (month)
		{
		case 4: case 6: case 9: case 11: // Hmm here I have to put everwhere case before int number; For example  case 4: 6: 9: 11: doesn't work
		{
			if (day > 30) error("error: to much days for months: April, June, September, November");
			break;
		}
		case 2:
		{
			if (leapyear(year) && day > num_of_february_days_lapyear()) error("error: to much days for month: February in lap year (maximimun 29)");
			if (!leapyear(year) && day > num_of_february_days()) error("error: to much days for month: February");
			break;
		}
		default:
		{
			break;
		}

		}

		y = year;
		m = month;
		d = day;

	}



	void Date::add_day(int n)
	{
		if (n < 1) error("error: add positive mumber of day (more than 0)");
		if (leapyear(y) && m == 2 && d == num_of_february_days_lapyear())
		{
			m = 3;
			d = n;
			return;
		}
		if (!leapyear(y) && (d == num_of_february_days() || d == 30 || d == 31))
		{
			if (m != 12)
			{
				m += 1;
				d = n;
				return;
			}
			else
			{
				y += 1;
				m = 1;
				d = n;
				return;
			}

		}

		d += n;

	}


	bool leapyear(int year)
	{
		if (year % 4 == 0) return true;
		return false;
	}

	const int& num_of_february_days_lapyear()
	{
		static int lapyear_feb_days = 29;
		return lapyear_feb_days;
	}

	const int& num_of_february_days()
	{
		static int days_in_feb = 28;
		return days_in_feb;
	}

}