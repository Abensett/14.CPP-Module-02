/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:12:13 by abensett          #+#    #+#             */
/*   Updated: 2022/06/16 01:32:27 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Point.hpp"

using std::cout;
using std::endl;

static void check(const Point a, const Point x, const Point y, const Point z) {
    cout << a << (bsp(x, y, z, a) ? " is inside" : " is outside")
            << " Triangle XYZ" << endl;
    cout << a << (bsp(z, y, x, a) ? " is inside" : " is outside")
            << " Triangle ZYX" << endl;
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

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "z: " << z << endl;

    check(a, x, y, z);
    check(b, x, y, z);
    check(c, x, y, z);
    check(d, x, y, z);
    check(e, x, y, z);
    check(x, x, y, z);
    check(y, x, y, z);
    check(z, x, y, z);

    return 0;
}