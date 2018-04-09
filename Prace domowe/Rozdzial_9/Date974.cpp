#include "stdafx.h"
#include "Date974.h"


namespace Date974
{

	Date::Month operator+(Date::Month& m, Date::Month& m1)// eg. feb + feb
	{
		Date::Month result;
		result = Date::Month(((m + m1) % 13) );
		return result;
	}

	//Date::Month operator+(Date::Month& m, int m1)
	//{
	//	Date::Month result;
	//	result = Date::Month(((m + m1) % 13) + 1);
	//	return result;
	//}

	Date::Month operator+=(Date::Month& m, int m1)
	{
		m = Date::Month(((m + m1) % 13) );
		return m;
	}

	Year operator+=(Year& y, int y1)
	{
		return (Year(y.year() + y1));
	}



	Year::Year() : y(2001)
	{
	}


	int Date::year() const
	{
		return y.year();
	}

	int Date::month() const
	{
		return m;
	}

	int Date::day() const
	{
		return d;
	}

	Date::Date(Year year, Month month, int day)
	{
		const int max_days_num = 31;
		const int max_months_num = 12;
		if (day <= 0 || day > max_days_num) error("error: days number has to be bigger than 0, or less than 32");
		if (month <= 0 || month > max_months_num) error("error: months number has to be bigger than 0, or less than 13");

		switch (month)
		{
		case apr: case jun: case sep: case nov:
		{
			if (day > 30) error("error: to much days for months: April, June, September, November");
			break;
		}
		case feb:
		{
			if (leapyear(year.year()) && day > num_of_february_days_lapyear()) error("error: to much days for month: February in lap year (maximimun 29)");
			if (!leapyear(year.year()) && day > num_of_february_days()) error("error: to much days for month: February");
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
		if (n < 1) error("error: add positive mumber of days (more than 0)");
		if (leapyear(y.year()) && m == feb && d == num_of_february_days_lapyear())
		{
			m = mar;
			d = n;
			return;
		}
		if (!leapyear(y.year()) && (d == num_of_february_days() || d == 30 || d == 31))
		{
			if (m != dec)
			{
				m += 1;
				d = n;
				return;
			}
			else
			{
				y += 1;
				m = jan;
				d = n;
				return;
			}

		}

		d += n;

	}

	void Date::add_month(int n)
	{
		if (n < 0) error("error: add positive mumber of months (more than 0)");
		m = Month(((m + n) % 13) );
		if (n > months_in_year())
		{
			int years = n / months_in_year();
			add_year(years);
		}

	}

	void Date::add_year(int n)
	{
		if (n < 0) error("error: add positive mumber of years (more than 0)");
		y = Year(y.year() + n);
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

	const int& months_in_year()
	{
		const static int months = 12;
		return months;
	}

}