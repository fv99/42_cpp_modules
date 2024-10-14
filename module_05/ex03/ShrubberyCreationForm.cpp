/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:36:07 by fvonsovs          #+#    #+#             */
/*   Updated: 2024/10/11 16:13:06 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): Form::Form("shrubbery creation form", 145, 137), _target(NULL)
{
	std::cout << "default constructor called for form " << this->getName() << ", grade to sign " << this->getSignGrade() \
	 << ", grade to exec " << this->getExecGrade() << ", target:" << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): Form::Form("shrubbery creation form", 145, 137), _target(target)
{
	std::cout << "constructor called for form " << this->getName() << ", grade to sign " << this->getSignGrade() \
	 << ", grade to exec " << this->getExecGrade() << ", target:" << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy): Form::Form(copy), _target(copy._target)
{
	std::cout << "copy constructor called for form " << this->getName() << ", grade to sign " << this->getSignGrade() \
	 << ", grade to exec " << this->getExecGrade() << ", target:" << _target << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "destructor called for form " << this->getName() << std::endl;
}

ShrubberyCreationForm const	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	Form::operator=(copy);
	this->_target = copy._target;
	return (*this);
}

void ShrubberyCreationForm::beExecuted(const Bureaucrat &bureaucrat) const
{
	std::ofstream file;

	file.open((this->_target + "_shrubbery").c_str());
	if (file.fail())
	{
		std::cout << "could not open file :(" << std::endl;
		return ;
	}
    file << "       .\n";
    file << "      `-- This\n";
    file << "         |-- is\n";
    file << "         |   |-- a\n";
    file << "         |   `-- nice\n";
    file << "         |       |-- tree!\n";
    file << "         |       `-- (diagram)\n";
    file << "         |           `-- :)\n";
    file << "         `-- Bottom text\n";
	file.close();
	std::cout << bureaucrat.getName() << " successfuly created a shrubbery" << std::endl;
}

std::ostream	&operator<<(std::ostream &ret, ShrubberyCreationForm const &form)
{
	ret << "form " << form.getName() << ", signed " << form.getSigned() << ", grade to sign " << form.getSignGrade() \
	 << ", grade to exec " << form.getExecGrade() << std::endl;
	return ret;
}
