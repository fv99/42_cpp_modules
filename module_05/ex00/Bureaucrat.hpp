# include <iostream>
# include <string>

class Bureaucrat
{
	private:
		const std::string name;
		size_t	grade;
		void setGrade(int grade);

	public:
		// constructors
		Bureaucrat();
		Bureaucrat(const std::string name);
		Bureaucrat(const std::string name, int grade);

		// deconstructor
		~Bureaucrat();


		// getters
		const std::string getName(void)const;
		size_t getGrade(void)const;


}