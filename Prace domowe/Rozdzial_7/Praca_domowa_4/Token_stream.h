#pragma once
#include "../../stdafx.h"
#include "../../std_lib_facilities_v2.h"
#include "Token.h"
#include "Database.h"
#include "Symbol_table.h"

class Token_stream
{

	Token buffer;
	bool is_buffer_full;
public:
	Token_stream();

	void unget(Token t);
	Token get();
	
	void ignore_signs(char sign_to_find);


};

