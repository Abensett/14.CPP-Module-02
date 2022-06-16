/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:12:13 by abensett          #+#    #+#             */
/*   Updated: 2022/06/16 23:02:09 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Point.hpp"

using std::cout;
using std::endl;

static void check(const Point point, const Point a, const Point b, const Point c)
{
    cout << point << (bsp(a, b, c, point) ? " is inside" : " is outside")
    << " the triangle." << endl;
}

int main(void) {
    Point x(0, 0);
    Point y(0, 1);
    Point z(1, 0);

    Point a(0, 0.5f);
    Point b(0.5f, 1);
    Point c(1, 0.5f);
    Point d(0.5f, 0);
    Point e(0.5f, 0.5f);
    Point f(0.25f,0.25f);
    Point g(0.375f,0.375f);

    cout << "a: " << x << endl;
    cout << "b: " << y << endl;
    cout << "c: " << z << endl;

    check(a, x, y, z);
    check(b, x, y, z);
    check(c, x, y, z);
    check(d, x, y, z);
    check(e, x, y, z);
    check(x, x, y, z);
    check(y, x, y, z);
    check(z, x, y, z);
    check(f, x, y, z);
    check(g, x, y, z);

    return 0;
}
