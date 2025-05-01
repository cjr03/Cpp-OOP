#ifndef BIGUINT_H
#define BIGUINT_H
#include <cstdlib>
#include <string>
#include <iostream>
class biguint
{
public:
    // TYPES and CONSTANTS
    typedef std::size_t size_type;
    typedef unsigned int digit_type;
    static const size_type CAPACITY = 100;
    // CONSTRUCTORS
    // pre: none
    // post: creates a biguint with given unsigned integer value (default value = 0)
    biguint(std::size_t = 0);
    // pre: s.size() <= CAPACITY && s consists of decimal digits only
    // post: creates a biguint whose digits are given in a string s
    // rightmost digit of s corresponds to the least significant digit
    biguint (const std::string & s);
    // pre: none
    // post: creates a biguint with the same value as b
    biguint(const biguint & b);
    // CONSTANT FUNCTIONS
    // pre: pos < CAPACITY
    // post: returns the (pos+1)^st digit from the right of this biguint
    digit_type operator [](size_type pos) const;
    // pre: none
    // post: returns the number of digits in this biguint (not counting leading zeros)
    size_type size() const;
    // pre: none
    // post: return 0 if this biguint == n
    // -1 if this biguint < n
    // 1 if this biguint > n
    int compare(const biguint & n) const;
    // MODIFICATION FUNCTIONS
    // SHIFT member functions
    // pre: none
    // post: digits of this biguint has been left shifted by n positions
    // the former n most significant digits are discarded
    // the new n least significiant digits are 0
    void ls (size_type n);
    // pre: none
    // post: digits of this biguint has been right shifted by n positions
    // the former n least significant digits are discarded
    
    // the new n most significant digit are 0
    void rs (size_type n);
    // ARITHMETIC member operators
    // pre: none
    // post: b has been added to this biguint
    // overflow digit will be thrown away, if any
    void operator +=(const biguint &b);
    // pre: none
    // post: if b > this biguint, then this biguint is reset to 0
    // else b is subtracted from this biguint
    void operator -=(const biguint & b);
    // pre: none
    // post: this biguint has been incremented/decremented by 1
    // return value is the new value (pre)
    biguint operator++();
    biguint operator--();
    // pre: none
    // post: this biguint has been incremented/decremented by 1
    // return value is the original value (post)
    biguint operator++(int);
    biguint operator--(int);
    private:
    digit_type _data[CAPACITY];
    // _data[i] corresponds to the (i+1)^st rightmost digit of this biguint (0 if it is not used)
    // _data[0] = least significant (units) digit
    // _data[CAPACITY-1] = most significant digit
    };
    // NON-MEMBER OPERATORS
    // I/O operators
std::ostream & operator <<(std::ostream & os, const biguint & n);
std::istream & operator >>(std::istream & is, biguint & n);
// ARITHMETIC operators
biguint operator + (const biguint & l, const biguint & r);
biguint operator - (const biguint & l, const biguint & r);
// COMPARISON operators
bool operator <(const biguint & l, const biguint & r);
bool operator <=(const biguint & l, const biguint & r);
bool operator ==(const biguint & l, const biguint & r);
bool operator !=(const biguint & l, const biguint & r);
bool operator >=(const biguint & l, const biguint & r);
bool operator >(const biguint & l, const biguint & r);

#endif // BIGUINT_H
