#include "Owner.h"

std::string Owner::GetFIO() const
{
	return FIO;
}

std::string Owner::GetAdress() const
{
	return adress;
}

Owner::Owner(std::string FIO, std::string Adress) : FIO(FIO), adress(Adress) {}
