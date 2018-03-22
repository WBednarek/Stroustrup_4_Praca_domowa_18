#pragma once
#include "../../stdafx.h"
#include "../../std_lib_facilities_v2.h"
#include "Token.h"
#include "Database.h"

class Token_stream
{

	Token buffer;
	bool is_buffer_full;
public:
	void unget(Token t);
	Token get();
	Token_stream();

};

