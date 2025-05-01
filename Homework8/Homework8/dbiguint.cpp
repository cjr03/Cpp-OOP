//
//  dbiguint.cpp
//  Homework8
//
//  Created by Cole Roberts on 2/27/25.
//

#include "dbiguint.h"

// pre: an unsigned integer (default value 0)
// post: a dbiguint has been  created with given initial value
dbiguint::dbiguint(std::size_t val) {
    if (val == 0) {
        _capacity = 1;
        _d = new digit_type[_capacity]{0};
    } else {
        _capacity = 0;
        std::size_t temp = val;
        while (temp > 0) {
            temp /= 10;
            ++_capacity;
        }
        _d = new digit_type[_capacity];
        for (size_type i = 0; i < _capacity; ++i) {
            _d[i] = val % 10;
            val /= 10;
        }
    }
}

// pre: a string of decimal digits
// post: a dbiguint has been created using the given digits (rightmost is the least significant digit)
dbiguint::dbiguint(const std::string & str) {
    _capacity = str.size();
    if (_capacity == 0) {
        _capacity = 1;
        _d = new digit_type[_capacity]{0};
        return;
    }
    
    _d = new digit_type[_capacity];
    size_type j = 0;
    for (int i = str.size() - 1; i >= 0; --i, ++j) {
        _d[j] = digit_type(str[i] - '0');
    }
}

// pre:
// post: this biguint is a copy of the given biguint
dbiguint::dbiguint(const dbiguint & d) {
    _capacity = d._capacity;
    _d = new digit_type[_capacity];
    std::copy(d._d, d._d + _capacity, _d);
}


 // pre:
 // post: returns dynamically allocated memory
dbiguint::~dbiguint(){
    delete[] _d;
}
// CONST MEMBER FUNCTIONS

// pre:
// post: returns the digit corresponding to 10^pos (0 if the number is smaller than 10^pos)
//
dbiguint::digit_type dbiguint::operator [] (size_type pos) const {
    return pos < _capacity ? _d[pos] : 0;
}

// pre:
// post: returns the number of digits in this biguint
//       not counting leading zeros
dbiguint::size_type dbiguint::size() const {
    for (size_type i = _capacity; i > 0; --i) {
        if (_d[i-1] != 0) {
            return i;
        }
    }
    return 1;
}

// pre:
// post: returns 0 if this biguint is the same as given biguint
//              -1 if smaller
//                +1 if bigger
int dbiguint::compare(const dbiguint & d) const {
    size_type _d_size = size(), d_size = d.size();
    if (_d_size != d_size){
        return (_d_size > d_size) ? 1 : -1;
    } else {
        for (size_type i = _d_size - 1; i >= 0; --i){
            if (_d[i] != d[i]){
                return (_d[i] > d[i]) ? 1 : -1;
            }
        }
        return 0;
    }
}

// pre:
// post: returns a string of digits of this biguint without leading zeros (least significant digit is the rightmost character)
//       return "0" if this biguint is 0
std::string dbiguint::to_string() const {
    std::string s;
    bool lz = true;
    for (size_type i = _capacity; i > 0; --i) {
        if (lz) {
            if (_d[i-1] == 0) {
                continue;
            }
            lz = false;
        }
        s += static_cast<char>('0' + _d[i-1]);
    }
    return s.empty() ? "0" : s;
}

// MODIFICATION MEMBER FUNCTIONS
//
//
// pre: none
// post: this dbiguint is now a copy of source
void dbiguint::operator =(const dbiguint & source){
    if (this != &source) {
        delete[] _d;
        _capacity = source._capacity;
        _d = new digit_type[_capacity];
        std::copy(source._d, source._d + _capacity, _d);
    }
}

// pre:
// post: b has been added to this biguint
void dbiguint::operator+=(const dbiguint & b) {
    size_type new_c = std::max(size(), b.size()) + 1;
    digit_type* new_d = new digit_type[new_c]();
    std::copy(_d, _d + _capacity, new_d);
    digit_type c = 0;
    for (size_type i = 0; i < new_c; ++i) {
        digit_type s = new_d[i] + b[i] + c;
        new_d[i] = s % 10;
        c = s / 10;
    }
    delete[] _d;
    _d = new_d;
    _capacity = new_c;
}

