#include "Owner.h"

#include <utility>

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
