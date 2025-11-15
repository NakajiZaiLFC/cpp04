#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
    this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	this->brain = new Brain(*other.brain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
		delete this->brain;
		this->brain = new Brain(*other.brain);
		Animal::operator=(other);
    }
	std::cout << "Dog assignation operator called" << std::endl;
    return *this;
}

Dog::~Dog() {
	delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}

