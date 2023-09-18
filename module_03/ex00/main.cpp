#include "ClapTrap.hpp"

int main()
{
	ClapTrap a;
	ClapTrap b("dodik");

	a.attack("eblan");
	a.takeDamage(10);
	a.takeDamage(10);
	a.beRepaired(5);
	a.attack("eblanishe");
	b.beRepaired(3);
	for (int i = 0; i < 12; i++)
		b.attack("lox");
	b.beRepaired(3);
	
	return (0);
}