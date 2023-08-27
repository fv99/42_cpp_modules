#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
Zombie *zombieHorde( int N, std::string name );

int	main(void)
{
	const int N = 5;
	
	Zombie* horde = zombieHorde(N, "eblan");
	for (int i = 0; i < N; ++i)
		horde[i].announce();

	delete[] horde;

	return (0);
}