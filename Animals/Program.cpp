#include "Owner.h"
#include "Animal.h"
#include "Species.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <cassert>
#include <ranges>

// Animal definition: species;name;age;owner name,owner adress

int main() {
	//Data keepers
	std::vector<Cat> cats;
	std::vector<Dog> dogs;
	std::vector<Fish> Fishes;
	std::vector<Parrot> Parrots;
	//end
	std::ifstream in("Data.txt");
	if (!in.is_open()) { std::cerr << "File wasn't opened"; return -1; }
	if (in.eof()) { std::cerr << "File empty"; return -2; }
	std::string temp;
	while (std::getline(in, temp)) {
		std::stringstream ss(temp);
		std::string spec; if (!std::getline(ss, spec, ';')) {std::cerr << "Something went wrong\n" << spec; return 0;}
		std::string name; if (!std::getline(ss, name, ';')) { std::cerr << "Something went wrong\n" << name; return 0; }
		std::string age; if (!std::getline(ss, age, ';')) { std::cerr << "Something went wrong\n" << age; return 0; }
		std::string own_name; if (!std::getline(ss, own_name, ',')) { std::cerr << "Something went wrong\n" << own_name; return 0; }
		std::string own_adrr; if (!std::getline(ss, own_adrr).eof()) { std::cerr << "Something went wrong\n" << own_adrr; return 0; }
		int num_age = -1;
		try { if (!age.empty()) { num_age = std::stoi(age); } }
		catch (std::invalid_argument) { std::cerr << "Not an age"; return 2; }
		catch (std::out_of_range) { std::cerr << "Too big"; return 1; }
		if (spec == "Dog") {
			dogs.push_back(Dog(Owner(own_name, own_adrr), num_age, name));
		}
		if (spec == "Cat") {
			cats.push_back(Cat(Owner(own_name, own_adrr), num_age, name));
		}
		if (spec == "Fish") {
			Fishes.push_back(Fish(Owner(own_name, own_adrr), num_age, name));
		}
		if (spec == "Parrot") {
			Parrots.push_back(Parrot(Owner(own_name, own_adrr), num_age, name));
		}
	}
	// }
	{
		struct comp {
			bool operator() (const Owner& i, const Owner& j) const {
			return i.GetFIO() == j.GetFIO() ? i.GetAdress() < j.GetAdress() : i.GetFIO() < j.GetFIO();
			}
		};
		std::map<Owner, int, comp> m;
		for (auto i : dogs) {
			m[i.GetOwner()]++;
		}
		for (auto i : cats) {
			m[i.GetOwner()]++;
		}
		for (auto i : Fishes) {
			m[i.GetOwner()]++;
		}
		for (auto i : Parrots) {
			m[i.GetOwner()]++;
		}
		std::cout << "amout of animals of owner" << '\n';
		for (auto i : m) {
			std::cout << i.first.GetFIO() << ": " << i.second << '\n';
		}
	}
	{
		std::string spec;
		std::cout << "enter specie to find:";
		std::cin >> spec;
		if (spec == "Dog") {
			std::cout << "Dogs:\n";
			for (auto i : dogs) {
				std::cout << i.GetOwner().GetFIO() << ", " << i.GetName() << '\n';
			}
		}
		if (spec == "Cat") {
			std::cout << "Cats:\n";
			for (auto i : cats) {
				std::cout << i.GetOwner().GetFIO() << ", " << i.GetName() << '\n';
			}
		}
		if (spec == "Fish") {
			std::cout << "Fishes:\n";
			for (auto i : Fishes) {
				std::cout << i.GetOwner().GetFIO() << ", " << i.GetName() << '\n';
			}
		}
		if (spec == "Parrot") {
			std::cout << "Parrots:\n";
			for (auto i : Parrots) {
				std::cout << i.GetOwner().GetFIO() << ", " << i.GetName() << '\n';
			}
		}
	}
	{
		std::string name;
		std::cout << "enter name:";
		std::cin >> name;
		std::cout << "species:\n";
        if (std::any_of(cats.begin(), cats.end(), [name](const Cat &i)
                        { return i.GetName() == name; }))
        {
            std::cout << "Cat\n";
        }
        if (std::any_of(dogs.begin(), dogs.end(), [name](const Dog &i)
                        { return i.GetName() == name; }))
        {
            std::cout << "Dog\n";
        }
        if (std::any_of(Fishes.begin(), Fishes.end(), [name](const Fish &i)
                        { return i.GetName() == name; }))
        {
            std::cout << "Fishes\n";
        }
        if (std::any_of(Parrots.begin(), Parrots.end(), [name](const Parrot &i)
                        { return i.GetName() == name; }))
        {
            std::cout << "Parrots\n";
        }
    }
	{
		struct AnimalSpecs : public Animal {
			std::string spec;
			AnimalSpecs() {}
            AnimalSpecs(Animal animal, std::string spec) : Animal(std::move(animal)), spec(std::move(spec)) {}
            bool operator<(const AnimalSpecs &i) const
            {
                return GetAge() < i.GetAge();
            }
        };
		std::vector <AnimalSpecs> ma;
		for (auto i: dogs) {
			if (i.GetAge() != -1) {
				assert(i.GetAge() >= 0);
				ma.push_back(AnimalSpecs(i, "dog"));
			}
		}
		for (auto i: cats) {
			if (i.GetAge() != -1) {
				assert(i.GetAge() >= 0);
				ma.push_back(AnimalSpecs(i, "cat"));
			}
		}
		for (auto i: Fishes) {
			if (i.GetAge() != -1) {
				assert(i.GetAge() >= 0);
				ma.push_back(AnimalSpecs(i, "fish"));
			}
		}
		for (auto i: Parrots) {
			if (i.GetAge() != -1) {
				assert(i.GetAge() >= 0);
				ma.push_back(AnimalSpecs(i, "parrot"));
			}
		}
		const auto [min, max] = std::minmax_element(ma.begin(), ma.end());
		std::cout << "min and max age:\nmin:" << min->spec << ';' << min->GetName() << ';' << min->GetAge() << ';' << min->GetOwner().GetFIO() << ';' << min->GetOwner().GetAdress();
		std::cout << "\nmax:" << max->spec << ';' << max->GetName() << ';' << max->GetAge() << ';' << max->GetOwner().GetFIO() << ';' << max->GetOwner().GetAdress();
	}
	return 0;
}