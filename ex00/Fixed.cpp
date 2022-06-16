/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 04:10:35 by abensett          #+#    #+#             */
/*   Updated: 2022/06/16 23:42:56 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

using std::cout;

Fixed::Fixed( void ) :_raw(0) {cout << "Default constructor called" <<endl; }   // Default constructor

Fixed::~Fixed( void ) {cout << "Destructor called" << endl;}                    // Destructor


Fixed::Fixed (const Fixed &fixed)                                                   // copy constructor
{
     cout << "Copy constructor called" << endl;
     *this = fixed;
}

Fixed    &Fixed::operator=(const Fixed &fixed)			        		        // surcharge
{
    cout << "Copy assignment operator called" << endl;
    if (this != &fixed)                                         // utilisation de assert(this, &fixed)
        _raw = fixed.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const                                               // Accessor
{
    cout << "getRawBits member function called" << endl;
    return _raw;
}

void Fixed::setRawBits(const int raw)
{
    _raw = raw;
}
