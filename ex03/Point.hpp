/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:28:19 by omoreno-          #+#    #+#             */
/*   Updated: 2023/06/26 19:39:11 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT_HPP__
#define __POINT_HPP__

# include <iostream>
# include <string>
# include "Fixed.hpp"

class Point
{
private:
	const Fixed	x;
	const Fixed	y;
public:
	Point();
	Point(float fX, float fY);
	Point(const Fixed fX, const Fixed fY);
	Point(const Point& b);
	~Point();
	Point&			operator=(const Point& b);
	const Fixed&	getX( ) const;
	const Fixed&	getY( ) const;
	const Fixed		getModuleSqr() const;
	const Fixed		getModule() const;
	bool			operator>(const Point& b) const;
	bool			operator<(const Point& b) const;
	bool			operator>=(const Point& b) const;
	bool			operator<=(const Point& b) const;
	bool			operator==(const Point& b) const;
	bool			operator!=(const Point& b) const;
	Point			operator+(const Point& b) const;
	Point			operator-(const Point& b) const;
	Fixed			operator*(const Point& b) const;
	Point&			operator+=(const Point& b);
	Point&			operator-=(const Point& b);
	Point			perpendicular() const;
	Point			unitary() const;
};

std::ostream& operator<<(std::ostream& os, const Point& p);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif //__POINT_HPP__