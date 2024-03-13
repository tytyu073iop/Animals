#include "AnimalVector.h"

void Folder::pop(size_t i)
{
	delete v[i];
}

int Folder::getAmount() const{
	int sum = 0;
	for (auto i : v) {
		sum += i->getAmount();
	}
	return sum;
}

void Folder::Do() const{
	for (auto i : v) {
		i->Do();
	}
}

void Folder::push_back(Unit* i) {
	v.push_back(i);
}