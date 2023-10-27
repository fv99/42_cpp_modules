#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat &original);
		Cat &operator=(const Cat &source);
		~Cat();

		void makeSound(void) const;
};

#endif
