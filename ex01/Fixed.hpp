/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:36:33 by omoreno-          #+#    #+#             */
/*   Updated: 2023/06/17 13:26:31 by omoreno-         ###   ########.fr       */
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
	Fixed(Fixed& b);
	Fixed& operator=(Fixed& b);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, Fixed& fx);

#endif //__FIXED_HPP__