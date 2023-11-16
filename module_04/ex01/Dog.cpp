#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog def constructor called" << std::endl;
	this->brain = new Brain();
	this->setType("Dog");
}

Dog::Dog(const Dog &source) : Animal(source)
{
	this->brain = new Brain(*source.brain);
	*this = source;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &source)
{
	this->type = source.type;
	*this->brain = *source.brain;

	std::cout << "Dog copy assignment constructor called" << std::endl;
	return *this;
}

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "haf haf grrrrrrrr" << std::endl;
}

Brain &Dog::getBrain(void) const
{
	return (*this->brain);
}

void	Dog::setBrain(Brain const &brain)
{
	*this->brain = brain;
}

