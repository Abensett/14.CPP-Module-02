/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:12:15 by abensett          #+#    #+#             */
/*   Updated: 2022/06/13 04:29:18 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fixed_HPP
#define Fixed_HPP

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::ostream;
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
		Fixed &operator=(const Fixed &fixed);		// assignment operator = surcharge de l'operation d'affectation

		Fixed( const int raw );								// constructeur d'initialisation = paramétré
		Fixed( const float raw ); 							// same mais avec flottant
		void	setRawBits( int const raw) ;			// setter
		int		getRawBits( void ) const;;				// accesser
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private:
		int _raw;
		static const int _nb_bits_frac = 8;
};

ostream &operator<<(ostream &o, const Fixed &fixed); // surcharge de l'operation d'insertion <<

#endif
