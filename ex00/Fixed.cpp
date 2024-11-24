#include "Fixed.hpp"

Fixed::Fixed()
{
    _fixed_point = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "cpy constructor called" << std::endl;
    *this = copy;
}

Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "cpy assignment operator called" << std::endl;
    this->_fixed_point = other.getRawBits();
    return(*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor caller" << std::endl;
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits caller" << std::endl;
    _fixed_point = raw;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(_fixed_point);
}
