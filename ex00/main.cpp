#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	std::cout << "----- Animal Tests -----" << std::endl;
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << std::endl;
	std::cout << "J Type: " << j->getType() << std::endl;
	std::cout << "I Type: " << i->getType() << std::endl;

	std::cout << std::endl;
	std::cout << "J Sound: ";
	j->makeSound();
	std::cout << "I Sound: ";
	i->makeSound();
	std::cout << "Meta Sound: ";
	meta->makeSound();

	std::cout << std::endl;
	std::cout << "----- Cleanup Animal Objects -----" << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << std::endl;
	std::cout << "----- WrongAnimal Tests -----" << std::endl;
	const WrongAnimal *wrongMeta = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();

	std::cout << std::endl;
	std::cout << "WrongCat Type: " << wrongCat->getType() << std::endl;

	std::cout << std::endl;
	std::cout << "WrongCat Sound (through WrongAnimal*): ";
	wrongCat->makeSound(); // Will call WrongAnimal::makeSound()
	std::cout << "WrongMeta Sound: ";
	wrongMeta->makeSound();

	std::cout << std::endl;
	// Direct WrongCat object test
	WrongCat directWrongCat;
	std::cout << "Direct WrongCat Sound: ";
	directWrongCat.makeSound(); // Will call WrongCat::makeSound()

	std::cout << std::endl;
	std::cout << "----- Cleanup WrongAnimal Objects -----" << std::endl;
	delete wrongMeta;
	delete wrongCat;

	return 0;
}
