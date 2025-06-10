#ifndef MATERIALSOURCE_HPP
# define MATERIALSOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria*   _inventory[4];
	
public:
	MateriaSource();
	MateriaSource(MateriaSource const & src);
	MateriaSource & operator=(MateriaSource const & rhs);
	~MateriaSource();
	
	
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif