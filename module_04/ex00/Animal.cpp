#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal def constructor called" << std::endl;
}

Animal::Animal(const Animal &source)
{
	*this = source;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &source)
{
	this->type = source.type;
	std::cout << "Animal copy assignment constructor called" << std::endl;
	return *this;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType(void) const
{
	return this->type;
}

void Animal::setType(std::string newType)
{
	this->type = newType;
}

void Animal::makeSound(void)
{
	std::cout << "Animal make sound called" << std::endl; 
}