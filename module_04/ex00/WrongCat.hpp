#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include <string>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(const WrongCat &original);
		WrongCat &operator=(const WrongCat &source);
		~WrongCat();

		void makeSound(void) const;
};

#endif
