#include "Species.h"
#include <iostream>
#include <utility>

Cat::Cat(Owner owner, int age = -1, std::string name = "") : Animal(std::move(owner), age, std::move(name)) {}

Dog::Dog(Owner owner, int age = -1, std::string name = "") : Animal(std::move(owner), age, std::move(name)) {}

Fish::Fish(Owner owner, int age = -1, std::string name = "") : Animal(std::move(owner), age, std::move(name)) {}

Parrot::Parrot(Owner owner, int age = -1, std::string name = "") : Animal(std::move(owner), age, std::move(name)) {}


void Cat::Do() const
{
	std::cout << "meow" << std::endl;
}


void Dog::Do() const
{
	std::cout << "Bark" << std::endl;
}

void Fish::Do() const
{
	std::cout << "meow" << std::endl;
}

void Parrot::Do() const
{
	std::cout << "Aaar" << std::endl;
}

