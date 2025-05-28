#include "ScavTrap.hpp"
#include <unistd.h>

/*----------------------------------------------------------------------------*/
/*                               Canonical Form                               */
/*----------------------------------------------------------------------------*/

ScavTrap::ScavTrap() :
	_guardMode(false)
{
	ClapTrap::setName("ScavTrap");
	ClapTrap::setHitPoints(100);
	ClapTrap::setEnergyPoints(50);
	ClapTrap::setAttackDamage(20);
	std::cout << "ScavTrap " << ClapTrap::getName() << " created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other), 
	_guardMode(other._guardMode)
{
	std::cout << "ScavTrap " << getName() << " copied." << std::endl;
}


ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		_guardMode = other._guardMode;
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << ClapTrap::getName() << " destroyed." << std::endl;
}

/*----------------------------------------------------------------------------*/
/*                               Other constructor                             */
/*----------------------------------------------------------------------------*/

ScavTrap::ScavTrap(const std::string &name) :
	_guardMode(false)
{
	ClapTrap::setName(name);
	ClapTrap::setHitPoints(100);
	ClapTrap::setEnergyPoints(50);
	ClapTrap::setAttackDamage(20);
	std::cout << "ScavTrap " << ClapTrap::getName() << " created." << std::endl;
}

/*----------------------------------------------------------------------------*/
/*                               Functions                                     */
/*----------------------------------------------------------------------------*/

void ScavTrap::attack(const std::string &target) {
	if (ClapTrap::getHitPoints() == 0) {
		std::cout << "ScavTrap " << ClapTrap::getName() << " is dead... Take a minute of silence in his memory." << std::endl;
		sleep(60);
		return;
	}
	if (ClapTrap::getEnergyPoints() > 0) {
		std::cout << "ScavTrap " << ClapTrap::getName() << " attacks " << target  << ", causing ";
		if (ClapTrap::getAttackDamage() > 0){
			std::cout << ClapTrap::getAttackDamage();
		} else {
			std::cout << "no";
		}
		std::cout << " points of damage!" << std::endl;
		ClapTrap::setEnergyPoints(ClapTrap::getEnergyPoints() - 1);
	} else {
		std::cout << "ScavTrap " << ClapTrap::getName() << " has no energy. Maybe it's time for the peace" << std::endl;
	}
}

void ScavTrap::guardGate( void ) {
	if (_guardMode) {
		std::cout << "ScavTrap " << ClapTrap::getName() << " is already in guard mode." << std::endl;
	} else {
		_guardMode = true;
		std::cout << "ScavTrap " << ClapTrap::getName() << " is now in guard mode." << std::endl;
	}
}
