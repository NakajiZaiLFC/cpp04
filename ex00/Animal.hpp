#pragma once
#include <string>

class Animal {
public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    ~Animal();

protected:
	std::string type;
};

