#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{
	IMateriaSource* src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	AMateria* tmpIce = new Ice();
	src->learnMateria(tmpIce); // clone() して学習させる
	delete tmpIce;             // 原本は main が delete する

	AMateria* tmpCure = new Cure();
	src->learnMateria(tmpCure); // clone() して学習させる
	delete tmpCure;            // 原本は main が delete する
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}