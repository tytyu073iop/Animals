#pragma once

#include <string>
#include "Owner.h"

class Animal {
	static int new_id;
	int id;
	std::string name;
	int age;
	Owner owner;
public:
	int GetId() const;
	std::string GetName() const;
	int GetAge() const;
	Owner GetOwner() const;
	virtual void Do() const = 0;
};