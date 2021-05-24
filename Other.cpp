//other.cpp
#include "other.h"

#include <iostream>

using namespace std;

void clearCin()
{
	cin.ignore(cin.rdbuf()->in_avail());
}