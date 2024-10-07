/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:06:30 by fvonsovs          #+#    #+#             */
/*   Updated: 2024/10/07 22:58:04 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// constructor

Bureaucrat::Bureaucrat(void): name("default"), grade(150)
{
	std::cout << "constructor called for bureaucrat " << this->getName() << " grade " << this->getGrade() << std::endl;

}

Bureaucrat::Bureaucrat(const Bureaucrat &src): name(src.getName() + "_copy")
{
	std::cout << "copy constructor called for " << src.getName() << " to " << this->getName() << std::endl;
	*this = src;
}

Bureaucrat::Bureaucrat(int grade): name("default")
{
	std::cout << "constructor called for bureaucrat " << this->getName() << " , grade " << grade << std::endl;

}

// destructor

Bureaucrat::~Bureaucrat()
{
	std::cout << "destructor called for bureaucrat " << this->getName() << std::endl;
}

// getters

const std::string	Bureaucrat::getName(void)const
{
	return (this->name);
}

size_t	Bureaucrat::getGrade(void)const
{
	return (this->grade);
}