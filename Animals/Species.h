#pragma once

#include "Animal.h"
#include <string>

class Cat : public Animal {
public:
	void meow() const;
	void lick() const;
	Cat(Owner, int age, std::string name);
};

class Dog : public Animal {
public:
	void Bark() const;
	void Play() const;
	Dog(Owner, int age, std::string name);
};

class Fish : public Animal {
public:
	void Swim() const;
	void Bolk() const;
	Fish(Owner, int age, std::string name);
};

class Parrot : public Animal {
public:
	void Aaar() const;
	void Fly() const;
	Parrot(Owner, int age, std::string name);
};