#pragma once

#include "Animal.h"
#include <string>

class Cat : public Animal {
public:
	void Do() const;
	Cat(Owner, int age, std::string name);
};

class Dog : public Animal {
public:
	void Do() const;
	Dog(Owner, int age, std::string name);
};

class Fish : public Animal {
public:
	void Do() const;
	Fish(Owner, int age, std::string name);
};

class Parrot : public Animal {
public:
	void Do() const;
	Parrot(Owner, int age, std::string name);
};