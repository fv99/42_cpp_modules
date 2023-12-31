#ifndef CLAP_HPP
# define CLAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	protected:
		std::string name;
		unsigned int hp;
		unsigned int energy;
		unsigned int dmg;

	public:
		ClapTrap();
		ClapTrap(const ClapTrap &copy);
		ClapTrap(std::string name);
		~ClapTrap();

		ClapTrap &operator=(const ClapTrap &src);

		void attack(const std::string &target);
		void takeDamage (unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
