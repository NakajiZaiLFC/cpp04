#include "Dog.hpp"

Dog::Dog() : Animal() {
    this->type = "Dog";
	std::cout <<  << std::endl;
}

Dog::Dog(const Dog& other) {
    *this = other;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
		Animal::operator=(other);
    }
    return *this;
}

Dog::~Dog() {
    
}
