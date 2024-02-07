#pragma once

#include <string>

class Owner {
	std::string FIO;
	std::string adress;
	Owner();
public:
	std::string GetFIO() const;
	std::string GetAdress() const;
	Owner(std::string FIO, std::string Adress);
};