// pre:
// post: b has been subtract to this biguint (0 if b is bigger than this biguint)
void dbiguint::operator-=(const dbiguint & b) {
    if (compare(b) < 0) {
        *this = dbiguint(0);
        return;
    } else {
        digit_type t = 0;
        for (size_type i = 0; i < _capacity; ++i) {
            digit_type s = b[i] + t;
            if (_d[i] < s) {
                _d[i] += 10 - s;
                t = 1;
            } else {
                _d[i] -= s;
                t = 0;
            }
        }
        while (_capacity > 1 && _d[_capacity-1] == 0) {
            --_capacity;
        }
    }
}

// pre:
// post: b has been multipled to this biguint
void dbiguint::operator*=(const dbiguint & b) {
    size_type new_c = size() + b.size();
    digit_type* r = new digit_type[new_c]();
    for (size_type i = 0; i < size(); ++i) {
        digit_type c = 0;
        for (size_type j = 0; j < b.size() || c; ++j) {
            digit_type p = r[i+j] + _d[i] * b[j] + c;
            r[i+j] = p % 10;
            c = p / 10;
        }
    }
    delete[] _d;
    _d = r;
    _capacity = new_c;
}


// pre:
// post: this dbiguint has been pre/post incremented/decremented (clamped at 0)
dbiguint dbiguint::operator++() {
    *this += dbiguint(1);
    return *this;
}
dbiguint dbiguint::operator++(int){
    dbiguint og = *this;
    ++*this;
    return og;
}
dbiguint dbiguint::operator--() {
    *this -= dbiguint(1);
    return *this;
}
dbiguint dbiguint::operator--(int){
    dbiguint og = *this;
    --*this;
    return og;
}

// pre:
// post: this dbiguint's digits have been shifted p positions to the LEFT; the rightmost p digits are now 0
dbiguint dbiguint::operator<<(size_type p) {
    size_type new_c = _capacity + p;
    digit_type* new_d = new digit_type[new_c]();
    std::copy(_d, _d + _capacity, new_d + p);
    delete[] _d;
    _d = new_d;
    _capacity = new_c;
    return *this;
}

// pre:
// post: this biguint's digits have been shifted p positions to the RIGHT; the rightmost p digits have been removed
dbiguint dbiguint::operator>>(size_type p) {
    if (p >= _capacity) {
        *this = dbiguint(0);
        return *this;
    }
    size_type new_c = _capacity - p;
    digit_type* new_d = new digit_type[new_c];
    std::copy(_d + p, _d + _capacity, new_d);
    delete[] _d;
    _d = new_d;
    _capacity = new_c;
    return *this;
}

// NONMEMBER FUNCTIONS
std::ostream & operator<<(std::ostream & o, const dbiguint & d) {
    return o << d.to_string();
}
std::istream & operator>>(std::istream & i, dbiguint & d) {
    std::string s;
    i >> s;
    d = dbiguint(s);
    return i;
}

dbiguint operator +(const dbiguint & l, const dbiguint & r){
    dbiguint n = l;
    n += r;
    return n;
}
dbiguint operator -(const dbiguint & l, const dbiguint & r){
    dbiguint n = l;
    n -= r;
    return n;
}
dbiguint operator *(const dbiguint & l, const dbiguint & r){
    dbiguint n = l;
    n *= r;
    return n;
}

bool operator <(const dbiguint & l, const dbiguint & r){
    return l.compare(r) == -1;
}
bool operator <=(const dbiguint & l, const dbiguint & r){
    int comp = l.compare(r);
    return comp == -1 || comp == 0;
}
bool operator ==(const dbiguint & l, const dbiguint & r){
    return l.compare(r) == 0;
}
bool operator !=(const dbiguint & l, const dbiguint & r){
    return l.compare(r) != 0;
}
bool operator >=(const dbiguint & l, const dbiguint & r){
    int comp = l.compare(r);
    return comp == 1 || comp == 0;
}
bool operator >(const dbiguint & l, const dbiguint & r){
    return l.compare(r) == 1;
}

