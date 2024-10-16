/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:40:27 by fvonsovs          #+#    #+#             */
/*   Updated: 2024/10/16 17:33:52 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

// private default constructor
Convert::Convert(): _input(""), _type(_ERR), _c_val(0), _d_val(0.0), _i_val(0), _f_val(0.0f)
{
    std::cout << "convertor default constructor called" << std::endl;
}

// public assign constructor
Convert::Convert(const std::string input): _input(input), _type(_ERR), _c_val(0), _d_val(0.0), _i_val(0), _f_val(0.0f)
{
    std::cout << "convertor assign constructor called, attempting to convert " << this->getInput() << std::endl;

    if (_input == "nan" || _input == "nanf")
    {
        _type = _NAN;
        _f_val = NAN;
        _d_val = NAN;
    }
    else if (_input == "+inf" || _input == "+inff" || _input == "inf" || _input == "inff")
    {
        _type = _FLOAT;
        _f_val = std::numeric_limits<float>::infinity();
        _d_val = std::numeric_limits<double>::infinity();
    }
    else if (_input == "-inf" || _input == "-inff")
    {
        _type = _FLOAT;
        _f_val = -std::numeric_limits<float>::infinity();
        _d_val = -std::numeric_limits<double>::infinity();
    }
    // try to convert to char
    else if (_input.length() == 3 && _input[0] == '\'' && _input[2] == '\'')
    {
        _type = _CHAR;
        _c_val = _input[1];
        _i_val = static_cast<int>(_c_val);
        _f_val = static_cast<float>(_i_val);
        _d_val = static_cast<double>(_i_val);
    }
    else
    {
        char* end;
        errno = 0;

        // try to convert to integer
        long val = std::strtol(_input.c_str(), &end, 10);
        if (errno == 0 && *end == '\0' && val <= std::numeric_limits<int>::max() && val >= std::numeric_limits<int>::min())
        {
            _i_val = static_cast<int>(val);
            _type = _INT;
            _c_val = (_i_val >= 32 && _i_val <= 126) ? static_cast<char>(_i_val) : 0;
            _f_val = static_cast<float>(_i_val);
            _d_val = static_cast<double>(_i_val);
        }
        else
        {
            // try to convert to float or double
            double d_val = std::strtod(_input.c_str(), &end);
            if (errno == 0 && *end == 'f' && *(end + 1) == '\0')
            {
                _f_val = static_cast<float>(d_val);
                _d_val = d_val;
                _type = _FLOAT;
            }
            else if (errno == 0 && *end == '\0')
            {
                _d_val = d_val;
                _f_val = static_cast<float>(_d_val);
                _type = _DOUBLE;
            }
            else
            {
                throw ErrorThrow();
            }
        }
    }
}

// copy constructor
Convert::Convert(const Convert &src): _input(src._input), _type(src._type), _c_val(src._c_val), _d_val(src._d_val), _i_val(src._i_val), _f_val(src._f_val)
{
    std::cout << "copy constructor called for " << src.getInput() << std::endl;
}

// destructor
Convert::~Convert()
{
    std::cout << "destructor called for convertor" << std::endl;
}

// overload
Convert &Convert::operator=(const Convert &src)
{
    std::cout << "convert assign operator called" << std::endl;
    if (this == &src)
        return *this;

    this->_type = src.getType();
    this->_c_val = src.getChar();
    this->_i_val = src.getInt();
    this->_f_val = src.getFloat();
    this->_d_val = src.getDouble();
    return *this;
}

// getters
std::string Convert::getInput(void)const
{
    return (this->_input);
}

Type Convert::getType(void)const
{
    return (this->_type);
}

char Convert::getChar(void)const
{
    if (_type == _CHAR || (_type == _INT && _i_val >= 32 && _i_val <= 126))
        return _c_val;
    else
        throw ErrorThrow();
}

int Convert::getInt(void)const
{
    if (_type == _INT || _type == _CHAR)
        return _i_val;
    else
        throw ErrorThrow();
}

float Convert::getFloat(void)const
{
    return (this->_f_val);
}

double Convert::getDouble(void)const
{
    return (this->_d_val);
}

// exception
const char *Convert::ErrorThrow::what(void) const throw()
{
    return ("ERROR: cannot print or convert input");
}

// overflow
std::ostream &operator<<(std::ostream &os, const Convert &converter)
{
    // Print char
    try
    {
        char c = converter.getChar();
        if (std::isprint(c))
        {
            os << "char: '" << c << "'" << std::endl;
        }
        else
        {
            os << "char: Non displayable" << std::endl;
        }
    }
    catch (const Convert::ErrorThrow &)
    {
        os << "char: impossible" << std::endl;
    }

    // Print int
    try
    {
        os << "int: " << converter.getInt() << std::endl;
    }
    catch (const Convert::ErrorThrow &)
    {
        os << "int: impossible" << std::endl;
    }

    // Print float
    try
    {
        os << "float: " << converter.getFloat() << "f" << std::endl;
    }
    catch (const Convert::ErrorThrow &)
    {
        os << "float: impossible" << std::endl;
    }

    // Print double
    try
    {
        os << "double: " << converter.getDouble() << std::endl;
    }
    catch (const Convert::ErrorThrow &)
    {
        os << "double: impossible" << std::endl;
    }

    return os;
}
