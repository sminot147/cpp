#include "ClapTrap.hpp"

#include <unistd.h>

/*----------------------------------------------------------------------------*/
/*                              Canonical Form                                */
/*----------------------------------------------------------------------------*/

ClapTrap::ClapTrap() :
_name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) :
_name(other._name), _hitPoints(other._hitPoints),
_energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap " << _name << " copied." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destroyed." << std::endl;
}

/*----------------------------------------------------------------------------*/
/*                           Other Constructor                                */
/*----------------------------------------------------------------------------*/

ClapTrap::ClapTrap(const std::string &name) :
_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " created." << std::endl;
}


/*----------------------------------------------------------------------------*/
/*                              Functions                                     */
/*----------------------------------------------------------------------------*/

void	ClapTrap::attack(const std::string &target) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is dead... Take a minute of silence in his memory." << std::endl;
		sleep(60);
		return;
	}
	if (_energyPoints > 0) {
		std::cout << "ClapTrap " << _name << " attacks " << target  << ", causing ";
		if (_attackDamage > 0){
			std::cout << _attackDamage;
		} else {
			std::cout << "no";}
		std::cout << " points of damage!" << std::endl;
		--_energyPoints;
	}
	else {
		std::cout << "ClapTrap " << _name << " have no energy. Maybe it's time for the peace" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is already dead. Stop attack him and take a minute of silence in his memory." << std::endl;
		sleep(60);
		return ;
	}
	if (amount >= _hitPoints) {
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
		return ;
	}
	if (amount == 0) {
		std::cout << "ClapTrap " << _name << " takes no damage." << std::endl;
		return;
	}
	_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is dead... Take a minute of silence in his memory." << std::endl;
		sleep(60);
		return;
	}
	if (amount == 0) {
		std::cout << "ClapTrap " << _name << " repairs nothing." << std::endl;
		return;
	}
	if (_hitPoints == 10) {
		std::cout << "ClapTrap " << _name << " is already at full health." << std::endl;
		return;
	}
	if (_energyPoints > 0) {
		--_energyPoints;
		std::cout << "ClapTrap " << _name << " repairs itself. He have " << _hitPoints << " hit points before repair and ";
		if (amount > 10 || _hitPoints + amount > 10) {
			_hitPoints = 10;
		}
		else {
			_hitPoints += amount;
		}
		std::cout <<  _hitPoints << " after." << std::endl;
	} else {
		std::cout << "ClapTrap " << _name << " have no energy. He can't repair itself" << std::endl;
	}
}



