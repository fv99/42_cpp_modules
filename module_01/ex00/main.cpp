#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie *a = newZombie("eblan");
	Zombie *b = newZombie("lox");
	Zombie *c = newZombie("pidar");

	a->announce();
	b->announce();
	c->announce();

	randomChump("dolbaeb");

	delete a;
	delete b;
	delete c;

	return (0);
}