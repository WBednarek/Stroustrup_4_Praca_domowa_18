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


	//Outer loop gives the possibility of not cheacking grammar anymore if the first miskake is found
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
		//Cleans input if show_result_symbol showed up in the inner loop. 
		//That function gives "tabula rasa" in the next line and only newly inputed values (sentence) in that new line will be considered for validation.
		//We are cleaning cin because we don't want to have old values in the next inner loop iterations.
		cin.ignore(INT_MAX, '\n'); //Skips number of INT_MAX symbols to the next line.
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

		bool conj = conjunction1(show_results_symbol);
		switch (conj) //Checks if we have we have conjunction
		{
		case true:
			is_sentence *= article() * noun() * verb();
			break;
		default:
			word = string_stream.get(); //In valid sentence (input line) we want to get show_result_symbol (e.g. ".")

			//conjunction1() function returned bad_conj information, there is no reson to validate sentence (input line) any longer
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

//Always has to be true and its functionality depends only on "the" article appearance in the sentence
//If sentence contains “the” article() function gets the next word - potential noun, otherwise function does practically nothing (it gest and puts back the same word)
bool article()
{
	string word = string_stream.get();
	if (word == "the" || word == "The")
	{
		word = string_stream.get(); //Gets the next word in sentence (after article)
	}
	string_stream.putback(word); //Stores the next word to be accessible for the next get() function usage (the function of our Stream_of_string class). 
	//We are using get() function almost everywhere, in every function on this program on unfortunately global object Stream_of_string string_stream.
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
			word = string_stream.get(); //Gets the next word in sentence (after noun)
			break;
		}
	string_stream.putback(word);
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
	//If the word is end line symbol there is no reason to validate conjunction since it is bad anyway
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

	//If still conjunction is not valid it puts back (stores) bad_conj value which will report sentence() about that
	//And if so (if conjunction is bad) there is no point to continue validation of whole inputted sentence, because it is bad according to Stroustrup PPP chapter 6.4.1 grammar assumptions
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
	//if (word == "") word = buffer; // I tried to do something when there is no symbols to get and function asks user for the next iput values.
	//That function shouldn't do that since user should input only values in the "main" ( praca_domowa_R6_6() ) function. 

	/*
	This bug description: when there is no any symbol at the end of the line in the inputted line (input A). 
	The program does not respond and gets stuck in verb() function (in our Stream_of_string class function) 
	because there are no more characters to get and it asks the user to input new (input B). 
	If the user does so then it continues in the sentence() function with previous input (input A) and validates it.
	*/
	 return word;
	
}

