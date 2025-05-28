#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : public ClapTrap {

private:
    bool _guardMode;

public:
    //canonical form
    ScavTrap();
    ScavTrap(const ScavTrap &other);
    ScavTrap &operator=(const ScavTrap &other);
    ~ScavTrap();

    //other constructor
    ScavTrap(const std::string &name);
    
    // Functions
    void attack(const std::string &target);
    void guardGate();
};

#endif