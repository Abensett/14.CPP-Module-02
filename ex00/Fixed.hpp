/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:12:15 by abensett          #+#    #+#             */
/*   Updated: 2022/06/13 04:10:43 by abensett         ###   ########.fr       */
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
- Copy assignment operator
*/
class Fixed
{
	public:
		Fixed( void );								// Default constructor -> no args
		~Fixed( void );								// Destructor		   -> deleter
		Fixed (const Fixed &fixed);					// Copy constructor	   -> used to copy
		Fixed &operator=(const Fixed &fixed);				// assignment operator = surcharge de l'operation d'affectation

		void setRawBits( int const raw) ;			// setter
		int getRawBits( void ) const;;				// accesser

	private:
		int _raw;
		static const int _nb_bits_frac = 8;
};


#endif
