#include <iostream>
#include <string>
#include <cmath>
#include "kenny_yu_RationalNumber.h"
using namespace std;

// (1) Default constructor initializes the numerator, denominator, and greatest common divisor to 1
RationalNumber::RationalNumber()
: numerator(1), denom(1), gcd(1) {};

// (2) 2-arg constructor receives two integers, if denominator is negative or 0, the following statements will not
//     execute. As long as the denominator is > 0, gcd is initialized to int returned by findGCD function, and numerator
//     and denominator are both simplified by dividing by the gcd
RationalNumber::RationalNumber(int numerator, int denom) {
    if (denom <= 0) {
        cout << "INVALID DENOMINATOR. Must be a positive whole integer." << endl;
    } else {
        this->gcd = findGCD(numerator, denom);
        this->numerator = numerator / gcd;
        this->denom = denom / gcd;
    }
    
}
// (3) Euclidean algorithm to find GCD, the recursion ends once the remainder is 0, otherwise, recursive func call, and
//     num will hold the greatest common divisor which will be returned
int RationalNumber::findGCD(int num, int denom) {
        return denom == 0 ? num : findGCD(denom, num % denom);
}
// (4) wholeString is printed if the remainder of numerator and denom is equal to 0, where this string also gives us the
//     simplified version of numerator/denom (whole number). Otherwise, rationalString is printed which gives the
//     standard numerator / denom with the "/" between the two
void RationalNumber::printRational() {
    int newGCD = findGCD(abs(this->numerator), abs(this->denom));
    string rationalString = to_string(this->numerator / newGCD) + "/" + to_string(this->denom / newGCD);
    string wholeString = to_string(this->numerator / this->denom);
    if ((this->numerator % this->denom)  == 0)
        cout << wholeString;
    else
        cout << rationalString;
}
// (5) operator+ overloaded operator adds the hidden this numerator and denom with the right hand object's numerator and
//     denom. If the denom of both objects are the same, add the numerators but keep denom the same
RationalNumber RationalNumber::operator+(const RationalNumber &rhs) const {
    RationalNumber temp;
    if (this->denom == rhs.denom) {
    temp.numerator = this->numerator + rhs.numerator;
        temp.denom = this->denom;
    } else {
// (6) If the denom is different, tempA and tempB store the original denoms of each object respectively. Then, we can
//     multiply the denoms of each object together to get a common denom, and store the value in temp's
//     denom, and the numerator is found by multiplying the quotient of the denom with the original denom stored in temp
//     respectively, with their respective numerator
        int tempA = this->denom, tempB = rhs.denom;
        temp.denom = tempA * tempB;
        temp.numerator = (((temp.denom / tempA) * this->numerator) + (temp.denom / tempB) * rhs.numerator);
    }\
    return temp;
}
RationalNumber RationalNumber::operator-(const RationalNumber &rhs) const {
    RationalNumber temp;
    if (this->denom == rhs.denom) {
    temp.numerator = this->numerator - rhs.numerator;
        temp.denom = this->denom;
    } else {
        int tempA = this->denom, tempB = rhs.denom;
        temp.denom = tempA * tempB;
        temp.numerator = (((temp.denom / tempA) * this->numerator) - (temp.denom / tempB) * rhs.numerator);
    }
    return temp;
}
// (7) operator* overloaded operator simply multiplies both the left object's numerator with the right object's
//     numerator, and their denom, stores these values in temp's member variables and temp is returned by value
RationalNumber RationalNumber::operator*(const RationalNumber &rhs) const {
    RationalNumber temp;
    temp.numerator = this->numerator * rhs.numerator;
    temp.denom = this->denom * rhs.denom;
    return temp;
}
RationalNumber RationalNumber::operator/(const RationalNumber &rhs) const {
    RationalNumber temp;
    temp.numerator = this->numerator * rhs.denom;
    temp.denom = this->denom * rhs.numerator;
    return temp;
}
// (8) operator= overloaded operator initializes this object's gcd, numerator, and denom to rhs's respective member variable values.
const RationalNumber& RationalNumber::operator=(const RationalNumber &rhs) {
    this->gcd = rhs.gcd;
    this->numerator = rhs.numerator;
    this->denom = rhs.denom;
    return *this;
}
// (9) numerator is casted to double for easy comparison within the overloaded operator> function for easy comparison.
//     returns true when left object's double value of numerator/denom is > than rhs's double value of numerator/denom
bool RationalNumber::operator>(const RationalNumber &rhs) const {
    return ((static_cast<double>(this->numerator) / this->denom) > static_cast<double>(rhs.numerator) / rhs.denom);
}
bool RationalNumber::operator<(const RationalNumber &rhs) const {
    return ((static_cast<double>(this->numerator) / this->denom) < static_cast<double>(rhs.numerator) / rhs.denom);
}
bool RationalNumber::operator>=(const RationalNumber &rhs) const {
    return ((static_cast<double>(this->numerator) / this->denom) >= static_cast<double>(rhs.numerator) / rhs.denom);
}
bool RationalNumber::operator<=(const RationalNumber &rhs) const {
    return ((static_cast<double>(this->numerator) / this->denom) <= static_cast<double>(rhs.numerator) / rhs.denom);
}
// (10) numerator is casted to double for easy comparison within the overloaded operator== function for easy comparison.
//     returns true when left object's double value of numerator/denom is equal to rhs's double value of numerator/denom
bool RationalNumber::operator==(const RationalNumber &rhs) const {
    return ((static_cast<double>(this->numerator) / this->denom) == static_cast<double>(rhs.numerator) / rhs.denom);
}
bool RationalNumber::operator!=(const RationalNumber &rhs) const {
    return ((static_cast<double>(this->numerator) / this->denom) != static_cast<double>(rhs.numerator) / rhs.denom);
}
