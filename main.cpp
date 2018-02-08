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

    LargeInteger a("1234567891234567890");
    LargeInteger b=a.Power(10);
    cout << b.toString() << endl;

    return 0;
}