#include "Zombie.hpp"

Zombie* newZombie( std::string name)
{
	return (new Zombie(name));
}

void randomChump(std::string name)
{
	Zombie a = Zombie(name);
	a.announce();
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "\tCreated Zombie object: " << this->name << std::endl;
}

Zombie::Zombie(void)
{
	this->name = "unnamed";
	std::cout << "\tCreated Zombie object: " << this->name << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "\tDestroyed Zombie object: " << this->name << std::endl;
}

void Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}