#include "stdafx.h"
#include "Praca_domowa_R6_8.h"

template<typename T>
ostream & operator<< (ostream & output, vector<T> & to_disp)
{
	for (T disp : to_disp)
	{
		output << disp;
	}
	return output;
}

template<typename T>
vector<T> display_vector1(vector<T> & to_display)
{
	return to_display;
}



void praca_domowa_R6_8()
{

	cout << "Gues the word only english letters are accepted\nmaximun number of letters is " << endl;
	cout << "All characters after 4th will be ignored" << endl;
	start_game();

}


template<typename T>
vector<T> random_vector()
{
	//In ASCII a-z letters are numerically 97-122.
	int a_ASCII = 97;
	int z_ASCII = 122;

	unsigned word_to_guess_length = 4;
	vector<T> random_vector(word_to_guess_length);
	
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);
	uniform_int_distribution<int> dist(a_ASCII, z_ASCII);

	for (int i = 0; i < word_to_guess_length; ++i)
	{	
		random_vector[i] = dist(generator);
	}
	
	return random_vector;
}

void start_game()
{
	vector<char> my_word = random_vector<char>();
	cout << "Random vector: " << my_word << endl;
	char program_finish_sign = '.';
	while (true)
	{
		vector<char> letters;
		char last_letter = read_letters(my_word, letters, program_finish_sign); //Stores input in a vector. Returns actual character and checks if it is '.' which finishes a program.

		if (last_letter == program_finish_sign) break;
		else
		{
			bool finish = evaluate_user_input_word(my_word, letters); //Check user input accuracy with word to find.
			if (finish) break;
		}
	}
}


char read_letters(vector<char> & to_guess, vector<char> & letters, char program_finish_sign)
{
	char test = ' ';
	int letters_counter = 0;

	while (letters_counter != to_guess.size())
	{
		++letters_counter;
		cin >> test;
		if (test == program_finish_sign) break;
		cin.putback(test);
		get_letter(letters);
	}
	return test;
}

bool evaluate_user_input_word(vector<char> & to_guess, vector<char> & letters)
{
	bool is_word_found = false;
	Bulls_and_cows bulls_and_cows = cacluate_hits(to_guess, letters);

	if (bulls_and_cows.bulls == to_guess.size())
	{
		cout << "Bravo you guessed!" << endl;
		is_word_found = true;
	}
	else
	{
		cout << "Considered input word: \"" << letters << "\"" << endl;
		cout << "Bull " << bulls_and_cows.bulls << " Cow " << bulls_and_cows.cows << endl;
		cin.ignore(INT_MAX, '\n');
	}

	return is_word_found;
}


bool contains(char letter, vector<char> & letters)
{
	bool is_contain = false;
	for (int i = 0; i < letters.size(); ++i)
	{
		if (letter == letters[i])
		{
			is_contain = true;
			break;
		}
	}
	return is_contain;
}

vector<char> make_unique_val_vector(vector<char> & letters)
{
	vector<char> unique_val;
	unique_val.push_back(letters[0]);
	for (int i = 1; i < letters.size(); ++i)
	{
		if (!contains(letters[i], unique_val))
		{
			unique_val.push_back(letters[i]);
		}
	}

	return unique_val;
}

Bulls_and_cows cacluate_hits(vector<char> & to_check, vector<char> & checking)
{
	if (to_check.size() != checking.size()) error("Size of input stream mismatch with size of the word to check");
	Bulls_and_cows bulls_and_cows;
	bulls_and_cows.bulls = 0;
	bulls_and_cows.cows = 0;

	//Calculate bulls
	for (int i = 0; i < to_check.size(); ++i)
	{
		if (to_check.at(i) == checking.at(i)) ++bulls_and_cows.bulls;
	}
	vector<char> unique_values = make_unique_val_vector(checking);

	//Calculate cows
	for (int i = 0; i < unique_values.size(); ++i)
	{
		for (int j = 0; j < to_check.size(); ++j)
		{
			if (unique_values.at(i) == to_check.at(j)) ++bulls_and_cows.cows;
		}
	}

	bulls_and_cows.cows -= bulls_and_cows.bulls;

	return bulls_and_cows;

}


void get_letter(vector<char> & letters)
{
	char letter = ' ';
	cin >> letter;
	switch (letter)
	{
		case 'a': case 'A': case 'b': case 'B': case 'c': case 'C': case 'd': case 'D':
		case 'e': case 'E': case 'f': case 'F': case 'g': case 'G': case 'h': case 'H':
		case 'i': case 'I': case 'j': case 'J': case 'k': case 'K': case 'l': case 'L':
		case 'm': case 'M': case 'n': case 'N': case 'o': case 'O': case 'p': case 'P':
		case 'q': case 'Q': case 'r': case 'R': case 's': case 'S': case 't': case 'T':
		case 'u': case 'U': case 'v': case 'V': case 'w': case 'W': case 'y': case 'Y':
		case 'z': case 'Z':
		{
			letters.push_back(letter);
			break;

		}
		default:
		{
			error("Letter not found");
			break;
		}
	}

}