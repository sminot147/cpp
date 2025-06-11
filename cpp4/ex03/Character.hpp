#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

# define MAX_MAT_ON_FLOOR 100

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria * _inventory[4];
	AMateria * floor[MAX_MAT_ON_FLOOR];
	int _nbMatFloor;

public:

	Character();
	Character(const Character &other);
	Character & operator=(const Character &rhs);
	~Character();

	Character(std::string name);
	
	std::string const & getName() const;
	void equip(AMateria * m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif
