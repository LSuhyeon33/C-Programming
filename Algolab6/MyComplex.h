#ifndef _MYCOMPLEX_H_
#define _MYCOMPLEX_H_
#include <iostream>
using namespace std;
class myComplex {
public:
    // Constructor (������)
    myComplex(int real = 0, int imag = 0);
    // Copy constructor (���� ������)
    myComplex(const myComplex& number);
    // Accessor functions (������)
    int getRealPart() const;
    int getImaginaryPart() const;
    // Mutator functions (������)
    void setRealPart(int real);
    void setImaginaryPart(int imag);
    void set(int real, int imag);
    // Overloaded binary operators
    myComplex operator +(const myComplex& number) const;
    myComplex operator +(int value) const;
    friend myComplex operator +(int value, const myComplex& number);
    myComplex operator -(const myComplex& number) const;
    myComplex operator -(int value) const;
    friend myComplex operator -(int value, const myComplex& number);
    myComplex operator *(const myComplex& number) const;
    myComplex operator *(int value) const;
    friend myComplex operator *(int value, const myComplex& number);
    // Overloaded assignment operators
    myComplex& operator =(const myComplex& number);
    myComplex& operator =(int value);
    myComplex& operator +=(const myComplex& number) { realPart += number.realPart; imaginaryPart += number.imaginaryPart; return *this; };
    myComplex& operator +=(int value) { return (*this) += myComplex(value); };
    myComplex& operator -=(const myComplex& number) { realPart -= number.realPart; imaginaryPart -= number.imaginaryPart; return *this; };
    myComplex& operator -=(int value) { return (*this) -= myComplex(value); };
    myComplex& operator *=(const myComplex& number);
    myComplex& operator *=(int value) { return (*this) *= myComplex(value); };
    // Overloading relational operators
    bool operator ==(const myComplex& number) const;
    bool operator !=(const myComplex& number) const;
    bool operator >(const myComplex& number) const;
    bool operator <(const myComplex& number) const;
    bool operator >=(const myComplex& number) const;
    bool operator <=(const myComplex& number) const;
    // Overloaded unary operators
    myComplex operator -();
    myComplex operator ~();
    myComplex operator ++();
    myComplex operator --();
    myComplex operator ++(int value);
    myComplex operator --(int value);
    // Overloeding Input/Output Operators
    friend ostream& operator <<(ostream& outStream, const myComplex& number);
    friend istream& operator >>(istream& inStream, myComplex& number);
private:
    int realPart;
    int imaginaryPart;
    int norm() const;
};
#endif