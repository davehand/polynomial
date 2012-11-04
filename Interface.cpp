//  Name: David Hand
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Assignment 4
//  Description: Interface for polynomial operations with user, allows
//               user to enter, output, add, and multiply polynomials
//  Filename: Interface.cpp
//  Last modified on: 10/25/12

#include <iostream>
#include "Interface.h"
#include "Polynomial.cpp"
#include "Complex.h"


void Interface::menu()
{
    //instantiate polynomials of different data types for use by user
    Polynomial<int> p1, p2, p3;
    Polynomial<float> p4, p5, p6;
    Polynomial<double> p7, p8, p9;
    Polynomial<Complex> p10, p11, p12;
    
    //instantiate additional variables for use by user
    int number = 5;
    float number2 = 3.2;
    double number4 = 3.2;
    Complex number3 (2, 0);
    
    int x = 0;
    Complex x1;
    
    //determines when to exit menu
    bool goAgain = true;
    
    //used for user input in navigating menu 
    int choice, operation;
    
    //begins menu loop, menu does not exit until user asks to exit
    while (goAgain)
    {
        //asks user what data type they would like to work with on this iteration
        //Test Driver allows user to test every data type with each requirement
        cout << "Welcome to the Polynomial Machine!  Please choose a data type for your Polynomial: " << endl;
        cout << "1 - int" << endl;
        cout << "2 - float" << endl;
        cout << "3 - double" << endl;
        cout << "4 - Complex" << endl;
        cout << "5 - Run Test Driver Instead (tests all functionality)" << endl;
    
        choice = getValidChoice();
        
        //goes to case corresponding to choice above
        switch (choice)
        {
            //if user chooses integer, prompted to enter 2 int polynomials    
            case 1:
                cout << "Input the first integer term: " << endl;
                cin >> p1;
                
                cout << "Input the second integer term: " << endl;
                cin >> p2;
                
                //user prompted to choose operation to perform on polynomials
                cout << "Select the operation you wish to perform: " << endl;
                cout << "1 - Equality/Replace" << endl;
                cout << "2 - Add" << endl;
                cout << "3 - Multiply" << endl;
                cout << "4 - Evaluate" << endl;
                cout << "5 - Write to File" << endl;
                
                operation = getValidOperation();
                
                //carries out operation selected by user above
                switch (operation)
                {
                    case 1:
                        cout << "Setting polynomial 1 equal to polynomial 2 yields polynomial 1: " << endl;
                        p1 = p2;
                        cout << p1 << endl;
                        break;
                    case 2:
                        cout << "Adding polynomial 1 and polynomial 2 yields: " << endl;
                        p3 = p1 + p2;
                        cout << p3 << endl;
                        break;
                    case 3:
                        cout << "Multiplying polynomial 1 and polynomial 2 yields: " << endl;
                        p3 = p1 * p2;
                        cout << p3 << endl;
                        break;
                    case 4:
                        cout << "Enter a value for evaluation: " << endl;
                        x = getValidInt();
                        cout << "Evaluating polynomial 1 with " << x << " yields: " << endl;
                        cout << p1.evalPoly(x) << endl;
                        break;
                    case 5:
                        cout << "The first polynomial was written to \"output.txt\""<< endl;
                        p1.writeToFile();
                }
                
                break;
            
            //if user chooses float, prompted to enter 2 float polynomials     
            case 2:
                cout << "Input the first float term: " << endl;
                cin >> p4;
                
                cout << "Input the second float term: " << endl;
                cin >> p5;
                
                //user prompted to choose operation to perform on polynomials
                cout << "Select the operation you wish to perform: " << endl;
                cout << "1 - Equality/Replace" << endl;
                cout << "2 - Add" << endl;
                cout << "3 - Multiply" << endl;
                cout << "4 - Evaluate" << endl;
                cout << "5 - Write to File" << endl;
                
                operation = getValidOperation();
                
                //carries out operation selected by user above
                switch (operation)
                {
                    case 1:
                        cout << "Setting polynomial 1 equal to polynomial 2 yields polynomial 1: " << endl;
                        p4 = p5;
                        cout << p4 << endl;
                        break;
                    case 2:
                        cout << "Adding polynomial 1 and polynomial 2 yields: " << endl;
                        p6 = p4 + p5;
                        cout << p6 << endl;
                        break;
                    case 3:
                        cout << "Multiplying polynomial 1 and polynomial 2 yields: " << endl;
                        p6 = p4 * p5;
                        cout << p6 << endl;
                        break;
                    case 4:
                        cout << "Enter a value for evaluation: " << endl;
                        x = getValidInt();
                        cout << "Evaluating polynomial 1 with " << x << " yields: " << endl;
                        cout << p4.evalPoly(x) << endl;
                        break;
                    case 5:
                        cout << "The first polynomial was written to \"output.txt\""<< endl;
                        p4.writeToFile();
                }
                
                break;
            
            //if user chooses double, prompted to enter 2 double polynomials                 
            case 3:
                cout << "Input the first double term: " << endl;
                cin >> p7;
            
                cout << "Input the second double term: " << endl;
                cin >> p8;
                
                //user prompted to choose operation to perform on polynomials
                cout << "Select the operation you wish to perform: " << endl;
                cout << "1 - Equality/Replace" << endl;
                cout << "2 - Add" << endl;
                cout << "3 - Multiply" << endl;
                cout << "4 - Evaluate" << endl;
                cout << "5 - Write to File" << endl;
                
                operation = getValidOperation();
                
                //carries out operation selected by user above
                switch (operation)
                {
                    case 1:
                        cout << "Setting polynomial 1 equal to polynomial 2 yields polynomial 1: " << endl;
                        p7 = p8;
                        cout << p7 << endl;
                        break;
                    case 2:
                        cout << "Adding polynomial 1 and polynomial 2 yields: " << endl;
                        p9 = p7 + p8;
                        cout << p9 << endl;
                        break;
                    case 3:
                        cout << "Multiplying polynomial 1 and polynomial 2 yields: " << endl;
                        p9 = p7 * p8;
                        cout << p9 << endl;
                        break;
                    case 4:
                        cout << "Enter a value for evaluation: " << endl;
                        x = getValidInt();
                        cout << "Evaluating polynomial 1 with " << x << " yields: " << endl;
                        cout << p7.evalPoly(x) << endl;
                        break;
                    case 5:
                        cout << "The first polynomial was written to \"output.txt\""<< endl;
                        p7.writeToFile();
                }
            
                break;  
            
            //if user chooses complex, prompted to enter 2 complex polynomials                 
            case 4:
                cout << "Input the first complex term: " << endl;
                cin >> p10;
                
                cout << "Input the second complex term: " << endl;
                cin >> p11;
                
                //user prompted to choose operation to perform on polynomials
                cout << "Select the operation you wish to perform: " << endl;
                cout << "1 - Equality/Replace" << endl;
                cout << "2 - Add" << endl;
                cout << "3 - Multiply" << endl;
                cout << "4 - Evaluate" << endl;
                cout << "5 - Write to File" << endl;
                
                operation = getValidOperation();
                
                //carries out operation selected by user above
                switch (operation)
                {
                    case 1:
                        cout << "Setting polynomial 1 equal to polynomial 2 yields polynomial 1: " << endl;
                        p10 = p11;
                        cout << p10 << endl;
                        break;
                    case 2:
                        cout << "Adding polynomial 1 and polynomial 2 yields: " << endl;
                        p12 = p10 + p11;
                        cout << p12 << endl;
                        break;
                    case 3:
                        cout << "Multiplying polynomial 1 and polynomial 2 yields: " << endl;
                        p12 = p10 * p11;
                        cout << p12 << endl;
                        break;
                    case 4:
                        cout << "Enter a value for evaluation: " << endl;
                        x = getValidInt();
                        cout << "Evaluating polynomial 1 with " << x << " yields: " << endl;
                        x1 = p10.evalPoly(x);
                        cout << x1 << endl;
                        break;
                    case 5:
                        cout << "The first polynomial was written to \"output.txt\""<< endl;
                        p10.complexWriteToFile();
                }
            
                break; 
            
            //if user chooses Test Driver, Test Driver begins                 
            case 5:
                cout << "This is the Test Driver. It checks all functionality for all data types.  Enjoy!" << endl;
                cout << "For reference, number is " << number << " for ints, " << number2 << " for floats/doubles, ";
                cout << "and " << number3 << " for complex numbers." << endl << endl;
                
                //prompts user to enter integer polynomial
                cout << "Enter Polynomial 1 (int): " << endl;
                cin >> p1;
                
                cout << "Polynomial 1 is:" << endl;
                cout << p1;
                
                //prompts user to input another integer polynomial from a file
                cout << "Enter Polynomial 2 (int) from a file" << endl;
                bool worked = true;
                string inFileName;
                ifstream inStr;
                
                //gets valid filename for input
                do 
                {
                    cout << "Enter name of file to read from: ";
                    cin >> inFileName;
                    
                    inStr.open (inFileName.c_str());
                    if (inStr.fail())
                    {
                        cerr << "Error opening file. Try again." << endl;
                        inStr.clear();
                        inStr.ignore(80, '\n');
                        worked = false;
                    }
                    else 
                        worked = true;
                    
                } while (!worked);
                
                inStr >> p2;
                inStr.close();
                
                cout << "Polynomial 2 is: " << endl;
                cout << p2;
                
                //sets polynomial 1 equal to polynomial 2
                cout << "Setting Polynomial 1 equal to Polynomial 2 makes Polynomial 1: " << endl;
                p1 = p2;
                cout << p1;
                
                //sets polynomial 1 equal to constant
                cout << "Setting Polynomial 1 equal to 4 makes Polynomial 1: " << endl;
                p1 = 4;
                cout << p1;
                
                //re-enter polynomial 1
                cout << "Enter Polynomial 1 (int)" << endl;
                cin >> p1;
                
                cout << "Polynomial 1 is now:" << endl;
                cout << p1;
                
                //test overloaded plus operator 
                cout << "Adding Polynomial 1 and Polynomial 2 gives:" << endl;
                p3 = p1 + p2;
                cout << p3 << endl;
                
                cout << "Adding Polynomial 1 and number gives:" << endl;
                p3 = p1 + number;
                cout << p3 << endl;
                
                cout << "Adding number and Polynomial 2 gives:" << endl;
                p3 = number + p2;
                cout << p3 << endl;
                
                //test overloaded multiplication operator
                cout << "Multiplying Polynomial 1 and Polynomial 2 gives:" << endl;
                p3 = p1 * p2;
                cout << p3 << endl;
                
                cout << "Multiplying Polynomial 1 and number gives:" << endl;
                p3 = p1 * number;
                cout << p3 << endl;
                
                cout << "Multiplying number and Polynomial 2 gives:" << endl;
                p3 = number * p2;
                cout << p3 << endl;
                
                //test polynomial evaluation
                cout << "Enter a value for x" << endl;
                cin >> x;
                
                cout << "Evaluating Polynomial 1 with " << x << " gives " << p1.evalPoly (x) << endl;
                
                //test writing to a file 
                cout << "Writing Polynomial 3 to a file." << endl << endl;

                p3.writeToFile();
                
                //------------------------------------------------------------------------------------------------------------------
                //------------------------------------------------------------------------------------------------------------------
                //------------------------------------------------------------------------------------------------------------------
                //------------------------------------------------------------------------------------------------------------------
                //------------------------------------------------------------------------------------------------------------------
                
                //prompts user to enter float polynomial
                cout << "Enter Polynomial 4 (float): " << endl;
                cin >> p4;
                
                cout << "Polynomial 4 is:" << endl;
                cout << p4;
                
                //prompts user to enter another float polynomial from a file
                cout << "Enter Polynomial 5 (float) from a file" << endl;
                
                //gets valid filename for input
                do 
                {
                    cout << "Enter name of file to read from: ";
                    cin >> inFileName;
                    
                    inStr.open (inFileName.c_str());
                    if (inStr.fail())
                    {
                        cerr << "Error opening file. Try again." << endl;
                        inStr.clear();
                        inStr.ignore(80, '\n');
                        worked = false;
                    }
                    else 
                        worked = true;
                    
                } while (!worked);
                
                inStr >> p5;
                inStr.close();
                
                cout << "Polynomial 5 is: " << endl;
                cout << p5;
                
                //sets polynomial 4 equal to polynomial 5
                cout << "Setting Polynomial 4 equal to Polynomial 5 makes Polynomial 4: " << endl;
                p4 = p5;
                cout << p4;
                
                //sets polynomial 4 equal to constant
                cout << "Setting Polynomial 4 equal to 3.3 makes Polynomial 4: " << endl;
                p4 = 3.3;
                cout << p4;
                
                //re-enter polynomial 4
                cout << "Enter Polynomial 4 (float)" << endl;
                cin >> p4;
                
                cout << "Polynomial 4 is now:" << endl;
                cout << p4;
                
                //test overloaded plus operator 
                cout << "Adding Polynomial 4 and Polynomial 5 gives:" << endl;
                p6 = p4 + p5;
                cout << p6 << endl;
                
                cout << "Adding Polynomial 4 and number gives:" << endl;
                p6 = p4 + number2;
                cout << p6 << endl;
                
                cout << "Adding number and Polynomial 5 gives:" << endl;
                p6 = number2 + p5;
                cout << p6 << endl;
                
                //test overloaded multiplication operator
                cout << "Multiplying Polynomial 4 and Polynomial 5 gives:" << endl;
                p6 = p4 * p5;
                cout << p6 << endl;
                
                cout << "Multiplying Polynomial 4 and number gives:" << endl;
                p6 = p4 * number2;
                cout << p6 << endl;
                
                cout << "Multiplying number and Polynomial 5 gives:" << endl;
                p6 = number2 * p5;
                cout << p6 << endl;
                
                //test polynomial evaluation
                cout << "Enter a value for x" << endl;
                cin >> x;
                
                cout << "Evaluating Polynomial 4 with " << x << " gives " << p4.evalPoly (x) << endl;
                
                //test writing to a file 
                cout << "Writing Polynomial 6 to a file." << endl << endl;

                p6.writeToFile();
                
                //------------------------------------------------------------------------------------------------------------------
                //------------------------------------------------------------------------------------------------------------------
                //------------------------------------------------------------------------------------------------------------------
                //------------------------------------------------------------------------------------------------------------------
                //------------------------------------------------------------------------------------------------------------------

                //prompts user to enter double polynomial
                cout << "Enter Polynomial 7 (double): " << endl;
                cin >> p7;
                
                cout << "Polynomial 7 is:" << endl;
                cout << p7;
                
                //prompts user to enter another double polynomial from a file
                cout << "Enter Polynomial 8 (double) from a file" << endl;
                
                //gets valid filename for input
                do 
                {
                    cout << "Enter name of file to read from: ";
                    cin >> inFileName;
                    
                    inStr.open (inFileName.c_str());
                    if (inStr.fail())
                    {
                        cerr << "Error opening file. Try again." << endl;
                        inStr.clear();
                        inStr.ignore(80, '\n');
                        worked = false;
                    }
                    else 
                        worked = true;
                    
                } while (!worked);
                
                inStr >> p8;
                inStr.close();
                
                cout << "Polynomial 8 is: " << endl;
                cout << p8;
                
                //sets polynomial 7 equal to polynomial 8
                cout << "Setting Polynomial 7 equal to Polynomial 8 makes Polynomial 7: " << endl;
                p7 = p8;
                cout << p7;
                
                //sets polynomial 7 equal to constant
                cout << "Setting Polynomial 7 equal to 6.7 makes Polynomial 7: " << endl;
                p7 = 6.7;
                cout << p7;
                
                //re-enter polynomial 7
                cout << "Enter Polynomial 7 (double)" << endl;
                cin >> p7;
                
                cout << "Polynomial 7 is now:" << endl;
                cout << p7;
                
                //test overloaded plus operator 
                cout << "Adding Polynomial 7 and Polynomial 8 gives:" << endl;
                p9 = p7 + p8;
                cout << p9 << endl;
                
                cout << "Adding Polynomial 7 and number gives:" << endl;
                p9 = p7 + number4;
                cout << p9 << endl;
                
                cout << "Adding number and Polynomial 8 gives:" << endl;
                p9 = number4 + p8;
                cout << p9 << endl;
                
                //test overloaded multiplication operator
                cout << "Multiplying Polynomial 7 and Polynomial 8 gives:" << endl;
                p9 = p7 * p8;
                cout << p9 << endl;
                
                cout << "Multiplying Polynomial 7 and number gives:" << endl;
                p9 = p7 * number4;
                cout << p9 << endl;
                
                cout << "Multiplying number and Polynomial 8 gives:" << endl;
                p9 = number4 * p8;
                cout << p9 << endl;
                
                //test polynomial evaluation
                cout << "Enter a value for x" << endl;
                cin >> x;
                
                cout << "Evaluating Polynomial 7 with " << x << " gives " << p4.evalPoly (x) << endl;
                
                //test writing to a file 
                cout << "Writing Polynomial 9 to a file." << endl << endl;
                
                p9.writeToFile();
                
                //------------------------------------------------------------------------------------------------------------------
                //------------------------------------------------------------------------------------------------------------------
                //------------------------------------------------------------------------------------------------------------------
                //------------------------------------------------------------------------------------------------------------------
                //------------------------------------------------------------------------------------------------------------------                

                //prompts user to enter complex polynomial
                cout << "Enter Polynomial 10 (complex): " << endl;
                cin >> p10;
                
                cout << "Polynomial 10 is:" << endl;
                cout << p10;
                
                //prompts user to enter another complex polynomial from a file
                cout << "Enter Polynomial 11 (complex) from a file" << endl;
                
                //gets valid filename for input
                do 
                {
                    cout << "Enter name of file to read from: ";
                    cin >> inFileName;
                    
                    inStr.open (inFileName.c_str());
                    if (inStr.fail())
                    {
                        cerr << "Error opening file. Try again." << endl;
                        inStr.clear();
                        inStr.ignore(80, '\n');
                        worked = false;
                    }
                    else 
                        worked = true;
                    
                } while (!worked);
                
                inStr >> p11;
                inStr.close();
                
                cout << "Polynomial 11 is: " << endl;
                cout << p11;
                
                //sets polynomial 10 equal to polynomial 11
                cout << "Setting Polynomial 10 equal to Polynomial 11 makes Polynomial 10: " << endl;
                p10 = p11;
                cout << p10;
                
                //sets polynomial 10 equal to constant
                cout << "Setting Polynomial 10 equal to (4 + 3i) makes Polynomial 10: " << endl;
                p10 = Complex(4,3);
                cout << p10;
                
                //re-enter polynomial 10
                cout << "Enter Polynomial 10 (complex)" << endl;
                cin >> p10;
                
                cout << "Polynomial 10 is now:" << endl;
                cout << p10;
                
                //test overloaded plus operator 
                cout << "Adding Polynomial 10 and Polynomial 11 gives:" << endl;
                p12 = p10 + p11;
                cout << p12 << endl;
                
                cout << "Adding Polynomial 10 and number gives:" << endl;
                p12 = p10 + number3;
                cout << p12 << endl;
                
                cout << "Adding number and Polynomial 11 gives:" << endl;
                p12 = number3 + p11;
                cout << p12 << endl;
                
                //test overloaded multiplication operator
                cout << "Multiplying Polynomial 10 and Polynomial 11 gives:" << endl;
                p12 = p10 * p11;
                cout << p12 << endl;
                
                cout << "Multiplying Polynomial 10 and number gives:" << endl;
                p12 = p10 * number3;
                cout << p12 << endl;
                
                cout << "Multiplying number and Polynomial 11 gives:" << endl;
                p12 = number3 * p11;
                cout << p12 << endl;
                
                //test polynomial evaluation
                cout << "Enter a value for x" << endl;
                cin >> x;
                x1 = p10.evalPoly(x);
                
                cout << "Evaluating Polynomial 10 with " << x << " gives " << x1 << endl;
                
                //test writing to a file 
                cout << "Writing Polynomial 12 to a file." << endl << endl;

                p12.complexWriteToFile();
                
                break;
        }
        
        //asks user if they would like to perform any other operations
        //sets goAgain accordingly
        cout << "Would you like to perform another operation: " << endl;
        cout << "1 - Yes" << endl;
        cout << "2 - No" << endl;
        goAgain = getValidDecision();
        cout << endl;
    }
    
    //once user is done, outputs thank you and returns to Driver to end program
    cout << endl << "Thanks for using the Polynomial Machine!" << endl << endl;
    
    return;
}

