#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria( void ) :
	_type("Default type")
{}

AMateria::AMateria(const AMateria &other) :
	_type(other._type)
{
	_type = other._type;
}

AMateria & AMateria::operator=(const AMateria &rhs)
{
	if (this != &rhs) {
		this->_type = rhs._type;
	}
}

AMateria::~AMateria()
{}

AMateria::AMateria(std::string const & type) :
	_type(type)
{}

std::string const & AMateria::getType( void ) const {
	return _type;
}

void use(ICharacter& target)
{
	std::cout << "You never see this message !" <<std::endl;
}
