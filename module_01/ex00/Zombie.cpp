
#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
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