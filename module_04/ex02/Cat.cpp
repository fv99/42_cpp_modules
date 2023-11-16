#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Cat def constructor called" << std::endl;
	this->brain = new Brain();
	this->setType("Cat");
}

Cat::Cat(const Cat &source) : Animal(source)
{
	this->brain = new Brain(*source.brain);

	*this = source;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &source)
{
	this->type = source.type;
	*this->brain = *source.brain;
	std::cout << "Cat copy assignment constructor called" << std::endl;
	return *this;
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "hssssss meow meow purr" << std::endl;
}

Brain &Cat::getBrain(void) const
{
	return (*this->brain);
}

void	Cat::setBrain(Brain const &brain)
{
	*this->brain = brain;
}
