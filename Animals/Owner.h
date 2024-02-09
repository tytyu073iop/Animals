#pragma once

#include <string>

class Owner {
	std::string FIO;
	std::string adress;
public:
	Owner();
	std::string GetFIO() const;
	std::string GetAdress() const;
	Owner(std::string FIO, std::string Adress);
};