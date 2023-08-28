#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): name(name), weapon(weapon)
{
    std::cout << "Created HumanA: " << name << " with weapon " << weapon.getType() << std::endl;
}

HumanA::~HumanA(void)
{
    std::cout << "Destroyed HumanA: " << name << std::endl;
}

void HumanA::attack(void)
{
    std::cout << this->name << " attacked with his " << this->weapon.getType() << std::endl;
} 

void HumanA::setWeapon(Weapon weapon)
{
    this->weapon = weapon;
}