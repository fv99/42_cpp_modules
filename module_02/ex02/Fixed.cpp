#include "Fixed.hpp"
#include <cmath>

const int Fixed::fraction = 8;

Fixed::Fixed(void) : val(0)
{
   // std::cout << "fixed default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : val(value << fraction)
{
    // std::cout << "fixed integer constructor called" << std::endl;
}

Fixed::Fixed(const float value) : val(roundf(value * (1 << fraction)))
{
    // std::cout << "fixed float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
    // std::cout << "fixed destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) : val(copy.val)
{
    // std::cout << "fixed copy constructor called" << std::endl;
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

// Overloaded comparison operators
bool Fixed::operator>(const Fixed &copy) const 
{
    return this->val > copy.val;
}

bool Fixed::operator<(const Fixed &copy) const 
{
    return this->val < copy.val;
}

bool Fixed::operator>=(const Fixed &copy) const 
{
    return this->val >= copy.val;
}

bool Fixed::operator<=(const Fixed &copy) const 
{
    return this->val <= copy.val;
}

bool Fixed::operator==(const Fixed &copy) const 
{
    return this->val == copy.val;
}

bool Fixed::operator!=(const Fixed &copy) const 
{
    return this->val != copy.val;
}

// Overloaded arithmetic operators
Fixed Fixed::operator+(const Fixed &copy) const 
{
    return Fixed(this->toFloat() + copy.toFloat());
}

Fixed Fixed::operator-(const Fixed &copy) const 
{
    return Fixed(this->toFloat() - copy.toFloat());
}

Fixed Fixed::operator*(const Fixed &copy) const 
{
    return Fixed(this->toFloat() * copy.toFloat());
}

Fixed Fixed::operator/(const Fixed &copy) const 
{
    if (copy.toFloat() != 0) {
        return Fixed(this->toFloat() / copy.toFloat());
    }
    return Fixed(2147483647);
}

// Overloaded increment and decrement operators
Fixed& Fixed::operator++() {
    this->val++;
    return *this;
}

Fixed& Fixed::operator--() {
    this->val--;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
}


// Static member function to find the minimum of two Fixed numbers
const Fixed& Fixed::min(const Fixed &a, const Fixed &b) 
{
    return (a < b) ? a : b;
}

// Static member function to find the maximum of two Fixed numbers
const Fixed& Fixed::max(const Fixed &a, const Fixed &b) 
{
    return (a > b) ? a : b;
}
