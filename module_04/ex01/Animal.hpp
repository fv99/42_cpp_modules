#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
#include "Brain.hpp"

class Animal
{
	
	protected:
		std::string type;

	public:	
		Animal(void);
		Animal(const Animal &source);
		Animal &operator=(const Animal &source);
		virtual ~Animal(void);

		std::string getType(void) const;
		void setType(std::string newType);
	
	
		virtual Brain &getBrain(void) const = 0;
		virtual void makeSound(void) const;
};

#endif
