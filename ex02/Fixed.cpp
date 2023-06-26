/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:20:25 by omoreno-          #+#    #+#             */
/*   Updated: 2023/06/26 15:36:30 by omoreno-         ###   ########.fr       */
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
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(const Fixed& b)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = b;
}

Fixed::Fixed::Fixed(int i)
{
	std::cout << "Int constructor called" << std::endl;
	value = i * (2 << (fractBits - 1));
}

Fixed::Fixed(float f)
{
	std::cout << "Float constructor called" << std::endl;
	value = std::roundf(f * (2 << (fractBits - 1)));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& b)
{
	std::cout << "Copy assignment operator called" << std::endl;
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

bool Fixed::operator>(const Fixed& b) const
{
	return (getRawBits() > b.getRawBits());
}

bool Fixed::operator<(const Fixed& b) const
{
	return (getRawBits() < b.getRawBits());
}

bool Fixed::operator>=(const Fixed& b) const
{
	return (getRawBits() >= b.getRawBits());
}

bool Fixed::operator<=(const Fixed& b) const
{
	return (getRawBits() <= b.getRawBits());
}

bool Fixed::operator==(const Fixed& b) const
{
	return (getRawBits() == b.getRawBits());
}

bool Fixed::operator!=(const Fixed& b) const
{
	return (getRawBits() != b.getRawBits());
}

Fixed&	Fixed::operator+=(const Fixed& b)
{
	setRawBits (getRawBits() + b.getRawBits());
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

Fixed	Fixed::operator+(const Fixed& b) const
{
	Fixed aux(*this);
	aux += b;
	return (aux);
}

Fixed	Fixed::operator-(const Fixed& b) const
{
	Fixed aux(*this);
	aux -= b;
	return (aux);
}

Fixed	Fixed::operator*(const Fixed& b) const
{
	Fixed aux(*this);
	aux *= b;
	return (aux);
}

Fixed	Fixed::operator/(const Fixed& b) const
{
	Fixed aux(*this);
	aux /= b;
	return (aux);
}

Fixed& Fixed::operator++()
{
	setRawBits(getRawBits() + 1);
    return *this;
}
 
Fixed& Fixed::operator--()
{
	setRawBits(getRawBits() - 1);
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    ++(*this);
     return temp;
}
 
Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    --(*this);
    return temp;
}

Fixed&			Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}
const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed&			Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fx)
{
	os << fx.toFloat();
	return (os);
}
