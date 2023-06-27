/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:35:57 by omoreno-          #+#    #+#             */
/*   Updated: 2023/06/27 10:46:15 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

static void testSet(Point& pA, Point& pB, Point& pC, Point& pP)
{
	std::cout << "BSP" << std::endl;
	std::cout << "A = " << pA;
	std::cout << "B = " << pB;
	std::cout << "C = " << pC;
	std::cout << "P = " << pP;
	if (bsp(pA, pB, pC, pP))
		std::cout << "inside" << std::endl;
	else
		std::cout << "outside" << std::endl;
}

int main( void ) {
	{
		Point pA(Fixed(1.0f), Fixed(1.0f));
		Point pB(Fixed(2.0f), Fixed(1.0f));
		Point pC(Fixed(1.0f), Fixed(2.0f));
		Point pP(Fixed(1.48f), Fixed(1.48f));
		Point pU;

		std::cout << "p module ** 2 = " << pP.getModuleSqr() << std::endl;
		std::cout << "p module = " << pP.getModule() << std::endl;
		pU = pP.unitary();
		std::cout << "u module = " << pU.getModule() << std::endl;
		std::cout << "u= " << pU;
		std::cout << "ABC rect triang, P close of hypot, but inside." << std::endl;
		testSet(pA, pB, pC, pP);
		// Point sum1, sum2, dif1, dif2;
		// sum1 = (pA + pC);
		// sum2 = (pC + pC);
		// dif1 = (pA - pC);
		// dif2 = (pC - pA);
		// std::cout << "a + c = " << sum1;
		// std::cout << "c + a = " << sum2;
		// std::cout << "a - c = " << dif1;
		// std::cout << "c - a = " << dif2;
	}
	{
		Point pA(Fixed(1.0f), Fixed(1.0f));
		Point pB(Fixed(2.0f), Fixed(1.0f));
		Point pC(Fixed(1.0f), Fixed(2.0f));
		Point pP(Fixed(1.5f), Fixed(1.5f));
		std::cout << "ABC rect triang, P over the hypot." << std::endl;
		testSet(pA, pB, pC, pP);
	}
	{
		Point pA(Fixed(1.0f), Fixed(1.0f));
		Point pB(Fixed(2.0f), Fixed(1.0f));
		Point pC(Fixed(1.0f), Fixed(2.0f));
		Point pP(Fixed(1.0f), Fixed(1.0f));
		std::cout << "ABC rect triang, P on a vertex." << std::endl;
		testSet(pA, pB, pC, pP);
	}
	{
		Point pA(Fixed(0.0f), Fixed(0.0f));
		Point pB(Fixed(1.0f), Fixed(0.0f));
		Point pC(Fixed(0.0f), Fixed(1.0f));
		Point pP(Fixed(0.0f), Fixed(0.5f));
		std::cout << "ABC rect triang with all vertex on x=0 or y=0,";
		std::cout << "P over x=0 over side" << std::endl;
		testSet(pA, pB, pC, pP);
	}
	{
		Point pA(Fixed(0.0f), Fixed(0.0f));
		Point pB(Fixed(1.0f), Fixed(0.0f));
		Point pC(Fixed(0.0f), Fixed(1.0f));
		Point pP(Fixed(0.5f), Fixed(0.0f));
		std::cout << "ABC rect triang with all vertex on x=0 or y=0,";
		std::cout << "P over y=0 over side" << std::endl;
		testSet(pA, pB, pC, pP);
	}
	{
		Point pA(Fixed(0.0f), Fixed(0.0f));
		Point pB(Fixed(1.0f), Fixed(0.0f));
		Point pC(Fixed(-1.0f), Fixed(1.0f));
		Point pP(Fixed(0.0f), Fixed(0.45f));
		std::cout << "ABC obtuse triang,";
		std::cout << "P over y=0 inside" << std::endl;
		testSet(pA, pB, pC, pP);
	}
	{
		Point pA(Fixed(0.0f), Fixed(0.0f));
		Point pB(Fixed(1.0f), Fixed(0.0f));
		Point pC(Fixed(-1.0f), Fixed(1.0f));
		Point pP(Fixed(-0.45f), Fixed(0.45f));
		std::cout << "ABC obtuse triang,";
		std::cout << "P over y=-x inside" << std::endl;
		testSet(pA, pB, pC, pP);
	}
	return 0; 
}
