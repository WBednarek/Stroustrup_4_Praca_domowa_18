
#include "stdafx.h"
#include "Praca_domowa_19.h"

string tolowercase(string tolower)
{
	for (int i = 0; i < tolower.length(); ++i)
	{
		if (tolower[i] < 97)
		{
			tolower[i] = tolower[i] + 32;
		}
	}

	return tolower;
}

void praca_domowa_19()
{
	string name = " ";
	int number = 0;
	vector<string> names;
	vector<int> numbers;

	cout << "Podaj par� imi�-liczba np. Jan 12" << endl;
	
	while (cin >> name >> number)
	{
		if (tolowercase(name) == "to koniec" && number == 0)
		{
			return;
		}

		for (int i = 0; i < names.size(); ++i)
		{
			if (name == names[i])
			{
				//error("Imi� si� powr�tzy�o"); // Drastical method
				cout << "B�ad, imi� si� powr�tzy�o" << endl;
				return;
			}
		}

		if(name != " " && number != NULL)
		{
			names.push_back(name);
			numbers.push_back(number);
		}
			

	}

	for (int i = 0; i < names.size(); ++i)
	{
		cout << names[i] << "\t" << numbers[i] << endl;
	}
	



}