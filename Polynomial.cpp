//  Name: David Hand
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Assignment 4
//  Description: Stores terms as a polynomial function
//  Filename: Polynomial.cpp
//  Last modified on: 10/25/12

#include "Polynomial.h"

//constructor for Polynomial
template <class T>
Polynomial<T>::Polynomial()
{
    numTerms = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        term_array[i].setCoefficient(0);
        term_array[i].setDegree(0);
    }
}

//constructor for constant Polynomial
template <class T>
Polynomial<T>::Polynomial(T a)
{
    numTerms = 1;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        term_array[i].setCoefficient(0);
        term_array[i].setDegree(0);
    }
    term_array[0].setCoefficient(a);
}

//overload = operator to set Polynomial = Polynomial
template <class T>
Polynomial<T> Polynomial<T>::operator=(const Polynomial<T>& p)
{
    //places all terms in one Polynomial into another
    for (int i = 0; i < p.numTerms; i++)
        term_array[i] = p.term_array[i];
    
    //removes excess terms from polynomial
    if (numTerms > p.numTerms)
    {
    	for (int i = numTerms; i < p.numTerms; i++)
    	{
    		term_array[i].setCoefficient(0);
    		term_array[i].setDegree(0);
    	}
    }
    
    //sets number of terms of one polynomial to number of terms of the other
    numTerms = p.numTerms;
    
    return *this;
}

//overload = operator to set Polynomial = constant
template <class T>
Polynomial<T> Polynomial<T>::operator=(T a)
{
    //Remove all values from polynomial
    for (int i = 0; i < numTerms; i++)
    {
    	term_array[i].setCoefficient(0);
    	term_array[i].setDegree(0);
    }
    
    //put constant in polynomial and set number of terms to 1
    numTerms = 1;
    Term<T> temp (a, 0);
    term_array[0] = temp;
    
    return *this;
}

//overload + operator to add two polynomials
template <class T>
Polynomial<T> Polynomial<T>::operator+(const Polynomial<T>& p)
{
    Term<T> temp_array[MAX_SIZE*2];
    bool not_present = true;
    int index = 0;
    Polynomial result;
    
    //put calling polynomials terms into temporary array
    for (int i = 0; i < numTerms; i++)
        temp_array[i] = term_array[i];
    
    //set calling polynomials numTerms to resultant polynomials numTerms
    result.numTerms = numTerms;
    index = numTerms;
        
    //perform the addition
    for (int i = 0; i < p.numTerms; i++)
    {
        Term<T> t = p.term_array[i];
        
        //checks if term's degree is already in array, adds coefficients of terms if it is 
        for (int j = 0; j < MAX_SIZE; j++)
        {
            if (temp_array[j].getDegree() == t.getDegree())
            {
                if (temp_array[j].getCoefficient() != 0)
                {
                    temp_array[j].setCoefficient(temp_array[j].getCoefficient() + t.getCoefficient());
                    not_present = false;
                }
            }
        }
        //if degree not present, puts term in array
        if (not_present)
        {
            if (result.numTerms < MAX_SIZE)
            	result.numTerms++;
            temp_array[index] = t;
            index++;
        }
        else
            not_present = true;
    }
    
    //sort array
    result.sort(temp_array, index);
    
    return result;
}

//overload * operator to multiply two polynomials
template <class T>
Polynomial<T> Polynomial<T>::operator*(const Polynomial<T>& p)
{
    Term<T> temp_array[MAX_SIZE*5];
    
    int index = 0;
    bool not_present = true;
    Polynomial result;
    
    //iterates through both polynomials, multiplying each term in one by each term in the other
    for (int i = 0; i < numTerms; i++)
        for (int j = 0; j < p.numTerms; j++)
        {
            Term<T> a = p.term_array[j];
            Term<T> t (term_array[i].getCoefficient() * a.getCoefficient(), term_array[i].getDegree() + a.getDegree());
            
            //checks if resultant term's degree is already in product polynomial, adds coefficients if it is
            for (int k = 0; k < MAX_SIZE*5; k++)
            {
                if (temp_array[k].getDegree() == t.getDegree())
                {
                    if (temp_array[k].getCoefficient() != 0)
                    {
                        temp_array[k].setCoefficient(temp_array[k].getCoefficient() + t.getCoefficient());
                        not_present = false;
                    }
                }
            }
            //if degree not present, puts term in array
            if (not_present)
            {
                temp_array[index] = t;
                index++;
                if (result.numTerms < MAX_SIZE)
                	result.numTerms++;
            }
            else
                not_present = true;
        }
    
    //sort temp_array
    result.sort(temp_array, index);
    
    return result;
}

//write polynomial's contents to file in input format
template <class T>
void Polynomial<T>::writeToFile()
{
    int count = 0;
    ofstream fout;
    
    fout.open("output.txt");  
    
    //output number of terms
    fout << numTerms;
    
    //output each term in the polynomial
    while (count < numTerms)
    {
        Term<T> t = term_array[count];
        T x = t.getCoefficient();
        fout << " " << x << " " << t.getDegree();
        count++;
    }
    
    fout.close();
}

//write polynomial's contents to file in input format
template <class T>
void Polynomial<T>::complexWriteToFile()
{
    int count = 0;
    ofstream fout;
    
    fout.open("complex_output.txt");  
    
    //output number of terms
    fout << numTerms;
    
    //output each term in the polynomial
    while (count < numTerms)
    {
        Term<T> t = term_array[count];
        T x = t.getCoefficient();
        fout << " " << x.getReal() << " " << x.getImag() << " " << t.getDegree();
        count++;
    }
    
    fout.close();
}

