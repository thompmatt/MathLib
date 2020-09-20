#/////////////////////////////// FILE HEADER ///////////////////////////////////
#/
#/ Title: Math Library Makefile
#/ Files: MathLib.h, MathLib.cpp, demo.cpp, README.md, Makefile
#/ Course: CS 368, Spring 2020
#/
#/ Author: Matt Thompson
#/ Student ID: 9081263262
#/ Email: mathompson23@wisc.edu
#/ Lecturer's Name: Marc Renault
#/
#/ Online Sources:
#/ - https://www.tutorialspoint.com/cplusplus-program-to-find-gcd-of-two-
#/	 numbers-using-recursive-euclid-algorithm
#/ - https://stackoverflow.com/questions/19485227/convert-ascii-value-to-char
#/ - http://www.cs.trincoll.edu/~ram/cpsc110/inclass/conversions.html
#/ 
#/////////////////////////// FILE DESCRIPTION /////////////////////////////////
#/ 
#/ This is the makefile for demo.cpp, which displays the Math Library.
#/
#//////////////////////////////////////////////////////////////////////////////

# Makefile

CXX=g++
CXXFLAGS=-Wall

all: build

MathLib.o: MathLib.h

clean:
	-rm MathLib.o
	-rm demo

build: demo.cpp MathLib.o
	$(CXX) $(CXXFLAGS) -o demo demo.cpp MathLib.o
