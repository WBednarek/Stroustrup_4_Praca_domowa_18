#include "stdafx.h"
#include "MyDate.h"

//For Date struct form chapter 9.4.3 and 9.7.1
ostream& operator<<(ostream& os, Date974::Date& d)
{
	return os << "(" << d.year() 
		<< ", " << d.month() << ", " 
		<< d.day() << ")";

}


//For Date struct form chapter 9.4.1 and 9.4.2
//ostream& operator<<(ostream& os, Date942::Date& d)// change for Date942::Date& d) for Date941 struct
//{
//	return os << "(" << d.y
//		<< ", " << d.m << ", "
//		<< d.d << ")";
//
//}

void cwiczenia_9()
{

	////Date form chapter 9.7.4
	try {
		Date974::Date today(Date974::Year(2181), Date974::Date::Month(2), 28);
		Date974::Date tomorrow = today;
		tomorrow.add_day(1);
		tomorrow.add_month(1);
		tomorrow.add_year(1);


		cout << "Today is: " << today << endl;
		cout << "Tomorrow is: " << tomorrow << endl;
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
	}


	////Date form chapter 9.7.1
	/*try {
		Date971::Date today(Date971::Year(2016), Date971::Date::Month(2), 28);
		Date971::Date tomorrow = today;
		tomorrow.add_day(1);


		cout << "Today is: " << today << endl;
		cout << "Tomorrow is: " << tomorrow << endl;
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
	}*/



	////Date form chapter 9.4.3
	/*try {
		Date943::Date today(2012, 13, 3);
		Date943::Date tomorrow = today;
		tomorrow.add_day(1);


		cout << "Today is: " << today << endl;
		cout << "Tomorrow is: " << tomorrow << endl;
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
	}*/


	////Date form chapter 9.4.2
	/*try {
		Date942::Date today(2012, 2, 29);
		Date942::Date tomorrow = today;
		tomorrow.add_day(1);


		cout << "Today is: " << today << endl;
		cout << "Tomorrow is: " << tomorrow << endl;
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
	}*/



	//Date form chapter 9.4.1
	//try {
	//	
	//	Date941::Date today;
	//	init_day(today, 2016, 2, 29);
	//	Date941::Date tomorrow = today;
	//	add_day(tomorrow);

	//	cout << "today is: " << today << endl;
	//	cout << "tomorrow is: " << tomorrow << endl;
	//}
	//catch (exception& e)
	//{
	//	cerr << e.what() << endl;
	//}
	
	

}


MyDate::MyDate()
{
}


MyDate::~MyDate()
{
}
