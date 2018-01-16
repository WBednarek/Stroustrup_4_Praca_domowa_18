#include "stdafx.h"
#include "Praca_domowa_20.h"




void praca_domowa_20()
{
	string name = " ";
	int number = 0;
	vector<string> names;
	vector<int> numbers;



	cout << "Podaj parê imiê-liczba np. Jan 12" << endl;

	while (cin >> name >> number)
	{
		if (tolowercase(name) == "tokoniec" && number == 0)
		{
			break;
		}

		for (int i = 0; i < names.size(); ++i)
		{
			if (name == names[i])
			{
				//error("Imiê siê powrótzy³o"); // Drastical method
				cout << "B³ad, imiê siê powrótzy³o" << endl;
				return;
			}
		}

		if (name != " " && number != NULL)
		{
			names.push_back(name);
			numbers.push_back(number);
		}


	}

	for (int i = 0; i < names.size(); ++i)
	{
		cout << names[i] << "\t" << numbers[i] << endl;
	}

	cout << "Wprowadz imiê do znalezienia z listy" << endl;
	string input_name = " ";
	bool name_found = false;
	cin >> input_name;

	if (input_name != " ")
	{
		for (int i = 0; i < names.size(); ++i)
		{
			if (input_name == names[i])
			{
				cout << input_name << "\t" << numbers[i] << endl;
				name_found = true;
			}
				
		}


	}
	if (name_found == false)
	{
		cout << "Nie znaleziono takiego imienia" << endl;
	}



}