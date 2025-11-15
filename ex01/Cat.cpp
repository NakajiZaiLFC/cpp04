#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
    this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	this->brain = new Brain(*other.brain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
		delete this->brain;
		this->brain = new Brain(*other.brain);
		Animal::operator=(other);
    }
	std::cout << "Cat assignation operator called" << std::endl;
    return *this;
}

Cat::~Cat() {
	delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain(void) const
{
	return this->brain;
}
