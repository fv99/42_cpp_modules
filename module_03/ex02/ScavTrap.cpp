#include "ScavTrap.hpp"


ScavTrap::ScavTrap(): ClapTrap(), guarding(false)
{
	std::cout << "ScavTrap constructor called" << std::endl;

	this->hp = 100;
	this->energy = 50;
	this->dmg = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = copy;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name), guarding(false)
{
	std::cout << "ScavTrap named constructor called, named " << name << std::endl;

	this->hp = 100;
	this->energy = 50;
	this->dmg = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap deconstrucotr called for " << name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "ScavTrap assign operator called" << std::endl;
	this->name = src.name;
	this->hp = src.hp;
	this->energy = src.energy;
	this->dmg = src.dmg;
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->energy > 0 && this->hp > 0)
	{
		std::cout << this->name << " attacks " << target << " for " << this->dmg << std::endl;
		this->energy--;
	}
	else if (this->energy == 0)
		std::cout << this->name << " is out of energy" << std::endl;
	else
		std::cout << this->name << " is out of energy" << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (this->guarding == false)
	{
		this->guarding = true;
		std::cout << this->name << " is guarding the gate" << std::endl;
	}
	else
		std::cout << this->name << " is already guarding the gate" << std::endl;
}