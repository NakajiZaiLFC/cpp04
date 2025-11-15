#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal 
{
public:
	Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	~Cat();

	virtual void makeSound(void) const;
	Brain* getBrain(void) const;

private:
	Brain* brain;
};

