#include "Animal.h"

#include <utility>

int Animal::GetId() const
{
    return id;
}

std::string Animal::GetName() const
{
    return name;
}

int Animal::GetAge() const
{
    return age;
}

Owner Animal::GetOwner() const
{
    return owner;
}

Animal::Animal(Owner owner, int age = -1, std::string name = "") : id(new_id++), owner(std::move(owner)), age(age), name(std::move(name)) {}

int Animal::new_id = 0;

Animal::Animal()
{
}
