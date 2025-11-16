#include "Ice.hpp"
#include <iostream>

Ice::Ice() {
    
}

Ice::Ice(const Ice& other) {
    *this = other;
}

Ice& Ice::operator=(const Ice& other) {
    if (this != &other) {
    }
    return *this;
}

Ice::~Ice() {
    
}

AMateria* Ice::clone(void) const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
