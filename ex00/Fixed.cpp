/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:20:25 by omoreno-          #+#    #+#             */
/*   Updated: 2023/06/17 13:03:14 by omoreno-         ###   ########.fr       */
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

Fixed::Fixed(Fixed& b)
{
	std::cout << "Copy constructor called" << std::endl;
	//value = b.getRawBits();
	*this = b;
}

Fixed& Fixed::operator=(Fixed& b)
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
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void Fixed::setRawBits( int const raw )
{
	value = raw;
}
