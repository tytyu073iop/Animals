#include "Owner.h"
#include <typeinfo>
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

Owner::Owner(std::string FIO, std::string Adress) : FIO(std::move(FIO)), adress(std::move(Adress)) {}

void Owner::interact(Animal* pet) const
{
	const type_info& t = typeid(*pet);
	std::cout << "it's a " << t.name() << '\n';
	pet->Do();
}