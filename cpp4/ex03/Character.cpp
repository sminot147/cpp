#include "Character.hpp"
#include <iostream>

Character::Character(void) : _name("Default")
{}

Character::Character(const Character &other) : 
_name(other._name)
{
	for (int i = 0; i < 4; ++i){
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = nullptr;
	}
}

Character & Character::operator=(const Character &rhs){
	_name = rhs._name;
	for (int i = 0; i < 4; ++i){
		if (this->_inventory[i] != nullptr)
			delete this->_inventory[i];
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = nullptr;
	}
}

Character::~Character(){
	for (int i = 0; i <= _nbMatFloor; ++i){
		delete floor[i];
	}
	for (int i = 0; i < 4; ++i){
		delete _inventory[i];
	}
}



Character::Character(std::string name) : _name(name)
{}

std::string const & Character::getName(void) const {
	return this->_name;
}

void Character::equip(AMateria* m){
	for (int i = 0; i < 4; ++i){
		if (this->_inventory[i] == nullptr){
			this->_inventory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx){
	if (idx >= 4)
		return ;
	if (this->_inventory[idx] != nullptr){
		if (_nbMatFloor >= MAX_MAT_ON_FLOOR - 1){
			std::cout << "The old objects have dispawned" << std::endl;
			for (int i = 0; i < 50; ++i){
				delete floor[i];
				floor[i] = floor [i + 50];
				floor[i + 50] = nullptr;
			}
			_nbMatFloor = 50;
		}
		floor[_nbMatFloor] = _inventory[idx];
		_nbMatFloor++;
		this->_inventory[idx] = nullptr;
	}
}

void Character::use(int idx, ICharacter& target){
	if (idx >= 4)
		return ;
	if (this->_inventory[idx] != nullptr){	 
		_inventory[idx]->use(target);
		delete _inventory[idx];
		_inventory[idx] = nullptr;
	}
}
