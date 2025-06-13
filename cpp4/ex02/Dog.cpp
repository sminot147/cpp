#include "Dog.hpp"

Dog::Dog() : Animal("Dog"),
_brain(new Brain)
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other){
	Animal::operator=(other);
	this->_brain = new Brain(*(other._brain));
}

Dog& Dog::operator=(const Dog &rhs){
	if (this != &rhs)
		Animal::operator=(rhs);
	delete this->_brain;
	this->_brain = new Brain(*(rhs._brain));
	return *this;
}

Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

void Dog::makeSound( void ) const {
	std::cout << "Woof" <<std::endl;
}


void Dog::setIdea(int index, const std::string &idea) {
	if (index >= 0 && index < 100) {
		_brain->setIdea(index, idea);
	}
}

std::string Dog::getIdea(int index) const {
	if (index >= 0 && index < 100) {
		return _brain->getIdea(index);
	}
	return "";
}