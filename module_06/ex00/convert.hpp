/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:35:06 by fvonsovs          #+#    #+#             */
/*   Updated: 2024/10/29 14:27:36 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <cerrno>
#include <cctype>
#include <string>

class Converter
{
private:
    Converter();
    Converter(const Converter &);
    Converter &operator=(const Converter &);
    ~Converter();
	
    static bool isChar(const std::string &input);
    static bool isInt(const std::string &input);
    static bool isFloat(const std::string &input);
    static bool isDouble(const std::string &input);

public:
    static void convert(const std::string &input);

};
