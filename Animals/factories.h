#include "Species.h"

class factory
{
private:
    /* data */
public:
    virtual Animal* createAnimal(const std::optional<Owner>& owner, int age, std::string name) = 0;
};

class catFactory : public factory
{
private:
    /* data */
public:
    Animal* createAnimal(const std::optional<Owner>& owner, int age, std::string name) {
        return new Cat(owner, age, name);
    }
};

class dogFactory : public factory
{
private:
    /* data */
public:
    Animal* createAnimal(const std::optional<Owner>& owner, int age, std::string name) {
        return new Dog(owner, age, name);
    }
};

class parrotFactory : public factory
{
private:
    /* data */
public:
    Animal* createAnimal(const std::optional<Owner>& owner, int age, std::string name) {
        return new Parrot(owner, age, name);
    }
};

class fishFactory : public factory
{
private:
    /* data */
public:
    Animal* createAnimal(const std::optional<Owner>& owner, int age, std::string name) {
        return new Fish(owner, age, name);
    }
};

