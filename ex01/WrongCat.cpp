#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() {
    this->type = "WrongCat";
	this->brain = new Brain();
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	this->brain = new Brain(*other.brain);
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) {
		WrongAnimal::operator=(other);
    }
	std::cout << "WrongCat assignation operator called" << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
	delete this->brain;
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}
