#include "../stdafx.h"
#include "../std_lib_facilities_v2.h"
//#include "../Tools.h"
#include <chrono>
#include <random>


struct Bulls_and_cows
{
	int bulls;
	int cows;

};

char read_letters(vector<char> & to_guess, vector<char> & letters, char program_finish_sign);

bool evaluate_user_input_word(vector<char>& to_guess, vector<char>& letters);

void start_game();

void praca_domowa_R6_8();

bool contains(char letter, vector<char>& letters);

vector<char> make_unique_val_vector(vector<char>& letters);

Bulls_and_cows cacluate_hits(vector<char>& to_check, vector<char>& checking);


void get_letter(vector<char> & letters);

template<typename T>
vector<T> display_vector1(vector<T> & to_display);

