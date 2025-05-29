#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"

int main()
{
	{
		Animal *animal[100];
		for (int i = 0; i < 50; i++)
			animal[i] = new Cat();
		for (int i = 50; i < 100; i++)
			animal[i] = new Dog();
		
		animal[25]->makeSound();
		animal[75]->makeSound();
		for (int i = 0; i < 100; i++){
			std::cout << "animal[" << i << "] type: " << animal[i]->getType() << std::endl;
			delete animal[i];
		}

	}

	{
		std::cout << "==== Test idea copy ===="<< std::endl;

		Cat cat1;

		cat1.setIdea(0, "Testing");
		{

			Cat cat2 = cat1;
			std::cout << "cat2 idea: " << cat2.getIdea(0) << std::endl;
		}
		{

			Cat cat3(cat1);
			std::cout << "cat3 idea: " << cat3.getIdea(0) << std::endl;
		}

	}
	{
		std::cout << "==== Old test ===="<< std::endl;
		// const Animal* meta = new Animal();
		// meta->makeSound();
		// delete meta;


		const Animal* i = new Cat();
		const Animal* j = new Dog();

		std::cout << i->getType() << " make ";
		i->makeSound();
		std::cout << j->getType() << " make  ";
		j->makeSound();
		

		delete i;
		delete j;
	}

return 0;
}