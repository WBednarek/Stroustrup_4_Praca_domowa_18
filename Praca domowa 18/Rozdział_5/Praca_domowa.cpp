#include "stdafx.h"
#include "Praca_domowa.h"


void praca_domowa_8()
{

	vector<int> input_vector;
	int input_val = 0;


	cout << "Podaj liczby do wektora" << endl;
	while (cin >> input_val)
	{
		if (input_val == 0)
		{
			break;
		}
		input_vector.push_back(input_val);

	
	}

	cout << "Ile pocz¹tkowych liczb zsumowaæ?" << endl;

	int num_of_numbers_to_sum = 0;
	cin >> num_of_numbers_to_sum;

	if (num_of_numbers_to_sum > input_vector.size() || num_of_numbers_to_sum < 0)
	{
		error("To big input number or value is less than 0");
	}
	int sum = 0;
	for (int i = 0; i < num_of_numbers_to_sum; ++i) 
	{
		sum += input_vector[i];

	}
	cout << "Suma " << num_of_numbers_to_sum << " pocz¹tkowych liczb wektora wynosi: " << sum << endl;

}
