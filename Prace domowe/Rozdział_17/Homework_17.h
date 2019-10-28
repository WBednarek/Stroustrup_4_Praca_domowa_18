#include "../stdafx.h"
#include "../std_lib_facilities_v2.h"


namespace Hw17
{
	class Link
	{
	public:
		string value;
		Link(const string& v, Link* p = 0, Link * s = 0) :
			value(v), prev(p), succ(s) {}
		Link* insert(Link* n);
		Link* add(Link* n);
		Link* erase();
		Link* find(const string& s);
		Link* Link::find_rev(const string& s);
		Link* advance(int n) ;
		Link* Link::move(int n);

		Link* next() const { return succ; }
		Link* previous() const{ return prev; }
		
	private:
		Link* prev;
		Link* succ;
	};


	void homework_17();
	void hw_1_2();
	void to_lower(char* s);
	ostream& print_array(ostream& os, const char* arr);
	void hw3();
	char* strup(const char*);
	int get_array_len(const char* arr);
	void hw4();
	const char* findx(const char* s, const char* x);
	void hw5();
	void hw6();
	Link* insert(Link* p, Link* n);

}
