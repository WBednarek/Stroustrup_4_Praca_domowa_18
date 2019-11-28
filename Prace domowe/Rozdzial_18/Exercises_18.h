#include "../stdafx.h"
#include "../std_lib_facilities_v2.h"

namespace Ex18
{


	struct X
	{
		int val;

		void out(const string& s, int nv)
		{
			cerr << this << "-->" << s << ": " << val << " (" << nv << ")\n";
		}
		X()
		{
			out("X()", 0);
			val = 0;
		}

		X(int v)
		{
			out("X(int)", v);
			val = v;
		}

		X(const X& x)
		{
			out("X(X&)", x.val);
			val = x.val;
		}

		X& operator=(const X& a)
		{
			out("X::operator=()", a.val);
			val = a.val;
			return *this;
		}

		~X()
		{
			out("~X()", 0);
		}
	};

	struct XX
	{
		X a;
		X b;
	};

	


	void drill_1();
	void drill_2();
	void exercise_1();
	void f(int tab[], int size);
	void copy(int first[], const int second[]);
	void fv(vector<int> vec);
}

namespace vec
{
	class vector
	{
		double* elem;
		int sz;
		void copy(const vector& v);
	public:
		vector();
		vector(int s) : sz(s), elem(new double[sz]) { }
		vector(const vector& v) : sz(v.sz), elem(new double[v.sz])
		{
			copy(v);
		}
		//double operator[](int n) { return elem[n]; } // wrong error: B³¹d	C2106	 "=": lewy operand musi byæ wartoœci¹ l	
		double& operator[](int n) { return elem[n]; }
		~vector() { delete[] elem; }
	};
}