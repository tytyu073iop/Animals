#pragma once

#include "Animal.h"
#include <string>

class Cat : public Animal {
public:
	void Do() const;
	Cat(std::optional<Owner>, int age, std::string name);
};

class Dog : public Animal {
public:
	void Do() const;
	Dog(std::optional<Owner>, int age, std::string name);
};

class Fish : public Animal {
public:
	void Do() const;
	Fish(std::optional<Owner>, int age, std::string name);
};

class Parrot : public Animal {
public:
	void Do() const;
	Parrot(std::optional<Owner>, int age, std::string name);
};