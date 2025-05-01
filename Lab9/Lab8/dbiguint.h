#ifndef DYNAMIC_BIGUINT_H
#define DYNAMIC_BIGUINT_H
#include <cstdlib>
#include <string>
class dbiguint
{
public:
// TYPES and CONSTANTS
typedef std::size_t size_type;
typedef unsigned int digit_type;
static const size_type DEFAULT_CAPACITY = 10;
// CONSTRUCTORS & DESTRUCTOR
// pre: none
// post: creates a dbiguint with inital value n (default value = 0) and initial capacity c (default value DEFAULT_CAPACITY)
dbiguint(std::size_t n = 0, size_type c = DEFAULT_CAPACITY);
// pre: s consists of decimal digits only
// post: creates a dbiguint whose digits are given in a string s
// rightmost digit of s corresponds to the least significant digit
// the capacity is the length of s
dbiguint (const std::string & s);
// pre: none
// post: creates a dbiguint with the same value as b
dbiguint(const dbiguint & b);
// pre: none
// post: returns dynamically allocated memory to the heap
~dbiguint();
// CONSTANT FUNCTIONS
// pre: none
// post: returns the (pos+1)^st digit from the right of this dbiguint (most digits are 0)
digit_type operator [](size_type pos) const;
// pre: none
// post: returns the number of digits in this dbiguint (not counting leading zeros)
size_type size() const;
// pre: none
// post: return 0 if this dbiguint == n
// -1 if this dbiguint < n
// 1 if this dbiguint > n
int compare(const dbiguint & n) const;
// MODIFICATION FUNCTIONS
// pre: none
// post: this dbiguint has been made a copy of source; old dynamically allocated memory has been returned to the heap
void operator = (const dbiguint & source);
// pre: none
// post: digits of this dbiguint has been left shifted by n positions
// the new n least significiant digits are 0
void ls (size_type n);
// pre: none
// post: digits of this dbiguint has been right shifted by n positions; the n least significant digits are discarded
void rs (size_type n);
// pre: none
// post: a new dynamically allocated array with new_capacity digits has been allocated;
// the digits have been copied to the new array
// the old dynamic array has been returned to the heap
// if new_capacity < size(), nothing happens
void reserve(size_type new_capacity);
// ARITHMETIC member operators
// pre: none
// post: b has been added to this dbiguint
void operator +=(const dbiguint &b);
// pre: none
// post: if b > this dbiguint, then this dbiguint is reset to 0
// else b is subtracted from this dbiguint
void operator -=(const dbiguint & b);
// pre: d represents a decimal digit
// post: this dbiguint has been multiplied by d
void operator *= (digit_type d);
// pre: none
// post: this dbiguint has been multiplied by b
void operator *= (const dbiguint & b);
// pre: b != 0
// post: this dbiguint has been divided by b; the result is rounded down to the nearest integer
void operator /= (const dbiguint & b);
// pre: b != 0
// post: this dbiguint has been modded by b;
// the new value is the remainder when dividing the original value by b
void operator %= (const dbiguint & b);
// pre: none
// post: this dbiguint has been incremented/decremented by 1 (but capped below at 0)
// return value is the new value (pre)
dbiguint operator++();
dbiguint operator--();
// pre: none
// post: this dbiguint has been incremented/decremented by 1 (but capped below at 0)
// return value is the original value (post)
dbiguint operator++(int);
dbiguint operator--(int);
std::string to_string() const;
private:
digit_type * _data;
size_type _capacity;
// _data[i] corresponds to the (i+1)^st rightmost digit of this dbiguint (0 if it is not used)
// _data[0] = least significant (units) digit
// _capacity = the current size of the dynamically allocated array _data points to
};
// NON-MEMBER OPERATORS
// I/O operators
std::ostream & operator <<(std::ostream & os, const dbiguint & d);
std::istream & operator >>(std::istream & is, dbiguint & d);
// ARITHMETIC operators
dbiguint operator + (const dbiguint &, const dbiguint &);
dbiguint operator - (const dbiguint &, const dbiguint &);
dbiguint operator * (const dbiguint &, const dbiguint &);
dbiguint operator / (const dbiguint &, const dbiguint &);
dbiguint operator % (const dbiguint &, const dbiguint &);
// COMPARISON operators
bool operator <(const dbiguint &, const dbiguint &);
bool operator <=(const dbiguint &, const dbiguint &);
bool operator ==(const dbiguint &, const dbiguint &);
bool operator !=(const dbiguint &, const dbiguint &);
bool operator >=(const dbiguint &, const dbiguint &);
bool operator >(const dbiguint &, const dbiguint &);
// SHIFT operators
dbiguint operator << (const dbiguint &, unsigned int);
dbiguint operator >> (const dbiguint &, unsigned int);
#endif // DYNAMIC_BIGUI
