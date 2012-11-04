//  Name: David Hand
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Assignment 4
//  Description: Header file for Polynomial class
//  Filename: Polynomial.h
//  Last modified on: 10/25/12

#if!defined _Polynomial_h
#define _Polynomial_h

#include <iostream>
#include <cmath>
#include <fstream>
#include "Term.cpp"
using namespace std;

const int MAX_SIZE = 10;

template <class T>
class Polynomial
{
private:
    //array for terms of polynomial and number of terms in polynomial
    Term<T> term_array[MAX_SIZE];
    int numTerms;
public:
    Polynomial();
    //Constructor for Polynomial class
    //PARAM: None
    Polynomial(T);
    //Constructor for Polynomial class
    //PARAM: T - sets Polynomial equal to T
    Polynomial<T> operator=(const Polynomial<T>&);
    //PRE: User wants to set one Poly equal to another
    //POST: Returns Polynomial equal to Polynomial
    //PARAM: Polynomial& - reference to polynomial to set equal to
    //RETURN: Polynomial - assigned to other Polynomial
    Polynomial<T> operator=(T);
    //PRE: User wants to set one Poly equal to a constant
    //POST: Returns Polynomial equal to constant
    //PARAM: T - value to set polynomial equal to
    //RETURN: Polynomial - assigned to constant 
    Polynomial<T> operator+(const Polynomial<T>&);
    //PRE: User wants to add two polynomials
    //POST: Returns polynomial of sum
    //PARAM: Polynomial& - reference to polynomial to add
    //RETURN: Polynomial - contains sum of two polynomials
    Polynomial<T> operator*(const Polynomial<T>&);
    //PRE: User wants to multiply two polynomials
    //POST: Returns polynomial of product
    //PARAM: Polynomial& - reference to polynomial to multiply
    //RETURN: Polynomial - contains product of two polynomials
    void writeToFile();
    //PRE: User wants to write polynomial to file
    //POST: Writes polynomial in input format to text file
    //PARAM: None
    //RETURN: None
    void complexWriteToFile();
    //PRE: User wants to write complex polynomial to file
    //POST: Writes complex polynomial in input format to text file
    //PARAM: None
    //RETURN: None
    T evalPoly(double);
    //PRE: User wants to evaluate polynomial for value of x
    //POST: Returns what polynomial evaluates to for value of x
    //PARAM: double - value for x
    //RETURN: double - value polynomial evaluates to
    void sort(Term<T>[], int);
    //PRE: Array of terms is unsorted
    //POST: Sorts the array in descending order
    //PARAM: Term[] - array of terms to sort
    //       int - number of terms in array to sort
    //RETURN: None

template <class U>    
friend istream& operator>>(istream&, Polynomial<U>&);
//PRE: User requests to input polynomial
//POST: Polynomial has been input
//PARAM: istream& - reference to input stream
//       Polynomial& - reference to polynomial to input 
//RETURN: istream& - reference to input stream
    
template <class U>
friend ostream& operator<<(ostream&, Polynomial<U>&);
//PRE: User requests to output polynomial
//POST: Polynomial has been output
//PARAM: ostream& - reference to output stream
//       Polynomial& - reference to polynomial to output
//RETURN: ostream& - reference to output stream
    
template <class U>
friend Polynomial<U> operator+(U, Polynomial<U>&);
//PRE: User wants to add an integer and polynomial
//POST: Polynomial and int have been added
//PARAM: U - constant to add
//       Polynomial& - reference to Polynomial to add to
//RETURN: Polynomial - holds sum

template <class U>
friend Polynomial<U> operator*(U, Polynomial<U>&);
//PRE: User wants to multiply an integer and polynomial
//POST: Polynomial and int have been multiplied
//PARAM: U - constant to multiply
//       Polynomial& - refernce to Polynomial to multiply
//RETURN: Polynomial - holds product
};

#endif
