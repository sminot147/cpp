#include "Character.hpp"
#include <iostream>

Character::Character(void) :
_name("Default"), _nbMatFloor(0)
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
	for (int i = 0; i < MAX_MAT_ON_FLOOR; ++i)
		floor[i] = NULL;
}

Character::Character(const Character &other) : 
_name(other._name),  _nbMatFloor(other._nbMatFloor)
{
	for (int i = 0; i < 4; ++i){
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character & Character::operator=(const Character &rhs){
	_nbMatFloor = rhs._nbMatFloor;
	_name = rhs._name;
	for (int i = 0; i < 4; ++i){
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
		if (rhs._inventory[i])
			_inventory[i] = rhs._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	return *this;
}

Character::~Character(){
	for (int i = 0; i < _nbMatFloor; i++){
		delete floor[i];
	}
	for (int i = 0; i < 4; ++i){
		delete _inventory[i];
	}
}



Character::Character(std::string name) :
_name(name), _nbMatFloor(0)
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
	for (int i = 0; i < MAX_MAT_ON_FLOOR; ++i)
		floor[i] = NULL;
}

std::string const & Character::getName(void) const {
	return this->_name;
}

void Character::equip(AMateria* m){
	for (int i = 0; i < 4; ++i){
		if (this->_inventory[i] == NULL){
			this->_inventory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx){
	if (idx >= 4 || idx < 0)
		return ;
	if (this->_inventory[idx] != NULL){
		if (_nbMatFloor >= MAX_MAT_ON_FLOOR - 1){
			for (int i = 0; i < 50; ++i){
				delete floor[i];
				floor[i] = floor [i + 50];
				floor[i + 50] = NULL;
			}
			_nbMatFloor = 50;
		}
		this->floor[_nbMatFloor] = _inventory[idx];
		_nbMatFloor++;

		this->_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target){
	if (idx >= 4 || idx < 0)
		return ;
	if (this->_inventory[idx] != NULL){	 
		_inventory[idx]->use(target);
		delete _inventory[idx];
		_inventory[idx] = NULL;
	}
}
