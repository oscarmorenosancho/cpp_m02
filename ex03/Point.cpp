/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:28:01 by omoreno-          #+#    #+#             */
/*   Updated: 2023/06/26 19:45:57 by omoreno-         ###   ########.fr       */
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

Point::Point(const Point& b) : x(b.getX()), y(b.getY())
{

}

Point::~Point()
{

}

Point&	Point::operator=(const Point& b)
{
	Fixed* px = (Fixed *)&x;
	Fixed* py = (Fixed *)&y;
	px->setRawBits(b.getX().getRawBits());
	py->setRawBits(b.getY().getRawBits());
	return (*this);
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

const Fixed	Point::getModule() const
{
	return (Fixed(1.0f/getModuleSqr().Q_rsqrt().toFloat()));
}

Point	Point::unitary() const
{
	float fx = getX().toFloat();
	float fy = getY().toFloat();
	float modSq = fx * fx + fy * fy;
	float invMod = Q_rsqrt(modSq);
	Point aux(fx*invMod, fy*invMod);
	return (aux);
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
	return ((getX() == b.getX()) && (getY() == b.getY()));
}

bool	Point::operator!=(const Point& b) const
{
	return ((getX() != b.getX()) || (getY() != b.getY()));
}

Point	Point::operator+(const Point& b) const
{
	Point aux((this->getX() + b.getX()), (this->getY() + b.getY()));
	return (aux);
}

Point	Point::operator-(const Point& b) const
{
	Point aux((this->getX() - b.getX()), (this->getY() - b.getY()));
	return (aux);
}

Fixed	Point::operator*(const Point& b) const
{
	return ((x * b.getX()) + (y * b.getY()));
}

Point	Point::perpendicular() const
{
	Point aux(getY(), - getX());
	return (aux);
}

Point&			Point::operator+=(const Point& b)
{
	*this = *this + b;
	return (*this);
}
Point&			Point::operator-=(const Point& b)
{
	*this = *this - b;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Point& p)
{
	os << "( " << p.getX() << ", " << p.getY() << " )" << std::endl;
	return (os);
}