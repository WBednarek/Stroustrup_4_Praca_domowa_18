#include "stdafx.h"
#include "Praca_domowa_6.h"



Stream_of_string string_stream;

void praca_domowa_R6_6()
{
	cout << "English grammar application" << endl;

	string test = " ";
	bool result = false;
	string finish_symbol = "k";
	string show_result_symbol = ".";
	string str ="";


	//Outer loop for the possibility of not cheacking grammar no more when the first miskake is found
	while (true)
	{
		while (cin)
		{
			str = string_stream.get();

			if (str == finish_symbol) break;
			if (str == show_result_symbol)
			{
				cout << answer(result) << endl;
				break;
			}
			else
			{
				string_stream.putback(str);
			}

			result = sentence(show_result_symbol);
		}

		if (str == finish_symbol) break; //Exit program
		//Cleans input if show_result_symbol showed up in the inner loop. Skips number of INT_MAX symbols to the next line.
		cin.ignore(INT_MAX, '\n'); 
	}
}

string answer(bool ans)
{
	if (ans == true)
	{
		return "Dobrze";
	}
	else
	{
		return "le";
	}
		
}


bool sentence(string show_results_symbol)
{
	string bad_conj = "badconjunction";
	bool is_sentence = article() * noun() * verb(); //'+' is logical or, '*' is logical and
	string word ="";
	while (true)
	{

		bool left_2 = conjunction1(show_results_symbol);
		switch (left_2) //Do we have conjunction?
		{
		case true:
			is_sentence *= article() * noun() * verb();
			break;
		default:
			word = string_stream.get(); //In valid sentence we want to get show_result_symbol (e.g. ".")

			//conjunction1() function returned bad_conj information, there is no reson to validate input longer
			if (word == bad_conj)
			{
				string_stream.putback(show_results_symbol);
				return false;
				break;
			}
			//Final return - shows if sentence is valid
			else
			{
				string_stream.putback(word);
				return is_sentence;
				break;
			}
		}
	}


}

bool article()
{
	string word = string_stream.get();
	//bool is_preposition = false;
	if (word == "the" || word == "The")
	{
		//is_preposition = true;
		word = string_stream.get(); //Gets the next word in input line (after article)
	}
		string_stream.putback(word);
	
	return true;
}


bool noun()
{
	string word = string_stream.get();
	vector<string> noun_set = { "birds", "fish", "C++" };
	bool is_noun = false;
	for (string noun : noun_set)
		if (word == noun)
		{
			is_noun = true;
			word = string_stream.get(); //Gets the next word in input line (after noun)
			break;
		}
	string_stream.putback(word); //Stores the next word to be accessible using for the next get() function usage (function of our Stream_of_string class) 
	return is_noun;
}

bool verb()
{
	string word = string_stream.get();
	vector<string> verb_set = { "rules", "fly", "swim" };
	bool is_verb = false;
	for (string verb : verb_set)
		if (word == verb)
		{
			is_verb = true;
			word = string_stream.get();
			break;
			
		}

	string_stream.putback(word);
	return is_verb;
}


bool conjunction1(string show_results_symbol)
{
	string word = string_stream.get();
	string bad_conj = "badconjunction";
	//If the word is end line symbol there is no reason to validate conjunction since is bad anyway
	if (word == show_results_symbol)
	{
		string_stream.putback(word);
		return false;
	}

	bool is_conj = false;
	vector<string> conj_set = { "and", "or", "but" };	
	for(string conj : conj_set)
	if (word == conj)
	{
		is_conj = true;
		word = string_stream.get();
		break;
	}

	//
	//If still conjunction is not valid it puts back bad_conj value which reports about that 
	//And if so (if conjunction is bad) there is no point to continue validation of whole inputted sentence, because it is bad according to our grammar assumptions
	//That value will inform sentence() function about that
	if (!is_conj)
	{
		string_stream.putback(bad_conj);
	}
		
	else
	{
		string_stream.putback(word);
	}
	
	return is_conj;

}

Stream_of_string::Stream_of_string() : full(false)
{
}

void Stream_of_string::putback(string word)
{
	if (full) error("Call putback() function then buffer is full");
	buffer = word;
	full = true;
}

string Stream_of_string::get()
{
	if (full)
	{
		full = false;
		return buffer;
	}
	string word;
	cin >> word;
	//if (word == "") word = buffer; // I tried to do something when there is no symbols to get
	 return word;
	
}

