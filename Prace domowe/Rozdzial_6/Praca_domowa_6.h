#include "../stdafx.h"
#include "../../../../../std_lib_facilities_v2.h"


void praca_domowa_R6_6();

string answer(bool ans);

bool sentence();

bool noun();

bool verb();

bool conjunction1(); // Problem with naming that function conjunction (is ambiguous)

string get_word();

class Stream_of_string
{
public:
	Stream_of_string();
	void putback(string word);
	string get();
private:
	string buffer;
	bool full;
};
