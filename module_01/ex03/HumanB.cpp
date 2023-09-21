#include "HumanB.hpp"

HumanB::HumanB(std::string name): weapon(NULL)
{
    this->name = name;
    std::cout << "Created HumanB: " << name << " without weapon " << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << "Destroyed HumanB: " << name << std::endl;
}

void HumanB::attack(void)
{
    std::cout << this->name << " attacked with his " << this->weapon->getType() << std::endl;
} 

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}
