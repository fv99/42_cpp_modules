/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:35:06 by fvonsovs          #+#    #+#             */
/*   Updated: 2024/10/17 15:57:55 by fvonsovs         ###   ########.fr       */
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

public:
    static void convert(const std::string &input);
};
