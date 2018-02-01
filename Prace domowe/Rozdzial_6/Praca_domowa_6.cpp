#include "stdafx.h"
#include "Praca_domowa_6.h"



Stream_of_string string_stream;

void praca_domowa_R6_6()
{
	cout << "English grammar application" << endl;

	string test = " ";
	bool result = false;
	while (cin)
	{
		string str = string_stream.get();
		
		if (str == "k") break;
		if (str == ";") cout << answer(result) << endl;
		else
		{
			string_stream.putback(str);
		}
		
		result = sentence();

	}


	//cout << "String stream is " << endl;

	/*bool t1 = true;
	bool t2 = false;

	cout << "BOOL GRAMMARR " << t1 * t2 << endl;*/

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


bool sentence()
{
	//if (noun() == false || conjunction1() == false || verb() == false) return false;
	bool is_sentence = false;
	bool left = noun();
	bool left_1 = verb();
	//string word = string_stream.get();
	if (left * left_1)
	{
		is_sentence = true;
		//word = string_stream.get();
		
	}
	//string_stream.putback(word);
	return is_sentence;
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
			word = string_stream.get();
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
			
		}
	word = string_stream.get();
	string_stream.putback(word);
	return is_verb;
}

bool conjunction1()
{
	string word = string_stream.get();
	vector<string> conj_set = { "and", "or", "but" };
	bool is_conj = false;
	for(string conj : conj_set)
	if (word == conj)
	{
		is_conj = true;
		word = string_stream.get();
	}
	string_stream.putback(word);
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

	return word;
}









string get_word()
{
	string word;
	cin >> word;

	return word;

}