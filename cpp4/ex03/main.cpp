#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	// Test unequip
	me->unequip(0); // Should be handled properly to avoid memory leaks
	me->use(0, *bob); // Should do nothing as slot is empty

	// Test invalid index
	me->use(42, *bob); // Should handle invalid index

	delete bob;
	delete me;
	delete src;

	return 0;
}