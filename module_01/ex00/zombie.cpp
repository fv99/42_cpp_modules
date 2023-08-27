
#include "zomibe.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "Created Zombie object " << this->name << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Destroyed Zombie object " << this->name << std::endl;
}

void Zombie::announce()
{
	std::cout << this->name " BraiiiiiiinnnzzzZ..." << std::endl;
}