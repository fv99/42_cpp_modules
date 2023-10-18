#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

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

		virtual void makeSound(void) const;
};

#endif ANIMAL_HPP
