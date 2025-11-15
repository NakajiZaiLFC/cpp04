#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main (){
	const Animal* i = new Dog();
	const Animal* j = new Cat(); 

	std::cout << i->getType() << std::endl;
	std::cout << j->getType() << std::endl;


}