#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {

private:
	Brain* _brain;

public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &rhs);
	~Cat();

	void setIdea(int index, const std::string &idea);
	std::string getIdea(int index) const;
	void makeSound() const;
};

#endif