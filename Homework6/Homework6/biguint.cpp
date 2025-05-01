//
//  biguint.cpp
//  Homework6
//
//  Created by Cole Roberts on 2/13/25.
//

#include "biguint.h"
//#include <string>
#include <cmath>


// pre: none
// post: creates a biguint with given unsigned integer value (default value = 0)

biguint::biguint(std::size_t n){
    for(size_t i = 0; i < CAPACITY; ++i){
        if(n > 0){
            _d[i] = digit_type(n % 10);
            n /= 10;
        } else {
            _d[i] = digit_type(0);
        }
    }
}


// pre: s contains decimal digits only
// post: creates a biguint whose digits are given in a string s
//       rightmost digit of s corresponds to the least significant digit
//       if there are fewer than CAPACITY digits in s, 0 will be used to fill the rest
//       if there are more than CAPACITY digits in s, only the RIGHTMOST digits will be used
biguint::biguint (const std::string & s) {
    for (std::size_t d = 0, end = s.size() - 1; d < CAPACITY; ++d, --end) {
        if (end >= 0) {
            _d[d] = digit_type(s[end] - '0');
        } else {
            _d[d] = digit_type(0);
        }
    }
}

// pre: none
// post: creates a biguint with the same value as b
biguint::biguint(const biguint & b){
    for(int i = 0; i < CAPACITY; ++i){
        _d[i] = b[i];
    }
    return;
}

// CONSTANT FUNCTIONS
// pre:
// post: returns the digit corresponding to 10^(pos), or 0 if pos >= CAPACITY
biguint::digit_type biguint::operator [](size_type pos) const {
    if(pos >= CAPACITY){
        return digit_type(0);
    } else {
        return _d[pos];
    }
}

// pre: none
// post: returns the number of digits in this biguint (not counting leading zeros)
biguint::size_type biguint::size() const {
    biguint::size_type size = 0;
    for(auto const & d : _d){
        if(d != 0){
            ++size;
        }
    }
    return size;
}

// pre: none
// post: return 0 if this biguint == n
//             -1 if this biguint < n
//              1 if this biguint > n
int biguint::compare(const biguint & n) const {
    for(int i = CAPACITY - 1; i >= 0; --i){
        if(_d[i] != n[i]){
            if(_d[i] < n[i]){
                return -1;
            } else {
                return 1;
            }
        }
    }
    return 0;
}

// MODIFICATION FUNCTIONS
// SHIFT member functions

// pre: none
// post: digits of this biguint has been left shifted by n positions
//       the former n most significant digits are discarded
//       the new n least significiant digits are 0
void biguint::operator << (size_type n){
    for(size_t i = CAPACITY - 1; i >= n; --i){
        _d[i] = _d[i-n];
    }
    for(size_t i = 0; i < n; ++i){
        _d[i] = digit_type(0);
    }
    return;
}

// pre: none
// post: digits of this biguint has been right shifted by n positions
//       the former n least significant digits are discarded
//       the new n most significant digit are 0
void biguint::operator >> (size_type n){
    for(size_t i = 0; i < CAPACITY - n; ++i){
        _d[i] = _d[i + n];
    }
    for(size_t i = CAPACITY - n; i < CAPACITY; ++i){
        _d[i] = digit_type(0);
    }
    return;
}

// ARITHMETIC member operators

// pre: none
// post: b has been added to this biguint
//       overflow digit will be thrown away, if any
void biguint::operator +=(const biguint &b){
    int remainder = 0;
    for(size_t i = 0; i < CAPACITY; ++i){
        int start = _d[i] + b[i] + remainder;
        if(start > 9){
            remainder = start / 10;
            start = start % 10;
        } else {
            remainder = 0;
        }
        _d[i] = start;
    }
    return;
}

// pre: none
// post: if b > this biguint, then this biguint is reset to 0
//       else b is subtracted from this biguint
void biguint::operator -=(const biguint & b){
    if(compare(b) == -1){
        for(size_t i = 0; i < CAPACITY; ++i){
            _d[i] = digit_type(0);
        }
    } else {
        int borrow = 0;
        for(size_t i = 0; i < CAPACITY; ++i){
            int sub = _d[i] - b[i] - borrow;
            if(sub < 0){
                sub += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            _d[i] = digit_type(sub);
        }
    }
}

// pre: none
// post: this biguint has been incremented/decremented by 1
//       return value is the new value (pre)
biguint biguint::operator++(){
    int counter = 0;
    while(_d[counter] == 9 && counter < CAPACITY){
        _d[counter] = 0;
        ++counter;
    }
    if (counter < CAPACITY){
        _d[counter] += 1;
    }
    return *this;
}
biguint biguint::operator--(){
    int counter = 0;
    while(counter < CAPACITY && _d[counter] == 0){
        _d[counter] = 9;
        ++counter;
    }
    if (counter < CAPACITY){
        _d[counter] -= 1;
    }
    return *this;
}

// pre: none
// post: this biguint has been incremented/decremented by 1
//       return value is the original value (post)
biguint biguint::operator++(int){
    biguint origin = *this;
    ++(*this);
    return origin;
}

biguint biguint::operator--(int){
    biguint origin = *this;
    --(*this);
    return origin;
}

// NON-MEMBER OPERATORS

// I/O operators
std::ostream & operator <<(std::ostream & os, const biguint & n){
    bool lz = true;
    for(int i = biguint::CAPACITY - 1; i >= 0; --i){
        if(n[i] != 0 || !lz){
            os << char(n[i] + '0');
            lz = false;
        }
    }
    if (lz) {
        os << '0';
    }
    return os;
}

std::istream & operator >>(std::istream & is, biguint & n){
    std::string construct;
    is >> construct;
    n = biguint(construct);
    return is;
}

// ARITHMETIC operators
biguint operator + (const biguint & left, const biguint & right){
    biguint plus = biguint(left);
    plus += right;
    return plus;
}
biguint operator - (const biguint & left, const biguint & right){
    biguint minus = biguint(left);
    minus -= right;
    return minus;
}

// COMPARISON operators
bool operator <(const biguint & left, const biguint & right){
    return left.compare(right) == -1;
}

bool operator <=(const biguint & left, const biguint & right){
    int result = left.compare(right);
    return result == -1 || result == 0;
}

bool operator ==(const biguint & left, const biguint & right){
    return left.compare(right) == 0;
}

bool operator !=(const biguint & left, const biguint & right){
    int result = left.compare(right);
    return result == 1 || result == -1;
}

bool operator >=(const biguint & left, const biguint & right){
    int result = left.compare(right);
    return result == 1 || result == 0;
}

bool operator >(const biguint & left, const biguint & right){
    return left.compare(right) == 1;
}

