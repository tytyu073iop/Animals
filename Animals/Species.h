#pragma once

#include "Animal.h"
#include <string>

class Cat : public Animal {
public:
	void Do() const;
	Cat(std::optional<Owner>, int age, std::string name);
	Cat(Cat&&);
	Cat(const Cat& rhs);
	Cat& operator=(const Cat& rhs);
	Cat& operator=(Cat&& rhs);
};

class Dog : public Animal {
public:
	void Do() const;
	Dog(std::optional<Owner>, int age, std::string name);
	Dog(const Dog& rhs);
	Dog(Dog&&);
	// move and copy assignment operators are not needed because they are inherited from Animal(aws)
	Dog& operator=(const Dog& rhs);
	Dog& operator=(Dog&& rhs);
};

class Fish : public Animal {
public:
	void Do() const;
	Fish(std::optional<Owner>, int age, std::string name);
	Fish(const Fish& rhs);
	Fish(Fish&&);
	Fish& operator=(const Fish& rhs);
	Fish& operator=(Fish&& rhs);
};

class Parrot : public Animal {
public:
	void Do() const;
	Parrot(std::optional<Owner>, int age, std::string name);
	Parrot(const Parrot& rhs);
	Parrot(Parrot&&);
	Parrot& operator=(const Parrot& rhs);
	Parrot& operator=(Parrot&& rhs);
};

