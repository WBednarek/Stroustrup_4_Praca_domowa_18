#include "stdafx.h"
#include "MyDate.h"

//
//template<typename T>
//ostream& operator<<(ostream& os, T& d)
//{
//	return os << "(" << d.year() 
//		<< ", " << d.month() << ", " 
//		<< d.day() << ")";
//
//}
//

ostream& operator<<(ostream& os, Date941& d)
{
	return os << "(" << d.y
		<< ", " << d.m << ", "
		<< d.d << ")";

}

void cwiczenia_9()
{
	try {
		//Date form chapter 9.4.1
		Date941 today;
		init_day(today, 2016, 13, -5);
		Date941 tomorrow = today;
		add_day(tomorrow);

		cout << "Today is: " << today << endl;
		cout << "Tomorrow is: " << tomorrow << endl;
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
	}

	

}


MyDate::MyDate()
{
}


MyDate::~MyDate()
{
}
