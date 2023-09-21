#include "FragTrap.hpp"


FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "FragTrap constructor called" << std::endl;

	this->hp = 100;
	this->energy = 100;
	this->dmg = 30;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = copy;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap named constructor called, named " << name << std::endl;

	this->hp = 100;
	this->energy = 100;
	this->dmg = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap deconstrucotr called for " << name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	std::cout << "FragTrap assign operator called" << std::endl;
	this->name = src.name;
	this->hp = src.hp;
	this->energy = src.energy;
	this->dmg = src.dmg;
	return *this;
}

void FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap " << name << " wants a hi five" << std::endl;
}
