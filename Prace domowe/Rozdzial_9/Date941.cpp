#include "stdafx.h"
#include "Date941.h"




void init_day(Date941& dd, int y, int m, int d)
{
	const int max_days_num = 31;
	const int max_months_num = 12;
	if (d <= 0 || d > max_days_num) error("error: days number has to be bigger than 0, or less than 32");
	if (m <= 0 || m > max_months_num) error("error: months number has to be bigger than 0, or less than 13");
	
	switch (m)
	{
		case 4: case 6: case 9: case 11: // Hmm here I have to put everwhere case before int mumber; case 4: 6: 9: 11: doesn't work
		{
			if(d > 30 ) error("error: to much days for months: April, June, September, November");
			break;
		}
		case 2:
		{
			if (d > 29) error("error: to much days for month: February");
			break;
		}
		default:
		{
			dd.d = max_days_num;
			break;
		}

	}

	dd.y = y;
	dd.m = m;
	dd.d = d;

}



void add_day(Date941& dd)
{
	if (lapyear(dd.y) && dd.m == 2 && dd.d == 29)
	{
		dd.m = 3;
		dd.d = 1;
		return;
	}
	if (dd.d == 28 || dd.d == 30 || dd.d == 31)
	{
		if (dd.m != 12)
		{
			dd.m += 1;
			dd.d = 1;
			return;
		}
		else
		{
			dd.y += 1;
			dd.m = 1;
			dd.d = 1;
			return;
		}
			
	}

	dd.d += 1;
	
}


bool lapyear(int year)
{
	if (year % 4 == 0) return true;
	return false;
}