/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:36:33 by omoreno-          #+#    #+#             */
/*   Updated: 2023/06/22 14:57:11 by omoreno-         ###   ########.fr       */
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
	bool	operator>(const Fixed& b);
	bool	operator<(const Fixed& b);
	bool	operator>=(const Fixed& b);
	bool	operator<=(const Fixed& b);
	bool	operator==(const Fixed& b);
	bool	operator!=(const Fixed& b);
	Fixed&	operator+(const Fixed& b);
	Fixed&	operator-(const Fixed& b);
	Fixed&	operator*(const Fixed& b);
	Fixed&	operator/(const Fixed& b);
	Fixed&	operator+=(const Fixed& b);
	Fixed&	operator-=(const Fixed& b);
	Fixed&	operator*=(const Fixed& b);
	Fixed&	operator/=(const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fx);

#endif //__FIXED_HPP__