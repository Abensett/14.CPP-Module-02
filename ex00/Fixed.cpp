/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 04:10:35 by abensett          #+#    #+#             */
/*   Updated: 2022/06/15 22:48:33 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

using std::cout;

Fixed::Fixed( void ) :_raw(0) {cout << "Default constructor called" <<endl; }   // Default constructor

Fixed::~Fixed( void ) {cout << "Destructor called" << endl;}                    // Destructor

Fixed::Fixed (const Fixed &fixed) { *this = fixed; }				            // this becomes the arg=fixed

Fixed    &Fixed::operator=(const Fixed &fixed)			        		        // surcharge
{
    cout << "Copy assignment operator called" << endl;
    if (this != &fixed)
        _raw = fixed.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const 
{
    cout << "getRawBits member function called" << endl;
    return _raw;
}

void Fixed::setRawBits(const int raw)
{
    _raw = raw;
}
