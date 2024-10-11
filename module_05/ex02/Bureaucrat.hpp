#include <iostream>
#include <string>

class Form;

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
		Bureaucrat(int grade);
		Bureaucrat(const Bureaucrat &src);
	
		// deconstructor
		~Bureaucrat();

		// increments
		void incrementGrade(void);
		void decrementGrade(void);

		// getters
		const std::string getName(void)const;
		size_t getGrade(void)const;

		// overload
		Bureaucrat &operator=(const Bureaucrat &src);

		//signing
		void signForm(Form &form);

		// executing
		void executeForm(Form const &form);

		// exceptions
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &ret, Bureaucrat const &bur);
