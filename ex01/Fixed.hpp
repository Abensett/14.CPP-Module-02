/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:12:15 by abensett          #+#    #+#             */
/*   Updated: 2022/06/16 00:04:28 by abensett         ###   ########.fr       */
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
/*CONVERSION
To convert from floating-point to fixed-point, we follow this algorithm:

    Calculate x = floating_input * 2^(fractional_bits)
    Round x to the nearest whole number (e.g. round(x))
    Store the rounded x in an integer container
*/
class Fixed
{
	public:
		Fixed( void );								// Default constructor -> no args
		~Fixed( void );								// Destructor		   -> deleter
		Fixed (const Fixed &fixed);					// Copy constructor	   -> used to copy
		Fixed &operator=(const Fixed &fixed);		// assignment operator = surcharge de l'operation d'affectation  -> Surchage de fonction membre
													// Copy constructor cree une nouvelle instance alors qu'assignment operator non
		Fixed( const int raw );						// constructeur d'initialisation = paramétré
		Fixed( const float raw ); 					// same mais avec flottant
		void	setRawBits( int const raw) ;		// setter
		int		getRawBits( void ) 	const;			// accessors
		float	toFloat( void ) 	const;		
		int		toInt( void ) 		const;
		

	private:
		int _raw;
		static const int _nb_bits_frac = 8;
};

ostream &operator<<(ostream &o, const Fixed &fixed); 			// surcharge de l'operation d'insertion << pour utiliser la sortie standard

#endif
