#include "stdafx.h"
#include "MyDate.h"

//For Date struct form chapter 9.4.3
ostream& operator<<(ostream& os, Date943::Date& d)
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

	////Date form chapter 9.4.3
	try {
		Date943::Date today(2012, 13, 3);
		Date943::Date tomorrow = today;
		tomorrow.add_day(1);


		cout << "Today is: " << today << endl;
		cout << "Tomorrow is: " << tomorrow << endl;
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
	}


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
