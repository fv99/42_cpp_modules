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
        ~Fixed(void);
        Fixed(Fixed const &copy);
        Fixed &operator=(Fixed const &copy);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif