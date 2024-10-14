/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:06:30 by fvonsovs          #+#    #+#             */
/*   Updated: 2024/10/11 16:05:48 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// form signing
void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->name << " cannot sign " << form.getName()<< ", " << e.what() << std::endl;
	}
}

// form execution
void Bureaucrat::executeForm(Form const &form)
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "cannot execute " << this->name << std::endl;
	}
}

// constructor

Bureaucrat::Bureaucrat(void): name("default"), grade(150)
{
	std::cout << "default constructor called for bureaucrat " << this->getName() << " grade " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): name(src.getName() + "_copy")
{
	std::cout << "copy constructor called for " << src.getName() << " to " << this->getName() << std::endl;
	*this = src;
}

Bureaucrat::Bureaucrat(int g): name("default")
{
	this->setGrade(g);
	std::cout << "constructor called for bureaucrat " << this->getName() << ", grade " << g << std::endl;
}

Bureaucrat::Bureaucrat(const std::string n): name(n), grade(150)
{
	std::cout << "constructor called for bureaucrat " << this->getName() << ", grade " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const std::string n, int g): name(n)
{
	this->setGrade(g);
	std::cout << "constructor called for bureaucrat " << this->getName() << ", grade " << this->getGrade() << std::endl;
}


// getters
const std::string Bureaucrat::getName(void)const
{
	return this->name;
}

size_t Bureaucrat::getGrade(void)const
{
	return this->grade;
}

// inc/dec
void Bureaucrat::incrementGrade(void)
{
	std::cout << "incrementing grade of " << this->getName() << std::endl;
	this->setGrade(this->grade + 1);
}

void Bureaucrat::decrementGrade(void)
{
	std::cout << "decrementing grade of " << this->getName() << std::endl;
	this->setGrade(this->grade - 1);
}

// setters
void Bureaucrat::setGrade(int i)
{
	if (i > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (i < 1)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade = i;
}

// destructors

Bureaucrat::~Bureaucrat()
{
	std::cout << "destructor called for bureaucrat " << this->getName() << std::endl;
}

// exceptions

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "grade too low";
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "grade too high";
}

// overload
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "burecraut assign operator called" << std::endl;
	if (this == &src)
		return *this;
	this->grade = src.getGrade();
	return *this;
}

// overload ostream

std::ostream &operator<<(std::ostream &ret, Bureaucrat const &bur)
{
	ret << "bureaucrat " << bur.getName() << " grade " << bur.getGrade() << std::endl;
	return ret;
}
