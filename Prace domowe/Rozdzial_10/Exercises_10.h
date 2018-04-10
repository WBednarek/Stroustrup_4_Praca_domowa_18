#pragma once
#include "../stdafx.h"
#include "../std_lib_facilities_v2.h"
#include "Point_10.h"

namespace Ex10
{

vector<Point> get_points(const string& communicate, char termination);

void clean_up_mess_10();

void ignore_10(const char termination);

void cwiczenia_10();

const char & termination_sign();

void save_inputted_data(const string& filename, vector<Point>& input_data);

vector<Point> read_inputted_data(const string& filename);

void compare_vectors(vector<Point>& first, vector<Point>& second);


}

