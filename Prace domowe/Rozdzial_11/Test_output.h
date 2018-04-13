#pragma once
#include "../stdafx.h"
#include "../std_lib_facilities_v2.h"


namespace Ex11
{

	void cwiczenia_11();
	void exercises_1_to_7();
	void exercise_8();
	void exercise_9();
	void exercise_10();

	void display_table(const vector<string>& names_vec, const vector<string>& surnames_vec,const vector<string>& phone_numbers_vec,const vector<string>& emails_vec);


	class Test_output
	{
	public:
		Test_output();
		~Test_output();

	private:
		int birth_year;
	};

}