//gets valid choice for first menu prompt
int getValidChoice()
{
    bool tryAgain = true;
    int x = 0;
    
    while (tryAgain)
    {
        cin >> x;
        
        //ensures valid number is read in
        if (cin.fail())
        {
            cout << "Invalid input - Please enter an integer: " << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if ((x < 1) || (x > MAX_CHOICES))
            cout << "Invalid input - Number must be between 1 and " << MAX_CHOICES << ": " << endl;
        else
            tryAgain = false;
    }
    
    return x;
}

//gets valid operation for second menu prompt
int getValidOperation()
{
    bool tryAgain = true;
    int x = 0;
    
    while (tryAgain)
    {
        cin >> x;
        
        //ensures valid number is read in
        if (cin.fail())
        {
            cout << "Invalid input - Please enter an integer: " << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if ((x < 1) || (x > MAX_OPERATIONS))
            cout << "Invalid input - Number must be between 1 and " << MAX_OPERATIONS << ": " << endl;
        else
            tryAgain = false;
    }
    
    return x;
}

//gets valid int for evaluate operations
int getValidInt()
{
    bool tryAgain = true;
    int x = 0;
    
    while (tryAgain)
    {
        cin >> x;
        
        //ensures valid number is read in
        if (cin.fail())
        {
            cout << "Invalid input - Please enter an integer: " << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else
            tryAgain = false;
    }
    
    return x;
}

//gets valid bool for when prompting user if they would like to perform additional operations
bool getValidDecision()
{
    bool tryAgain = true;
    int x = 0;
    
    while (tryAgain)
    {
        cin >> x;
        
        //ensures valid number is read in
        if (cin.fail())
        {
            cout << "Invalid input - Please enter an integer: " << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if ((x < 1) || (x > MAX_DECISIONS))
            cout << "Invalid input - Number must be between 1 and " << MAX_DECISIONS << ": " << endl;
        else
            tryAgain = false;
    }
    
    //converts number to bool
    if (x == 1)
        return true;
    else
        return false;
}
