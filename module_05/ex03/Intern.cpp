/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:04:50 by fvonsovs          #+#    #+#             */
/*   Updated: 2024/10/14 14:33:52 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "default constructor called for intern " << std::endl;
}

Intern::Intern(const Intern &src)
{
	std::cout << "copy constructor called for intern" << std::endl;
	*this = src;
}

Intern::~Intern()
{
	std::cout << "intern deconstructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &src)
{
	std::cout << "assignment operator called for intern" << std::endl;
	if (this == &src)
		return *this;
	
	return *this;
}

static Form	*makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static Form	*makeRobotomy(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static Form	*makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form *Intern::makeForm(std::string name, std::string target)
{
	const std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	Form *(*all_forms[])(const std::string target) = {&makePresident, &makeRobotomy, &makeShrubbery};

	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i])
		{
			std::cout << "intern makes" << name << std::endl;
			return(all_forms[i](target));
		}
	}

	std::cout << "intern cannot create a form" << name << std::endl;
	return NULL;
}
