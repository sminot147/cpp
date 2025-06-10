#ifndef MATERIALSOURCE_HPP
# define MATERIALSOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MaterialSource : public IMateriaSource
{
private:
	AMateria*   _inventory[4];
	
public:
	MaterialSource();
	MaterialSource(MaterialSource const & src);
	MaterialSource & operator=(MaterialSource const & rhs);
	~MaterialSource();
	
	
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif