#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const FragTrap &copy);
		FragTrap(std::string name);

		~FragTrap();

		FragTrap &operator=(const FragTrap &src);

		void highFiveGuys(void);

};
