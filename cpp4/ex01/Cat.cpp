#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal("Cat"), 
_brain(new Brain())
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	Animal::operator=(other);
	this->_brain = new Brain(*(other._brain));
}

Cat& Cat::operator=(const Cat &rhs){
	if (this != &rhs)
		Animal::operator=(rhs);
	delete this->_brain;
	this->_brain = new Brain(*(rhs._brain));
	return *this;
}

Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

void Cat::makeSound( void ) const {
	std::cout << "Meow"  << std::endl;
}


void Cat::setIdea(int index, const std::string &idea) {
	if (index >= 0 && index < 100) {
		_brain->setIdea(index, idea);
	}
}

std::string Cat::getIdea(int index) const {
	if (index >= 0 && index < 100) {
		return _brain->getIdea(index);
	}
	return "";
}