#include "Cure.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure")
{}

Cure::Cure(const Cure &other) : AMateria(other)
{}

Cure & Cure::operator=(const Cure &other)
{
	AMateria::operator=(other);
}

Cure::~Cure(){}

AMateria * Cure::clone() const
{
	return &Cure(*this);
}

void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}