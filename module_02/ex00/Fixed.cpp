#include "Fixed.hpp"

const int Fixed::fraction = 8;

Fixed::Fixed(void): val(0)
{
    std::cout << "fixed default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
    std::cout << "fixed destructor called" << std::endl;
}

Fixed::Fixed(Fixed const & copy)
{
    std::cout << "fixed copy constructor called" << std::endl;
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    std::cout << "fixed copy assignment called" << std::endl;
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
