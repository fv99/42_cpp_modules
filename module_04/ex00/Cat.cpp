#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Cat def constructor called" << std::endl;
	this->setType("Cat");
}

Cat::Cat(const Cat &source) : Animal(source)
{
	*this = source;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &source)
{
	this->type = source.type;
	std::cout << "Cat copy assignment constructor called" << std::endl;
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "hssssss meow meow purr" << std::endl;
}
