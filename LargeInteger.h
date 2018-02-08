#include <cstdint>
#include "iostream"

using namespace std;


/*
 * File:   LargeInteger.h
 * Author: Brandon Long
 * Class:  COMP365
 * Created on January 31, 2018
 */

class LargeInteger {

private:
    string num;

    string Add(string longer, string shorter, int carry); // Recursive Add function
    LargeInteger MultiplyOne(LargeInteger product, string A, string B); // Recursive Multiplication function part one
    string MultiplyTwo(int digit, string number, int carry); // Recursive Multiplication function part two

public:

    LargeInteger(); // Default constructor
    LargeInteger(string y); // Constructor
    LargeInteger Add(LargeInteger B); // Add Driver function
    LargeInteger Multiply(LargeInteger B); // Multiply Driver function
    LargeInteger Power(int n); // return LargeInteger to the n power
    string toString() const; // Return LargeInteger as string

};