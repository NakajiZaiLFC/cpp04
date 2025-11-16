#include "AMateria.hpp"

AMateria::AMateria() {
    
}

AMateria::AMateria(const AMateria& other) {
    *this = other;
}

AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other) {
    }
    return *this;
}

AMateria::~AMateria() {
}

std::string const& AMateria::getType(void) const
{
	return this->type;
}
