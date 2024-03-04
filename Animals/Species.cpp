#include "Species.h"
#include <iostream>
#include <utility>

Cat::Cat(const std::optional<Owner>& owner, int age = -1, std::string name = "") : Animal(owner, age, std::move(name)) {
	std::cout << "Cat created\n";
}

Cat::Cat(Cat&& rhs) : Animal(std::move(rhs))
{
	std::cout << "moved: " << "Cat\n";
}

Cat::Cat(const Cat& rhs) : Animal(rhs) {
	std::cout << "Copying a Cat object.\n";
}

Cat& Cat::operator=(const Cat& rhs)
{
	
	Animal::operator=(rhs);
	std::cout << "equaled copy cat\n";
	return *this;
}

Cat& Cat::operator=(Cat&& rhs)
{
	Animal::operator=(std::move(rhs));
	std::cout << "equaled move cat\n";
	return *this;
}


Dog::Dog(std::optional<Owner> owner, int age = -1, std::string name = "") : Animal(std::move(owner), age, std::move(name)) {
	std::cout << "Dog created\n";
}

// all operators should cout
Dog::Dog(Dog&& rhs) : Animal(std::move(rhs)) {
	std::cout << "Moving a Dog object.\n";
}
Dog::Dog(const Dog& rhs) : Animal(rhs) {
	std::cout << "Copying a Dog object.\n";
}
Dog& Dog::operator=(const Dog& rhs)
{
	Animal::operator=(rhs);
	std::cout << "equaled copy dog\n";
	return *this;
}
Dog& Dog::operator=(Dog&& rhs)
{
	Animal::operator=(std::move(rhs));
	std::cout << "equaled move dog\n";
	return *this;
}


Fish::Fish(std::optional<Owner> owner, int age = -1, std::string name = "") : Animal(std::move(owner), age, std::move(name)) {}

Fish::Fish(Fish&& rhs) : Animal(std::move(rhs)) {
	std::cout << "Moving a Fish object.\n";
}
Fish::Fish(const Fish& rhs) : Animal(rhs) {
	std::cout << "Copying a Fish object.\n";
}
Fish& Fish::operator=(const Fish& rhs)
{
	Animal::operator=(rhs);
	std::cout << "equaled copy fish\n";
	return *this;
}
Fish& Fish::operator=(Fish&& rhs)
{
	Animal::operator=(std::move(rhs));
	std::cout << "equaled move fish\n";
	return *this;
}

Parrot::Parrot(std::optional<Owner> owner, int age = -1, std::string name = "") : Animal(std::move(owner), age, std::move(name)) {}


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

Parrot::Parrot(const Parrot& rhs) : Animal(rhs) {
	std::cout << "Copying a Parrot object.\n";
}

Parrot::Parrot(Parrot&& rhs) : Animal(std::move(rhs)) {
	std::cout << "Moving a Parrot object.\n";
}

Parrot& Parrot::operator=(const Parrot& rhs) {
	Animal::operator=(rhs);
	std::cout << "equaled copy parrot\n";
	return *this;
}
Parrot& Parrot::operator=(Parrot&& rhs) {
	Animal::operator=(std::move(rhs));
	std::cout << "equaled move parrot\n";
	return *this;
}