#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{

		const Animal* meta = new Animal();
		const Animal* i = new Cat();
		const Animal* j = new Dog();

		meta->makeSound();
		std::cout << i->getType() << " make ";
		i->makeSound();
		std::cout << j->getType() << " make  ";
		j->makeSound();
		
		meta->makeSound();
		
		delete meta;
		delete i;
		delete j;
	}
	{
		std::cout << "======test Wrong Cat===========" << std::endl;
		
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();

		meta->makeSound();
		i->makeSound();


		delete meta;
		delete i;
}

return 0;
}