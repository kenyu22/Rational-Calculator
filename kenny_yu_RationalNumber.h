#ifndef KENNY_YU_RATIONALNUMBER_H
#define KENNY_YU_RATIONALNUMBER_H
class RationalNumber {
public:
    RationalNumber();
    RationalNumber(int, int);
    int findGCD(int, int);
    void printRational();
    
    RationalNumber operator+(const RationalNumber &rhs) const;
    RationalNumber operator-(const RationalNumber &rhs) const;
    RationalNumber operator*(const RationalNumber &rhs) const;
    RationalNumber operator/(const RationalNumber &rhs) const;
    const RationalNumber& operator=(const RationalNumber &rhs);
    
    bool operator>(const RationalNumber &rhs) const;
    bool operator<(const RationalNumber &rhs) const;
    bool operator>=(const RationalNumber &rhs) const;
    bool operator<=(const RationalNumber &rhs) const;
    bool operator==(const RationalNumber &rhs) const;
    bool operator!=(const RationalNumber &rhs) const;
    
private:
    int numerator;
    int denom;
    int gcd;
};

#endif /* kenny_yu_RationalNumber_h */
