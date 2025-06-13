#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include <cassert>

int main() {

	
	// Animal animal; // Impossible because abstract


	// But we can create pointers to Animal
	Animal* cat = new Cat();
	Animal* dog = new Dog();
	
	assert(cat->getType() == "Cat");
	assert(dog->getType() == "Dog");
	cat->makeSound(); 
	dog->makeSound();

	delete cat;
	delete dog;

	return 0;
}
