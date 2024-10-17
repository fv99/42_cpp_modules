/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:40:27 by fvonsovs          #+#    #+#             */
/*   Updated: 2024/10/17 15:54:36 by fvonsovs         ###   ########.fr       */
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

    // check special cases
    if (input == "nan" || input == "nanf")
    {
        d_val = std::numeric_limits<double>::quiet_NaN();
        f_val = std::numeric_limits<float>::quiet_NaN();
        char_impossible = true;
        int_impossible = true;
    }
    else if (input == "+inf" || input == "+inff" || input == "inf" || input == "inff")
    {
        d_val = std::numeric_limits<double>::infinity();
        f_val = std::numeric_limits<float>::infinity();
        char_impossible = true;
        int_impossible = true;
    }
    else if (input == "-inf" || input == "-inff")
    {
        d_val = -std::numeric_limits<double>::infinity();
        f_val = -std::numeric_limits<float>::infinity();
        char_impossible = true;
        int_impossible = true;
    }
    // single char
    else if (input.length() == 1 && isprint(input[0]) && !isdigit(input[0]))
    {
        c_val = input[0];
        i_val = static_cast<int>(c_val);
        f_val = static_cast<float>(c_val);
        d_val = static_cast<double>(c_val);
    }
    else
    {
        // convert to double
        char *end;
        errno = 0;
        d_val = std::strtod(input.c_str(), &end);
        if (errno != 0 || end == input.c_str())
        {
            std::cerr << "Invalid input" << std::endl;
            return;
        }

        if (*end == 'f' && *(end + 1) == '\0')
        {
            // input is a float literal with f
            f_val = static_cast<float>(d_val);
        }
        else if (*end == '\0')
        {
            // input is a valid double literal
            f_val = static_cast<float>(d_val);
        }
        else
        {
            std::cerr << "Invalid input" << std::endl;
            return;
        }

        // convert to int
        if (d_val < static_cast<double>(std::numeric_limits<int>::min()) ||
            d_val > static_cast<double>(std::numeric_limits<int>::max()) ||
            std::isnan(d_val) || std::isinf(d_val))
        {
            int_impossible = true;
        }
        else
        {
            i_val = static_cast<int>(d_val);
        }

        // convert to char
        if (d_val < static_cast<double>(std::numeric_limits<char>::min()) ||
            d_val > static_cast<double>(std::numeric_limits<char>::max()) ||
            std::isnan(d_val) || std::isinf(d_val))
        {
            char_impossible = true;
        }
        else
        {
            c_val = static_cast<char>(i_val);
        }
    }

    // Output char
    if (char_impossible)
    {
        std::cout << "char: impossible" << std::endl;
    }
    else if (!isprint(c_val))
    {
        std::cout << "char: Non displayable" << std::endl;
    }
    else
    {
        std::cout << "char: '" << c_val << "'" << std::endl;
    }

    // Output int
    if (int_impossible)
    {
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        std::cout << "int: " << i_val << std::endl;
    }

    // Output float
    std::cout << std::fixed << std::setprecision(1);
    if (std::isnan(f_val))
    {
        std::cout << "float: nanf" << std::endl;
    }
    else if (std::isinf(f_val))
    {
        if (f_val > 0)
            std::cout << "float: +inff" << std::endl;
        else
            std::cout << "float: -inff" << std::endl;
    }
    else
    {
        std::cout << "float: " << f_val << "f" << std::endl;
    }

    // Output double
    if (std::isnan(d_val))
    {
        std::cout << "double: nan" << std::endl;
    }
    else if (std::isinf(d_val))
    {
        if (d_val > 0)
            std::cout << "double: +inf" << std::endl;
        else
            std::cout << "double: -inf" << std::endl;
    }
    else
    {
        std::cout << "double: " << d_val << std::endl;
    }
}
