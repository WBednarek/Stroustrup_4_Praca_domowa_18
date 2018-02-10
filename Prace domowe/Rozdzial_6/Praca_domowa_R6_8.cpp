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
	vector<char> my_word = { 'd', 'a', 'r', 'o' };
	cout << "Gues the word only english letters are accepted\nmaximun number of letters is " << my_word.size() << endl;
	cout << "All characters after 4th will be ignored" << endl;
	
	while (true)
	{
		char test = ' ';
		int letters_counter = 0;
		vector<char> letters;
		bool wrong_letters_num = false;
		if (test == '.') break;
		while (letters_counter != my_word.size())
		{
			++letters_counter;
			if (letters_counter > my_word.size()) 
			{	
				wrong_letters_num = true; 
				break; 
			}
			cin >> test;
			if (test == '.') break;
			cin.putback(test);
			get_letter(letters);		
		}
		if (wrong_letters_num)
		{
			cout << "Wrong length of input, try again" << endl;
		}
		else
		{
			Bulls_and_cows b_and_c = cacluate_hits(my_word, letters);
			if (b_and_c.bulls == my_word.size())
			{
				cout << "Bravo you guessed" << endl;
				break;
			}
			else
			{
				cout << "Considered input word: \"" << letters << "\"" << endl;
				cout << "Bull " << b_and_c.bulls << " Cow " << b_and_c.cows << endl;
				cin.ignore(INT_MAX, '\n');
			}
		}
		

	}


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