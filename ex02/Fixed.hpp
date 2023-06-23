/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:36:33 by omoreno-          #+#    #+#             */
/*   Updated: 2023/06/23 12:50:16 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __FIXED_HPP__
#define __FIXED_HPP__

# include <string>
# include <iostream>
class Fixed
{
private:
	int	value;
	static int	fractBits;
public:
	Fixed();
	Fixed(int i);
	Fixed(float f);
	Fixed(const Fixed& b);
	~Fixed();
	Fixed&	operator=(const Fixed& b);
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
	bool	operator>(const Fixed& b) const;
	bool	operator<(const Fixed& b) const;
	bool	operator>=(const Fixed& b) const;
	bool	operator<=(const Fixed& b) const;
	bool	operator==(const Fixed& b) const;
	bool	operator!=(const Fixed& b) const;
	Fixed&	operator+=(const Fixed& b);
	Fixed&	operator-=(const Fixed& b);
	Fixed&	operator*=(const Fixed& b);
	Fixed&	operator/=(const Fixed& b);
	Fixed	operator+(const Fixed& b) const;
	Fixed	operator-(const Fixed& b) const;
	Fixed	operator*(const Fixed& b) const;
	Fixed	operator/(const Fixed& b) const;
	//The increment/decrement operator (prefix)
	Fixed& operator++();
    Fixed& operator--();
	//-The increment/decrement operator (postfix)
	Fixed	operator++(int);
	Fixed	operator--(int);
	// • A static member function min that takes as parameters two references on fixed-point numbers, and returns a reference to the smallest one.
	static Fixed&		min(Fixed& a, Fixed& b);
	// • A static member function min that takes as parameters two references to constant fixed-point numbers, and returns a reference to the smallest one.
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	// • A static member function max that takes as parameters two references on fixed-point numbers, and returns a reference to the greatest one.
	static Fixed&		max(Fixed& a, Fixed& b);
	// • A static member function max that takes as parameters two references to constant fixed-point numbers, and returns a reference to the greatest one.
	static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fx);

#endif //__FIXED_HPP__