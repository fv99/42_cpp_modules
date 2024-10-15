/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:40:27 by fvonsovs          #+#    #+#             */
/*   Updated: 2024/10/15 16:08:17 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

// private default constructor
Convert::Convert()
{
	std::cout << "convertor default constructor called" << std::endl;
}

// public assign constructor
Convert::Convert(const std::string input): _input(input)
{
	std::cout << "convertor assign constructor called for " << this->getInput() << std::endl;
}

// copy constructor
Convert::Convert(const Convert &src): _input(src.getInput())
{
	std::cout << "copy constructor called for " << src.getInput() << std::endl;
	*this = src;

}


// getters
std::string	Convert::getInput(void)const
{
	return (this->_input);
}

Type	Convert::getType(void)const
{
	return (this->_type);
}

char	Convert::getChar(void)const
{
	return (this->_c_val);
}

int	Convert::getInt(void)const
{
	return (this->_i_val);
}

float	Convert::getFloat(void)const
{
	return (this->_f_val);
}

double Convert::getDouble(void)const
{
	return (this->_d_val);
}

// overload
Convert &Convert::operator=(const Convert &src)
{
	std::cout << "Convert Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	this->_type = src.getType();
	this->_c_val = src.getChar();
	this->_i_val = src.getInt();
	this->_f_val = src.getFloat();
	this->_d_val = src.getDouble();
	return *this;
}

// exception
const char *Convert::ErrorThrow::what(void) const throw()
{
	return ("ERROR: cannot print or convert input");
};
