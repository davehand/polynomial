//  Name: David Hand
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Assignment 4
//  Description: Stores real and imaginary components of a number
//  Filename: Complex.cpp
//  Last modified on: 10/25/12

#include "Complex.h"

//constructor for Complex, sets initial values for real and imag
Complex::Complex (int r, int i)
{
    real = r;
    imag = i;
}

//return value of real
int Complex::getReal()
{
    return real;
}

//return value of imag
int Complex::getImag()
{
    return imag;
}

//adds two complex numbers and returns a complex number
Complex Complex::operator+(const Complex& C)
{
    return (Complex(real + C.real, imag + C.imag));
}

//multiplies two complex numbers and returns a complex number
Complex Complex::operator*(const Complex& C)
{
    Complex temp;
    temp.real = ((real*C.real) + (-1)*(imag*C.imag));
    temp.imag = ((real*C.imag) + (imag*C.real));
    return temp;
}

//sets complex number equal to another complex number
void Complex::operator=(const Complex& C)
{
    real = C.real;
    imag = C.imag;
}

//checks if complex number real and imag components is equal to an integer
bool Complex::operator==(int a)
{
    if ((real == a) && (imag == a))
        return true;
    else
        return false;
}

//checks if complex number real and imag components is not equal to an integer
bool Complex::operator!=(int a)
{
    if ((real == a) && (imag == a))
        return false;
    else
        return true;
}

//returns false, used for output purposes only
bool Complex::operator<(int a)
{
    return false;
}

//returns true, used for output purposes only
bool Complex::operator>(int a)
{
    return true;
}

//adds a complex number and an integer and returns a complex number
Complex operator+(int i, const Complex& C)
{
    return (Complex(i + C.real, C.imag));
}

//multiplies a complex number and an integer and returns a complex number
Complex operator*(int a, const Complex& C)
{
    return (Complex(a*C.real, a*C.imag));
}

//overload >> operator to input real and imag
istream& operator>>(istream& stream, Complex& C)
{
    stream >> C.real >> C.imag;
    return stream;
}

//overload << operator to output in Complex number format
ostream& operator<<(ostream& stream, Complex& C)
{
    //produces different output depending on sign and magnitude of real and imag
    if (abs(C.imag) != 1)
    {
        if ((C.real != 0) && (C.imag > 0))
            stream << "(" << C.real << " + " << C.imag << "i)";
        else if ((C.real != 0) && (C.imag < 0))
            stream << "(" << C.real << " - " << abs(C.imag) << "i)";
        else if ((C.real == 0) && (C.imag > 0))
            stream << "(" << C.imag << "i)";
        else if ((C.real == 0) && (C.imag < 0))
            stream << "(" << C.imag << "i)";
        else
            stream << C.real;
    }
    else
    {
        if ((C.real != 0) && (C.imag > 0))
            stream << "(" << C.real << " + " << "i)";
        else if ((C.real != 0) && (C.imag < 0))
            stream << "(" << C.real << " - " << "i)";
        else if ((C.real == 0) && (C.imag > 0))
            stream << "(" << "i)";
        else if ((C.real == 0) && (C.imag < 0))
            stream << "(" << "-" << "i)";
        else
            stream << C.real;
    }
    return stream;
}

