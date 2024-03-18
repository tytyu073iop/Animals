#include "Composite.h"
#include <iostream>

void Unit::push_back(Unit* i)
{
	std::cout << "WRONG! not composite";
}

void Unit::pop(size_t i)
{
	std::cout << "WRONG! not composite";
}

Unit::~Unit()
{
}
