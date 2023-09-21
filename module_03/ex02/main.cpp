#include "FragTrap.hpp"
#include "ScavTrap.hpp"

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


	ScavTrap c;
	ScavTrap d("pidar");

	c.attack("pidar");
	c.takeDamage(10);
	d.takeDamage(10);
	c.beRepaired(20);
	d.beRepaired(20);
	c.guardGate();
	c.guardGate();
	d.guardGate();
	d.guardGate();
	c.takeDamage(999);
	c.takeDamage(1);


	FragTrap e;
	FragTrap f("nagibator");

	e.attack("pidar");
	
	e.takeDamage(10);
	f.takeDamage(10);
	e.highFiveGuys();
	f.highFiveGuys();
	e.takeDamage(999);
	e.takeDamage(1);

	return (0);
}
