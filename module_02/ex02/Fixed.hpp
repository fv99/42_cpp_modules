#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
    int val;
    static const int fraction;

public:
    Fixed(void);
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &copy);
    ~Fixed(void);


    Fixed &operator=(const Fixed &copy);
    Fixed operator+(Fixed const &copy) const;
    Fixed operator-(Fixed const &copy) const;
    Fixed operator*(Fixed const &copy) const;
    Fixed operator/(Fixed const &copy) const;
    bool operator==(Fixed const &copy) const;
    bool operator!=(Fixed const &copy) const;
    bool operator<=(Fixed const &copy) const;
    bool operator>=(Fixed const &copy) const;
    bool operator<(Fixed const &copy) const;
    bool operator>(Fixed const &copy) const;

    Fixed &operator++(void);
    Fixed &operator--(void);
    Fixed operator++(int value);
    Fixed operator--(int value);

    static const Fixed &min(Fixed const &a, Fixed const &b);
    static const Fixed &max(Fixed const &a, Fixed const &b);


    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
