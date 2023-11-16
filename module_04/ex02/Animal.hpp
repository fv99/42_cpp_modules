#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
#include "Brain.hpp"

class Animal
{
	protected:
		Animal(void);
		// Animal(std::string const &type);
		Animal(const Animal &source);
		std::string type;

	public:	
		virtual ~Animal(void);
		Animal &operator=(const Animal &source);

		std::string getType(void) const;
		void setType(std::string newType);
	
		virtual Brain &getBrain(void) const = 0;
		virtual void makeSound(void) const;
};

#endif
