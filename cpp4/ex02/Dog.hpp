#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {

	private:
		Brain* _brain;

	public:
		Dog();
		Dog(const Dog &other);
		virtual ~Dog();
		Dog &operator=(const Dog &other);

		void setIdea(int index, const std::string &idea);
		std::string getIdea(int index) const;
		void makeSound() const;
};

#endif