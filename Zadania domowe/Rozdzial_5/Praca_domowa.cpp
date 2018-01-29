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

/**
@param input - number to be split into separate digits
@param numbers - vector stores digits from input
Splitting an input number into separate digits stored in a vector
*/
void factorize_number(vector<int> & numbers, int input)
{
	if (input < 0) { input = -input; }
	numbers.resize(number_of_digits(input));
	unsigned int division_coef = 1;
	unsigned int number_length = numbers.size();
	for (int i = 1; i <= number_length; ++i)
	{
		numbers[number_length - i] = (input / division_coef) % 10;
		division_coef *= 10;
	}
}

template<typename T>
bool vector_contains(vector<T> & input, T number)
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
	unsigned int number_to_guess = 2645;
	vector<int> fact_number_to_guess(number_of_digits(number_to_guess));
	factorize_number(fact_number_to_guess, number_to_guess);
	unsigned int krowa_count = 0;
	unsigned int byk_count = 0;

	vector<int> occured_number;
	vector<int> trimmed_vector;
	//Loop breaks if whole number is properly guessed
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

		//Trimmed vector has only unique value, there are no doubled values in it
		trimmed_vector = make_unique_numbers_vector(user_numbers);
		//Finding Right digit on the right positions
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

		// Subtracting from all found digits occurances (in vector which you have to guess), properly find with proper position occurances 
		krowa_count -= byk_count;
		cout << byk_count << " byk i " << krowa_count << " krowa"<< endl;
	}
	
	

	cout << "Brawo odgad³eœ!" << endl;
	

	
}



/**
Praca domowa 13
*/



void praca_domowa_13()
{

	vector<int> test1;
	int numer = -23234;
	factorize_number(test1, numer);
	cout << "factorized number " << numer << endl;
	display_vector(test1);

	unsigned int input = 0;
	int seed = 0;
	cout << "Hello!\nGuess number from a ragne 1000 to 9999" << endl;
	//cout << "Input seed for random generator" << endl;
	//cin >> seed;
	//srand(seed);
	unsigned int number_to_guess = randint(1000,9999);
	cout << "RAND num is " << number_to_guess << endl;;
	//vector<int> fact_number_to_guess(number_of_digits(number_to_guess));
	vector<int> fact_number_to_guess;
	factorize_number(fact_number_to_guess, number_to_guess);
	unsigned int krowa_count = 0;
	unsigned int byk_count = 0;

	vector<int> occured_number;
	vector<int> trimmed_vector;
	cout << "Input your number form 1000 to 9999" << endl;
	bool is_over = false;
	//Loop breaks if whole number is properly guessed
	while (byk_count != 4 && cin >> input)
	{
		byk_count = 0;
		krowa_count = 0;
		
		vector<int> user_numbers;
		factorize_number(user_numbers, input);
		if (input == 0)
		{
			cout << "This is the end" << endl;
			break;
		}
		if (input < 1000 || input > 9999)
		{
			error("Input value in bigger than 9999 or less than 1000");
		}

		

		//Trimmed vector has only unique value, there are no doubled values in it
		trimmed_vector = make_unique_numbers_vector(user_numbers);
		//Finding right digit on the right positions
		for (int i = 0; i < user_numbers.size(); ++i)
		{
			if (user_numbers[i] == fact_number_to_guess[i])
			{
				++byk_count;
			}
			//Counting all occurances of the inputed digits in the vector to guess by user
			for (int j = 0; j < trimmed_vector.size(); ++j)
			{
				if (trimmed_vector[j] == fact_number_to_guess[i])
				{
					++krowa_count;
				}
			}
		}

		// Subtracting from all found digits occurances (in vector which you have to guess), properly find with proper position occurances 
		krowa_count -= byk_count;
		if (byk_count == 4) is_over = true;
		cout << byk_count << " byk i " << krowa_count << " krowa" << endl;
		cout << "Input your number form 1000 to 9999" << endl;
	}


	if (is_over) { cout << "Brawo odgad³eœ!\nKolejna runda" << endl; praca_domowa_13(); }
	
	




}
