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
#include <typeinfo>
#include <typeindex>
#include <cctype>
#include <set>
#include <optional>

// Animal definition: species;name;age;owner name,owner adress

// Databases
std::map<std::type_index, std::string> itot {
	{typeid(Cat), "Cat"},
	{typeid(Dog), "Dog"},
	{typeid(Fish), "Fish"},
	{typeid(Parrot), "Parrot"},
};
//

void task1(const std::vector<Animal*>);
void task2(const std::vector<Animal*>);
void task3(const std::vector<Animal*>);
void task4(const std::vector<Animal*>);
void move_semantic_test();
void StandartizeString(std::string&);
void interact(Animal* pet)
{
	const std::type_info& t = typeid(*pet);
	std::cout << "it's a " << itot[std::type_index(t)] << '\n';
	pet->Do();
}
void animal_out(const Animal* min) {
	std::cout << itot[std::type_index(typeid(*min))] << ';' << min->GetName() << ';' << (min->GetAge() == -1 ? "" : std::to_string(min->GetAge())) << ';';
	auto owner = min->GetOwner();
	if (owner) {
		std::cout << owner->GetFIO() << ',' << owner->GetAdress();
	}
	std::cout << ';' << min->GetId() << '\n';
}
void virtual_test(Animal* i) {
	std::cout << "virtual test\n";  interact(i); std::cout << '\n';
}

void move_test(Cat&& i) {
	Cat q(std::move(i));
}

int main() {
	std::vector<Animal*> box;
	std::ifstream in("Data.txt");
	if (!in.is_open()) { std::cerr << "File wasn't opened"; return -1; }
	if (in.peek() == std::char_traits<char>::eof()) { std::cerr << "File empty"; return -2; }
	std::string temp;
	while (std::getline(in, temp)) {
		std::stringstream ss(temp);
		std::string spec; if (!std::getline(ss, spec, ';')) {std::cerr << "Something went wrong\n" << spec; return 0;}
		std::string name; if (!std::getline(ss, name, ';')) { std::cerr << "Something went wrong\n" << name; return 0; }
		std::string age; if (!std::getline(ss, age, ';')) { std::cerr << "Something went wrong\n" << age; return 0; }
		bool f = false;
		std::string own_name; if (!std::getline(ss, own_name, ',')) { f = true; }
		std::string own_adrr; std::getline(ss, own_adrr);
		std::optional<Owner> owner;
		if (!f) {
		if (own_name.empty()) { std::cerr << "No name"; return 4; }
		if (own_adrr.empty()) { std::cerr << "No adress"; return 5; }
		owner = Owner(own_name, own_adrr);
		}
		int num_age = -1;
		try { if (!age.empty()) { num_age = std::stoi(age); } }
		catch (std::invalid_argument) { std::cerr << "Not an age"; return 2; }
		catch (std::out_of_range) { std::cerr << "Too big"; return 1; }
		StandartizeString(spec);
		if (spec == "Dog") {
			// auto i = Dog(Owner(own_name, own_adrr), num_age, name);
			box.push_back(new Dog(owner, num_age, name));
			//box.push_back(dogs.back());
		} else if (spec == "Cat") {
			box.push_back(new Cat(owner, num_age, name));
		} else if (spec == "Fish") {
			box.push_back(new Fish(owner, num_age, name));
		} else if (spec == "Parrot") {
			box.push_back(new Parrot(owner, num_age, name));
		} else {
			std::cerr << "No species"; return -3;
		}
	}
	virtual_test(box[0]);
	std::cout << "Choose task from 1-5: ";
	short task;
	std::cin >> task;
	switch (task)
	{
	case 1:
		task1(box);
		break;
	case 2:
		task2(box);
		break;
	case 3:
		task3(box);
		break;
	case 4:
		task4(box);
		break;
	case 5:
		move_semantic_test();
		break;
	default:
		std::cout << "No task on that number\n";
		break;
	}

	
	
	return 0;
}

void task1(const std::vector<Animal*> box)
{
	struct comp {
		bool operator() (const std::optional<Owner>& i, const std::optional<Owner>& j) const {
		if (!i || !j) {
			return bool(i) < bool(j);
		}
		return i->GetFIO() == j->GetFIO() ? i->GetAdress() < j->GetAdress() : i->GetFIO() < j->GetFIO();
		}
	};
	std::map<std::optional<Owner>, int, comp> m;
	for (const auto i : box) {
		m[i->GetOwner()]++;
	}
	std::cout << "amout of animals of owner" << '\n';
	for (auto i : m) {
		std::cout << (i.first ? i.first->GetFIO() : "No owner") << ": " << i.second << '\n';
	}
}

void task2(const std::vector<Animal*> box)
{
	std::string spec;
	std::cout << "enter specie to find:";
	std::cin >> spec;
	StandartizeString(spec);
	std::cout << spec << "s:\n";
	bool f = false;
	for (auto i : box) {
		if(std::string(typeid(*i).name()).find(spec) != std::string::npos) {
			f = true;
			std::cout << (i->GetOwner() ? i->GetOwner()->GetFIO() : "No owner") << ", " << (i->GetName().empty() ? "No name" : i->GetName()) << '\n';
		}
	}
	if (!f) {
		std::cout << "No animal of that specie\n";
	}
}

void task3(const std::vector<Animal*> box)
{
	std::string name;
	std::cout << "enter name: ";
	std::cin >> name;
    std::set<std::type_index> s;
	for (const auto& i : box) {
		if (i->GetName() == name) {
			s.insert(std::type_index(typeid(*i)));
		}
	}
	std::cout << "amount of species: " << s.size() << '\n';
}

void task4(const std::vector<Animal*> box)
{
	std::vector<Animal*> c(box.size());
	auto end = std::copy_if(box.begin(), box.end(), c.begin(), [](Animal* i){ return i->GetAge() != -1; });
	if (c.begin() != end) {
		auto [min, max] = std::minmax_element(c.begin(), end, [](Animal* i, Animal* j){ return i->GetAge() < j->GetAge(); });
		std::cout << "min and max age:\nmin: "; animal_out(*min);
		std::cout << "max: "; animal_out(*max);
	} else {
		std::cout << "No animals with age\n";
	}
}

void StandartizeString(std::string& i) {
if (!i.empty())
	{
		i[0] = std::toupper(i[0]);
		for (auto j = i.begin()+1;j!= i.end();j++)
		{
			*j = std::tolower(*j);
		}
		
	}
}

void move_semantic_test() {
	std::cout << "mOVE TEST:\n";
	Cat m(Owner("pi", "86"), 8, "Max");
	std::cout << "\tcopy:\n";
	Cat i(m);
	// std::cout << "equal\n";
	// i = m;
	std::cout << "\tmoving\n";
	Cat j(std::move(m));
	{
		std::cout << "\texperiment\n";
		Cat&& w(std::move(i));
		std::cout << "\trvalue made\ntest:" << i.GetName() << '\n';
		move_test(std::move(i));
	}
	std::cout << "\tvs\n";
	{
		Cat w(j);
		move_test(std::move(w));
	}
	std::cout << "\t=\n";
	{
		Cat w = j;
		w = std::move(j);
	}
}