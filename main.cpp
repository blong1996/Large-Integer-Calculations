/*
 * File:   main.cpp
 * Author: Brandon Long
 * Class:  COMP365
 * Created on January 31, 2018
 */
#include "LargeInteger.h"
using namespace std;

bool is_digits(const std::string &str)
{
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

int main() {

    bool good_input = false;
    string a, b;
    cout<<"Please enter two large integer values:"<<endl;

    // Input validation
    while (!good_input) {
        cin >> a;
        cin >> b;
        if (is_digits(a) && is_digits(b))
            good_input = true;
        else
            cout<<"\nInvalid, input. Please enter two large integer values:"<<endl;

    }
    // Create Large Ints and do arithmetic
    LargeInteger A(a);
    LargeInteger B(b);
    LargeInteger C = B.Add(A);
    LargeInteger D = B.Multiply(A);
    cout<<"\nThe sum of these two values is:\n"<<endl;
    C.Output();
    cout<<"\nThe product of these two values is:\n"<<endl;
    D.Output();

    return 0;
}