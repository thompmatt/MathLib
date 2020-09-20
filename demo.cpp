/////////////////////////////// FILE HEADER ///////////////////////////////////
//
// Title: Demo for Math Library
// Files: MathLib.h, MathLib.cpp, demo.cpp, README.md, Makefile
// Course: CS 368, Spring 2020
//
// Author: Matt Thompson
// Student ID: 9081263262
// Email: mathompson23@wisc.edu
// Lecturer's Name: Marc Renault
//
// Online Sources:
// - https://www.tutorialspoint.com/cplusplus-program-to-find-gcd-of-two-
//	 numbers-using-recursive-euclid-algorithm
// - https://stackoverflow.com/questions/19485227/convert-ascii-value-to-char
// - http://www.cs.trincoll.edu/~ram/cpsc110/inclass/conversions.html
// 
//////////////////////////// FILE DESCRIPTION /////////////////////////////////
// 
// This file demo's all the function in the Math Library.
//
///////////////////////////////////////////////////////////////////////////////

#include "MathLib.h"
#include <iostream>

int main()
{
	std::cout << "Abs Value Int: " << absVal(-4) << std::endl;
	std::cout << "Abs Value Double: " << absVal(-20.5) << std::endl;
	std::cout << "Abs Value Long: " << absVal(-1234567899876543211) << std::endl;
	std::cout << "Ceiling: " << ceiling(24.1) << std::endl;
	std::cout << "Floor: " << floor(-63.0) << std::endl;
	std::cout << "ROUND_DOWN: " << round(2.3, ROUND_DOWN) << std::endl;
	std::cout << "ROUND_UP: " << round(-42.0, ROUND_UP) << std::endl;
	std::cout << "ROUND_TO_ZERO: " << round(7.3, ROUND_TO_ZERO) << std::endl;
	std::cout << "ROUND_AWAY_ZERO: " << round(-81.3, ROUND_AWAY_ZERO) << std::endl;
	std::cout << "ROUND_HALF_UP: " << round(21.2, ROUND_HALF_UP) << std::endl;
	std::cout << "ROUND_HALF_DOWN: " << round(-44.6, ROUND_HALF_DOWN) << std::endl;
	std::cout << "ROUND_HALF_TO_ZERO: " << round(7.8, ROUND_HALF_TO_ZERO) << std::endl;
	std::cout << "ROUND_HALF_AWAY_ZERO: " << round(91.5, ROUND_HALF_AWAY_ZERO) << std::endl;
	std::cout << "ROUND_HALF_TO_EVEN: " << round(-5.6, ROUND_HALF_TO_EVEN) << std::endl;
	std::cout << "ROUND_HALF_TO_ODD: " << round(17.5, ROUND_HALF_TO_ODD) << std::endl;
	std::cout << "Power: " << pow(2.0, 5) << std::endl;
	std::cout << "toString: " << toString(25, 2, false) << std::endl;
	std::cout << "GCD: " << gcd(72, 14) << std::endl;

	return 0;
}