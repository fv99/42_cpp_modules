#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("unnamed"), hp(10), energy(10), dmg(1)
{
	std::cout << "claptrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "claptrap copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap::ClapTrap(std::string name): name(name), hp(10), energy(10), dmg(1)
{
	std::cout << "claptrap named constructor called, named " << name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "claptrap deconstrucotr called for " << name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "claptrap assign operator called" << std::endl;
	this->name = src.name;
	this->hp = src.hp;
	this->energy = src.energy;
	this->dmg = src.dmg;
	return *this;
}

void ClapTrap::attack(const std::string &target)
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

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hp > amount)
		this->hp -= amount;
	else if (this->hp > 0)
		this->hp = 0;
	else
	{
		std::cout << this->name << " is dead" << std::endl;
		return ;
	}
	std::cout << this->name << " was hit for " << amount << " damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy > 0 && this->hp > 0 && this->hp <= 10)
	{
		this->hp += amount;
		std::cout << this->name << " repaired himself for " << amount << " HP" << std::endl;
		this->energy--;
	}
	else if (this->energy == 0)
		std::cout << this->name << " has no energy for repairs" << std::endl;
	else if (this->hp <= 0)
		std::cout << this->name << " is dead" << std::endl;
	else
		std::cout << this->name << " is already at full HP" << std::endl;
}