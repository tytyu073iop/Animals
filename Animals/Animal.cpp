#include "Animal.h"

#include <utility>
#include <iostream>

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


Animal::Animal(const std::optional<Owner>& owner, int age = -1, std::string name = "") : id(new_id++), owner(std::forward<const std::optional<Owner>>(owner)), age(age), name(std::move(name)) 
{
    std::cout << "created: " << "Animal\n";
}

//id moves!
Animal::Animal(Animal&& rhs) : id(std::move(id)), owner(std::move(owner)), age(std::move(age)), name(std::move(name))
{
    std::cout << "moved: " << "Animal\n";
}

Animal::Animal(const Animal& rhs) {
    id = rhs.id;
    name = rhs.name;
    age = rhs.age;
    owner = rhs.owner;
    std::cout << "copied: " << "Animal\n";
}

Animal& Animal::operator=(const Animal& rhs)
{
    id = rhs.id;
    name = rhs.name;
    age = rhs.age;
    owner = rhs.owner;
    std::cout << "equaled copy: " << "Animal\n";
    return *this;
}

Animal& Animal::operator=(Animal&& rhs)
{
    id = std::move(rhs.id);
    name = std::move(rhs.name);
    age = std::move(rhs.age);
    owner = std::move(rhs.owner);
    std::cout << "equaled move: " << "Animal\n";
    return *this;
}

int Animal::getAmount() const {
    return 1;
}

int Animal::new_id = 0;
