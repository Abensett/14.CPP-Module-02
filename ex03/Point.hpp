/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:19:14 by abensett          #+#    #+#             */
/*   Updated: 2022/06/16 01:31:04 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP_
#define POINT_HPP_

#include "Fixed.hpp"
class Point 
{
 public:
    Point(void);
     ~Point(void);
    Point(const float x, const float y);            // double float constructor
    Point(const Point &point);                      // copy constructor 
    Point &operator=(const Point &point);

    const Fixed get_x(void) const;
    const Fixed get_y(void) const;

 private:
    const Fixed _x;
    const Fixed _y;
};

/* Point.cpp */
ostream &operator<<(ostream &o, const Point &point);

/* bsp.cpp */
// a, b, c are the 3 points of the triangle, point is the point to test return True si dans le triangle, False sinon (sommet et arretes return FALSE)
bool bsp(const Point a, const Point b, const Point c, const Point point);       
#endif