#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int _fixed_point;                 // Número en formato de punto fijo
    static const int _bit = 8;        // Número de bits para la parte fraccional

public:
    // Constructores y destructor
    Fixed();
    Fixed(const Fixed &copy);
    Fixed(const int num);
    Fixed(const float num);
    ~Fixed();

    // Operadores de asignación y comparación
    Fixed& operator=(const Fixed &other);
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    // Operadores aritméticos
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    // Operadores de incremento y decremento
    Fixed& operator++();      // Pre-incremento
    Fixed operator++(int);    // Post-incremento
    Fixed& operator--();      // Pre-decremento
    Fixed operator--(int);    // Post-decremento

    // Métodos para bits y conversiones
    float toFloat() const;
    int toInt() const;
    int getRawBits() const;
    void setRawBits(int const raw);

    // Métodos estáticos para min y max
    static Fixed& min(Fixed &x, Fixed &y);
    static const Fixed& min(const Fixed &x, const Fixed &y);
    static Fixed& max(Fixed &x, Fixed &y);
    static const Fixed& max(const Fixed &x, const Fixed &y);
};

// Sobrecarga del operador de salida
std::ostream& operator<<(std::ostream &o, const Fixed &fixed);

#endif
