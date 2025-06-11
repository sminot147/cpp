#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <cassert>
#include <iostream>

void testMateriaCreation() {
	IMateriaSource* src = new MateriaSource();
	
	// Test learning materia
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	// Test creating materia
	AMateria* ice = src->createMateria("ice");
	assert(ice != NULL && ice->getType() == "ice");
	
	AMateria* cure = src->createMateria("cure");
	assert(cure != NULL && cure->getType() == "cure");
	
	// Test invalid materia creation
	AMateria* invalid = src->createMateria("invalid");
	assert(invalid == NULL);
	
	delete ice;
	delete cure;
	delete src;
}

void testCharacterEquipAndUse() {
	Character* me = new Character("me");
	Character* target = new Character("target");
	
	// Test equipping materia
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	
	me->equip(ice);
	me->equip(cure);
	
	// Test using materia
	me->use(0, *target);
	me->use(1, *target);
	
	// Test invalid or empty slot use
	me->use(4, *target);
	me->use(0, *target);
	me->use(-1, *target);
	
	delete target;
	delete me;
}

void testUnequipAndMemory() {
	Character* me = new Character("me");
	
	// Test equip and unequip
	for (int i = 0; i < 20; ++i){
		AMateria* ice = new Ice();
		me->equip(ice);
		me->unequip(0);
	}
	
	// Test unequip invalid slot
	me->unequip(4);
	me->unequip(-1);
	
	// Test unequip empty slot
	me->unequip(0);
	
	delete me;
}

void testCharacterCopy() {
	Character* original = new Character("original");
	AMateria* ice = new Ice();
	original->equip(ice);
	
	// Test copy constructor
	Character* copy = new Character(*original);
	
	// Test they are independent
	original->unequip(0);
	copy->use(0, *original);
	
	delete original;
	delete copy;
}

void testMateriaSourceFull() {
	IMateriaSource* src = new MateriaSource();
	
	// Try to learn more than max materias
	for(int i = 0; i < 5; ++i) {
		AMateria* ice = new Ice();
		src->learnMateria(ice);
		if (i >= 4){
			delete ice;
		}
	}
	delete src;
}


void main_subect()
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
	
	delete bob;
	delete me;
	delete src;
}

int main() {
	main_subect();
	std::cout << "Main of subject passed" << std::endl;

	testMateriaCreation();
	std::cout << "Materia creation tests passed!" << std::endl;

	testCharacterEquipAndUse();
	std::cout << "Character equip and use tests passed!" << std::endl;

	testUnequipAndMemory();
	std::cout << "Unequip and memory tests passed!" << std::endl;

	testCharacterCopy();
	std::cout << "Character copy tests passed!" << std::endl;

	testMateriaSourceFull();
	std::cout << "MateriaSource full capacity tests passed!" << std::endl;
	

	std::cout << "All tests passed successfully!" << std::endl;

	return 0;
}
