/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:12:15 by abensett          #+#    #+#             */
/*   Updated: 2022/06/16 23:22:28 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fixed_HPP
#define Fixed_HPP

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

/* From now on  Classes gotta be Orthodox Canonical Form:
- Default constructor
- Copy constructor
- Destructor
*/
/* Binary point  is the number of bits used to represent the fractional part of the number.
53 = 11 0101 = 1 * 2**5 + 1 * 2**4 + 1 * 2**2 + 1 * 2**0 = 32 + 16 + 4 + 1 = 53
26.5 = 1 1010.1 = 1 * 2**4 + 1 * 2**3 + 1 * 2**1 + 1 * 2**-1 = 16 + 8 + 4 + 0.5 = 26.5
*/
/* Point fixe : -> We fix the binary point
	<width,frac>		<8,3> = 00010.110
	Dans ce projet frac = 8
*/
class Fixed
{
	public:
		Fixed( void );									// Default constructor -> no args
		~Fixed( void );									// Destructor		   -> deleter
		Fixed (const Fixed &fixed);						// Copy constructor	   -> used to copy
		Fixed &operator=(const Fixed &fixed);			// assignment operator = surcharge de l'operation d'affectation

		void 	setRawBits( int const raw) ;			// setter
		int		getRawBits( void ) const;;				// accessor

	private:
		int				 _raw;							// nombre en virgule fixe exemple : 26.5 = 1 1010.1
		static const int _nb_bits_frac = 8;				//  le nombre de bits de la partie fractionnaire
};

#endif
