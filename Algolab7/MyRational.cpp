#include "MyRational.h"

// Constructor
myRational::myRational(long num, long den)
{
    _num = num;
    _den = den;

    this->reduce();
}
// Copy constructor
myRational::myRational(const myRational& rat)
{
    _num = rat._num;
    _den = rat._den;

    this->reduce();
}
// Accessor functions
long myRational::getNumerator() const
{
    return _num;
}
long myRational::getDenominator() const
{
    return _den;
}
// Member Functions
myRational myRational::reciprocal() const
{
    long new_num = _den;
    long new_den = _num;
    return myRational(new_num, new_den);
}
// Overloaded binary operators
myRational myRational::operator +(const myRational& number) const
{
    long new_den = _den * number._den;
    long new_num = _num * number._den + number._num * _den;
    return myRational(new_num, new_den);
}
myRational myRational::operator +(int value) const
{
    return myRational(value) + (*this);
}
myRational operator +(int value, const myRational& number)
{
    return myRational(value) + number;
}
myRational myRational::operator -(const myRational& number) const
{
    long new_den = _den * number._den;
    long new_num = _num * number._den - number._num * _den;
    return myRational(new_num, new_den);
}
myRational myRational::operator -(int value) const
{
    return (*this) - myRational(value);
}
myRational operator -(int value, const myRational& number)
{
    return myRational(value) - number;
}
myRational myRational::operator *(const myRational& number) const
{
    long new_den = _den * number._den;
    long new_num = _num * number._num;
    return myRational(new_num, new_den);
}
myRational myRational::operator *(int value) const
{
    return (*this) * myRational(value);
}
myRational operator *(int value, const myRational& number)
{
    return myRational(value) * number;
}
myRational myRational::operator /(const myRational& number) const
{
    long new_den = _den * number._num;
    long new_num = _num * number._den;
    return myRational(new_num, new_den);
}
myRational myRational::operator /(int value) const
{
    return (*this) / myRational(value);
}
myRational operator /(int value, const myRational& number)
{
    return myRational(value) / number;
}
// Overloaded unary operators
myRational myRational::operator ++()
{
    _num += _den; 
    return *this;
}
myRational myRational::operator --()
{
    _num -= _den;
    return *this;
}
myRational myRational::operator ++(int value)
{
    myRational t(*this);
    operator++();
    return t;
}
myRational myRational::operator --(int value)
{
    myRational t(*this);
    operator--();
    return t;
}
myRational myRational::operator -()
{
    _num *= -1;
    return *this;
}
// Overloading relational operators
bool myRational::operator ==(const myRational& number) const
{
    return (_num == number._num) &&
        (_den == number._den);
}
bool myRational::operator !=(const myRational& number) const
{
    return (_num != number._num) || (_den != number._den);
}
bool myRational::operator >(const myRational& number) const
{
    return _num * number._den > number._num * _den;
}
bool myRational::operator <(const myRational& number) const
{
    return _num * number._den < number._num* _den;
}
bool myRational::operator >=(const myRational& number) const
{
    return _num * number._den >= number._num * _den;
}
bool myRational::operator <=(const myRational& number) const
{
    return _num * number._den <= number._num * _den;
}
// Overloaded assignment operators
myRational& myRational::operator =(const myRational& number)
{
    this->_num = number._num;
    this->_den = number._den;
    this->reduce();
    return * this;
}
myRational& myRational::operator =(int value)
{
    _num = value;
    _den = 1;
    return *this;
}
myRational& myRational::operator +=(const myRational& number)
{
    long temp;
    temp = _den;
    _den *= number._den; 
    _num = _num * number._den + number._num * temp;
    this->reduce();
    return *this;
}
myRational& myRational::operator -=(const myRational& number)
{
    long temp;
    temp = _den;
    _den *= number._den;
    _num = _num * number._den - number._num * temp;
    this->reduce();
    return *this;
}
myRational& myRational::operator *=(const myRational& number)
{
    _den *= number._den;
    _num *= number._num;
    this->reduce();
    return *this;
}
myRational& myRational::operator /=(const myRational& number)
{
    _den *= number._num;
    _num *= number._den;
    this->reduce();
    return *this;
}
// Overloeding Input/Output Operators
ostream& operator <<(ostream& outStream, const myRational& r)
{
    if (r._num == 0)
        outStream << 0;
    else if (r._den == 1)
        outStream << r._num;
    else
        outStream << r._num << "/" << r._den ;

    return outStream;
}
istream& operator >>(istream& inStream, myRational& r)
{
    inStream >> r._num >> r._den;
    if (r._den == 0)
    {
        r._num = 0;
        r._den = 1;
    }
    r.reduce();
    return inStream;
}
long myRational::gcd(long m, long n)
{
    if (m == n)
        return n;
    else if (m < n)
        return gcd(m, n - m);
    else
        return gcd(m - n, n);
}
void myRational::reduce()
{
    if (_num == 0 || _den == 0)
    {
        _num = 0;
        _den = 1;
        return;
    }
    if (_den < 0)
    {
        _den *= -1;
        _num *= -1;
    }
    if (_num == 1)
        return;
    int sgn = (_num < 0 ? -1 : 1);
    long g = gcd(sgn * _num, _den);
    _num /= g;
    _den /= g;
}
void myRational::frac_sort() 
{

}
