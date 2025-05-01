//
//  dbiguint.cpp
//  Lab8
//
//  Created by Cole Roberts on 3/4/25.
//

#include "dbiguint.h"
#include <iostream>

dbiguint::dbiguint(std::size_t n, size_type c) {
    if (n == 0) {
        _capacity = DEFAULT_CAPACITY;
        _data = new digit_type[_capacity]{0};
    } else {
        _capacity = c;
        _data = new digit_type[_capacity];
        for (size_type i = 0; i < _capacity; ++i) {
            _data[i] = n % 10;
            n /= 10;
        }
    }
}

dbiguint::dbiguint(const std::string & s) {
    _capacity = s.size();
    if (_capacity == 0) {
        _capacity = 1;
        _data = new digit_type[_capacity]{0};
        return;
    }
    
    _data = new digit_type[_capacity];
    size_type j = 0;
    for (int i = s.size() - 1; i >= 0; --i, ++j) {
        _data[j] = digit_type(s[i] - '0');
    }
}

dbiguint::dbiguint(const dbiguint & b) {
    _capacity = b._capacity;
    _data = new digit_type[_capacity];
    std::copy(b._data, b._data + _capacity, _data);
}

dbiguint::~dbiguint(){
    delete[] _data;
}

dbiguint::digit_type dbiguint::operator [] (size_type pos) const {
    return pos < _capacity ? _data[pos] : 0;
}

dbiguint::size_type dbiguint::size() const {
    for (size_type i = _capacity; i > 0; --i) {
        if (_data[i-1] != 0) {
            return i;
        }
    }
    return 1;
}

std::string dbiguint::to_string() const {
    std::string s;
    bool lz = true;
    for (size_type i = _capacity; i > 0; --i) {
        if (lz) {
            if (_data[i-1] == 0) {
                continue;
            }
            lz = false;
        }
        s += static_cast<char>('0' + _data[i-1]);
    }
    return s.empty() ? "0" : s;
}

std::ostream & operator<<(std::ostream & os, const dbiguint & d) {
    return os << d.to_string();
}
std::istream & operator>>(std::istream & is, dbiguint & d) {
    std::string s;
    is >> s;
    d = dbiguint(s);
    return is;
}

void dbiguint::operator+=(const dbiguint & b) {
    size_type new_c = std::max(size(), b.size()) + 1;
    digit_type* new_d = new digit_type[new_c]();
    std::copy(_data, _data + _capacity, new_d);
    digit_type c = 0;
    for (size_type i = 0; i < new_c; ++i) {
        digit_type s = new_d[i] + b[i] + c;
        new_d[i] = s % 10;
        c = s / 10;
    }
    delete[] _data;
    _data = new_d;
    _capacity = new_c;
}

dbiguint operator +(const dbiguint & l, const dbiguint & r){
    dbiguint n = l;
    n += r;
    return n;
}

int dbiguint::compare(const dbiguint & d) const {
    size_type _d_size = size(), d_size = d.size();
    if (_d_size != d_size){
        return (_d_size > d_size) ? 1 : -1;
    } else {
        for (size_type i = _d_size - 1; i >= 0; --i){
            if (_data[i] != d[i]){
                return (_data[i] > d[i]) ? 1 : -1;
            }
        }
        return 0;
    }
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

dbiguint dbiguint::operator++() {
    *this += dbiguint(1);
    return *this;
}

dbiguint dbiguint::operator++(int){
    dbiguint og = *this;
    ++*this;
    return og;
}

void dbiguint::operator*=(const dbiguint & b) {
    size_type new_c = size() + b.size();
    digit_type* r = new digit_type[new_c]();
    for (size_type i = 0; i < size(); ++i) {
        digit_type c = 0;
        for (size_type j = 0; j < b.size() || c; ++j) {
            digit_type p = r[i+j] + _data[i] * b[j] + c;
            r[i+j] = p % 10;
            c = p / 10;
        }
    }
    _capacity = new_c;
    for (size_type i = _capacity - 1; i >= 0; --i){
        if(_data[i] == 0){
            _capacity = i + 1;
            break;
        }
    }
    delete[] _data;
    _data = r;
}

dbiguint operator *(const dbiguint & l, const dbiguint & r){
    dbiguint n = l;
    n *= r;
    return n;
}

void dbiguint::operator =(const dbiguint & source){
    if (this != &source) {
        delete[] _data;
        _capacity = source._capacity;
        _data = new digit_type[_capacity];
        std::copy(source._data, source._data + _capacity, _data);
    }
}
