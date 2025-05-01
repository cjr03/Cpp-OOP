#ifndef DBIGUINT
#define DBIGUINT

#include <iostream>


// need: a class to represent integers of arbitrary sizes
//       (regular int variables can hold up to 10 decimal digits)

class dbiguint {

  public:

    // CONSTANTS & TYPES
    
    typedef std::size_t size_type;
    typedef std::size_t digit_type;

    // CONSTRUCTORS: default, copy

    // pre: an unsigned integer (default value 0)
    // post: a dbiguint has been created with given initial value
     dbiguint(std::size_t = 0);

    // pre: a string of decimal digits
    // post: a dbiguint has been created using the given digits (rightmost is the least significant digit)
     dbiguint(const std::string &);

    // pre:
    // post: this biguint is a copy of the given biguint
     dbiguint(const dbiguint &);


     // pre:
     // post: returns dynamically allocated memory
    ~dbiguint();
    // CONST MEMBER FUNCTIONS

    // pre:
    // post: returns the digit corresponding to 10^pos (0 if the number is smaller than 10^pos)
    //
    digit_type operator [] (size_type pos) const;

    // pre:
    // post: returns the number of digits in this biguint
    //       not counting leading zeros
    size_type size() const;

    // pre:
    // post: returns 0 if this biguint is the same as given biguint
    //              -1 if smaller
    //                +1 if bigger
    int compare(const dbiguint &) const;

    // pre:
    // post: returns a string of digits of this biguint without leading zeros (least significant digit is the rightmost character)
    //       return "0" if this biguint is 0
     std::string to_string() const;

    // MODIFICATION MEMBER FUNCTIONS
    //
    //
    // pre: none
    // post: this dbiguint is now a copy of source
    void operator =(const dbiguint & source);

    // pre:
    // post: b has been added to this biguint
    void operator +=(const dbiguint & b);

    // pre:
    // post: b has been subtract to this biguint (0 if b is bigger than this biguint)
    void operator -=(const dbiguint & b);

    // pre:
    // post: b has been multipled to this biguint
    void operator *=(const dbiguint & b);

    // pre:
    // post: this dbiguint has been pre/post incremented/decremented (clamped at 0)
    dbiguint operator++();
    dbiguint operator++(int);
    dbiguint operator--();
    dbiguint operator--(int);

    // pre:
    // post: this dbiguint's digits have been shifted p positions to the LEFT; the rightmost p digits are now 0
    dbiguint operator <<(size_type p);

    // pre:
    // post: this biguint's digits have been shifted p positions to the RIGHT; the rightmost p digits have been removed
    dbiguint operator >>(size_type p);

  private:

    // INVARIANTS
    // 1) _d points to a dynamic array of digits of
    //    size _capacity
    //    digit corresponding 10^i is stored in
    //    _d[i]
    // 2) unused digits are replaced by 0
    //
    
    digit_type *_d;
    size_type _capacity;

};

// NONMEMBER FUNCTIONS

std::ostream & operator <<(std::ostream &, const dbiguint &);
std::istream & operator >>(std::istream &, dbiguint &);

dbiguint operator +(const dbiguint &, const dbiguint &);
dbiguint operator -(const dbiguint &, const dbiguint &);
dbiguint operator *(const dbiguint &, const dbiguint &);

bool operator <(const dbiguint &, const dbiguint &);
bool operator <=(const dbiguint &, const dbiguint &);
bool operator ==(const dbiguint &, const dbiguint &);
bool operator !=(const dbiguint &, const dbiguint &);
bool operator >=(const dbiguint &, const dbiguint &);
bool operator >(const dbiguint &, const dbiguint &);

#endif
