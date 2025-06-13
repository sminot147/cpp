#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include <cassert>

int main() {

	{
		std::cout << "\n=== Testing Animal Array ===" << std::endl;
		
		Animal *animals[4];
		
		animals[0] = new Cat();
		animals[1] = new Dog(); 

		assert(animals[0]->getType() == "Cat");
		assert(animals[1]->getType() == "Dog");
		
		for(int i = 0; i < 2; i++) {
			delete animals[i];
		}
	}
	{
		std::cout << "\n=== Testing Cat Deep Copy ===" << std::endl;
		
		Cat original;
		original.setIdea(0, "test 1");
		original.setIdea(1, "test 2");
		
		Cat copy(original);
		assert(copy.getIdea(0) == "test 1");
		assert(copy.getIdea(1) == "test 2");
		
		original.setIdea(0, "modify my think");
		assert(copy.getIdea(0) == "test 1");
	}

	{
		std::cout << "\n=== Testing Dog Deep Copy ===" << std::endl;
		
		Dog original;
		original.setIdea(5, "Dog is stupid");
		
		Dog copy(original);
		assert(copy.getIdea(5) == "Dog is stupid");
	}

	{
		std::cout << "\n=== Testing Idea Boundaries ===" << std::endl;
		
		Cat cat;
		
		cat.setIdea(0, "test");
		cat.setIdea(99, "test");
		
		assert(cat.getIdea(0) == "test");
		assert(cat.getIdea(99) == "test");
	
		std::cout <<  cat.getIdea(20) << cat.getIdea(0) <<std::endl;
		assert(cat.getIdea(10) == "");
		assert(cat.getIdea(-1) == "");
	}

	std::cout << "\nAll tests passed successfully!" << std::endl;
	return 0;
}
