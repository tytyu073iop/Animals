#pragma once

#include <string>
#include <optional>
#include "Owner.h"
#include "Composite.h"

class Animal : public Unit {
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
	Animal(const std::optional<Owner>&, int age, std::string name);
	Animal(Animal&& rhs);
	Animal(const Animal& rhs);
	Animal& operator=(const Animal& rhs);
	Animal& operator=(Animal&& rhs);
	int getAmount() const;
};