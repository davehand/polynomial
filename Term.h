//  Name: David Hand
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Assignment 4
//  Description: Header file for Term template class 
//  Filename: Term.h
//  Last modified on: 10/25/12

#if!defined _Term_h
#define _Term_h

#include <iostream>
#include <cmath>
using namespace std;

template <class T>
class Term
{
private:
    //stores two integers for coefficient and degree
    T coefficient;
    int degree;
public:
    Term (T = 0, int = 0);
    //Constructor for Term class
    //PARAM: Defaults the coefficient and degree both to 0
    T getCoefficient();
    //PRE: User requests coefficient of term
    //POST: Returns the value of the coefficient
    //PARAM: None
    //RETURN: T - value of coefficient
    void setCoefficient(T);
    //PRE: User wants to set coefficient of term
    //POST: Sets coefficient and returns
    //PARAM: T - value user wants to set coefficient to
    //RETURN: None
    int getDegree();
    //PRE: User requests degree of term
    //POST: Returns the int value of the degree
    //PARAM: None
    //RETURN: int - value of degree
    void setDegree(int);
    //PRE: User wants to set degree of term, degree is 0 or greater
    //POST: Sets degree and returns
    //PARAM: int - value user wants to set degree to
    //RETURN: None
    void operator=(const Term<T>&);
    //PRE: User wants to set Term equal to another Term
    //POST: Returns Term equal to Term
    //PARAM: Term& - reference to Term to set equal to
    //RETURN: None

template <class U>    
friend ostream& operator<<(ostream&, Term<U>&);
//PRE: User requests to output Term
//POST: Term has been output
//PARAM: ostream& - reference to output stream
//       Term& - reference to Term to output
//RETURN: ostream& - reference to output stream
    
template <class U>    
friend istream& operator>>(istream&, Term<U>&);
//PRE: User requests to input Term
//POST: Term has been input
//PARAM: istream& - reference to input stream
//       Term& - reference to Term to output
//RETURN: istream& - reference to input stream
};

#endif
