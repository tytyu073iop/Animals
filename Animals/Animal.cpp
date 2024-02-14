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

int Animal::new_id = 0;
