#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->type = "Cat";
}

Cat::Cat(const Cat& other) {
    *this = other;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
		Animal::operator=(other);
    }
    return *this;
}

Cat::~Cat() {
    
}
