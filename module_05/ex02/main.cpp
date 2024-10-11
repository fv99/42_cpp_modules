/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:47:43 by fvonsovs          #+#    #+#             */
/*   Updated: 2024/10/11 16:20:33 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main(void)
{
	/* Create the 3 forms and some Bureaucrats */

	ShrubberyCreationForm shrubbery("shrub");
	RobotomyRequestForm robotomy("robo");
	PresidentialPardonForm pardon("trump");
	Bureaucrat bur1("bur1", 150);
	Bureaucrat bur2("bur2", 120);
	Bureaucrat bur3("bur3", 3);
	
	/* Try to execute forms without being signed */
	{
		try
		{
			std::cout << bur1 << std::endl;
			std::cout << shrubbery << std::endl;
			std::cout << robotomy << std::endl;
			std::cout << pardon << std::endl;
			bur1.executeForm(shrubbery);
			bur1.executeForm(robotomy);
			bur1.executeForm(pardon);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n --------------------- \n\n";
	
	/* Sign form and try to execute without enough grade */
	{
		try
		{
			std::cout << bur1 << std::endl;
			std::cout << bur2 << std::endl;
			std::cout << shrubbery << std::endl;
			std::cout << robotomy << std::endl;
			std::cout << pardon << std::endl;
			shrubbery.beSigned(bur2);
			bur1.executeForm(shrubbery);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n --------------------- \n\n";
	
	/* Sign forms and execute them */
	{
		try
		{
			robotomy.beSigned(bur3);
			pardon.beSigned(bur3);
			std::cout << shrubbery << std::endl;
			std::cout << robotomy << std::endl;
			std::cout << pardon << std::endl;
			
			std::cout << "\n --------------------- \n\n";
			bur3.executeForm(shrubbery);
			std::cout << "\n --------------------- \n\n";
			bur3.executeForm(robotomy);
			std::cout << "\n --------------------- \n\n";
			bur3.executeForm(pardon);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
	std::cout << "\n --------------------- \n\n";


	return (0);
}
