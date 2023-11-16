#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog &original);
		Dog &operator=(const Dog &source);
		~Dog();

		void makeSound(void) const;
		Brain &getBrain(void) const;
		void setBrain(Brain const &brain);
};

#endif
