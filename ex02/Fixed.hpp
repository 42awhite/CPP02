#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    private:
        int _fixed_point;
        static const int _bit = 8;
    public:
        Fixed();
        Fixed(const Fixed &copy);
        Fixed(const int num);
        Fixed(const float num);
        Fixed& operator=(const Fixed &other);
        ~Fixed();

        float   toFloat( void ) const;
        int     toInt( void ) const;

        int     getRawBits(void) const;
        void    setRawBits( int const raw);
};

std::ostream&	operator<<(std::ostream &o, Fixed const &fixed);

#endif