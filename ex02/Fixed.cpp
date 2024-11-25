#include "Fixed.hpp"

//CONSTRUCTORS
Fixed::Fixed()
{
    _fixed_point = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Cpy constructor called" << std::endl;
    *this = copy;
}

Fixed::Fixed(const int number)
{
    std::cout << "Int constructor called" << std::endl;
    _fixed_point = number << _bit;
}

Fixed::Fixed(const float number)
{
    std::cout << "Float constructor called" << std::endl;
    _fixed_point = roundf(number * (1 << _bit));
}

//OPERATOR
Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Cpy assignment operator called" << std::endl;
    this->_fixed_point = other.getRawBits();
    return(*this);
}

//DESTRUCTOR
Fixed::~Fixed()
{
    std::cout << "Destructor caller" << std::endl;
}

//FUNTION BIT
void    Fixed::setRawBits(int const raw)
{
    _fixed_point = raw;
}

int Fixed::getRawBits(void) const
{
    return(_fixed_point);
}

// CONVERT
float   Fixed::toFloat( void ) const
{
    return(float) _fixed_point / (float)(1 << _bit);
}

int     Fixed::toInt( void ) const
{
    return(int)(_fixed_point >> _bit);
}

std::ostream&	operator<<(std::ostream &o, const Fixed &fixed) 
{
	o << fixed.toFloat();
	return o;
}

bool Fixed::operator>(const Fixed &other)
{
    return (this->_fixed > other._fixed_point)
}