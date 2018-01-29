#include "stdafx.h"
#include "Tools.h"


template<typename T>
void display_vector(vector<T> & to_disp)
{
	for (T disp : to_disp)
	{
		cout << disp << " ";
	}
}


string tolowercase(string tolower)
{
	for (int i = 0; i < tolower.length(); ++i)
	{
		if (tolower[i] < 97)
		{
			tolower[i] = tolower[i] + 32;
		}
	}

	return tolower;
}


template<typename T>
bool compare_vectors(vector<T> & v1, vector<T> & v2)
{
	bool are_the_same = false;
	if (v1.size() != v2.size())
	{
		are_the_same = false;
		return are_the_same;
	}

	for (int i = 0; i < v1.size(); ++i)
	{
		if (v1.at(i) == v2.at(i))
		{
			are_the_same = true;
		}
		else
		{
			are_the_same = false;
		}
	}
	return are_the_same;

}