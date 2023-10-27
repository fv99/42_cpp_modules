#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	
	protected:
		std::string type;

	public:	
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &source);
		WrongAnimal &operator=(const WrongAnimal &source);
		virtual ~WrongAnimal(void);

		std::string getType(void) const;
		virtual void makeSound(void) const;
};

#endif
