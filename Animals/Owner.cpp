#include "Owner.h"
#include <utility>
#include <iostream>
#include "Animal.h"

Owner::Owner()
{
}

std::string Owner::GetFIO() const
{
	return FIO;
}

std::string Owner::GetAdress() const
{
	return adress;
}

Owner::Owner(std::string FIO, std::string Adress) : FIO(std::move(FIO)), adress(std::move(Adress)) {
	std::cout << "Constructor called for Owner" << '\n';
}

Owner::Owner(const Owner& owner) 
{
  std::cout << "Copy constructor called for Owner" << '\n';
  FIO = owner.FIO;
  adress = owner.adress;
}

Owner::Owner(Owner&& owner)
{
  std::cout << "Move constructor called for Owner" << '\n'; 
  FIO = std::move(owner.FIO);
  adress = std::move(owner.adress);
}

Owner& Owner::operator=(const Owner& owner)
{
  std::cout << "Copy assignment operator called for Owner" << '\n';
  FIO = owner.FIO;
  adress = owner.adress;
  return *this;
}

Owner& Owner::operator=(Owner&& owner)
{
  std::cout << "Move assignment operator called for Owner" << '\n';
  FIO = std::move(owner.FIO);
  adress = std::move(owner.adress);
  return *this; 
}