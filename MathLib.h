/////////////////////////////// FILE HEADER ///////////////////////////////////
//
// Title: Math Library Header
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
// This header file includes all the functions to be used for the Math Library
// in MathLib.cpp.
//
///////////////////////////////////////////////////////////////////////////////

// Guards
#ifndef MATHLIB_H
#define MATHLIB_H

#include <string>

// Enumeration with all the rounding rule options (0-9)
enum RoundingRule {
	ROUND_DOWN, 
	ROUND_UP, 
	ROUND_TO_ZERO,
	ROUND_AWAY_ZERO, 
	ROUND_HALF_UP, 
	ROUND_HALF_DOWN, 
	ROUND_HALF_TO_ZERO, 
	ROUND_HALF_AWAY_ZERO,
	ROUND_HALF_TO_EVEN, 
	ROUND_HALF_TO_ODD
};

/*
 * Calculates and returns the absolute value of any given number as an integer.
 * 
 * @param val The value to be calculated
 * @return An integer with the absolute value of given val.
 */
int absVal(int val);

/**
 * Calculates and returns the absolute value of any given number as a double.
 * 
 * @param val The value to be calculated
 * @return A double with the absolute value of given val.
 */
double absVal(double val);

/*
 * Calculates and returns the absolute value of any given number as a long.
 * 
 * @param val The value to be calculated
 * @return A long with the absolute value of given val.
 */
long absVal(long val);

/*
 * Calculates and returns the ceiling of the double parameter.
 * 
 * @param val The value to be calculated
 * @return A long with the ceiling value of given val.
 */
long ceiling(double val);

/*
 * Calculates and returns the floor of the double parameter.
 * 
 * @param val The value to be calculated
 * @return A long with the floor value of given val.
 */
long floor(double val);

/*
 * Depending on the RoundingRule parameter, performs one of the following
 * through use of a switch statement:
 *
 * 0 - ROUND_DOWN: The floor of val.
 * 1 - ROUND_UP: The ceiling of val.
 * 2 - ROUND_TO_ZERO: Round to the value closer to zero.
 * 3 - ROUND_AWAY_ZERO: Round to the value further from zero.
 * 4 - ROUND_HALF_UP: Rounds to nearest integer, .5 rounds to ceiling
 * 5 - ROUND_HALF_DOWN: Rounds to nearest integer, .5 rounds to floor
 * 6 - ROUND_HALF_TO_ZERO: Rounds closer to zero
 * 7 - ROUND_HALF_AWAY_ZERO: Rounds further away from zero
 * 8 - ROUND_HALF_TO_EVEN: Rounds to nearest even integer
 * 9 - ROUND_HALF_TO_ODD: Rounds to nearest odd integer
 *
 * Has ROUND_HALF_UP as default case.
 * 
 * @param val The value to be calculated
 * @param rule The rule wished to be used on the function
 * @return A long with the value depending on the function that was called
 */
long round(double val, RoundingRule rule);

/*
 * Calculates and returns the double val to the long exponent power.
 * 
 * @param val The double value to be raised to exponent power.
 * @param exponent The long value that serves as the exponent for val.
 * @return A double with the result of value to the exponent power.
 */
double pow(double val, long exponent);

/*
 * This function builds a std::string representation of the int (num) parameter using 
 * the unsigned int (radix) parameter as the radix (i.e. numerical base). The string 
 * representation of the int will use the digits from 0 - 9 followed by a - z as needed. 
 * Negative numbers are prefixed with ’-’.
 *
 * If the radix is greater than 36, return a string containing "Radix too large.". The radix
 * should have a default value of 10.
 *
 * The bool parameter indicates if the returned number contains lower case (true) or upper case
 * (false) letters. This only applies when the radix is less than 37. It should have a default
 * value of true.
 *
 * @param num Integer to be represented as a string using the radix value.
 * @param radix Unsigned integer that serves as numerical base for integer num.
 * @param boolean If true, returns letters as lowercase, otherwise returns uppercase.
 * @return A std::string representation of the calculated value.
 */
std::string toString(int num, unsigned int radix, bool boolean);

/*
 * Calculates and returns the greatest common divisor between
 * param firstVal and param secondVal. 
 * 
 * @param firstVal The first value to find the GCD.
 * @param secondVal The second value to find the GCD with firstVal.
 * @return An int with the GCD between firstVal and secondVal.
 */
int gcd(int firstVal, int secondVal);

#endif // MATHLIB_H