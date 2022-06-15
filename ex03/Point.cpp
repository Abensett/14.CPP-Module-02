/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:26:35 by abensett          #+#    #+#             */
/*   Updated: 2022/06/16 01:34:22 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 
#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}                                // Default constructor   //initialize the point to (0, 0)
Point::~Point(void) {}                                              // Destructor   

Point::Point(const float x, const float y) : _x(x), _y(y) {}        // Constructor with parameters

Point::Point(const Point &point) {*this = point;}                   // Copy constructor

Point &Point::operator=(const Point &point) {                       // Copy assignment operator
    if (this != &point) {
        const_cast<Fixed&>(_x) = point.get_x();
        const_cast<Fixed&>(_y) = point.get_y();
    }
    return *this;
}

const Fixed Point::get_x(void) const {
    return _x;
}

const Fixed Point::get_y(void) const {
    return _y;
}

ostream &operator<<(ostream &o, const Point &point) {
    return (o << "(" << point.get_x() << ", " << point.get_y() << ")");
}