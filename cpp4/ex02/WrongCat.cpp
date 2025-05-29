#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other){
	WrongAnimal::operator=(other);
}

WrongCat& WrongCat::operator=(const WrongCat &rhs){
	if (this != &rhs)
	WrongAnimal::operator=(rhs);
	return *this;
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound( void ) const {
	std::cout << "Meow"  << std::endl;
}