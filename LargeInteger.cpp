/*
 * File:   LargeInteger.cpp
 * Author: Brandon Long
 * Class:  COMP365
 * Created on January 31, 2018
 */

#include "LargeInteger.h"

using namespace std;

/**
 * Constructor to default large integer to 0
 */
LargeInteger::LargeInteger() {
    num = "0";
}

/**
 * Constructor function with large integer provided
 *
 * @param x - large integer value in string form
 */
LargeInteger::LargeInteger(string x) {
    num = std::move(x);
}

/**
 * Driver function for Addition
 *
 * @param B the number being added
 * @return sum
 */
LargeInteger LargeInteger::Add(LargeInteger B) {
    LargeInteger sum("");
    if (num.size() <= B.num.size())
        sum.num += Add(B.num, num, 0);
    else
        sum.num += Add(num, B.num, 0);
    return sum;
}

/**
 * Recursively add two numbers
 *
 * @param longer - the longer number
 * @param shorter - the shorter number
 * @param carry - difference between 9 and any value greater than 9
 * @return total sum
 */
string LargeInteger::Add(string longer, string shorter, int carry) {
    string x;
    int sum = 0;
    if (longer.length() == 0 && carry == 0)
        return x;
    else if (longer.length() == 0 && carry != 0)
        return to_string(carry);
    if (shorter.length() == 0)
        sum = (int) longer[longer.length() - 1] - 48 + carry;
    else {
        sum = (int) longer[longer.length() - 1] - 48 +
              (int) shorter[shorter.length() - 1] - 48 + carry;
        shorter.erase(shorter.size() - 1);
    }
    if (sum >= 10) {
        carry = 1;
        sum -= 10;
    } else
        carry = 0;
    return Add(longer.erase(longer.size() - 1), shorter, carry) +
           to_string(sum);

}

/**
 * Driver function for Multiplication
 *
 * @param B - the number being multiplied by
 * @return product
 */
LargeInteger LargeInteger::Multiply(LargeInteger B) {
    LargeInteger product = MultiplyOne(product, toString(), B.toString());

    if (product.num[0] == '0')
        product.num = "0";
    return product;
}

/**
 * Recursively call Multiply to, sending it one value in string A at a time to be multiplied by string B,
 * each time adding the product to the total product
 *
 * @param - product current product
 * @param A - string we are iterating through
 * @param B - string we are multiplying by
 * @return total product
 */
LargeInteger LargeInteger::MultiplyOne(LargeInteger product, string A, string B) {
    string prod;
    if (A.length() == 0)
        return product;
    else {
        prod = MultiplyTwo((int) A[A.length() - 1] - 48, B, 0);
        return MultiplyOne(product.Add(prod), A.erase(A.size() - 1), B + "0");
    }

}

/**
 * Recursively multiply number by single digit
 *
 * @param digit - single value doing multiplication
 * @param number - value being multiplied by
 * @param carry - difference between 9 and any value greater than 9
 * @return product
 */
string LargeInteger::MultiplyTwo(int digit, string number, int carry) {
    int product = 0;
    if (number.length() == 0 && carry == 0)
        return "";
    if (number.length() == 0 && carry != 0)
        return to_string(carry);
    else {
        product = digit * ((int) number[number.length() - 1] - 48) + carry;
        if (product >= 10) {
            carry = product / 10;
            product = product % 10;
        } else carry = 0;
        return MultiplyTwo(digit, number.erase(number.size() - 1), carry) +
               to_string(product);
    }
}

/**
 * Multiply LargeInteger by itself n times
 *
 * @param n
 * @return product of arithmetic
 */
LargeInteger LargeInteger::Power(int n) {
    LargeInteger b(toString());
    LargeInteger c(toString());
    if (n == 0) {
        c.num = "1";

    } else if (n > 1) {
        for (int y = 1; y < n; y++) {
            c = b.Multiply(c);
        }
    }
    return c;
}

/**
 * return string value of LargeInteger
 *
 * @return num
 */
string LargeInteger::toString() const {
    return num;
}

