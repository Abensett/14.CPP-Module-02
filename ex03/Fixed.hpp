/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:12:15 by abensett          #+#    #+#             */
/*   Updated: 2022/06/16 00:13:51 by abensett         ###   ########.fr       */
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

		Fixed( const int raw );						// constructeur d'initialisation = paramétré
		Fixed( const float raw ); 					// same mais avec flottant
		void	setRawBits( int const raw) ;		// setter
		int		getRawBits( void ) const;;			// accessor
		float	toFloat( void ) const;
		int		toInt( void ) const;

		bool operator>(const Fixed &fixed) const;
		bool operator<(const Fixed &fixed) const;
		bool operator>=(const Fixed &fixed) const;
		bool operator<=(const Fixed &fixed) const;
		bool operator==(const Fixed &fixed) const;
		bool operator!=(const Fixed &fixed) const;

		Fixed operator+(const Fixed &fixed) const;
		Fixed operator-(const Fixed &fixed) const;
		Fixed operator*(const Fixed &fixed) const;
		Fixed operator/(const Fixed &fixed) const;

		Fixed &operator++(void);
		Fixed &operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);

		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);


	private:
		int 			_raw;
		static const int _nb_bits_frac = 8;
};

ostream &operator<<(ostream &o, const Fixed &fixed); // surcharge de l'operation d'insertion <<

#endif
