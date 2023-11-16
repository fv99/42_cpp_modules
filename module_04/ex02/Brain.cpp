#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain def constructor called" << std::endl;
}

Brain::Brain(const Brain &source)
{
	*this = source;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain const &Brain::operator=(const Brain &source)
{
	std::copy(source.ideas, source.ideas + 100, this->ideas);
	std::cout << "Brain copy assignment constructor called" << std::endl;
	return *this;
}

std::string const	&Brain::getIdea(int const &index) const
{
	if (index >= 0 && index < 100)
		return (this->ideas[index]);
	return (this->ideas[0]);
}

void	Brain::setIdea(std::string const &idea, int const &index)
{
	if (index >= 0 && index < 100)
		this->ideas[index] = idea;
}


