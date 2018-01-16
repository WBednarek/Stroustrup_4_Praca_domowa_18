#include "stdafx.h"
#include "Praca_domowa_11.h"


int number_of_smaller_numbers(int bigger, vector<int> & numbers)
{
	int smaller_numbers = 0;
	
		for (int i = 0; i < numbers.size(); ++i)
		{
			
			if (bigger > numbers.at(i))
			{
				++smaller_numbers;
			}
		}
	return smaller_numbers;
}

bool is_prime(int to_check, vector<int> & primes)
{
	int range = number_of_smaller_numbers(to_check, primes);
	bool is_prime = false;

	if (to_check == 2)
	{
		is_prime = true;
		return is_prime;
	}

	for (int i = 0; i < range; ++i)
	{
		//You need to just check if to_check number is divided without rest by a primes vector value only once
		if (to_check % primes.at(i) == 0)
		{
			is_prime = false;
			break;
		}
		else
		{
			is_prime = true;
		}
	}
	return is_prime;
}

template<typename T>
void display_vector(vector<T> & vec_to_display)
{
	for (int elem : vec_to_display)
	{
		cout << elem << " ";
	}
}

void praca_domowa_11()
{
	vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };

	vector<int> check_primes;

	for (int i = 1; i < 101; ++i)
	{
		if (is_prime(i, primes))
		{
			check_primes.push_back(i);
		}
	}

	cout << "Wektor z internetu: " << endl; 
	display_vector<int>(primes);
	cout << endl;
	cout << "Moj wektor: " << endl;
	display_vector<int>(check_primes);
	cout << endl;

}