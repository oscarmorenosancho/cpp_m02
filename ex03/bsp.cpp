/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:28:41 by omoreno-          #+#    #+#             */
/*   Updated: 2023/06/27 10:51:51 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static bool onSameSide(Point const base, Point const cobase,
						Point const test, Point const point)
{
	Point side = cobase - base;
	Point relTest = test - base;
	Point relPoint = point - base;
	Point perp = side.perpendicular();
	Fixed TestDotProd = perp * relTest;
	Fixed PointDotProd = perp * relPoint;
	// std::cout << "Testing on side" << std::endl;
	// std::cout << "side = " << side;
	// std::cout << "perp = " << perp;
	// std::cout << "relTest = " << relTest;
	// std::cout << "relPoint = " << relPoint;
	// std::cout << "TestDotProd = " << TestDotProd << std::endl;
	// std::cout << "PointDotProd = " << PointDotProd << std::endl;
	// std::cout << "TestDotProd * PointDotProd = " << TestDotProd * PointDotProd << std::endl;
	return ((TestDotProd * PointDotProd) > 0);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	std::cout << "a= " << a;
	std::cout << "b= " << b;
	std::cout << "c= " << c;
	std::cout << "p= " << point;
	if (a == b)
		std::cout << "a == b" << std::endl;
	if (a == c)
		std::cout << "a == c" << std::endl;
	if (b == c)
		std::cout << "b == c" << std::endl;
	if ((a != b) && (a != c) && (b != c))
	{
		bool inside = onSameSide(a, b, c, point);
		inside = inside && onSameSide(b, c, a, point);
		inside = inside && onSameSide(c, a, b, point);
		return (inside);
	}
	return (false);
}