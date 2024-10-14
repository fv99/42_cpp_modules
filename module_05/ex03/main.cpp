/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:47:43 by fvonsovs          #+#    #+#             */
/*   Updated: 2024/10/14 15:46:05 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"


int main(void)
{
	Bureaucrat bur1 = Bureaucrat("bur1", 3);
	Bureaucrat bur1_copy = bur1;
	Bureaucrat bur2 = Bureaucrat("bur2", 150);
	Bureaucrat bur3 = Bureaucrat("bur3", 20);

	Intern mrSlave = Intern();

	Form *form1 = mrSlave.makeForm("ShrubberyCreationForm", "target1");
	Form *form2 = mrSlave.makeForm("PresidentialPardonForm", "target2");
	Form *form3 = mrSlave.makeForm("RobotomyRequestForm", "target3");
	
	mrSlave.makeForm("invalid", "target4");

	bur1.executeForm(*form1);
	bur2.signForm(*form1);
	bur1.signForm(*form1);
	bur2.executeForm(*form1);
	bur1.executeForm(*form1);

	bur3.signForm(*form2);
	bur3.executeForm(*form2);

	bur3.signForm(*form3);
	bur3.executeForm(*form3);
	bur1.executeForm(*form3);

	delete form1;
	delete form2;
	delete form3;

	return 0;
}
