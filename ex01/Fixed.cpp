/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:20:25 by omoreno-          #+#    #+#             */
/*   Updated: 2023/06/19 09:58:04 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "Fixed.hpp"

int	Fixed::fractBits = 8;

Fixed::Fixed()
{
	value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& b)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = b;
}

Fixed::Fixed::Fixed(int i)
{
	std::cout << "Int constructor called" << std::endl;
	value = i;
}

Fixed::Fixed(float f)
{
	std::cout << "Float constructor called" << std::endl;
	value = f;
}

Fixed& Fixed::operator=(const Fixed& b)
{
	std::cout << "Copy assignment operator called" << std::endl;
	value = b.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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
	return (getRawBits());
}

int Fixed::toInt( void ) const
{
	return (getRawBits());
}

std::ostream& operator<<(std::ostream& os, const Fixed& fx)
{
	os << fx.toFloat();
	return (os);
}
