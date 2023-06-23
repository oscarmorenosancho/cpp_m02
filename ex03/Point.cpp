/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:28:01 by omoreno-          #+#    #+#             */
/*   Updated: 2023/06/23 15:51:12 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0.0f), y(0.0f)
{
}

Point::Point(float fX, float fY) : x(fX), y(fY)
{
}
Point::Point(const Fixed fX, const Fixed fY) : x(fX), y(fY)
{
}

Point::Point(const Point& b)
{
	*this = b;
}

Point::~Point()
{

}

Point	Point::operator=(const Point& b)
{
	return (Point(b.getX(), b.getY()));
}

const Fixed&	Point::getX( ) const
{
	return (x);
}

const Fixed&	Point::getY( ) const
{
	return (y);
}

const Fixed	Point::getModuleSqr() const
{
	return ((x * x) + (y * y));
}

bool	Point::operator>(const Point& b) const
{
	return (getModuleSqr() > b.getModuleSqr());
}

bool	Point::operator<(const Point& b) const
{
	return (getModuleSqr() < b.getModuleSqr());
}

bool	Point::operator>=(const Point& b) const
{
	return (getModuleSqr() >= b.getModuleSqr());
}

bool	Point::operator<=(const Point& b) const
{
	return (getModuleSqr() <= b.getModuleSqr());
}

bool	Point::operator==(const Point& b) const
{
	return (getModuleSqr() == b.getModuleSqr());
}

bool	Point::operator!=(const Point& b) const
{
	return (getModuleSqr() != b.getModuleSqr());
}

Point&	Point::operator+=(const Point& b)
{
	Point aux(x + b.getX(), y + b.getY());
	*this = aux;
	return (*this);
}

Point&	Point::operator-=(const Point& b)
{
	Point aux(x - b.getX(), y - b.getY());
	*this = aux;
	return (*this);
}

Point	Point::operator+(const Point& b) const
{
	Point aux(*this);
	aux += b;
	return (aux);
}

Point	Point::operator-(const Point& b) const
{
	Point aux(*this);
	aux -= b;
	return (aux);
}

Fixed	Point::operator*(const Point& b) const
{
	return ((x * b.getX()) + (y * b.getY()));
}

std::ostream& operator<<(std::ostream& os, const Point& p)
{
	os << "( " << p.getX() << ", " << p.getY() << " )" << std::endl;
	return (os);
}