#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap : public ClapTrap {

private:
	bool _guardMode;

public:
	//canonical form
	FragTrap();
	FragTrap(const FragTrap &other);
	FragTrap &operator=(const FragTrap &other);
	~FragTrap();

	//other constructor
	FragTrap(const std::string &name);
	
	// Functions
	void attack(const std::string &target);
	void highFivesGuys();
};

#endif