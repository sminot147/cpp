#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other){
	Animal::operator=(other);
}

Dog& Dog::operator=(const Dog &rhs){
	if (this != &rhs)
		Animal::operator=(rhs);
	return *this;
}

Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound( void ) const {
	std::cout << "Woof" <<std::endl;
}