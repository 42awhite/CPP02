#include "Fixed.hpp"

// CONSTRUCTORES
Fixed::Fixed() : _fixed_point(0) // Inicialización con lista de miembros
{
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) : _fixed_point(copy._fixed_point) // Constructor de copia con inicialización
{
    //std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int number)
{
    //std::cout << "Int constructor called" << std::endl;
    _fixed_point = number << _bit; // Conversión de entero a punto fijo
}

Fixed::Fixed(const float number)
{
    //std::cout << "Float constructor called" << std::endl;
    _fixed_point = roundf(number * (1 << _bit)); // Conversión de flotante a punto fijo
}

// DESTRUCTOR
Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}

// OPERADOR DE ASIGNACIÓN
Fixed& Fixed::operator=(const Fixed &other)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) // Evitar autoasignación
    {
        this->_fixed_point = other._fixed_point;
    }
    return *this;
}

// MÉTODOS GET/SET
int Fixed::getRawBits() const
{
    return _fixed_point;
}

void Fixed::setRawBits(int const raw)
{
    _fixed_point = raw;
}

// MÉTODOS DE CONVERSIÓN
float Fixed::toFloat() const
{
    return static_cast<float>(_fixed_point) / (1 << _bit);
}

int Fixed::toInt() const
{
    return _fixed_point >> _bit;
}

// SOBRECARGA DEL OPERADOR DE SALIDA
std::ostream& operator<<(std::ostream &o, const Fixed &fixed)
{
    o << fixed.toFloat();
    return o;
}

// OPERADORES DE COMPARACIÓN
bool Fixed::operator>(const Fixed &other) const
{
    return _fixed_point > other._fixed_point;
}

bool Fixed::operator<(const Fixed &other) const
{
    return _fixed_point < other._fixed_point;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return _fixed_point >= other._fixed_point;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return _fixed_point <= other._fixed_point;
}

bool Fixed::operator==(const Fixed &other) const
{
    return _fixed_point == other._fixed_point;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return _fixed_point != other._fixed_point;
}

// OPERADORES ARITMÉTICOS
Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->_fixed_point + other._fixed_point);
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->_fixed_point - other._fixed_point);
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((this->_fixed_point * other._fixed_point) >> _bit);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    if (other._fixed_point == 0)
    {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed();
    }
    Fixed result;
    result.setRawBits((this->_fixed_point << _bit) / other._fixed_point);
    return result;
}

// OPERADORES DE INCREMENTO Y DECREMENTO
Fixed& Fixed::operator++() // Pre-incremento
{
    ++_fixed_point;
    return *this;
}

Fixed Fixed::operator++(int) // Post-incremento
{
    Fixed temp(*this);
    ++_fixed_point;
    return temp;
}

Fixed& Fixed::operator--() // Pre-decremento
{
    --_fixed_point;
    return *this;
}

Fixed Fixed::operator--(int) // Post-decremento
{
    Fixed temp(*this);
    --_fixed_point;
    return temp;
}

// MÉTODOS ESTÁTICOS PARA MIN Y MAX
Fixed& Fixed::min(Fixed &x, Fixed &y)
{
    return (x < y) ? x : y;
}

const Fixed& Fixed::min(const Fixed &x, const Fixed &y)
{
    return (x < y) ? x : y;
}

Fixed& Fixed::max(Fixed &x, Fixed &y)
{
    return (x > y) ? x : y;
}

const Fixed& Fixed::max(const Fixed &x, const Fixed &y)
{
    return (x > y) ? x : y;
}
