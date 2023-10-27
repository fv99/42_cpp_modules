#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog def constructor called" << std::endl;
	this->setType("Dog");
}

Dog::Dog(const Dog &source) : Animal(source)
{
	*this = source;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &source)
{
	this->type = source.type;
	std::cout << "Dog copy assignment constructor called" << std::endl;
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "haf haf grrrrrrrr" << std::endl;
}
