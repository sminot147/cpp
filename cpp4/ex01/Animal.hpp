#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {

private :
	std::string _type;

public:
	Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual ~Animal();

	Animal(const std::string type);

	virtual void makeSound() const;
	std::string getType() const;
};

#endif