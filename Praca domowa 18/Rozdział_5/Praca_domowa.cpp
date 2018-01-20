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

/**
Praca domowa 12
*/


int number_of_digits(int number)
{
	unsigned int number_of_digits = 0;
	unsigned int base = 10;
	do {
		++number_of_digits;
		number /= base;
	} while (number);
	return number_of_digits;
}

void factorize_number(vector<int> & numbers, unsigned int input)
{
	unsigned int division_coef = 1;
	unsigned int number_length = numbers.size();
	for (int i = 1; i <= number_length; ++i)
	{
		numbers[number_length - i] = (input / division_coef) % 10;
		division_coef *= 10;
	}
}


bool vector_contains(vector<int> & input, int number)
{
	bool contains = false;
	for (int i : input)
	{
		if (i == number) contains = true;
	}
	return contains;
}

template<typename T>
vector<T> make_unique_numbers_vector(vector<T> & input)
{
	vector<T> output;
	for (unsigned int i = 0; i < input.size(); ++i)
	{
		if (!vector_contains(output, input[i]))
		{
			output.push_back(input[i]);
		}
	}
	return output;

}

void praca_domowa_12()
{

	unsigned int input = 0;
	unsigned int number_to_guess = 6557;
	vector<int> fact_number_to_guess(number_of_digits(number_to_guess));
	factorize_number(fact_number_to_guess, number_to_guess);
	unsigned int krowa_count = 0;
	unsigned int byk_count = 0;

	
	bool number_occured = false;
	vector<int> occured_number;
	
	int start_counter = 0;
	vector<int> trimmed_vector;
	while (byk_count != 4 && cin >> input)
	{
		byk_count = 0;
		krowa_count = 0;
		cout << "Input your number form 1000 to 9999" << endl;
		vector<int> user_numbers(number_of_digits(input));
		factorize_number(user_numbers, input);
		if (input < 1000 || input > 9999)
		{
			error("Input value in bigger than 9999 or less than 1000");
		}
		trimmed_vector = make_unique_numbers_vector(user_numbers);
	
		for (int i = 0; i < user_numbers.size(); ++i)
		{
			if (user_numbers[i] == fact_number_to_guess[i])
			{
				++byk_count;
			}		
			//Counting all occurances of the inputed digits in the vector to guess by user
			for (int j = 0; j < trimmed_vector.size(); ++j)
			{
				if ( trimmed_vector[j] == fact_number_to_guess[i])
				{
					++krowa_count;
				}
			}
		}

		// Subtracting from all digit occurance, properly guessed occurances
		krowa_count -= byk_count;
		cout << byk_count << " byk i " << krowa_count << " krowa"<< endl;
	}
	
	

	cout << "Brawo odgad³eœ!" << endl;
	

	
}
