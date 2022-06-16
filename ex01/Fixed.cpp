/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 04:10:35 by abensett          #+#    #+#             */
/*   Updated: 2022/06/16 21:45:02 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"
#include <cmath>
using std::cout;

/*****************************************************************************
To convert from floating-point to fixed-point, we follow this algorithm:

    Calculate x = floating_input * 2^(fractional_bits)
    Round x to the nearest whole number (e.g. round(x))
    Store the rounded x in an integer container

    2^8 = 256 = (1 << 8) donc float * 256 = fixed
    << 8 = * 256
*****************************************************************************/

Fixed::Fixed( void ) :_raw(0) {cout << "Default constructor called" <<endl; }

Fixed::~Fixed( void ) {cout << "Destructor called" << endl;}

Fixed::Fixed (const Fixed &fixed)                                                   // copy constructor
{
     cout << "Copy constructor called" << endl;
     *this = fixed; }

Fixed &Fixed::operator=(const Fixed &fixed)				                            // surcharge operateur = assignation
{
    cout << "Copy assignment operator called" << endl;
    if (this != &fixed)
        _raw = fixed.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const {return _raw ;}

void Fixed::setRawBits(const int raw) {_raw = raw ;}

Fixed::Fixed( const int raw ) : _raw(raw << _nb_bits_frac) {cout << "Int constructor called" << endl; }
                                        // * 256 = shit by 8
Fixed::Fixed( const float raw ) : _raw(roundf(raw * (1 << _nb_bits_frac))) {cout << "Float constructor called" << endl; }
                                            // * 256

float Fixed::toFloat(void) const { return (static_cast<float>(_raw) / (1 << _nb_bits_frac)); }

int Fixed::toInt(void) const {return (_raw >> _nb_bits_frac);}

// overload << operator
ostream &operator<<(ostream &o, const Fixed &fixed) {  return (o << fixed.toFloat()); }
