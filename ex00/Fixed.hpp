/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:36:33 by omoreno-          #+#    #+#             */
/*   Updated: 2023/06/23 15:02:45 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __FIXED_HPP__
#define __FIXED_HPP__

# include <string>
class Fixed
{
private:
	int	value;
	static int	fractBits;
public:
	Fixed();
	Fixed(const Fixed& b);
	~Fixed();
	Fixed& operator=(const Fixed& b);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};


#endif //__FIXED_HPP__