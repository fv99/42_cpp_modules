/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:55:41 by fvonsovs          #+#    #+#             */
/*   Updated: 2024/10/14 15:47:42 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// execute

void Form::execute(Bureaucrat const &bur) const
{
	if (!this->_signed)
		throw Form::FormNotSignedException();
	else if (bur.getGrade() > this->getSignGrade())
		throw Form::GradeTooLowException();
	else
	{
		std::cout << bur.getName() << " executed form " << this->getName() << std::endl;
		this->beExecuted(bur);
	}
}

// constructors

Form::Form(void): _name("default"), _gsign(150), _gexec(150), _signed(false)
{
	std::cout << "default constructor called for form " << this->getName() << ", grade to sign " << this->getSignGrade() \
	 << ", grade to exec " << this->getExecGrade() << std::endl;
}

Form::Form(std::string const &name, size_t const &gsign, size_t const &gexec): _name(name), _gsign(gsign), _gexec(gexec), _signed(false)
{
	if (this->_gsign < 1)
		throw(GradeTooHighException());
	if (this->_gsign > 150)
		throw(GradeTooLowException());
	if (this->_gexec < 1)
		throw(GradeTooHighException());
	if (this->_gexec > 150)
		throw(GradeTooLowException());
	std::cout << "default constructor called for form " << this->getName() << ", grade to sign " << this->getSignGrade() \
	 << ", grade to exec " << this->getExecGrade() << std::endl;

}

Form::Form(Form const &copy): _name(copy._name), _gsign(copy._gsign), _gexec(copy._gexec), _signed(false)
{
	*this = copy;
	std::cout << "copy constructor called for form " << this->getName() << ", grade to sign " << this->getSignGrade() \
	 << ", grade to exec " << this->getExecGrade() << std::endl;
}

// destructor
Form::~Form(void)
{
	std::cout << "destructor called for form " << this->getName() << std::endl;
}

// default operator
Form const &Form::operator=(const Form &copy)
{
	this->_signed = copy._signed;
	return (*this);
}

// signer
void Form::beSigned(Bureaucrat &bureaucrat)
{
	if(bureaucrat.getGrade() > this->_gsign)
		throw(Form::GradeTooLowException());
	else
	{
		this->_signed = true;
		std::cout << "bureaucrat " << bureaucrat.getName() << "signed form " << this->getName() << std::endl;
	}
}

// getters
const std::string Form::getName(void)const
{
	return this->_name;
}

size_t Form::getSignGrade(void)const
{
	return this->_gsign;
}

size_t Form::getExecGrade(void)const
{
	return this->_gexec;
}

bool Form::getSigned(void)const
{
	return this->_signed;
}

// exceptions
char const	*Form::GradeTooHighException::what(void) const throw()
{
	return ("grade too high");
}

char const	*Form::GradeTooLowException::what(void) const throw()
{
	return ("grade too low");
}

char const	*Form::FormNotSignedException::what(void) const throw()
{
	return ("form not signed");
}

std::ostream &operator<<(std::ostream &ret, Form const &form)
{
	ret << "form " << form.getName() << ", signed " << form.getSigned() << ", grade to sign " << form.getSignGrade() \
	 << ", grade to exec " << form.getExecGrade() << std::endl;
	return ret;
}
