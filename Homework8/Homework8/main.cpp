#include <iostream>
#include "dbiguint.h"

using namespace std;

int main()
{


    dbiguint a(9876543210123456789), b, c("98765432101234567890"), d(a), e(c);

    

    cout << "a, b, c, d, e  = " << a << ", " << b << ", " << c << ", " << d << ", " << e << endl;

    
    cout << a << " + " << c << " = " << a + c << endl;
    cout << a << " - " << c << " = " << a - c << endl;
    cout << c << " - " << a << " = " << c - a << endl;
    cout << a << " * " << c << " = " << a * c << endl;

    int s = a.size();
    cout << a << " has " << s << " digit(s): ";
    for (int i = 0; i < s; ++i)
      cout << a[i] << " ";
    cout << endl;

    cout << a << " << 13 = " << (a << 13) << endl;
    cout << a << " >> 8 = " << (a >> 8) << endl;

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


