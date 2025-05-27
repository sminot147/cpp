#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

class ScavTrap {
public:
    ScavTrap();
    ~ScavTrap();
    void attack(const std::string &target);
    void guardGate();
};

#endif // SCAVTRAP_HPP