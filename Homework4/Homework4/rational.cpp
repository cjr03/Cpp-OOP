#include <iostream>
#include <cassert>
#include <numeric>
using namespace std;

class Rational {
  public:

    // pre-condition: d != 0
    // post-condition: a new Rational n/d has been created
    //                 default value = 0/1
    Rational(int n = 0, int d = 1)    // constructor, default to 0/1
    {
    assert(d != 0);
    _n = n;
    _d = d;
    simplify();
    }
    // GETTERS// pre-condition: none// post-condition: returns numerator of this Rational
    int getN() const {
    return _n;

    }
    // pre-condition: none// post-condition: returns denominator of this Rational
    int getD() const {
    return _d;
    }
    // SETTERS// pre-condition: none// post-condition: numerator has been set to newN
    void setN(int newN) {
    _n = newN;
    }

    // pre-condition: newD != 0
    // post-condition: denominator has been set to newD
    void setD(int newD) {
    assert(newD != 0);
    _d = newD;
    }

    // OPERATOR OVERLOADING

    // pre: none
    // post: rhs has been added to this Rational
    void operator +=(const Rational & rhs) {
    _n = _n * rhs._d + _d * rhs._n;
    _d *= rhs._d;
    simplify();
    }

    // pre: none
    // post: rhs has been subtracted from this Rational
    void operator -=(const Rational & rhs) {

    _n = _n * rhs._d - _d * rhs._n;
    _d *= rhs._d;
    simplify();

    }

    // pre: rhs != 0
    // post: this Rational has been divided by rhs
    void operator /=(const Rational & rhs) {
    assert(rhs._n != 0);
    _n *= rhs._d;
    _d *= rhs._n;
    simplify();
    }

    // pre-condition: none
    // post-condition: this Rational has been multipled by rhs
    void operator *=(const Rational & rhs) {
    _n *= rhs._n;
    _d *= rhs._d;
    simplify();
    }

    // pre-condition: this Rational is not 0
    // post-condition: this Rational has been inverted
    //                 (numerator <-> denominator)
    void operator !() {
    assert(_n != 0);
    int temp(_n);
    _n = _d;
    _d = temp;
    }

    // pre: none
    // post: one has been added to this Rational
    //       the NEW value is returned
    Rational operator ++() {
    _n += _d;
    return *this;
    }

    // pre: none
    // post: one has been added to this Rational
    //       the ORIGINAL value is returned
    Rational operator ++(int) {
    Rational original(*this);
    _n += _d;
    return original;
    }

    // pre: none
    // post: return 0 if this Rational has the same value as rhs
    //       return 1 if this Rational is greater than rhs
    //       return -1 if this Rational is smaller than rhs
    int compare(const Rational & rhs) const {
    int n1(_n), d1(_d), n2(rhs._n), d2(rhs._d);
    if (d1 < 0) {
        d1 = -d1;
        n1 = -n1;
    }
    if (d2 < 0) {
        d2 = -d2;
        n2 = -n2;
    }

    int p1 = n1 * d2;
    int p2 = n2 * d1;

    if (p1 == p2)
        return 0;
    else if (p1 > p2)
        return 1;
    else
        return -1;
    }

    // FRIEND FUNCTIONS
    friend ostream & operator <<(ostream & os, const Rational & r);

    friend istream & operator >>(istream &, Rational &);

  private:
    int _n, _d;            // numerator and denominator

    // pre-condition:
    // post-condition: numerator and denominator has no
    //                 common divisor greater than 1
    void simplify() {
    int g = gcd(_n, _d);
    _n /= g;
    _d /= g;
    }

};

istream & operator >>(istream & is, Rational & r)
{
    is >> r._n >> r._d;
    return is;
}

ostream & operator <<(ostream & os, const Rational & r)
{

    os << r._n << "/" << r._d;
    return os;
}

Rational operator *(const Rational & x, const Rational & y)
{
    Rational ans(x);
    ans *= y;
    return ans;
}

Rational operator /(const Rational & x, const Rational & y)
{
    Rational ans(x);
    ans /= y;
    return ans;
}

Rational operator +(const Rational & x, const Rational & y)
{
    Rational ans(x);
    ans += y;
    return ans;
}

Rational operator -(const Rational & x, const Rational & y)
{
    Rational ans(x);
    ans -= y;
    return ans;
}

bool operator <(const Rational & left, const Rational & right) {
    return left.compare(right) == -1;
}

bool operator <=(const Rational & left, const Rational & right) {
    return left.compare(right) <= 0;
}

bool operator ==(const Rational & left, const Rational & right) {
    return left.compare(right) == 0;
}

bool operator !=(const Rational & left, const Rational & right) {
    return left.compare(right) != 0;
}

bool operator >=(const Rational & left, const Rational & right) {
    return left.compare(right) >= 0;
}

bool operator >(const Rational & left, const Rational & right) {
    return left.compare(right) == 1;
}

Rational operator -(const Rational & operand) {
    return Rational(-(operand.getN()), operand.getD());
}

int main()
{
    const int N(10);

    for (int n1 = -N; n1 <= N; ++n1) {
    Rational a(n1);
    for (int n2 = -N; n2 <= N; ++n2) {
        Rational b(n2);
        for (int d1 = -N; d1 <= N; ++d1)
        for (int d2 = -N; d2 <= N; ++d2) {
            if (d1 == 0 || d2 == 0)
            continue;
            a.setD(d1);
            b.setD(d2);

            assert((a < b) ==
               ((double) n1 / d1 < double (n2) / d2));
            assert((-a < b) ==
               ((double) n1 / -d1 < double (n2) / d2));
            assert((a <= b) ==
               ((double) n1 / d1 <= double (n2) / d2));
            assert((a <= -b) ==
               ((double) n1 / d1 <= double (n2) / -d2));
            assert((a == b) ==
               ((double) n1 / d1 == double (n2) / d2));
            assert((-a == b) ==
               ((double) n1 / -d1 == double (n2) / d2));
            assert((a != b) ==
               ((double) n1 / d1 != double (n2) / d2));
            assert((a != -b) ==
               ((double) n1 / d1 != double (n2) / -d2));
            assert((a >= b) ==
               ((double) n1 / d1 >= double (n2) / d2));
            assert((-a >= b) ==
               ((double) n1 / -d1 >= double (n2) / d2));
            assert((a > b) ==
               ((double) n1 / d1 > double (n2) / d2));
            assert((a > -b) ==
               ((double) n1 / d1 > double (n2) / -d2));
        }
    }
    }

    cout << "Passed!" << endl;
    return 0;
}

