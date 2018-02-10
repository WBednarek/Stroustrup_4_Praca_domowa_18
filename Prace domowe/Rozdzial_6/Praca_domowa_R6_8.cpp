#include "stdafx.h"
#include "Praca_domowa_R6_8.h"

template<typename T>
ostream & operator<< (ostream & output, vector<T> & to_disp)
{
	for (T disp : to_disp)
	{
		output << disp << " ";
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

	char test = ' ';
	vector<char> letters;

	while (cin >> test)
	{
		if (test == '.') break;
		cin.putback(test);
		get_letter(letters);
		
	}

	cout << "Vector contains " << display_vector1(letters) << endl;

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