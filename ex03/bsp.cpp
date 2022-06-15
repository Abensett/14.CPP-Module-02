/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:37:26 by abensett          #+#    #+#             */
/*   Updated: 2022/06/16 01:32:14 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed calc(const Point x, const Point y, const Point z) {            // calculate the distance between two points
    Fixed tmp_1 = (x.get_x() - y.get_x()) * (z.get_y() - y.get_y());        //calculate the first term of the distance  
    Fixed tmp_2 = (x.get_y() - y.get_y()) * (z.get_x() - y.get_x());        // calculate the second term    

    return (tmp_1 - tmp_2);                                                   
}

bool bsp(const Point a, const Point b, const Point c, const Point point) {  // check if a point is in the triangle
    Fixed s = calc(a, c, point);                                    // calculate the s term of the bsp equation (see the formula)                                  
    Fixed t = calc(b, a, point);

    if ((s < Fixed(0)) != (t < Fixed(0)) && s != Fixed(0) && t != Fixed(0)) // if the point is in the triangle
        return false;

    Fixed d = calc(c, b, point);                                            // calculate the distance between the point and the triangle

    return (d == Fixed(0) || (d < Fixed(0)) == (s + t <= Fixed(0)));        
}