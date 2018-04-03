#pragma once
#include "../stdafx.h"
#include "../std_lib_facilities_v2.h"

/*
Stroustrup PPP Chapter 9 
Exercise 1 for Date struct form chapter 9.4.1

*/

struct Date941
{
	int y;
	int m;
	int d;

};

void init_day(Date941& dd, int y, int m, int d);
void add_day(Date941& dd);
bool lapyear(int year);

