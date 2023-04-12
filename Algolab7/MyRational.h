#ifndef _MYRATIONAL_H_
#define _MYRATIONAL_H_
#include <iostream>
using namespace std;

class myRational
{
private:
    // �м��� �׻� ���������� ���м��� ǥ���ϸ�, ���� �׻� _den>0 �̴�. 
    long _num; // numerator
    long _den; // denominator

    long gcd(long m, long n); // �ִ�����
    void reduce(); // ���м�
public:
    // Constructor (������)
    myRational (long _num = 0, long _den = 1);
    // Copy constructor (���� ������)
    myRational (const myRational& rat);
    // Accessor functions (������)
    long getNumerator() const;
    long getDenominator() const;
    // Member Functions
    myRational reciprocal() const;
    // Overloaded binary operators
    myRational operator +(const myRational& number) const;
    myRational operator +(int value) const;
    friend myRational operator +(int value, const myRational& number);
    myRational operator -(const myRational& number) const;
    myRational operator -(int value) const;
    friend myRational operator -(int value, const myRational& number);
    myRational operator *(const myRational& number) const;
    myRational operator *(int value) const;
    friend myRational operator *(int value, const myRational& number);
    myRational operator /(const myRational& number) const;
    myRational operator /(int value) const;
    friend myRational operator /(int value, const myRational& number);
    // Overloaded unary operators
    myRational operator ++();
    myRational operator --();
    myRational operator ++(int value);
    myRational operator --(int value);
    myRational operator-();
    // Overloading relational operators
    bool operator ==(const myRational& number) const;
    bool operator !=(const myRational& number) const;
    bool operator >(const myRational& number) const;
    bool operator <(const myRational& number) const;
    bool operator >=(const myRational& number) const;
    bool operator <=(const myRational& number) const;
    // Overloaded assignment operators
    myRational& operator =(const myRational& number);
    myRational& operator =(int value);
    myRational& operator +=(const myRational& number); 
    myRational& operator +=(int value) { return (*this) += myRational(value); };
    myRational& operator -=(const myRational& number);
    myRational& operator -=(int value) { return (*this) -= myRational(value); };
    myRational& operator *=(const myRational& number);
    myRational& operator *=(int value) { return (*this) *= myRational(value); };
    myRational& operator /=(const myRational& number);
    myRational& operator /=(int value) { return (*this) /= myRational(value); };
    // Overloeding Input/Output Operators
    friend ostream& operator <<(ostream& outStream, const myRational& number);
    friend istream& operator >>(istream& inStream, myRational& number);
    void frac_sort();
};
#endif 
