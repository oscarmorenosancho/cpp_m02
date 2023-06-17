/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:35:57 by omoreno-          #+#    #+#             */
/*   Updated: 2023/06/17 13:06:46 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {

Fixed a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );

a = Fixed( 1234.4321f );

std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;

std::cout << "a is " << a.toInt() << " as integer" << std::endl; 
std::cout << "b is " << b.toInt() << " as integer" << std::endl; 
std::cout << "c is " << c.toInt() << " as integer" << std::endl; 
std::cout << "d is " << d.toInt() << " as integer" << std::endl;

return 0; 
}
