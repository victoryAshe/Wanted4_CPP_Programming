#include "Account.h"
#include <iostream>

Account::Account(int inID, const char* inName)
{
	id = inID; 
	
	int length = strlen(inName) + 1;
	name = new char[length];
	strcpy_s(name, length, inName);
}

Account::~Account()
{
	delete name;
	name = nullptr;
}
