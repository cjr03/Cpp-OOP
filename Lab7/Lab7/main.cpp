//
//  main.cpp
//  Lab7
//
//  Created by Cole Roberts on 2/18/25.
//

#include "biguint.h"
#include <iostream>


int main(){
    biguint a = biguint(1234), b = biguint(1111);
    std::cout << "a = " << a << "\nb = " << b << "\na+=b = ";
    a += b;
    std::cout << a << std::endl;
    std::cout << "a = " << a << "\nb = " << b << "\na+b = " << a+b << std::endl;
    std::cout << "a < b ? " << (a<b) << std::endl << "a <= b ? " << (a<=b) << std::endl << "a > b ? " << (a>b) << std:: endl << "a >= b ? " << (a>=b) << std::endl << "a == b ? " << (a==b) << std::endl << "a != b ? " << (a!=b) << std::endl;
        
}
