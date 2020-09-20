/////////////////////////////// FILE HEADER ///////////////////////////////////
//
// Title: Math Library
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
// This file contains and defines all the functions stated in MathLib.h.
// Contains the following methods:
// 
// - absVal();
// - ceiling();
// - floor();
// - round();
// - pow();
// - toString();
// - gcd();
//
///////////////////////////////////////////////////////////////////////////////

#include "MathLib.h"

#include <iostream>

/*
 * Calculates and returns the absolute value of any given number as an integer.
 * 
 * @param val The value to be calculated
 * @return An integer with the absolute value of given val.
 */
int absVal(int val) {
	if (val < 0) { // If value is negative, multiply by -1
		val = -1 * val;
		return val;
	}

	return val;
}

/*
 * Calculates and returns the absolute value of any given number as a double.
 * 
 * @param val The value to be calculated
 * @return A double with the absolute value of given val.
 */
double absVal(double val) {
	if (val < 0) { // If value is negative, multiply by -1
		val = -1.0 * val;
		return val;
	}

	return val;
}

/*
 * Calculates and returns the absolute value of any given number as a long.
 * 
 * @param val The value to be calculated
 * @return A long with the absolute value of given val.
 */
long absVal(long val) {
	if (val < 0) { // If value is negative, multiply by -1
		val = -1 * val;
		return val;
	}

	return val;
}

/*
 * Calculates and returns the ceiling of the double parameter.
 * 
 * @param val The value to be calculated
 * @return A long with the ceiling value of given val.
 */
long ceiling(double val) {
	if (val >= 0) {
		long ceil = (long) val;

		if (val - ceil != 0) { // If decremented too much, increase 1
			ceil++;
		}

		return ceil;
	}

	long ceil = (long) val;

	return ceil;
}

/*
 * Calculates and returns the floor of the double parameter.
 * 
 * @param val The value to be calculated
 * @return A long with the floor value of given val.
 */
long floor(double val) {
	if (val < 0) {
		long floor = (long) val; 

		if (val - floor != 0) { // If incremented too much, decrement 1
			floor--;
		}
		
		return floor;
	}

	long floor = (long) val;

	return floor;
}

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
long round(double val, RoundingRule rule) {
	// Temporary values for cases
	long temp; 
	long temp2;

	switch (rule) {
		case 0: // ROUND_DOWN
			return floor(val);
			break;
		case 1: // ROUND_UP
			return ceiling(val);
			break;
		case 2: // ROUND_TO_ZERO
			return (long)val;
			break;
		case 3: // ROUND_AWAY_ZERO
			// Postive integers case
			if (val > -1) {
				temp = (long) val;

				if (val - temp != 0){
					temp++;
					return temp;
				}
			}

			// Negative integers case
			temp = (long) val;

			if (val - temp != 0) {
				temp--;
			}

			return temp;
			break;
		case 4: // ROUND_HALF_UP
			return floor(val + 0.5); // +0.5 as the separation factor
			break;
		case 5: // ROUND_HALF_DOWN
			return ceiling(val - 0.5); // -0.5 as the separation factor
			break;
		case 6: // ROUND_HALF_TO_ZERO
			// Positive integers case
			if (val > -1) {
				temp = (long) val;

				// If value minus temp is less than 0.5, round to 0
				if (val - temp <= 0.5) {
				return floor(val);
				}

				return ceiling(val);
			}

			return floor(val + 0.5);
			break;
		case 7: // ROUND_HALF_AWAY_ZERO
			// Positive integers case
			if (val >= 0) {
				return floor(val + 0.5);
			}

			temp = (long) val;

				// If value minus temp is less or equal to -0.5, round away from zero
				// Negatives case only
				if (val - temp <= -0.5) {
				return floor(val);
				}

				return ceiling(val);
			break;
		case 8: // ROUND_HALF_TO_EVEN
			// Positive integers case
			if (val >= 0) {
				temp2 = (long) val;

				// If value minus temp2 is greater than 0.9, increase val by 1
				// and return. (Rounds up)
				if (val - temp2 > 0.9) {
					temp = (long) val;
					val++;
					return val;
				}

				// Takes the floor and divides it by correction factor of two
				temp = floor(val + 0.5) / 2;

				return temp * 2;
			}

			temp = (long) val;

			// If value has a decimal of -0.5, take the mod of the coefficient
			if (val - temp == -0.5) {
				if (temp % 2 != 0) {
					temp--;
					return temp;
				}

				return floor(val + 0.5);
			}

			return floor(val + 0.5);
			break;
		case 9: // ROUND_HALF_TO_ODD
			// Positive integers case
			if (val < 0) {
				temp = (long) val;

				// If decimal of val is -0.5, take mod 2 of coefficient
				if (val - temp == -0.5) {
					if (temp % 2 == 0) {
						temp--;
						return temp;
					}
				}

				return floor(val + 0.5);
			}

			temp = (long) val;

			// If remainder of temp is not equal to zero, return temp
			// (an odd number)
			if (temp % 2 != 0) {
				return temp;
			}

			return floor(val + 0.5);
			break;
		default: // Default case: ROUND_HALF_UP
			return floor(val + 0.5);
			break; 
	}
}

