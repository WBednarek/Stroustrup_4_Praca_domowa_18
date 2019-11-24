// Praca domowa 18.cpp : Defines the entry point for the console application.

/*
#include "Praca_domowa_5.h"
#include "Praca_domowa_11.h"
#include "Praca_domowa_19.h"
#include "Praca_domowa_20.h"
#include "Praca_domowa_21.h"
#include "Rozdzial_5\Praca_domowa.h"
#include "Rozdzial_5\Wypróbuj_Rozdzia³_5.h"
#include "Rozdzial_6\Wypróbuj_6_6_original.h"
#include "Rozdzial_6\cwiczenia_6.h"
#include "Rozdzial_6\Wyprobuj_6_9.h"
#include "Rozdzial_6\Praca_domowa_6.h"
#include "Rozdzial_6\Praca_domowa_R6_8.h"
#include "Rozdzial_6\Praca_domowa_R6_10.h"
#include "Rozdzial_6\Praca_domowa_R6_10_v2.h"
#include "Rozdzial_7\cwiczenia_7.h"
#include "Rozdzial_7\Praca_domowa_4\Rodzial_7_Praca_domowa_4.h"
#include "Rozdzial_8\use.h"
#include "Rozdzial_9\MyDate.h"
#include "Rozdzial_10\Exercises_10.h"
#include "Rozdzial_11\Test_output.h"
*/

#include "stdafx.h"
#include "std_lib_facilities_v2.h"
#include "Rozdzial_12\Exercises_12.h"
#include "Rozdzia³_17/Exercises_17.h"
#include "Rozdzia³_17/Homework_17.h"
#include "Rozdzial_18/Exercises_18.h"



int main()
{
	try {
		system("chcp 1250");
		Ex18::drill_2();
		system("pause");
		
	}

	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		return 1; 
	}
	catch (...) {
		cerr << "exception\n";
		return 2; 
	}
	return 0;

	

	/**
	Rodzia³ 17
	Hw17::homework_17();
	Ex17::cwiczenia_17_part2();
	Ex17::cwiczenia_17_part1();


	Rozdzia³ 12
	Ex12::cwiczenia_12();


	Rozdia³ 11
	Ex11::cwiczenia_11();

	Rozdzia³ 10
	Ex10::cwiczenia_10();

	Rodzia³ 9
	cwiczenia_9();

	Rodzia³ 8
	cwiczenia_8();

	Rozdzia³ 7
	praca_domowa_R7_4();
	//cwiczenia_7();


	Rozdzia³ 6
	//praca_domowa_R6_8();
	//praca_domowa_R6_6();
	//cwiczenia_6_1();
	//wyproboj_6_9();
	//calculate();
	*/
	

	//praca_domowa_13();
	//praca_domowa_12();
	//praca_domowa_8();
	//wyproboj_5_10_1(1231243, 20001290);
	//wyproboj_5_7();
	//wyproboj_5_6_3();
	//f(4, 3, 5);
	//wyproboj_5_3_2();
	//praca_domowa_5();
	//praca_domowa_11();
	//praca_domowa_18();
	//praca_domowa_19();
	//praca_domowa_20();
	 //praca_domowa_21();


}





void praca_domowa_18()
{
	double a, b, c;
	double x1 = 0.0;
	double x2 = 0.0;
	double delta = 0.0;

	cout << "Rozwi¹zwyanie równania kwadratowego  ax^2 + bx + c = 0 " << endl << "Podaj wspó³czynniki a, b i c" << endl;

	cin >> a >> b >> c;
	cout << "Wspó³czynniki a = " << a << ", b = " << b << ", c = " << c << endl;

	delta = (b*b) - 4 * a*c;

	cout << "Delta = " << delta << endl;

	if (delta > 0)
	{
		x1 = (-b + sqrt(delta)) / (2 * a);
		x2 = (-b - sqrt(delta)) / (2 * a);

		cout << "Detla > 0 wiêc jak w liceum równanie ma dwa rozwi¹¿ania x1 = " << x1 << " i x2 = " << x2 << endl;
	}
	else if (delta == 0)
	{
		x1 = -b / (2 * a);
		cout << "Detla = 0 wiêc jak w liceum równanie ma jendno rozwi¹¿anie " << x1 << endl;
	}
	else
	{
		cout << "Równanie nie ma rozwi¹zañ w dziedzinie liczb Rzeczywistych" << endl;
	}

}