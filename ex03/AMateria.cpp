#include "AMateria.hpp"

AMateria::AMateria() {
    
}

AMateria::AMateria(const AMateria& other) {
    *this = other;
}

AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other) {
		this->m_type = other.m_type;
    }
    return *this;
}

AMateria::~AMateria() {
}

std::string const& AMateria::getType(void) const
{
	return this->m_type;
}

AMateria::AMateria(const std::string& type) : m_type(type)
{
}