//  Name: David Hand
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Assignment 4
//  Description: Holds coefficient and degree of a term
//  Filename: Term.cpp
//  Last modified on: 10/25/12

#include "Term.h"

//constructor for Term, sets initial values for coef and deg
template <class T>
Term<T>::Term (T coef, int deg)
{
    coefficient = coef;
    degree = deg;
}

//returns value of coefficient for a term
template <class T>
T Term<T>::getCoefficient()
{
    return coefficient;
}

//sets value of coefficient for a term
template <class T>
void Term<T>::setCoefficient(T a)
{
    coefficient = a;
}

//returns value of degree for a term
template <class T>
int Term<T>::getDegree()
{
    return degree;
}

//sets value of degree for a term, if value is greater than or equal to 0
template <class T>
void Term<T>::setDegree(int a)
{
    if (a >= 0)
        degree = a;
}

//overload = operator to set a term equal to another term
template <class T>
void Term<T>::operator=(const Term<T>& t)
{
    coefficient = t.coefficient;
    degree = t.degree;
    
    return;
}

//overload << operator to output term
template <class U>
ostream& operator<<(ostream& stream, Term<U>& t)
{
    U x;
    //outputs term if coefficient isn't 0
    if (t.coefficient != 0)
    {
        //checks value of coefficient and degree, outputs accordingly
        //removes negative sign if present for output purposes only
        if (t.coefficient > 0)
        {
            if (t.coefficient != 1)
            {
                if (t.degree > 1)
                    stream << t.coefficient << "x^" << t.degree;
                else if (t.degree == 1)
                    stream << t.coefficient << "x";
                else
                    stream <<t.coefficient;
            }
            else
            {
                if (t.degree > 1)
                    stream << "x^" << t.degree;
                else if (t.degree == 1)
                    stream << "x";
                else
                    stream << t.coefficient;
            }
        }
        else
        {
            if (t.coefficient != 1)
            {
                x = -1*(t.coefficient);
                if (t.degree > 1)
                {
                    stream << x << "x^" << t.degree;
                }
                else if (t.degree == 1)
                    stream << x << "x";
                else
                    stream << x;
            }
            else
            {
                if (t.degree > 1)
                    stream << "x^" << t.degree;
                else if (t.degree == 1)
                    stream << "x";
                else
                {
                    x = -1*(t.coefficient);
                    stream << x;
                }
            }
        }
    }

    return stream;
}

//overload >> operator to input term
template <class U>
istream& operator>>(istream& stream, Term<U>& t)
{
    int degree;
    bool tryAgain = true;
    
    //get coefficient and degree
    stream >> t.coefficient >> degree;

    //make sure degree is greater than 1
    //if not, prompt user for reentry
    if (degree >= 0)
        t.degree = degree;
    else
    {
        //use cin so that prompts user to fix data from file if faulty degree is placed in file
        cout << "Degree needs to be 0 or greater.  Try again: " << endl;
        while (tryAgain)
        {
            cin >> degree;
        
            if (cin.fail())
            {
                cout << "Invalid input - Please enter an integer value: " << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else if (degree < 0)
                cout << "Invalid input - Please enter a value greater than or equal to 0: " << endl;
            else
                tryAgain = false;
        }
        t.degree = degree;
    }
    
    return stream;
}
