#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other){
	Animal::operator=(other);
}

Cat& Cat::operator=(const Cat &rhs){
	if (this != &rhs)
		Animal::operator=(rhs);
	return *this;
}

Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound( void ) const {
	std::cout << "Meow"  << std::endl;
}