/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:37:26 by abensett          #+#    #+#             */
/*   Updated: 2022/06/16 23:05:00 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
/*********************************************************
Si on note , et les coordonnées des points A, B et C
	Alors si on note
(d est determinant de (AB AC))
d = (Ax - Bx)(Cy - Ay) - (Ay - By)(Cx - Bx)
Si :
a) d > 0, alors C est à gauche de la droite
b) d = 0, alors C est sur la droite
c) d < 0, alors C est à droite de la droite
**********************************************************/
static Fixed IsLeft(const Point a, const Point b, const Point c)
{            // IsLeftulate (Ax - Bx)(Cy - Ay)
	Fixed tmp_1 = (b.get_x() - a.get_x()) * (c.get_y() - a.get_y());        //IsLeftulate (Ay - By)(Cx - Bx)
	Fixed tmp_2 = (b.get_y() - a.get_y()) * (c.get_x() - a.get_x());
	return (tmp_1 - tmp_2);													// return la difference des deu
}

bool bsp(const Point a, const Point b, const Point c, const Point point) {  // check if a point is in the triangle
	Fixed side1 = IsLeft(a, c, point);                                    // positive if on the left of AC
	Fixed side2 = IsLeft(a, b, point);                                    // positive if on the left of AB
	Fixed side3 = IsLeft(c, b, point);                                    // positive if on the left of CB

	return (IsLeft(a, c, b) * side1 > Fixed(0)
 		&& IsLeft(a, b, c)  * side2 > Fixed(0)
 		&& IsLeft(c, b, a) * side3 > Fixed(0));
 }
