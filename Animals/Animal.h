#pragma once

#include "Owner.h"
#include <string>

class Animal {
	static int new_id;
	int id;
	std::string name;
	int age;
	Owner owner;
	Animal();
public:
	int GetId() const;
	std::string GetName() const;
	int GetAge() const;
	Owner GetOwner() const;
	Animal(Owner, int age, std::string name);
};