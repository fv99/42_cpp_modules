/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:35:06 by fvonsovs          #+#    #+#             */
/*   Updated: 2024/10/15 16:06:00 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <limits>
#include <cmath>

enum Type {_NAN = 1, _ERR = 2, _CHAR = 3, _INT = 4, _FLOAT = 5, _DOUBLE = 6};

class Convert
{
	private:
		std::string _input;
		Type _type;
		char _c_val;
		double _d_val;
		int	_i_val;
		float _f_val;
	
		// constructor
		Convert();

		// getters
		std::string getInput(void)const;
		Type getType(void)const;
		char getChar(void)const;
		int getInt(void)const;
		float getFloat(void)const;
		double getDouble(void)const;
		
	public:
		// constructors
		Convert(const std::string input);
		Convert(const Convert &src);
		// deconstructor
		~Convert();

		// overload
		Convert &operator=(const Convert &src);
		
		// exception
		class ErrorThrow : public std::exception
		{
			public:
				virtual const char *what() const throw();
		}; 


};
