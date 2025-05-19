#include "HumanB.hpp"

HumanB::HumanB(std::string name) : 
	_name(name),
	_weapon(NULL)
{}

void HumanB::setWeapon(Weapon& weapon){
	this->_weapon = &weapon;
}

void HumanB::attack() const {
	if (this->_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " attacks with their hands" << std::endl;
}

HumanB::~HumanB()
{}
