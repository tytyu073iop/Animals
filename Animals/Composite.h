#pragma once

class Unit {
public:
	virtual void Do() const = 0;
	virtual int getAmount() const = 0;
	//DANGER! WORKS ONLY FOR COMPOSITE OBJECTS!
	virtual void push_back(Unit*);
	virtual void pop(size_t i);
};