#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	{
		ScavTrap scav1("Bob");
		
		std::cout << "\n=== Testing energy points ===\n" << std::endl;
		for (int i = 0; i < 51; ++i) {
			std::cout << "Attack " << i + 1 << ": ";
			scav1.attack("Target");
		}
	}
	{
		std::cout << "\n=== Testing basic functions ===\n" << std::endl;
		ScavTrap scav1("Bob");
		ScavTrap scav2("Alice");

		std::cout << "\n=== Testing gard mode ===\n" << std::endl;
		scav1.guardGate();
		scav1.guardGate();

		std::cout << "\n=== Testing other ===\n" << std::endl;
		scav1.attack("Alice");
		scav2.takeDamage(60);
		scav2.beRepaired(10);
		scav1.attack("Alice");
		scav2.takeDamage(60);
		scav2.beRepaired(10);
		scav2 = scav1;
		scav2.attack("Test");
	}

	return 0;
}