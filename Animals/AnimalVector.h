#pragma once
#include "Composite.h"
#include "Animal.h"
#include <vector>

class Folder : public Unit {
private:
	std::vector<Unit*> v;
public:
	void Do() const;
	void push_back(Unit* i);
	void pop(size_t i);
	int getAmount() const;
};