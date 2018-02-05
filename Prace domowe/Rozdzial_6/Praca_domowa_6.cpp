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


	while (true)
	{
		while (cin)
		{
			str = string_stream.get();

			if (str == finish_symbol) break;
			if (str == show_result_symbol)
			{
				cout << answer(result) << endl;
				//cin.ignore(INT_MAX);
				break;
			}
			else
			{
				string_stream.putback(str);
			}

			result = sentence(show_result_symbol);
			/*if (str == show_result_symbol)
			{
				
			}*/
		}
		if (str == finish_symbol) break;
		cin.ignore(INT_MAX, '\n');
		

	}

	

	/*
	
	if (str == finish_symbol) break;
	cin.ignore(INT_MAX);

	}
	*/




		/*
		if (str != show_result_symbol)
		{

		}
*/
	
		
		


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


bool sentence(string show_results_symbol)
{
	//if (noun() == false || conjunction1() == false || verb() == false) return false;
	bool first_loop = true;
	string bad_conj = "badconjunction";
	//bool left = noun();
	//bool left_1 = verb();
	bool is_sentence = noun() * verb();
	string word ="";
	while (true)
	{
		
		bool left_2 = conjunction1(show_results_symbol);
		//bool small_sentence = left * left_1;
		
		//if (word == ";") return is_sentence;
		switch (left_2)
		{
		case true:
			/*bool left = noun();
			bool left_1 = verb();*/
			is_sentence *= noun() * verb();
			first_loop = false;
			//word = string_stream.get();
			//is_sentence = small_sentence;
			//is_sentence *= small_sentence;
			//word = string_stream.get();
			break;
		default:
			word = string_stream.get();
			if (word == bad_conj)
			{
				string_stream.putback(show_results_symbol);
				return false;
				break;
			}
			else
			{
				string_stream.putback(word);
				return is_sentence;
				break;
			}
			


			//
			//word = string_stream.get();
			//string_stream.putback(word);
			/*if (first_loop)
			{
				return is_sentence;
			}
			else
			{
				first_loop = false;
				return is_sentence;
			}*/
			
			
			//if (small_sentence && counter == 1)
			//{
			//	//word = string_stream.get();
			//	is_sentence = true;
			//	string_stream.putback(word);
			//}
			//else
			//{
			//	//word = string_stream.get();
			//	is_sentence = false;
			//	string_stream.putback(word);
			//}


			//is_sentence = false;
			//string_stream.putback(word);
			

			/*
			if (small_sentence  && word == ";")
			{
				is_sentence = true;
				string_stream.putback(word);
				break;
			}
			else
			{
				is_sentence = false;
				string_stream.putback(word);
				break;
			}
			
			*/
			

		}
	}
		
	
	


	/*

	if (small_sentence * left_2)
	{
		sentence();
		is_sentence = true;
	}
	else if (small_sentence && word == ";")
	{
		is_sentence = true;
		string_stream.putback(word);
	
	
	else
	{
		is_sentence = false;
		string_stream.putback(word);
	}

	}*/
	//string_stream.putback(word);

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

	//Putsback value that reports an input word is dirrent than words in the conj_set vector,
	//That value will inform that there is no point to continue validation
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
	//if (word == "") word = buffer;
	 return word;
	
}

