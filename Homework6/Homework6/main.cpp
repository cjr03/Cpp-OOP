
#include <iostream>
//#include <string>
#include "biguint.h"

using namespace std;

int main()
{


    cout << "PLEASE CHANGE biguint::CAPACITY to 10 before continuing..." << endl << endl << endl;

    biguint a(987654321), b, c("1234567890"), d(a), e(c);

    

    cout << "a, b, c, d, e  = " << a << ", " << b << ", " << c << ", " << d << ", " << e << endl;

    
    cout << a << " + " << c << " = " << a + c << endl;
    cout << a << " - " << c << " = " << a - c << endl;
    cout << c << " - " << a << " = " << c - a << endl;

    size_t s = a.size();
    cout << a << " has " << s << " digit(s): ";
    for (int i = 0; i < s; ++i)
      cout << a[i] << " ";
    cout << endl;

    cout << a << " << 3 = ";
    a << 3;
    cout << a << endl;
    cout << a << " >> 5 = ";
    a >> 5;
    cout << a << endl;

    cout << "d, ++d, d = " << d << ", " << ++d << ", " << d << endl;
    cout << "e, e++, e = " << e << ", " << e++ << ", " << e << endl;

    cout << "d, --d, d = " << d << ", " << --d << ", " << d << endl;
    cout << "e, e--, e = " << e << ", " << e-- << ", " << e << endl;

    cout << a << " <= " << d << " = " << (a <= d) << endl;
    cout << a << " == " << d << " = " << (a == d) << endl;
    cout << a << " != " << d << " = " << (a != d) << endl;
    cout << a << " < " << ++d << " = " << (a < d) << endl;
    cout << ++a << " >= " <<  d << " = " << (a >= d) << endl;
    cout << a << " > " << d << " = " << (a > d) << endl;



    return 0;
}
