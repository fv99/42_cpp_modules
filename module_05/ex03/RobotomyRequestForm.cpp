/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:04:14 by fvonsovs          #+#    #+#             */
/*   Updated: 2024/10/11 16:22:28 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): Form::Form("robotomy creation form", 72, 45), _target(NULL)
{
	std::cout << "default constructor called for form " << this->getName() << ", grade to sign " << this->getSignGrade() \
	 << ", grade to exec " << this->getExecGrade() << ", target:" << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): Form::Form("robotomy creation form", 72, 45), _target(target)
{
	std::cout << "constructor called for form " << this->getName() << ", grade to sign " << this->getSignGrade() \
	 << ", grade to exec " << this->getExecGrade() << ", target:" << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy): Form::Form(copy), _target(copy._target)
{
	std::cout << "copy constructor called for form " << this->getName() << ", grade to sign " << this->getSignGrade() \
	 << ", grade to exec " << this->getExecGrade() << ", target:" << _target << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "destructor called for form " << this->getName() << std::endl;
}

RobotomyRequestForm const	&RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	Form::operator=(copy);
	this->_target = copy._target;
	return (*this);
}

void RobotomyRequestForm::beExecuted(const Bureaucrat &bureaucrat) const
{
	bool ret;

	srand((unsigned) time(NULL));
	ret = rand() % 2 + 1;
	(void)bureaucrat;
	if (ret)
		std::cout << "succesfully robotimized " << this->getName() << std::endl;
	else
		std::cout << "failed to robotimize " << this->getName() << std::endl;
}

std::ostream	&operator<<(std::ostream &ret, RobotomyRequestForm const &form)
{
	ret << "form " << form.getName() << ", signed " << form.getSigned() << ", grade to sign " << form.getSignGrade() \
	 << ", grade to exec " << form.getExecGrade() << std::endl;
	return ret;
}
