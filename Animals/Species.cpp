#include "Species.h"
#include <iostream>

void Cat::meow() const
{
	std::cout << "meow" << std::endl;
}

void Cat::lick() const
{
	std::cout << "You've been licked" << std::endl;
}

Cat::Cat(Owner owner, int age = -1, std::string name = "") : Animal(owner, age, name) {}

Dog::Dog(Owner owner, int age = -1, std::string name = "") : Animal(owner, age, name) {}

Fish::Fish(Owner owner, int age = -1, std::string name = "") : Animal(owner, age, name) {}

Parrot::Parrot(Owner owner, int age = -1, std::string name = "") : Animal(owner, age, name) {}

void Dog::Bark() const
{
	std::cout << "Bark" << std::endl;
}

void Dog::Play() const
{
	std::cout << "You've played with dog" << std::endl;
}

void Fish::Swim() const
{
	std::cout << "meow" << std::endl;
}

void Fish::Bolk() const
{
	std::cout << "bolk" << std::endl;
}

void Parrot::Aaar() const
{
	std::cout << "Aaar" << std::endl;
}

void Parrot::Fly() const
{
	std::cout << "Parrot flyed somewhere" << std::endl;
}