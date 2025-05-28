#include "FragTrap.hpp"
#include <unistd.h>

//canonical form
/*----------------------------------------------------------------------------*/
/*                               Canonical Form                               */
/*----------------------------------------------------------------------------*/

FragTrap::FragTrap() :
	_guardMode(false)
{
	ClapTrap::setName("FragTrap");
	ClapTrap::setHitPoints(100);
	ClapTrap::setEnergyPoints(100);
	ClapTrap::setAttackDamage(30);
	std::cout << "FragTrap " << ClapTrap::getName() << " created." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other), 
	_guardMode(other._guardMode)
{
	std::cout << "FragTrap " << getName() << " copied." << std::endl;
}


FragTrap &FragTrap::operator=(const FragTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		_guardMode = other._guardMode;
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << ClapTrap::getName() << " destroyed." << std::endl;
}

/*----------------------------------------------------------------------------*/
/*                               Other constructor                             */
/*----------------------------------------------------------------------------*/

FragTrap::FragTrap(const std::string &name) :
	_guardMode(false)
{
	ClapTrap::setName(name);
	ClapTrap::setHitPoints(100);
	ClapTrap::setEnergyPoints(100);
	ClapTrap::setAttackDamage(30);
	std::cout << "FragTrap " << ClapTrap::getName() << " created." << std::endl;
}

/*----------------------------------------------------------------------------*/
/*                               Functions                                     */
/*----------------------------------------------------------------------------*/

void FragTrap::attack(const std::string &target) {
	if (ClapTrap::getHitPoints() == 0) {
		std::cout << "FragTrap " << ClapTrap::getName() << " is dead... Take a minute of silence in his memory." << std::endl;
		sleep(60);
		return;
	}
	if (ClapTrap::getEnergyPoints() > 0) {
		std::cout << "FragTrap " << ClapTrap::getName() << " attacks " << target  << ", causing ";
		if (ClapTrap::getAttackDamage() > 0){
			std::cout << ClapTrap::getAttackDamage();
		} else {
			std::cout << "no";
		}
		std::cout << " points of damage!" << std::endl;
		ClapTrap::setEnergyPoints(ClapTrap::getEnergyPoints() - 1);
	} else {
		std::cout << "FragTrap " << ClapTrap::getName() << " has no energy. Maybe it's time for the peace" << std::endl;
	}
}

void FragTrap::highFivesGuys( void ) {
	std::cout << "FragTrap " << ClapTrap::getName() << " send you a positive high fives request !" << std::endl;
}
