#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	{
		ClapTrap clap1("CL4P-TP");
		ClapTrap clap2("TR4P-CL");
		
		
		for (int i = 0; i < 12; i++) {
			std::cout << "\nAttack " << i + 1 << ":" << std::endl;
			clap1.attack("TR4P-CL");
			clap2.beRepaired(1);
			clap2.takeDamage(1);
		}
		std::cout << "\nOther test:" << std::endl;
		clap2.takeDamage(5);
		clap2.beRepaired(3);
	}
	
	ClapTrap clap;

	std::cout << "\nDead test:" << std::endl;
	clap.beRepaired(5);
	clap.takeDamage(10);
	clap.attack("CL4P-TP");

	
	return 0;
}