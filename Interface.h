//  Name: David Hand
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Assignment 4
//  Description: Header file for Interface
//  Filename: Interface.h
//  Last modified on: 10/25/12

#ifndef _Interface_h
#define _Interface_h

#include <iostream>

const int MAX_CHOICES = 5;
const int MAX_OPERATIONS = 5;
const int MAX_DECISIONS = 2;

int getValidChoice();
//PRE: User wants valid number for menu prompt
//POST: Valid number for menu is returned
//PARAM: None
//RETURN: int - menu choice
int getValidOperation();
//PRE: User wants valid number for second menu prompt
//POST: Valid number for menu is returned
//PARAM: None
//RETURN: int - menu choice
int getValidInt();
//PRE: User wants an integer
//POST: Integer is returned
//PARAM: None
//RETURN: int - data type user wants
bool getValidDecision();
//PRE: User wants valid bool for menu loop
//POST: Valid bool for menu loop is returned
//PARAM: None
//RETURN: bool - loop conditional

class Interface
{
public:
    //using g++ default constructor
    
    void menu();
    //PRE: User would like to perform polynomial operations
    //POST: User has performed all desired polynomial operations
    //PARAM: None
    //RETURN: None
};

#endif
