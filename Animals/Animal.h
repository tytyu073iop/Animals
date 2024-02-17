#pragma once

#include <string>
#include <optional>
#include "Owner.h"

class Animal {
	static int new_id;
	int id;
	std::string name;
	int age;
	std::optional<Owner> owner;
public:
	int GetId() const;
	std::string GetName() const;
	int GetAge() const;
	std::optional<Owner> GetOwner() const;
	virtual void Do() const = 0;
	Animal(std::optional<Owner>, int age, std::string name);
};