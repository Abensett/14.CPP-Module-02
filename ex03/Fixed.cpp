/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 04:10:35 by abensett          #+#    #+#             */
/*   Updated: 2022/06/16 01:35:32 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"
#include <cmath>
using std::cout;


Fixed::Fixed( void ) :_raw(0) {}
Fixed::~Fixed( void ) {}

Fixed::Fixed (const Fixed &fixed) { *this = fixed; }				// copy constructor

Fixed &Fixed::operator=(const Fixed &fixed)				        	// surcharge
{
    if (this != &fixed)
        _raw = fixed.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const {
    return _raw;
}

void Fixed::setRawBits(const int raw)
{   
    _raw = raw;
}

Fixed::Fixed( const int raw ) : _raw(raw << _nb_bits_frac) {}

Fixed::Fixed( const float raw ) : _raw(roundf(raw *(1 << _nb_bits_frac))) {}


float Fixed::toFloat(void) const
{
    return (static_cast<float>(_raw) / (1 << _nb_bits_frac));
}

int Fixed::toInt(void) const
{
    return (_raw >> _nb_bits_frac);
}

bool Fixed::operator>(const Fixed &fixed) const {
    return ((_raw) > fixed._raw);
}

bool Fixed::operator<(const Fixed &fixed) const {
    return ((_raw) < fixed._raw);
}

bool Fixed::operator>=(const Fixed &fixed) const {
    return ((_raw) >= fixed._raw);
}

bool Fixed::operator<=(const Fixed &fixed) const {
    return ((_raw) <= fixed._raw);
}

bool Fixed::operator==(const Fixed &fixed) const {
    return ((_raw) == fixed._raw);
}

bool Fixed::operator!=(const Fixed &fixed) const {
    return ((_raw) != fixed._raw);
}

Fixed Fixed::operator+(const Fixed &fixed) const {
    return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const {
    return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const {
    return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const {
    return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++(void) {
    ++(_raw);
    return *this;
}

Fixed &Fixed::operator--(void) {
    --(_raw);
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp = *this;
    ++(_raw);
    return tmp;
}

Fixed Fixed::operator--(int) {
    Fixed tmp = *this;
    --(_raw);
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a <= b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a >= b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a <= b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a >= b ? a : b);
}


ostream &operator<<(ostream &o, const Fixed &fixed) {
    return (o << fixed.toFloat());
}
