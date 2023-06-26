/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:35:57 by omoreno-          #+#    #+#             */
/*   Updated: 2023/06/26 19:54:58 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main( void ) {
	Point pA(Fixed(1.0f), Fixed(1.0f));
	Point pB(Fixed(2.0f), Fixed(1.0f));
	Point pC(Fixed(1.0f), Fixed(2.0f));
	Point pP(Fixed(1.48f), Fixed(1.48f));
	Point pU;

	std::cout << "p module ** 2 = " << pP.getModuleSqr() << std::endl;
	std::cout << "p module = " << pP.getModule() << std::endl;
	pU = pP.unitary();
	std::cout << "u module = " << pU.getModule() << std::endl;

	std::cout << "a= " << pA;
	std::cout << "b= " << pB;
	std::cout << "c= " << pC;
	std::cout << "p= " << pP;
	std::cout << "u= " << pU;

	// Point sum1, sum2, dif1, dif2;
	// sum1 = (pA + pC);
	// sum2 = (pC + pC);
	// dif1 = (pA - pC);
	// dif2 = (pC - pA);
	// std::cout << "a + c = " << sum1;
	// std::cout << "c + a = " << sum2;
	// std::cout << "a - c = " << dif1;
	// std::cout << "c - a = " << dif2;

	std::cout << "BSP" << std::endl;
	if (bsp(pA, pB, pC, pP))
		std::cout << "inside" << std::endl;
	else
		std::cout << "outside" << std::endl;
	return 0; 
}
