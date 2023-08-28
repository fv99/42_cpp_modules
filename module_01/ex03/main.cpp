#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
    {
        Weapon ak = Weapon("ak47");

        HumanA eblan("eblan", ak);
        eblan.attack();
        ak.setType("kalach kalach");
        eblan.attack();
    }
    {
        Weapon deagle = Weapon("deagle");

        HumanB lox("lox");
        lox.setWeapon(deagle);
        lox.attack();
        deagle.setType("deagle brand deagle");
        lox.attack();
    }
    return (0);
}