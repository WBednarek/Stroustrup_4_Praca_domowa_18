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
*/

#include "stdafx.h"
#include "../../../../std_lib_facilities_v2.h"
#include "Rozdzial_6\cwiczenia_6.h"
#include "Rozdzial_6\Wyprobuj_6_9.h"



int main()
{

	system("chcp 1250");
	

	cwiczenia_6_1();
	//wyproboj_6_9();
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

	system("pause");

    return 0;
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