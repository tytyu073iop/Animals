#pragma once

#include <string>

class Owner {
	std::string FIO;
	std::string adress;
public:
	Owner();
	Owner(std::string FIO, std::string Adress);
	std::string GetFIO() const;
	std::string GetAdress() const;
	//void interact(Animal* pet) const; cycle problem
	Owner& operator=(const Owner& rhs);
	Owner(const Owner& other);
	Owner& operator=(Owner&& rhs);
	Owner(Owner&& other);
};