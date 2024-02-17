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

std::optional<Owner> Animal::GetOwner() const
{
    return owner;
}

Animal::Animal(std::optional<Owner> owner, int age = -1, std::string name = "") : id(new_id++), owner(owner), age(age), name(std::move(name)) {}

int Animal::new_id = 0;
