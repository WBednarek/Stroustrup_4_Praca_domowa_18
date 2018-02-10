#include "../stdafx.h"
#include "../../../../../std_lib_facilities_v2.h"
//#include "../Tools.h"


struct Bulls_and_cows
{
	int bulls;
	int cows;

};

void praca_domowa_R6_8();

bool contains(char letter, vector<char>& letters);

vector<char> make_unique_val_vector(vector<char>& letters);

Bulls_and_cows cacluate_hits(vector<char>& to_check, vector<char>& checking);


void get_letter(vector<char> & letters);

template<typename T>
vector<T> display_vector1(vector<T> & to_display);

