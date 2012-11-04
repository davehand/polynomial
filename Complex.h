//  Name: David Hand
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Assignment 4
//  Description: Header file for Complex class
//  Filename: Complex.h
//  Last modified on: 10/25/12

#if!defined _Complex_h
#define _Complex_h

#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
private:
    //real and imaginary integers for complex number
    int real;
    int imag;
public:
    Complex (int = 0, int = 0);
    //Constructor for Complex class
    //PARAM: defaults real and imag to 0
    int getReal();
    //PRE: User requests real component of complex
    //POST: Returns the int value of real
    //PARAM: None
    //RETURN: int - value of real
    int getImag();
    //PRE: User requests imag component of complex
    //POST: Returns the int value of imag
    //PARAM: None
    //RETURN: int - value of imag
    Complex operator+(const Complex&);
    //PRE: User wants to add two complex numbers
    //POST: Returns sum of two complex numbers
    //PARAM: Complex& - reference of Complex to add
    //RETURN: Complex - holds sum
    Complex operator*(const Complex&);
    //PRE: User wants to multiply two complex numbers
    //POST: Returns product of two complex numbers
    //PARAM: Complex& - reference of Complex to multiply
    //RETURN: Complex - holds product
    void operator=(const Complex&);
    //PRE: User wants to set Complex equal to Complex
    //POST: Complex is equal to Complex
    //PARAM: Complex& - reference to Complex to set Complex equal to
    //RETURN: None
    bool operator==(int);
    //PRE: User wants to set up equality between Complex and integer
    //POST: True if real and imag are equal to integer, false otherwise
    //PARAM: int - int value to compare with Complex
    //RETURN: bool - true if equality is correct, false otherwise
    bool operator!=(int);
    //PRE: User wants to set up equality between Complex and integer
    //POST: True if real and imag are not equal to integer, false otherwise
    //PARAM: int - int value to compare with Complex
    //RETURN: bool - true if equality is incorrect, false otherwise
    bool operator<(int);
    //PRE: User wants to set up equality between Complex and integer
    //POST: False for output purposes
    //PARAM: int - int value to compare with Complex
    //RETURN: bool - false always
    bool operator>(int);
    //PRE: User wants to set up equality between Complex and integer
    //POST: True for output purposes
    //PARAM: int - int value to compare with Complex
    //RETURN: bool - true always

friend Complex operator+(int, const Complex&);
//PRE: User wants to add int and Complex number
//POST: Returns Complex number of sum
//PARAM: int - constant to add to Complex
//       Complex& - reference to Complex number to add constant to
//RETURN: Complex - holds sum
friend Complex operator*(int, const Complex&);
//PRE: User wants to multiply int and Complex number
//POST: Returns Complex number of product
//PARAM: int - constant to multiply with Complex
//       Complex& - reference to Complex number to multiply constant to
//RETURN: Complex - holds product
friend ostream& operator<<(ostream&, Complex&);
//PRE: User wants to output Complex number
//POST: Complex number is output
//PARAM: ostream& - reference to output stream
//       Complex& - Complex number to output
//RETURN: ostream& - reference to output stream
friend istream& operator>>(istream&, Complex&);
//PRE: User wants to input Complex number
//POST: Complex number is input
//PARAM: istream& - reference to input stream
//       Complex& - Complex number to input
//RETURN: istream& - reference to input stream
};


#endif
