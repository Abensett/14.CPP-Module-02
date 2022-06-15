/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:12:13 by abensett          #+#    #+#             */
/*   Updated: 2022/06/15 21:10:54 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;										// 	Default constructor called
	Fixed b( a );									//	Copy constructor called
	Fixed c;										//	Default constructor called

	c = b;

	std::cout << a.getRawBits() << std::endl;		// 	getRawBits member function called
	std::cout << b.getRawBits() << std::endl;		
	std::cout << c.getRawBits() << std::endl;

	return 0;										//	Destructor called -> delete a; delete b; delete c;
}
