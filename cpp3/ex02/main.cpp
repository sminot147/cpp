#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	{
		FragTrap frag("Bob");
		
		std::cout << "\n=== Testing energy points ===\n" << std::endl;
		for (int i = 0; i < 101; ++i) {
			std::cout << "Attack " << i + 1 << ": ";
			frag.attack("Target");
		}
	}
	{
		std::cout << "\n=== Testing basic functions ===\n" << std::endl;
		FragTrap frag("Bob");
		frag.highFivesGuys();
		frag.attack("ALice");
		frag.takeDamage(60);
		frag.beRepaired(10);
		frag.takeDamage(60);
		frag.beRepaired(10);
	}

	return 0;

}