/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:40:27 by fvonsovs          #+#    #+#             */
/*   Updated: 2024/10/29 14:31:47 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

Converter::Converter() {}
Converter::Converter(const Converter &) {}
Converter &Converter::operator=(const Converter &) { return *this; }
Converter::~Converter() {}

void Converter::convert(const std::string &input)
{
    char c_val = 0;
    int i_val = 0;
    float f_val = 0.0f;
    double d_val = 0.0;

    bool char_impossible = false;
    bool int_impossible = false;

    if (isChar(input))
    {
        c_val = input[0];
        i_val = static_cast<int>(c_val);
        f_val = static_cast<float>(c_val);
        d_val = static_cast<double>(c_val);
    }
    else if (isInt(input))
    {
        long temp = std::strtol(input.c_str(), NULL, 10);
        if (temp < std::numeric_limits<int>::min() || temp > std::numeric_limits<int>::max())
            int_impossible = true;
        else
            i_val = static_cast<int>(temp);
        c_val = static_cast<char>(i_val);
        f_val = static_cast<float>(i_val);
        d_val = static_cast<double>(i_val);
    }
    else if (isFloat(input))
    {
        f_val = std::strtof(input.c_str(), NULL);
        d_val = static_cast<double>(f_val);
        if (std::isnan(f_val) || std::isinf(f_val) || f_val < std::numeric_limits<int>::min() || f_val > std::numeric_limits<int>::max())
            int_impossible = true;
        else
            i_val = static_cast<int>(f_val);
        c_val = static_cast<char>(i_val);
    }
    else if (isDouble(input))
    {
        d_val = std::strtod(input.c_str(), NULL);
        f_val = static_cast<float>(d_val);
        if (std::isnan(d_val) || std::isinf(d_val) || d_val < std::numeric_limits<int>::min() || d_val > std::numeric_limits<int>::max())
            int_impossible = true;
        else
            i_val = static_cast<int>(d_val);
        c_val = static_cast<char>(i_val);
    }
    else
    {
        std::cerr << "Invalid input" << std::endl;
        return;
    }

    // Check for char impossibility
    if (int_impossible || i_val < std::numeric_limits<char>::min() || i_val > std::numeric_limits<char>::max())
        char_impossible = true;

    // Output the results
    // Char
    if (char_impossible)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(c_val))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c_val << "'" << std::endl;

    // Int
    if (int_impossible)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i_val << std::endl;

    // Float
    std::cout << std::fixed << std::setprecision(1);
    if (std::isnan(f_val))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(f_val))
        std::cout << "float: " << (f_val > 0 ? "+inff" : "-inff") << std::endl;
    else
        std::cout << "float: " << f_val << "f" << std::endl;

    // Double
    if (std::isnan(d_val))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(d_val))
        std::cout << "double: " << (d_val > 0 ? "+inf" : "-inf") << std::endl;
    else
        std::cout << "double: " << d_val << std::endl;
}

bool Converter::isChar(const std::string &input)
{
    return (input.length() == 1 && isprint(input[0]) && !isdigit(input[0]));
}

bool Converter::isInt(const std::string &input)
{
    char *end;
    errno = 0;
    long val = std::strtol(input.c_str(), &end, 10);
    if (*end != '\0' || errno == ERANGE || val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
        return false;
    return true;
}

bool Converter::isFloat(const std::string &input)
{
    if (input == "+inff" || input == "-inff" || input == "nanf")
        return true;
    if (input.find('f') != input.length() - 1)
        return false;
    char *end;
    std::strtof(input.c_str(), &end);
    if (*end != 'f' || *(end + 1) != '\0')
        return false;
    return true;
}

bool Converter::isDouble(const std::string &input)
{
    if (input == "+inf" || input == "-inf" || input == "nan")
        return true;
    char *end;
    std::strtod(input.c_str(), &end);
    return (*end == '\0');
}
