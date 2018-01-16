#include "stdafx.h"
#include "Praca_domowa_5.h"


void praca_domowa_5()
{
	string operation = " ";
	double first_number = 0.0;
	double second_number = 0.0;
	cin  >> first_number >> second_number >> operation;
	if (operation == "+")
	{
		cout << "Suma liczb " << first_number << " i " << second_number << " wynosi " << first_number + second_number << endl;
	}
	if (operation == "-")
	{
		cout << "Ró¿nica liczb " << first_number << " i " << second_number << " wynosi " << first_number - second_number << endl;
	}
	if (operation == "*")
	{
		cout << "Iloczyn liczb " << first_number << " i " << second_number << " wynosi " << first_number * second_number << endl;
	}
	if (operation == "/")
	{
		cout << "Wynik dzielenia liczb " << first_number << " i " << second_number << " wynosi " << first_number / second_number << endl;
	}

	if (operation == "plus")
	{
		cout << "Suma liczb " << first_number << " i " << second_number << " wynosi " << first_number + second_number << endl;
	}
	if (operation == "minus")
	{
		cout << "Ró¿nica liczb " << first_number << " i " << second_number << " wynosi " << first_number - second_number << endl;
	}
	if (operation == "mno")
	{
		cout << "Iloczyn liczb " << first_number << " i " << second_number << " wynosi " << first_number * second_number << endl;
	}
	if (operation == "dziel")
	{
		cout << "Wynik dzielenia liczb " << first_number << " i " << second_number << " wynosi " << first_number / second_number << endl;
	}

}
