#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "ICharacter"


class Character : public Character
{
public:
	virtual ~Character() {}
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif
