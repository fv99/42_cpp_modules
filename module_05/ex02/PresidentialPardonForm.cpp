/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:10:16 by fvonsovs          #+#    #+#             */
/*   Updated: 2024/10/11 16:12:56 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): Form::Form("presidential pardon form", 25, 5), _target(NULL)
{
	std::cout << "default constructor called for form " << this->getName() << ", grade to sign " << this->getSignGrade() \
	 << ", grade to exec " << this->getExecGrade() << ", target:" << _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): Form::Form("presidential pardon form", 25, 5), _target(target)
{
	std::cout << "constructor called for form " << this->getName() << ", grade to sign " << this->getSignGrade() \
	 << ", grade to exec " << this->getExecGrade() << ", target:" << _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy): Form::Form(copy), _target(copy._target)
{
	std::cout << "copy constructor called for form " << this->getName() << ", grade to sign " << this->getSignGrade() \
	 << ", grade to exec " << this->getExecGrade() << ", target:" << _target << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "destructor called for form " << this->getName() << std::endl;
}

PresidentialPardonForm const	&PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	Form::operator=(copy);
	this->_target = copy._target;
	return (*this);
}

void PresidentialPardonForm::beExecuted(const Bureaucrat &bureaucrat) const
{
	(void)bureaucrat;
	std::cout << "presidential pardon issued for " << this->getName() << std::endl;
}

std::ostream	&operator<<(std::ostream &ret, PresidentialPardonForm const &form)
{
	ret << "form " << form.getName() << ", signed " << form.getSigned() << ", grade to sign " << form.getSignGrade() \
	 << ", grade to exec " << form.getExecGrade() << std::endl;
	return ret;
}
