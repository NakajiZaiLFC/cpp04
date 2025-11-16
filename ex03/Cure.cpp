#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {
    
}

Cure::Cure(const Cure& other) : AMateria(other){
}

Cure& Cure::operator=(const Cure& other) {
    if (this != &other) {
		this->m_type = other.m_type;
    }
	return *this;
}

Cure::~Cure() {
    
}

AMateria* Cure::clone(void) const {
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
