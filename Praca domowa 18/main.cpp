// Praca domowa 18.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../../../../std_lib_facilities_v2.h"
#include "Praca_domowa_11.h"
#include "Praca_domowa_19.h"
#include "Praca_domowa_20.h"
#include "Praca_domowa_21.h"



void praca_domowa_18()
{
	double a, b, c;
	double x1 = 0.0;
	double x2 = 0.0;
	double delta = 0.0;

	cout << "Rozwi�zwyanie r�wnania kwadratowego  ax^2 + bx + c = 0 " << endl << "Podaj wsp�czynniki a, b i c" << endl;

	cin >> a >> b >> c;
	cout << "Wsp�czynniki a = " << a << ", b = " << b << ", c = " << c << endl;

	delta = (b*b) - 4 * a*c;

	cout << "Delta = " << delta << endl;

	if (delta > 0)
	{
		x1 = (-b + sqrt(delta)) / (2 * a);
		x2 = (-b - sqrt(delta)) / (2 * a);

		cout << "Detla > 0 wi�c jak w liceum r�wnanie ma dwa rozwi��ania x1 = " << x1 << " i x2 = " << x2 << endl;
	}
	else if (delta == 0)
	{
		x1 = -b / (2 * a);
		cout << "Detla = 0 wi�c jak w liceum r�wnanie ma jendno rozwi��anie " << x1 << endl;
	}
	else
	{
		cout << "R�wnanie nie ma rozwi�za� w dziedzinie liczb Rzeczywistych" << endl;
	}

}

int main()
{

	system("chcp 1250");
	praca_domowa_11();
	//praca_domowa_18();
	//praca_domowa_19();
	//praca_domowa_20();
	 //praca_domowa_21();

	 
	system("pause");

    return 0;
}

