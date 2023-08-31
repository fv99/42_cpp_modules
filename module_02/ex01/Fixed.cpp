#include "Fixed.hpp"
#include <cmath>

const int Fixed::fraction = 8;

Fixed::Fixed(void) : val(0)
{
    std::cout << "fixed default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : val(value << fraction)
{
    std::cout << "fixed integer constructor called" << std::endl;
}

Fixed::Fixed(const float value) : val(roundf(value * (1 << fraction)))
{
    std::cout << "fixed float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
    std::cout << "fixed destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) : val(copy.val)
{
    std::cout << "fixed copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    std::cout << "fixed copy assignment called" << std::endl;
    if (this != &copy)
        this->val = copy.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits called" << std::endl;
    return this->val;
}

void Fixed::setRawBits(int const raw)
{
    this->val = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(val) / (1 << fraction);
}

int Fixed::toInt(void) const
{
    return val >> fraction;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