//evaluate the value of a polynomial for a value of x
template <class T>
T Polynomial<T>::evalPoly(double a)
{
    T result = 0;
    
    //plug x into each term of the polynomial and add to result
    for (int i = 0; i < numTerms; i++)
        result = result + ((pow(a,term_array[i].getDegree()))*term_array[i].getCoefficient());
    
    return result;
}

//sorts an array into descending order
//if more than 10 terms, keeps terms of highest degree
template <class T>
void Polynomial<T>::sort(Term<T> temp_array[], int index)
{
	int count = 0;
	
    //finds highest degree in array and places it at the next highest spot in term_array
    //removes term from temp_array when moved so no duplicates
    while ((count < numTerms) && (count < MAX_SIZE))
    {
        int max_index = 0;
        int max_deg = 0;
        
        for (int k = 0; k < index; k++)
        {
            
            if (temp_array[k].getDegree() > max_deg)
            {
                max_deg = temp_array[k].getDegree();
                max_index = k;
            }
            if (temp_array[k].getDegree() == max_deg)
            {
                if (temp_array[k].getCoefficient() != 0)
                {
                    max_deg = temp_array[k].getDegree();
                    max_index = k;
                }
            }
        }
        
        term_array[count] = temp_array[max_index];
        temp_array[max_index].setDegree(0);
        temp_array[max_index].setCoefficient(0);
        count++;
    }
}

//reads in number of terms and coeffecient and degree for each term of a polynomial (overload >>)
//input format is number of terms followed by coefficient and degree for each term
//incorrect degree will be corrected before proceeding
template <class U>
istream& operator>>(istream& stream, Polynomial<U>& p)
{
    int numTerms = 0;
    Term<U> temp_array[MAX_SIZE];
    bool tryAgain = true;
    bool not_present = true;
    
    //sets each term in the array to 0
    if (p.numTerms != 0)
    {
    	for (int i = 0; i < p.numTerms; i++)
    	{
    		p.term_array[i].setCoefficient(0);
    		p.term_array[i].setDegree(0);
    	}
    }
        
    //gets good input for number of terms to be entered
    while (tryAgain)
    {
        stream >> numTerms;
        
        if (stream.fail())
        {
            cout << "Invalid input - Please enter an integer." << endl;
            stream.clear();
            stream.ignore(1000, '\n');
        }
        else if ((numTerms < 1) || (numTerms > MAX_SIZE))
            cout << "Invalid input - Please enter a value between 1-" << MAX_SIZE << endl;
        else
            tryAgain = false;
    }
    
    //set polynomials number of terms to numTerms
    p.numTerms = numTerms;
    
    //inputs terms into array
    for (int i = 0; i < numTerms; i++)
    {
        Term<U> t;
        stream >> t;
        
        //if 0, decrement numTerms
        if (t.getCoefficient() == 0) 
        	p.numTerms--;
        else
        {
            //searches for duplicate degrees in array, if already existent, add coefficients
            for (int j = 0; j < MAX_SIZE; j++)
            {
                if (temp_array[j].getDegree() == t.getDegree())
                {
                    if (temp_array[j].getCoefficient() != 0)
                    {
                        temp_array[j].setCoefficient(temp_array[j].getCoefficient() + t.getCoefficient());
                        not_present = false;
                    }
                }
            }
            //if not existent, add term to array
            if (not_present)
                temp_array[i] = t;
            else
            {
                not_present = true;
                if (t.getCoefficient() != 0)
                    p.numTerms--;
            }
        }
    }
    
    //sort array
    p.sort(temp_array, numTerms);
    
    return stream;   
}

//output the polynomial with correct sign notation (overload <<)
template <class U>
ostream& operator<<(ostream& stream, Polynomial<U>& p)
{
    if (p.term_array[0].getCoefficient() < 0)
        stream << "-";
    
    bool empty = true;
    
    for (int i = 0; i < p.numTerms; i++)
    {
        Term<U> t = p.term_array[i];
        if (t.getCoefficient() != 0)
            empty = false;
    }
    
    //prints sign and term for each term in polynomial
    //prints 0 id polynomial is only 0
    if (!empty)
    {
        for (int i = 0; i < p.numTerms; i++)
        {   
            if (p.term_array[i].getCoefficient() != 0)
            { 
                stream << p.term_array[i];
                
                if ((i+1) < p.numTerms)
                {
                    if (p.term_array[i+1].getCoefficient() > 0)
                        stream << " + ";
                    else if (p.term_array[i+1].getCoefficient() < 0)
                        stream << " - ";
                    else
                        stream << "";
                }
            }
        }
    }
    else
        stream << "0";
    
    stream << endl;
    return stream;    
}

//adds int and polynomial by making int a polynomial and adding two polynomials
template <class U>
Polynomial<U> operator+(U a, Polynomial<U>& p)
{
    Polynomial<U> temp;
    temp.numTerms = 1;
    temp.term_array[0].setCoefficient(a);
    return (p + temp);
}

//multiplies int and polynomial by making int a polynomial and multiplying two polynomials
template <class U>
Polynomial<U> operator*(U a, Polynomial<U>& p)
{
    Polynomial<U> temp;
    temp.numTerms = 1;
    temp.term_array[0].setCoefficient(a);
    return (p * temp);
}
