/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:20:25 by omoreno-          #+#    #+#             */
/*   Updated: 2023/06/22 15:41:15 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cmath>
#include <stdexcept>
#include "Fixed.hpp"

int	Fixed::fractBits = 8;

Fixed::Fixed()
{
	value = 0;
}

Fixed::Fixed(const Fixed& b)
{
	*this = b;
}

Fixed::Fixed::Fixed(int i)
{
	value = i * (2 << (fractBits - 1));
}

Fixed::Fixed(float f)
{
	value = std::roundf(f * (2 << (fractBits - 1)));
}

Fixed::~Fixed()
{
}

Fixed& Fixed::operator=(const Fixed& b)
{
	value = b.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	return (value);
}

void Fixed::setRawBits( int const raw )
{
	value = raw;
}

float Fixed::toFloat( void ) const
{
	float	f;
	f = getRawBits() * 1.0 / (2 << (fractBits - 1));
	return (f);
}

int Fixed::toInt( void ) const
{
	return (getRawBits() / (2 << (fractBits - 1)));
}

bool Fixed::operator>(const Fixed& b)
{
	return (getRawBits() > b.getRawBits());
}

bool Fixed::operator<(const Fixed& b)
{
	return (getRawBits() < b.getRawBits());
}

bool Fixed::operator>=(const Fixed& b)
{
	return (getRawBits() >= b.getRawBits());
}

bool Fixed::operator<=(const Fixed& b)
{
	return (getRawBits() <= b.getRawBits());
}

bool Fixed::operator==(const Fixed& b)
{
	return (getRawBits() == b.getRawBits());
}

bool Fixed::operator!=(const Fixed& b)
{
	return (getRawBits() != b.getRawBits());
}

std::ostream& operator<<(std::ostream& os, const Fixed& fx)
{
	os << fx.toFloat();
	return (os);
}

Fixed&	Fixed::operator+(const Fixed& b)
{
	Fixed* aux = new Fixed(*this);
	aux->setRawBits(aux->getRawBits() + b.getRawBits());
	return (*aux);
}

Fixed&	Fixed::operator-(const Fixed& b)
{
	Fixed* aux = new Fixed(*this);
	aux->setRawBits(aux->getRawBits() - b.getRawBits());
	return (*aux);
}

Fixed&	Fixed::operator*(const Fixed& b)
{
	Fixed* aux = new Fixed(toFloat() * b.toFloat());
	return (*aux);
}

Fixed&	Fixed::operator/(const Fixed& b)
{
	if (b.getRawBits() == 0 )
		throw std::runtime_error(std::string("Exception. Fixed Division by Zero"));
	Fixed* aux = new Fixed(toFloat() / b.toFloat());
	return (*aux);
}

Fixed&	Fixed::operator+=(const Fixed& b)
{
	setRawBits(getRawBits() + b.getRawBits());
	return (*this);
}

Fixed&	Fixed::operator-=(const Fixed& b)
{
	setRawBits(getRawBits() - b.getRawBits());
	return (*this);
}

Fixed&	Fixed::operator*=(const Fixed& b)
{
	Fixed aux(toFloat() * b.toFloat());
	setRawBits(aux.getRawBits());
	return (*this);
}

Fixed&	Fixed::operator/=(const Fixed& b)
{
	if (b.getRawBits() == 0 )
		throw std::runtime_error(std::string("Exception. Fixed Division by Zero"));
	Fixed aux(toFloat() / b.toFloat());
	setRawBits(aux.getRawBits());
	return (*this);
}
