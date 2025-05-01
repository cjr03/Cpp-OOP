//
//  main.cpp
//  Lab8
//
//  Created by Cole Roberts on 3/4/25.
//

#include <iostream>
#include "dbiguint.h"

using namespace std;

int main()
{


    dbiguint a(9876543210123456789), b, c("98765432101234567890"), d(a), e(c);

    

    cout << "a, b, c, d, e  = " << a << ", " << b << ", " << c << ", " << d << ", " << e << endl;

    
    cout << a << " + " << c << " = " << a + c << endl;
    cout << a << " * " << c << " = " << a * c << endl;
    cout << a << " *= " << c;
    dbiguint ta(a);
    ta *= c;
    cout << " = " << ta << endl;
    cout << a << " += " << c;
    dbiguint pa(a);
    pa += c;
    cout << " = " << pa << endl;



    cout << "d, ++d, d = " << d << ", " << ++d << ", " << d << endl;
    cout << "e, e++, e = " << e << ", " << e++ << ", " << e << endl;

    cout << a << " <= " << d << " = " << (a <= d) << endl;
    cout << a << " == " << d << " = " << (a == d) << endl;
    cout << a << " != " << d << " = " << (a != d) << endl;
    cout << a << " < " << ++d << " = " << (a < d) << endl;
    cout << ++a << " >= " <<  d << " = " << (a >= d) << endl;
    cout << a << " > " << d << " = " << (a > d) << endl;



    return 0;
}


