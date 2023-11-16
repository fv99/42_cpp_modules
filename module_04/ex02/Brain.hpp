#include <iostream>

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain(void);
		Brain(Brain const &source);
		~Brain(void);

		Brain const &operator=(Brain const &source);

		std::string const &getIdea(int const &index) const;
		void setIdea(std::string const &idea, int const &index);
};
