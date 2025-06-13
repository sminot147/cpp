#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include <cassert>

void testAnimalArray() {
	std::cout << "\n=== Testing Animal Array ===" << std::endl;
	
	Animal *animals[4];
	animals[0] = new Cat();
	animals[1] = new Dog(); 
	animals[2] = new Cat();
	animals[3] = new Dog();

	// Test proper type assignment
	assert(animals[0]->getType() == "Cat");
	assert(animals[1]->getType() == "Dog");
	
	// Clean up
	for(int i = 0; i < 4; i++) {
		delete animals[i];
	}
}

void testCatDeepCopy() {
	std::cout << "\n=== Testing Cat Deep Copy ===" << std::endl;
	
	Cat original;
	original.setIdea(0, "Original idea");
	original.setIdea(1, "Second thought");
	
	// Test copy constructor
	Cat copy(original);
	assert(copy.getIdea(0) == "Original idea");
	assert(copy.getIdea(1) == "Second thought");
	
	// Modify original to verify deep copy
	original.setIdea(0, "Modified idea");
	assert(copy.getIdea(0) == "Original idea");
	
	// Test assignment operator
	Cat assigned;
	assigned = original;
	assert(assigned.getIdea(0) == "Modified idea");
	
	// Modify original again
	original.setIdea(0, "Third modification");
	assert(assigned.getIdea(0) == "Modified idea");
}

void testDogDeepCopy() {
	std::cout << "\n=== Testing Dog Deep Copy ===" << std::endl;
	
	Dog original;
	original.setIdea(0, "Dog thought");
	
	Dog copy(original);
	assert(copy.getIdea(0) == "Dog thought");
	
	original.setIdea(0, "New dog thought");
	assert(copy.getIdea(0) == "Dog thought");
}

void testIdeaBoundaries() {
	std::cout << "\n=== Testing Idea Boundaries ===" << std::endl;
	
	Cat cat;
	
	// Test setting and getting ideas at boundaries
	cat.setIdea(0, "First");
	cat.setIdea(99, "Last");
	
	assert(cat.getIdea(0) == "First");
	assert(cat.getIdea(99) == "Last");
	
	// Test invalid indices should return empty string
	assert(cat.getIdea(100) == "");
	assert(cat.getIdea(-1) == "");
}

void testAbstractAnimal() {
	std::cout << "\n=== Testing Abstract Animal ===" << std::endl;
	
	// Following line should not compile as Animal is abstract
	// Animal animal; 
	
	// But we can create pointers to Animal
	Animal* cat = new Cat();
	Animal* dog = new Dog();
	
	assert(cat->getType() == "Cat");
	assert(dog->getType() == "Dog");
	
	delete cat;
	delete dog;
}

int main() {
	std::cout << "Starting tests..." << std::endl;
	
	testAnimalArray();
	testCatDeepCopy();
	testDogDeepCopy();
	testIdeaBoundaries();
	testAbstractAnimal();
	
	std::cout << "\nAll tests passed successfully!" << std::endl;
	return 0;
}