/*
 * Calculates and returns the double val to the long exponent power.
 * 
 * @param val The double value to be raised to exponent power.
 * @param exponent The long value that serves as the exponent for val.
 * @return A double with the result of value to the exponent power.
 */
double pow(double val, long exponent) {
	double newVal = val;

	// Zero-exponent rule
	if (exponent == 0) {
		return 1.0;
	}

	// Negative exponents, multiply val by exponent times, return 1 / newVal
	if (exponent < 0) {
		for (int i = exponent; i < -1; i++) {
			newVal = newVal * val;
		}

		return 1/newVal;
	}

	// Positive exponents, multiply val by exponent times
	for (int i = 1; i < exponent; i++) {
		newVal = newVal * val;
	}

	return newVal;
}

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
std::string toString(int num, unsigned int radix, bool boolean) {
	int remainder;
	std::string str;
	bool negative = false;

	// If radix range goes above 37
	if (radix >= 37) {
		return "Radix too large.";
	}

	// Checks if number is negative, multiplies by -1
	if (num < 0) {
		negative = true;
		num = num * -1;
	}

	// Until num reach zero, first it calculates the remainder between
	// num and radix. After, it divides num by radix to have it set for
	// next loop (unless it is 0). Then, the remainder is calculated
	// and added as a char to a string. At the end, str is returned
	// with the representation of num and radix.
	while (num > 0) {
		char c;
		remainder = num % radix;
		num = num / radix;

		if (remainder >= 10) { // If its above 10, it is a letter.
			if (boolean) {
				c = char(remainder + 87); // Lowercase if true
			} else {
				c = char(remainder + 55); // Uppercase if false
			}
		} else {
			c = char(remainder + 48); // Numbers 0-9
		}
		str = c + str; // Concatenates to string
	}

	if (negative) {
		str = "-" + str; // If negative, adds negative sign to front of string
	}

	return str;
}

/*
 * Calculates and returns the greatest common divisor between
 * param firstVal and param secondVal. 
 * 
 * @param firstVal The first value to find the GCD.
 * @param secondVal The second value to find the GCD with firstVal.
 * @return An int with the GCD between firstVal and secondVal.
 */
int gcd(int firstVal, int secondVal) {
	// If secondVal is 0, the program has found the GCD.
	if (secondVal == 0) {
		if (firstVal < 0 || secondVal < 0) { // If any of the two numbers are negative, multiply by -1
			return -1 * firstVal;
		} else {
			return firstVal; // GCD
		}
	}

	// If secondVal is not zero, it calls itself again, modding the second value until
	// it finds the GCD
	return gcd(secondVal, firstVal % secondVal); 
}