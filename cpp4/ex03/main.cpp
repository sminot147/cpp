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
	Character* BruceLee = new Character("BruceLee");
	Character* you = new Character("you");
	
	// Test equipping materia
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	
	BruceLee->equip(ice);
	BruceLee->equip(cure);
	
	// Test using materia
	BruceLee->use(0, *you);
	BruceLee->use(1, *you);
	

	BruceLee->use(4, *you);
	BruceLee->use(0, *you);
	BruceLee->use(-10, *you);
	
	delete you;
	delete BruceLee;
}

void testUnequipAndMemory() {
	Character* me = new Character("me");
	
	for (int i = 0; i < 20; ++i){
		AMateria* ice = new Ice();
		me->equip(ice);
		me->unequip(0);
	}
	
	me->unequip(4);
	me->unequip(-1);
	
	me->unequip(0);
	
	delete me;
}

void testCharacterCopy() {
	Character* BruceLee = new Character("BruceLee");
	AMateria* ice = new Ice();
	BruceLee->equip(ice);
	
	Character* BruceLeeCopy = new Character(*BruceLee);
	
	BruceLee->unequip(0);
	BruceLeeCopy->use(0, *BruceLee);
	
	delete BruceLee;
	delete BruceLeeCopy;
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
