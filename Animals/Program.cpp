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
#include <filesystem>
#include <functional>

// Animal definition: species;name;age;owner name,owner adress

void animal_out(const Animal& min) {
	
	std::cout << std::string(typeid(min).name()) << ';' << min.GetName() << ';' << min.GetAge() << ';' << min.GetOwner().GetFIO() << ';' << min.GetOwner().GetAdress();
}

void virtual_test(Animal* i) {
	std::cout << "virtual test\n";  i->GetOwner().interact(i); std::cout << '\n';
}

int main() {
	//Data keepers
	std::vector<Cat> cats;
	std::vector<Dog> dogs;
	std::vector<Fish> fishes;
	std::vector<Parrot> parrots;
	//
	std::vector<std::reference_wrapper<Animal>> box;
	//end
	std::ifstream in("Data.txt");
	if (!in.is_open()) { std::cerr << "File wasn't opened"; return -1; }
	if (in.peek() == std::char_traits<char>::eof()) { std::cerr << "File empty"; return -2; }
	std::string temp;
	while (std::getline(in, temp)) {
		std::stringstream ss(temp);
		std::string spec; if (!std::getline(ss, spec, ';')) {std::cerr << "Something went wrong\n" << spec; return 0;}
		std::string name; if (!std::getline(ss, name, ';')) { std::cerr << "Something went wrong\n" << name; return 0; }
		std::string age; if (!std::getline(ss, age, ';')) { std::cerr << "Something went wrong\n" << age; return 0; }
		std::string own_name; if (!std::getline(ss, own_name, ',')) { std::cerr << "Something went wrong\n" << own_name; return 0; }
		if (own_name.empty()) { std::cerr << "No name"; return 4; }
		std::string own_adrr; std::getline(ss, own_adrr);
		if (own_adrr.empty()) { std::cerr << "No adress"; return 5; }
		int num_age = -1;
		try { if (!age.empty()) { num_age = std::stoi(age); } }
		catch (std::invalid_argument) { std::cerr << "Not an age"; return 2; }
		catch (std::out_of_range) { std::cerr << "Too big"; return 1; }
		if (spec == "Dog") {
			dogs.push_back(Dog(Owner(own_name, own_adrr), num_age, name));
			box.push_back(dogs.back());
		} else if (spec == "Cat") {
			cats.push_back(Cat(Owner(own_name, own_adrr), num_age, name));
			box.push_back(cats.back());
		} else if (spec == "Fish") {
			fishes.push_back(Fish(Owner(own_name, own_adrr), num_age, name));
			box.push_back(fishes.back());
		} else if (spec == "Parrot") {
			parrots.push_back(Parrot(Owner(own_name, own_adrr), num_age, name));
			box.push_back(parrots.back());
		} else {
			std::cerr << "No species"; return -3;
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
		for (auto i : box) {
			m[i.get().GetOwner()]++;
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
		std::cout << spec << "s:\n";
		for (auto i : box) {
			if (typeid(i.get()).name() == spec) {
				std::cout << i.get().GetOwner().GetFIO() << ", " << i.get().GetName() << '\n';
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
        if (std::any_of(fishes.begin(), fishes.end(), [name](const Fish &i)
                        { return i.GetName() == name; }))
        {
            std::cout << "Fishes\n";
        }
        if (std::any_of(parrots.begin(), parrots.end(), [name](const Parrot &i)
                        { return i.GetName() == name; }))
        {
            std::cout << "Parrots\n";
        }
    }
	{
		
		const auto [min, max] = std::minmax_element(box.begin(), box.end());
		std::cout << "min and max age:\nmin:"; animal_out(*min);
		std::cout << "\nmax:"; animal_out(*max);
	}
	return 0;
}
